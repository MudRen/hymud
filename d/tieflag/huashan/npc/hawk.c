#include <ansi.h>
#include <globals.h>
inherit NPC;
string player_env(object target, object me); 
//void eatMeat(object ob);
void create()
{
    set_name(HIC"��ӥ"NOR, ({ "hawk" }) );
    set("race", "Ұ��");
    set("age", 1);
    set("gender", "����");
    set("long","һֻ������צ�Ĳ�ӥ����һ˫�����������۾��������㿴�����ް������֮�⡣ ");
    set("attitude","peaceful");
    set("limbs", ({ "ͷ��", "����","β��" }) );
    set("verbs", ({ "bite","claw" }) );
        set("weight", 3000);
        set("agi", 40);
        set("per",30);
        set("str",150);
        set_skill("move",400);
    set_skill("unarmed",400);
    set_skill("dodge",400);
    set("combat_exp", 50000000);
        set("max_jing", 3000);
    set("max_qi", 3000);
    set("max_sen", 3000);
    set("eff_jing", 3000);
    set("eff_qi", 3000);
        set("eff_sen", 3000);
        set("marks/chained",1);
        set("marks/trained",0);
        set("no_give", 1);
        //set("no_drop", 1);
//    set("unique_amount", 1);  
//    ITEM_D->setup_unique(this_object());  
        setup();
}  
void init() 
{
        ::init();
   add_action("do_catch", "catch");
        add_action("do_feed","feed");
        add_action("do_chain","chain");
        add_action("do_train","train");
        add_action("do_drop","drop");
} 
int checkChained()
{
        
        object hawk;
        hawk = this_object();
        if (hawk->query("marks/chained"))
        {
                object room;
                room = find_object(__DIR__"fupi");
                if(environment() == room && room->query("item_desc") == 0)
                {
                        room->set("item_desc", ([
                        "chain": "һ��ϵӥ�õ�ϸϸ�ĺ�ɫ�������ƺ������������ġ�\n �����룬��֪����������Կ�������Ҳ�����ʲô���Կ���(chop)���� \n",
                        "����":"һ��ϵӥ�õ�ϸϸ�ĺ�ɫ�������ƺ������������ġ� \n �����룬��֪����������Կ�������Ҳ�����ʲô���Կ���(chop)����\n",
                        ]) );
                }
                //return notify_fail("��ӥ�Ľ��ϻ�ϵ�������أ� \n");
                return 1;
        }
        return 0;
}  
int do_catch(string arg) 
{
        object me, hawk, chain, *inv;
        object hawktrainer;
        int i;
        me = this_player();
        hawk=this_object();
        if(!arg || (arg != "hawk" && arg != "��ӥ")) 
        {
                return 0;
        }
        if(!(present(hawk, environment(me))) || hawk->query("marks/trained"))
        {
        return 0;
    }
        
        if (hawktrainer=present("trainer",environment(hawk)))
        {
                message_vision(RED"$N��$n���һ�����������ӥ�����⣡���ò��ͷ��ˣ� \n"NOR,
                       hawktrainer,this_player());
        hawktrainer->kill_ob(this_player());
        this_player()->start_busy(2);
        return 1;
        }
        if (checkChained())
        {
                return notify_fail("��ӥ�Ľ��ϻ�ϵ�������أ� \n");
        }
        
        if (random(4))
        {
                message_vision(HIW"��ӥһ�����У�����$N��Ҫ������\n"NOR,me);
        }
        else
        {
                message_vision(HIR"��ӥһ�ĳ���������һ˫��צץ��$N��ǰ��\n"NOR,me);
                inv = all_inventory(me);
                for (i=0;i<sizeof(inv);i++ )
                {
                        //write (inv[i]->name()+":"+inv[i]->query("equipped")+"\n");
                        if (objectp(inv[i]) && (inv[i]->name()==YEL"����"NOR) && (inv[i]->query("equipped")=="worn"))
                        {
                                message_vision(HIW"��ӥ��˫צž�ػ���$N�������ϣ����հ������� \n"NOR,me);
                                return 1;
                        }
                }               
                // will be blind sob
                tell_object(me, HIR"��˫��һ���ʹ�� \n �����ǰһƬ��ڡ����� \n"NOR);
                me->set_temp("block_msg/all", 1);
        }
        return 1;
} 
void eatMeat(object me)
{
        int avai,remain;
        object hawk,wolfmeat;
        hawk = this_object();
        call_out("eatMeat",20,me);
        if (!present(hawk,me))
        {
                remove_call_out("eatMeat");
                message_vision("$N��Хһ�����򳤿շ�ȥ��\n",hawk);
                destruct(hawk);
        }
        if (wolfmeat = present("wolfmeat",me))
        {
                remain = (int)wolfmeat->query("food_remaining") * (int)wolfmeat->query("food_supply");
                avai = 100;
                //avai = (int)hawk->max_food_capacity() - (int)hawk->query("food");
                //make avai a certain amount to make hawk eat faster
                if( remain > avai )
                {
                        add("food_remaining", -(avai/(int)wolfmeat->query("food_supply")));
                }
                else
                {
                        //hawk->add("food",remain);
                        wolfmeat->set("food_remaining", 0);
                }
                        wolfmeat->set("value", 0);
                        if( !wolfmeat->query("food_remaining") ) 
                        {
                                //meat is gone
                                message_vision("$N��ʣ�µ�" + name() + "�Ե�ǬǬ������\n", hawk);
                                if( !wolfmeat->finish_eat() )
                                        destruct(wolfmeat);
                                message_vision("$N����$n���е��⣬��������з�ȥ��\n",hawk,me);
                                me->clear_condition("hawk_claw");
                                remove_call_out("eatMeat");
                                destruct(hawk);
                        }
                        else 
                                message_vision("$N����$nҧ�˼��ڡ�\n", hawk,wolfmeat);
   }
        else
        {
                //dunno why have to do this
                message_vision("$n���е��ⱻ�����ˣ�$N��������з�ȥ��\n",hawk,me);
                me->clear_condtion("hawk_claw");
                remove_call_out("eatMeat");
                destruct(hawk);
        }
        return ;
} 
int do_drop(string arg)
{
        object me,hawk;
        hawk = this_object();
        me = this_player();
        if (arg != "hawk" && arg !="��ӥ")
        {
                return 0;
        }
        //seems no need to check so many status, just for caution
        if(!present(hawk, me) || hawk->query("marks/owner"))
        {
                return 0;
        }
        me->clear_condtion("hawk_claw");
        remove_call_out("eatMeat");
        if (hawk->query("marks/feeding"))
        {
                message_vision("$N�ֱ۳�ʹ����������ӥ����������\n",me);
        }
        message_vision("��ӥ�ڿ���������Ȧ�������ȥ��\n",me);
        destruct(hawk);
        return 1;
}
     
