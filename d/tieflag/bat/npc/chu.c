#include <ansi.h>
#include <combat.h>
inherit NPC;
inherit F_MASTER;
int direct();
void consider(); 
void create()
{
    set_name("������", ({"master chu", "chu","master" }));
    set("nickname", HIY "�������"NOR );
    set("gender", "����");
    set("age", 32);
    set("long",
        "
��˫ü���泤�������������������������˫�峺�����磬ȴ�����������ݡ�������
ֱͦ��������ǿ�����ϵ���ʯ�ĳ������Ǳ����ģ�������̵��죬����Ҳ��Щ��ᣬ��
ֻҪ��һЦ��������ǿ�ͱ������ᣬ���Ҳ����ͬ�飬��������ů�Ĵ��紵���˴�ء�
");
    set("attitude","friendly");
    create_family("����˧", 1, "����");
    set("student_title","����");
    set("title","��˧");
    set("reward_npc", 1);
    set("difficulty", 10);
    set("int", 40);
    set("pubmaster",1);
    set("con", 26);
    set("agi", 50);
    set("skill_public",1);
    set("per", 40);
    set("chat_chance_combat", 30);
    set("chat_msg_combat", ({
        (: perform_action, "unarmed.luori" :),
            }) );       
    
    set("chat_chance", 1);
    set("chat_msg", ({
"�������������ǰ������÷��ʦһ�Σ��Ǵ��������ض�����ȥ�λ�ɽʱԶԶ�ƹ���һ�ۡ� \n",
    }));
    set("inquiry", ([
        "����"   :  (: direct :),
        "bat island" : (: direct :),
        "batisland" : (: direct :),
        "bian fu dao" : (: direct :),
        "bianfudao" : (: direct :),
        ]));  
    set("neili", 37000);
    set("max_neili", 37000);
    set("force_factor", 50); 
    set("combat_exp", 4000000);
    set("score", 50000); 
    set_skill("force", 120);
    set_skill("bibo-force", 100);
    set_skill("blade", 220);
    set_skill("wind-blade", 520);
    set_skill("unarmed", 150);
    set_skill("dodge", 150);
    set_skill("luoriquan", 220);
    set_skill("dodge", 320);
    set_skill("fengyu-piaoxiang", 320);
    set_skill("parry", 120);
    set_skill("literate",180);
    set_skill("stealing",320);
    
    map_skill("blade"  , "wind-blade");
    map_skill("force"  , "bibo-force");
    map_skill("unarmed", "luoriquan");
    map_skill("dodge"  , "fengyu-piaoxiang");
    map_skill("dodge"  , "fengyu-piaoxiang");
    set_skill("force", 150);
        set_skill("unarmed", 120);
        set_skill("parry", 150);
        set_skill("dodge", 320);
        set_skill("dodge", 320);
        set_skill("literate", 150);

        set_skill("bibo-force", 550);
        set_skill("luoriquan", 500);
        set_skill("fengyu-piaoxiang", 520);
        set_skill("stealing",500);

        map_skill("force", "bibo-force");
        map_skill("unarmed", "luoriquan");
        map_skill("dodge", "fengyu-piaoxiang");
        map_skill("dodge", "fengyu-piaoxiang");
    setup();
    carry_object(__DIR__"obj/cloth_whitesilk")->wear();
}  
void attempt_apprentice(object ob)
{
    if(!ob->query_temp("marks/murderhu"))
    {
        say("������˵����Ϊ��ʦ���ǲ��ҵ��ģ��������ˣ�\n");
        say("����������(qiecuo)һ�£��������������Ƿ�����˵��ң�\n");
    } else {
        say("������ȵ�����ɱ������õ����Ѻ󻹸������ң�\n");
        kill_ob(ob);
        ob->kill_ob(this_object());
    }
}  
int direct()
{
    object me;
    object room;
    
    me = this_player();
    
    if (this_object()->is_fighting(me)) {
        tell_object(me,"������˵�����𵺣���������û�����ż����ˣ�\n");
        return 1;
    }
    
    if (this_object()->is_fighting(me)) {
        tell_object(me,"������˵�����𵺣��㻹���Ȱ�����ĵ��˴��˰ɡ�\n");
        return 1;
    }
    
    message_vision("������ͻȻ���зų������Ĺ�â���૵���
���𵺣�Ŷ�����������ˣ�������������������Ҫȥ�ǰ�һ����Ҫ�������飬
�������Ҳ����Ȥ������ȥ����֮�����š�\n\n",this_object(),me);
    message_vision(
"$N��������һ������ʱ���˼������Ȥ���Ͻ���������ȥ.....\n",me);
    room = load_object("/d/tieflag/bat/bfd1");
    me->move(room);
    return 1;
} 
void die()
{
    object killer;
    if(objectp(killer = query_temp("last_damage_from")))
        killer->set("marks/ɱ������", 1);
    ::die();
} 
void init()
{
        ::init();       
    add_action("do_look", "look");
    add_action("do_qiecuo","qiecuo");
    add_action("do_killing", "kill");
} 
int do_look(string arg)
{
    object me;
    me = this_player();
    
    if( (string)me->query("gender") == "Ů��" && 
        ( arg == "master" || arg == "master chu" || arg == "chu"))
    {
        message_vision("$Nһ�ŷ�����������ķɿ죮������\n"NOR, me);
        me->unconcious();
        return 1;
    }
    else return 0;
} 
int do_killing(string arg)
{
    object player, victim;
    string id;
    int sen; 
    player = this_player();
    if(!arg || arg == "") return 0;
    victim = present(arg, environment(player));
    if(!objectp(victim))
                return notify_fail("����û������ˡ�\n");
    if(living(victim))
    {
        id= victim->query("id");
        if( id == "li hongxiu")
        {
            message_vision(
"$N���������İ��Ĵ���ɱ���İ���Ů�ˣ��⣬��Ҳ̫�����˰ɣ�\n", this_object());
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            return 0;
        }
    }
    return 0;
} 
int heal_up()
{
    int mgin,mkee,msen;
    mgin=(int)query("max_jing");
    mkee=(int)query("max_qi");
    msen=(int)query("max_jing");
    set("eff_qi",mkee);
    set("eff_gin",mgin);
    set("eff_sen",msen);
    set("jing",mgin);
    set("qi",mkee);
    set("jing",msen);
    ::heal_up();
    return 1;
} 
int recognize_apprentice(object ob)
{
	if (ob->query_temp("learn_timeb"))
{
   	if( ob->query_temp("learn_timeb") <= 0) return 0;
else         
ob->add_temp("learn_timeb",-1);
return 1;
}
        if (ob->query("marks/master_chu_food")+ 1800 < time() && (int)ob->query("marks/master_chu")+ 600  < time()) 
        {
        if (ob->query("marks/master_chu_food")+ 1800 < time()) 
        {
        message_vision("�������������ӣ���$N��Ц������ĳ��������ø�ȥ���𵺣�����Ժ���Ե�Ļ�
�����ٻ����д��д�ɡ�\n",ob);
        command("grin "+ob->query("id"));
        return 0;
        }  
        if( (int)ob->query("marks/master_chu")+ 1800  < time())
        {
        say("������˵�����������ѧ�˲����ˣ�������������(qiecuo)һ�°ɣ�\n");
        return 0;
        }
   }    
    return 1;
} 
int do_qiecuo(string arg)
{
    object me;
    int sen;
    me = this_player();
    if (this_object()->is_fighting() || this_object()->is_busy())
        return notify_fail("����������æ���أ�û�պ������裡\n"); 
    if((int)me->query("marks/failed_chu") + 86400 > time())
    {
        say("\������˵�����㲻��ǰ������ң��������ٱȰɣ�\n");
        return 1;
    }
    delete_temp("last_damage_from");
    heal_up();
    sen = (int) me->query("jing")/10;
    me->set("jing", sen);
    COMBAT_D->do_attack(me,this_object(),me->query_temp("weapon"),
                        TYPE_REGULAR);
    if(query_temp("last_damage_from") == me)
    {
        say("\n������˵������Ĺ����治���ӽ��Ժ����Ǿ��໥ѧϰ�ɣ�\n");
        me->set("marks/master_chu",time());
        return 1;
    }
    say("\n������Ц��������һ�У�������\n");
    COMBAT_D->do_attack(me,this_object(),me->query_temp("weapon"),
                        TYPE_REGULAR);
    if(query_temp("last_damage_from") == me)
    {
        say("\n������˵������Ĺ����治���ӽ��Ժ����Ǿ��໥ѧϰ�ɣ�\n");
        me->set("marks/master_chu",time());
        return 1;
    }
    say("\n������Ц�����������У�������\n");
    COMBAT_D->do_attack(me,this_object(),me->query_temp("weapon"),
                        TYPE_REGULAR);
    if(query_temp("last_damage_from") == me)
    {
        say("\n������˵������Ĺ����治���ӽ��Ժ����Ǿ��໥ѧϰ�ɣ�\n");
        me->set("marks/master_chu",time());
        return 1;
    }
    say("\n������Ц�������������ѹ�����������Щ�����ɣ�\n");
    me->set("marks/failed_chu",time());
    return 1;
} 
int accept_object(object me, object ob)
{
        object food,who;
        	int i;
who=me;
	if (!(int)who->query_temp("learn_timeb"))      
		who->set_temp("learn_timeb", 0);

	

if (ob->query("money_id") )
{
	if(who->query_skill("unarmed",1)<30)
		i=ob->value() / 50;
	else
	{
		if(who->query_skill("unarmed",1)<60)
			i=ob->value() / 100;
		else
		{
			if(who->query_skill("unarmed",1)<100)
				i=ob->value() / 100;
			else
				i=ob->value() / 100;
		}
	}
	who->add_temp("learn_timeb",i);
command("say ��Ȼ�������ѧ�ҵ��书���Ҿͳ�ȫ��ȫ��ɡ�");
	return 1;
}	
        if(ob->query("id")!="bamboo basket") return 0;
        food=present("food",ob);
        if(!food) return 0;
        if(food->query("name")!= RED"б���д������"NOR) return 0;
        if(!me->query_temp("song_food_carrier"))
        {
                message_vision("������˵������лл��ĺ��⣬����ֻ���������˴����ҵġ�б���д�����С�����\n", me);
                return 0;
        }
        if (me->query("combat_exp")<2500000)    
        {message_vision("������˵������лл��ĺ��⣬�����д����֣���ϧ���¸����в���ʵ�������ʺ�ѧ�ҵ��书����\n",me);
        message_vision("������˵�������޹�������»����ϧ�������ζ����\n",me);
        return 0;
        }
        else {
        message_vision("������һ��������Ц���������Ѿͷ�����ã��ã�������ѧ���к����ʲ��� 
�����д�һ����\n\n",me);
        me->set("marks/master_chu_food",time());
        return 1;
        }
}
        


