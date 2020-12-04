#include <ansi.h>
void smart_fight();
void smart_busy();
void smart_attack(); 
inherit F_MASTER;
inherit NPC;
void imbue_event(object me);
void create()
{
        set_name("���ʮ����", ({ "tianfeng"}) );
        set("gender", "����" );
        set("age", 55);
        set("nickname", CYN "��������" NOR);
        set("long", 
"һ����ɫ���ƣ�Ũü��ȧ���������ߣ�������ɱ��������ϥ����ɽ��֮�ϣ�
�¾���¶�����㣬ȴ��һ˫�߳���ľ��ľ��˷���ǰ��ľ���Ͼ��ַ��ű���
�ʳ�����\n");
//      create_family("һ����", 7, "�Ҷ�");
//      set("rank_nogen",1);
//      set("ranks",({"����","����","����",RED"��ɲ"NOR,HIR"����"NOR}));
//      set("rank_levels",({32000,512000,1536000,3456000 }));
        set("combat_exp", 3200000);
        set("attitude", "friendly");
        set("reward_npc", 1);
        set("difficulty", 10);
        
        set("neili", 800);
        set("max_neili",800);
        set("force_factor",30);
        set("skill_public",1);
        
        set_skill("unarmed", 140);
        set_skill("ghosty-force", 300);
        set_skill("enmeiryu",150);
        set_skill("ittouryu",160);
        set_skill("ninjitsu",200);
        set_skill("dodge", 140);
        set_skill("ghosty-steps",200);
        set_skill("blade",140);
        set_skill("literate", 140);
           set_skill("force", 180);
        set_skill("parry", 140);
        set_skill("magic", 100);
        set("resistance/kee",10);
        
        map_skill("magic", "ninjitsu");
        map_skill("unarmed", "enmeiryu");
        map_skill("blade", "ittouryu");
        map_skill("parry", "ittouryu");
        map_skill("force", "ghosty-force");
        
        
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: smart_fight() :),    
        }) );  
   
   
   
        set_temp("apply/damage",100);
        set("chat_chance", 1);
        set("chat_msg", ({
                        "���ʮ������ب�Ų��������ɫ����ͻȻ�����������۵�һ���ȳ�����Ѫ��\n",
                                })  );
        set("inquiry",  ([
                "���" : "���ӡ������ӡ��������������\n",
                "�Ϲ���" : "��ʧɢ����ĺ��Ӱ�������֮������ܼ���һ����Ҳ�޺�����\n",
                "�޻�" : "��ʧɢ����ĺ��Ӱ�������֮������ܼ���һ����Ҳ�޺�����\n",
                ])              );
        
        setup();
        carry_object(__DIR__"obj/wucloth")->wear();
        carry_object(__DIR__"obj/muji")->wear();
        carry_object(__DIR__"obj/blackblade")->wield();
}   
void win_enemy(object loser)
{
    message_vision(HIC "���ʮ�������쳤̾һ�������á���\n"NOR,loser);
    message_vision(HIR "���ʮ����ͻȻ�۵�һ���������Ѫ������һ�����쳤˻��
���Ӱ����㡣�����㡣���ںη�����\n"NOR,loser);
   loser->set("���_quest1",time());
} 
void lose_enemy( object winner)
{
        object blade;
        
        winner->set("���_quest1","�ɹ�");
        if(blade=present("black blade",this_object()))
        {
                message_vision(HIR"���ʮ�������Ұ���۾�ͻȻ����������˫�ֽ����ʳ�������$N��
˫ϥ�����Ȼ�����㣬�ú����˵�����ת��������������������ˡ���\n"NOR,winner);
                blade->move(winner);
        }
                
} 
int accept_fight(object me)
{
        int count;
        object blade,who;
        who=this_object();
        
        if (this_object()->is_fighting() || this_object()->is_busy())
                return notify_fail("���ʮ��������æ���أ�û�պ�����\n");
        
        if(!present("black blade",this_object())) return 0;
        if(me->query("���_quest1")=="�ɹ�")
        {
                message_vision(HIW"���ʮ�����ʵ������Ұ���������飬�����������𣿡�\n"NOR,me);
                return 0;
        }
        if(me->query("���_quest1")&&me->query("���_quest1")+600>time())
        {
                message_vision(HIR"���ʮ���ɲ�м�Ŀ���$N˵���������°ܽ���������������\n"NOR,me);
                return 0;
        }
        count=me->query_temp("���_��ս����");
        
        if(me->query("combat_exp")<2500000||me->query("score")<15000)
        {
        if(count==0)
           message_vision(HIY"���ʮ���ɻ�Ȼ����˫����ɨ��$Nһ�ۣ�΢̾һ������Ŀ���\n"NOR,me);
        
        else if(count==1)
                message_vision(HIY"���ʮ���ɺ���һ���ͺȵ������˶�����ʮ���ɣ���ս�������µµ��Ϊ֮����\n"NOR,me);
        else if(count==2)
        {
                message_vision(HIW"���ʮ����üͷ΢�壬��Ǻ����һ��������է�֡�\n"NOR,me);
                kill_ob(me);
                me->delete_temp("���_��ս����");
                return 2;
        }
        me->add_temp("���_��ս����",1);
        return 0;
        }
        
        if (who->query("qi")<who->query("max_qi") || who->query("eff_qi")<who->query("max_qi")
        || who->query("sen")<who->query("max_sen") || who->query("eff_sen")<who->query("max_sen")
        || who->query("jing")<who->query("max_jing") || who->query("eff_jing")<who->query("max_jing"))
                {tell_object(this_player(),"���ʮ������������,û������.\n");
                return 0;
                }
        message_vision(HIY"���ʮ���ɳ���һ����,��Ȼ����˫����Ŀ����綢��$N����������㣬���У�\n"NOR,me);
        return 1;
}
        
        
int accept_object(object who, object ob)
{
        if(!ob->query("saki")) return 0;
        message_vision(HIC"���ʮ����˫�ֽ�����ƿ��ƣ�����ر���\n"NOR,who);
        call_out("be_poisoned",5+random(5),who);
        return 1;
} 
int be_poisoned(object who)
{
    message_vision(HIR"\n���ʮ���ɲ�����������ƣ������ݺᣬһ��������\n
ͻȻ���ʮ���ɻ�������������죬��Ȼ�������ӣ��㡣���㡣��������
��λ"+RANK_D->query_respect(who)+"���������涾�������ܱƳ���Ҳ�ع������ϣ�����һ������
��֪��ɷ��Ӧ��\n"NOR,who);
        if(who->query("���_quest4")!="�ɹ�")
   {
                die();
                return 1;
        }
    tell_object(who,HIY"answer yes/no \n"NOR);
        who->set_temp("answer_person",1);
        return 1;
} 
int do_answer(string arg)
{
        object skinmask,who;
        
        who=this_player();
        if(!who->query_temp("answer_person")) return 0;
        if(arg=="yes")
        {
                message_vision("$N��ɫ���صص���һ��ͷ��\n",who);
                message_vision(HIB"���ʮ���������Ц�����ã��ҽ���Լս����ԭһ��죬��ʹ���
һս�ɡ�����ص�ӿȪ�౨��\n"NOR,who);
                skinmask=new(__DIR__"obj/skinmask");
                skinmask->move(who);
                message_vision("���ʮ���ɸ�$Nһ��װ����\n",who);
                who->set("���_quest5","�ɹ�");
                who->delete_temp("answer_person");
                return 1;
                
        }
        if(arg=="no")
        {
                message_vision(HIR"���ʮ������ȻһЦ���³�����Ѫ�����ض�����\n"NOR,who);
                die();
                return 1;
        }
        return 0;
}  
void imbue_event(object me){
    object obj, weapon, *inv;
    string prop;
    int i;
    
    if(!interactive(me) || environment(me) != environment(this_object())) {
            return;
    }
        obj = me->query_temp("weapon");
        if(objectp(obj) && obj->query("owner")) {
                weapon = me->query_temp("weapon");
        } else { 
                inv = all_inventory(me);        
                for(i=0; i<sizeof(inv); i++) {
                        if(inv[i]->query("weapon_prop") && inv[i]->query("owner")) {
                                weapon = inv[i];
                                break;
                        }
                }       
        }
        if(!objectp(weapon)){
                if(!objectp(obj)) {
                        message_vision(HIG"\n��ˮ�������ϣ�һ�������ʧ�ˡ�����\n"NOR, me);
                } else {
                        message_vision(HIG"\n��ˮ������$N��" + obj->name() + HIG"�ϣ���˳��"
                        + obj->name() + HIG"�䵽�˵��ϡ�\n"NOR, me);    
                }
        }else{
                message_vision(HIG"\n��ˮ������$N��"NOR + weapon->name() + 
                                HIG"�ϣ����������Ƶ����˽�ȥ���� \n"NOR, me);
                if(weapon->query("weapon_prop")) {
                        prop="weapon_prop/";
                }
                if(weapon->query("equipped") == "wielded") {
                        weapon->unequip();
                }
                weapon->add(prop+"strength", 3);
                weapon->add(prop+"damage", 10);
                weapon->add("base_damage", 10);
                weapon->save();
                me->set("imbue/tianfeng", 1);
                return;
        }
        me->set("imbue/tianfeng", 2);
        return;
} 
void init()
{       object ob;
        ::init();
        add_action("do_answer","answer");
        add_action("do_accept", "accept");
        add_action("do_killing", "kill");
        if( interactive(ob = this_player()) && !is_fighting() ) 
        if (ob->query("���_quest6"))
        {
                remove_call_out("recruiting");
                call_out("recruiting", 1, ob);
        } 
}  
void recruiting(object ob)
{
        if(ob->query("���_quest6")=="ʧ��")
        {
                message_vision(HIR"���ʮ������ȻһЦ���³�����Ѫ�����ض�����\n"NOR,ob);
                ob->delete("���_quest6");
                this_object()->die();
                return;
        }
        if(ob->query("���_quest6")=="�ɹ�"&& !ob->query("tianfeng/done_quest"))
        {
                tell_object(ob,WHT"���ʮ��������������˫�ۣ�΢΢Ц�����ã��ã��㲻�����������ߡ�\n"NOR);
                tell_object(ob,WHT"�����ж�������ڵ�Ϧ�����ⷬ��ԭ֮����Ը���ˣ�ȴҲ�޺���\n"NOR);
                tell_object(ob,WHT"���м��Ŵ�������书,��������ѧ.\n"NOR);
                tell_object(ob,WHT"��ĬƬ�����ʮ�����ֵ���������Ե���ҿɴ���һ�ŷ�ɣ�书�����Ը�⣿��accept yes or no��\n"NOR);
                ob->set_temp("tianfeng/a_sk1",1);
                return;
        }
}  
int do_accept(string arg)
{
    if(!this_player()->query_temp("tianfeng/a_sk1")) return 0;
    if( arg == "no" )
    {
        message_vision(HIB"\n$N��ԥ��һ�£�ҡ��ҡͷ������������ʦ�У���������ѧ�ա�\n"NOR, this_player());
        message_vision(WHT"���ʮ����̾�˿���,��"+RANK_D->query_respect(this_player())+"־����ҿɼ�.", this_player());
        message_vision(WHT"��ϧ��һ�����޴��ˡ�����\n"+HIG"���λ��ǵ���ˮ�����ʮ���������Ϲ���������\n"NOR, this_player());
        this_player()->set("tianfeng/done_quest","2");
        if(!this_player()->query("imbue/tianfeng")){
              imbue_event(this_player());
        }
        return 1;
    }
    else if( arg == "yes" )
    {
        message_vision(CYN "\n$N����һҾ����ǰ��ָ��," + RANK_D->query_self(this_player()) + "�������棡\n\n"NOR, this_player());
        tell_object(this_player(),WHT"���ʮ���ɵ�:�����⼸���书,�������ѡһ��....\n"NOR,this_object());
        if (this_player()->query("gender")=="Ů��") {
                tell_object(this_player(),HIG"½��Բ����ȭ��(enmeiryu),  �޿�����(ghosty-force),  ̫��ò�(ghosty-steps),
                һ��������(ittouryu),  ����(ninjitsu).\n"NOR+HIY"��choose �书��\n"NOR);
                }
                else
                tell_object(this_player(),HIG"½��Բ����ȭ��(enmeiryu),  һ��������(ittouryu),  �޿�����(ghosty-force),  ����(ninjitsu).\n"NOR+HIY"��choose �书��\n"NOR);
        this_player()->set_temp("tianfeng/a_sk2",1);
        add_action("do_choose", "choose");
        return 1;
     }
    else  return 0;
}  
int do_choose(string arg)
{
    if(!this_player()->query_temp("tianfeng/a_sk2")) return 0;
    if( this_player()->query("tianfeng/done_quest")) return 0;
    if( arg == "½��Բ����ȭ��"|| arg== "enmeiryu" )
    {
        this_player()->set("tianfeng/done_quest",1);
        this_player()->set("tianfeng/enmeiryu",1);
        tell_object(this_player(),WHT"���ʮ���ɵ��˵�ͷ˵:��,½��Բ������һ������һ���Ҷ���������������һ�����֣�ȭ��˲Ϣ���,����ַ���ʤ��.��ú�����.\n"NOR);
        tell_object(this_player(),WHT"����,��ɣ�书ֻ����Ե֮��,��ʹ�Ƿ�������Ҳ������,�м�!\n"NOR);
//      remove_action("do_choose", "choose");
        return 1;
    }
    if( (arg == "�޿�����"|| arg== "ghosty-force"))
    {
        this_player()->set("tianfeng/done_quest",1);
        this_player()->set("tianfeng/ghosty-force",1);
        tell_object(this_player(),BLU"���ʮ����̾�˿���,���޿�����....��ú�����.\n"NOR);
        tell_object(this_player(),WHT"����,��ɣ�书ֻ����Ե֮��,��ʹ�Ƿ�������Ҳ������,�м�!\n"NOR);
//      remove_action("do_choose", "choose");
        return 1;
    }
    if( (arg == "̫��ò�"|| arg== "ghosty-steps") && this_player()->query("gender")=="Ů��")
    {
        this_player()->set("tianfeng/done_quest",1);
        this_player()->set("tianfeng/ghosty-steps",1);
        tell_object(this_player(),BLU"���ʮ����̾�˿���,��̫��ò�....��ú�����.\n"NOR);
        tell_object(this_player(),"WHT����,��ɣ�书ֻ����Ե֮��,��ʹ�Ƿ�������Ҳ������,�м�!\n"NOR);
//      remove_action("do_choose", "choose");
        return 1;
    }
    if( arg == "һ��������"|| arg== "ittouryu" )
    {
        this_player()->set("tianfeng/done_quest",1);
        this_player()->set("tianfeng/ittouryu",1);
        tell_object(this_player(),WHT"���ʮ���ɵ��˵�ͷ˵:�˵��������һ������,����֮ʱ,�������֮��,������Σ�ڶ���....��ú�����.\n"NOR);
        tell_object(this_player(),WHT"����,��ɣ�书ֻ����Ե֮��,��ʹ�Ƿ�������Ҳ������,�м�!\n"NOR);
//      remove_action("do_choose", "choose");
        return 1;
    }
    if( arg == "����"|| arg== "ninjitsu")
    {
        this_player()->set("tianfeng/done_quest",1);
        this_player()->set("tianfeng/ninjitsu",1);
        tell_object(this_player(),WHT"���ʮ���ɵ��˵�ͷ˵:��������ʿ��������....��ú�����.\n"NOR);
        tell_object(this_player(),WHT"����,��ɣ�书ֻ����Ե֮��,��ʹ�Ƿ�������Ҳ������,�м�!\n"NOR);
//      remove_action("do_choose", "choose");
        return 1;
    }
    return 0;
} 
int recognize_apprentice(object ob)
{
    if(ob->query("tianfeng/done_quest"))  return 1;
        return 0;
}  
smart_fight()
{
        int i;
        object *enemy;
        enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        if (enemy[i]->query_temp("weapon")&& !random(5))
                        {
                                command("wield all");
                                this_object()->smart_busy();
                        } else 
                        {       if (this_object()->query_temp("weapon"))
                                        command("say ��,�Ҳ��ñ���!");
                                command("unwield all");
                                this_object()->smart_attack();
                        } 
                }
        }
} 
smart_busy() {
        this_object()->perform_action("blade.gobankiri");
}
smart_attack() {
        this_object()->perform_action("unarmed.shiden");        
}  
int do_killing(string arg)
{
    object player, victim;
    string id,id_class;
    player = this_player();
    if(!arg || arg == "") return 0;
    victim = present(arg, environment(player));
    if(!objectp(victim))
                return notify_fail("����û������ˡ�\n");
    if(living(victim))
    {
        if(victim->query("id")=="tianfeng")
        {
            this_object()->remove_all_enemy();
            command ("say �ã���ɱ��!");
            return 0;
        } 
    }
    return 0;
}      