int do_feed(string arg)
{
        object me;
        object wolfmeat,leathersleeves,hawktrainer;
   object hawk;
        string argmeat, arghawk;
        hawk = this_object();
        me = this_player();
        if(!(present(hawk, environment(me))) || hawk->query("marks/trained"))
        {
        return 0;
    }
        if(!arg) 
        {
                return notify_fail("��Ҫι˭ʲ�ᶫ����\n");
    }
    if(sscanf(arg, "%s to %s", argmeat, arghawk)==2 || sscanf(arg, "%s %s", arghawk, argmeat)==2 );
    else 
        {
                return 0;
    }
    
        if (argmeat !="wolfmeat" && arg !="���⸬" && arghawk != "hawk" && arghawk != "��ӥ")
        {
                return 0;
        }
        if (checkChained())
        {
                return notify_fail("��ӥ�Ľ��ϻ�ϵ�������أ����ܷɹ������⣡\n");
        }
        if (hawktrainer = present("hawk trainer",this_object()))
        { 
        message_vision(RED"$N��$n���һ�����������ӥ�����⣡���ò��ͷ��ˣ� \n"NOR,
                       hawktrainer,me);
        hawktrainer->kill_ob(me);
        me->start_busy(2);
        return 1;
    }
        if (!wolfmeat=present("wolfmeat",me))
        {       
                return notify_fail("������û���������� \n");
        }
        message_vision("$N�����ó����⸬������ӥ��\n ",me);
        if (random(10) && me->query("per")<=20)
   {
                message_vision("��ӥ���ɲ����ؿ���$N��\n" ,me);
                return 1;
        }
        if (hawk->move(me))
        {
                message_vision("��ӥ����$N���ֱۣ���$N���������⸬����������\n",me);
                if (!leathersleeves=present("leather sleeves",me))
                {
                        me->apply_condition("hawk_claw",10);
                }
                hawk->set("marks/feeding",1);
                call_out("eatMeat",10,me);
        }
        else
        {
                tell_object(me,"�������޷����ܲ�ӥ��������\n");
        }
        return 1;
} 
int do_chain(string arg)
{
        object hawk, me,chain;
        hawk = this_object();
        me = this_player();
        if (!present(hawk,me) || !hawk->query("marks/feeding") || hawk->query("marks/trained"))
        {
                return 0;
        }
        if (arg != "hawk" && arg !="��ӥ")
        {
                return 0;
        }
        
        if (!chain = present("chain",me))
        {
                return notify_fail("��Ҫ��ʲôϵ��ӥ \n");
        }
        message_vision("$N��$næ�ų����⸬������ذ�һ��С����ϵ�������ϡ�\n",me,hawk);
        destruct(chain);
   hawk->set("marks/feeding",0);
        //now we can stick hawk with the player
        set("no_drop", 1);
        hawk->set("marks/owner",me->name());
        me->clear_condition("hawk_claw");
        remove_call_out("eatMeat");
        return 1; 
}
int do_train(string arg)
{
        object me,hawk;
        hawk = this_object();
        me = this_player();
        if (!present(hawk,me) || hawk->query("marks/owner") != me->name() || hawk->query("marks/trained"))
        {
                return 0;
        }
        if (arg != "hawk" && arg != "��ӥ")
        {
                return 0;
        }
        if (me->query_skill("animal-training") < 300)
        {
                return notify_fail("���ѵ�����������ߣ�\n");
        }
        message_vision("$N���ĵ�ѵ��$n,$n�ƺ�������$N�Ļ����������������˼�Ȧ��������$N�ļ��ϡ�\n",me,hawk);
        set("marks/trained",1);
        set_name(HIC"��ӥ"NOR, ({ "hawk" }) );
    set("long","һֻ��������ӥ�������԰�����죨SPY�������");
        add_action("do_spy","spy");
        return 1;
}
void spy_player(object target, object me)
{
        if (!target)
        {
                delete("marks/inspy");
                remove_call_out("spy_player");
                tell_object(me,"��ӥ����㱨������Ҫ�������뿪�� \n");
        }
   if (!present(this_object(),me))
        {
                delete("marks/inspy");
                remove_call_out("spy_player");
                tell_object(me,"��ӥ�Ѿ������ȥ�����ܼ���Ϊ����졣 \n");
                destruct(this_object());
        }
        call_out("spy_player",10,target,me);
        set("marks/inspy",1);
        tell_object(me,"��ӥ�������������˼�Ȧ��������ļ��� \n");
        tell_object(me,"��ӥ����㱨����\n");
        tell_object(me,player_env(target,me));
}
int do_spy(string arg)
{
        object hawk,me,target;
        hawk = this_object();
        me = this_player();
        if (!present(hawk,me) || hawk->query("marks/owner") != me->name() || !hawk->query("marks/trained"))
        {
                return 0;
        }
        if (!arg)
        {
                return notify_fail("�������˭�������(spy none �������ֹͣ�ִ����)\n");
        }
        if (arg=="none")
        {
                delete("marks/inspy");
                remove_call_out("spy_player");
        }else
        {
                target = find_living(arg);
                if (!target || !userp(target))
                {
                        return notify_fail("��ӥ�����Ŀ����㣬�ƺ���˵���ϴ�û�������Ү��\n");
                }
                if (wizardp(target))
                {
                        // will ban them to spy wizard , grin
           }
                if (query("marks/inspy"))
                {
                        return notify_fail("��ӥ�����Ŀ����㣬�ƺ���˵���ϴ󣬲�ҪŰ�������ֹͣ����������˵ ��(spy none) \n");
                }
                spy_player(target,me);
        }
        return 1;
} 
string player_env(object target,object me) {
        int i;
        object *inv,env;
        mapping exits;
        string roomdesc, str, *dirs;
        env = environment(target); 
        if(!env) {
                return target->name() + "�����ܻ����ɵ�һƬ��ʲ��Ҳû�С�\n";
        }
        if (!env->query("outdoors"))
                str = target->name() + "������ \n";
        else
                str = "";
        
        // room descriptions.
        str += sprintf( "%s \n    %s",
                        env->query("short"),
                        //wizardp(target)? file_name(env)+sprintf(" - (%d,%d,%d)",env->query("coor/x"),
                        //              env->query("coor/y"),env->query("coor/z")): "",
                        //env->long(),
                        env->query("outdoors")? NATURE_D->outdoor_room_description() : "" ); 
        // exits.
        if(mapp(exits = env->query("exits"))) {
                dirs = keys(exits);
                for(i=0; i<sizeof(dirs); i++) {
                        if((int)env->query_door(dirs[i], "status") & 1 ) {
                                dirs[i] = 0;
                        }
                }
                dirs -= ({ 0 });
                if(sizeof(dirs)==0) {
                   str += "    ����û���κ����Եĳ�·��\n";
                } else if(sizeof(dirs)==1) {
                        str += "    ����Ψһ�ĳ����� " + BOLD + dirs[0] +NOR + "��\n";
                } else {
                        str += sprintf("    �������Եĳ����� " + BOLD + "%s" +NOR + 
                                        " �� " + BOLD + "%s" +NOR + "��\n",
                                        implode(dirs[0..sizeof(dirs)-2], "��"), dirs[sizeof(dirs)-1]);
                }
        } else {
                str += "    ����û���κ����Եĳ�·��\n";
        }
        
        // all things in the room.
        inv = all_inventory(env);
        for(i=0; i<sizeof(inv); i++) {
                if( inv[i]->query("no_shown") || !me->visible(inv[i])) {
                        continue;
                }
                str += "  " + inv[i]->short() + "\n";
        }
        return str;
}        
