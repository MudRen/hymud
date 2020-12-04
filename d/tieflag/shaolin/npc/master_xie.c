 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
    set_name("л����", ({ "master xie", "master", "xiexiaofeng" }) );
    set("nickname", HIG"��ʥ"NOR);
    set("gender", "����" );
        set("class","swordsman");
    set("reward_npc", 1);
    set("difficulty", 30); 
    set("age", 34);
    set("cor", 30);
    set("cps", 80);
    set("int", 30);
    set("per", 30);
    set("attitude","friendly");
    
    set("resistance/kee",90);
    set("resistance/sen",90);
    set("resistance/gin",90);
    
    set("max_neili", 5000);
    set("neili", 5000);
    set("force_factor", 200);
    set("max_mana",4000);
    set("mana",4000);
    
    set("long",
        "л��������ѧ��,ʮ���꽣��,ʮ����ܻ�����,һ�����ϸ�����ὣ��������˫
��������������,��������Ľ����ݶ����,����һ����ծ����\n");
    set("rank_nogen",1);
    create_family("��ɽׯ", 1, "ׯ��");
    set("ranks",({"��ū","����","��ʿ","����","����","����","��ʥ",BLU"����"NOR,
                      YEL"���"NOR,HIC"��ɷ"NOR,HIW"����"NOR,HIR"����"NOR}));
    set("rank_levels",({ 32000,64000,128000,256000,512000,
                             1024000,1536000,2304000,3456000,
                             5187000,26244000 }));     
    set("combat_exp", 10000000);
    set("score", random(200000)); 
   set("max_qi", 152000);
	set("max_jing", 151000);
	set("neili", 153000);
	set("max_neili", 153000);
	set("jiali", 100);
	set("combat_exp", 8800000);
	set("score", 500000);
set("pubmaster",1);
	  set("combat_exp", 80000000);
        set("score", 200000);
        set_skill("parry", 100);
        set_skill("dodge", 120);
        set_skill("force", 100);
        set_skill("literate", 100);
	set_skill("sword",530);
	set_skill("softsword",550);
        set_skill("cloudforce",520);
        set_skill("shadowsteps",520);
	map_skill("force", "cloudforce");
	map_skill("parry","softsword");
        map_skill("sword","softsword");
        map_skill("dodge","shadowsteps");
        map_skill("dodge","shadowsteps"); 
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 600);      
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.bajian" :),
                (: perform_action, "sword.yixiao" :),
                (: perform_action, "dodge.lianhuanjiao" :),
        }) );
    setup();
    carry_object(__DIR__"obj/qingcloth")->wear();
    carry_object(__DIR__"obj/xiesword")->wield();
} 
void init()
{
        object me;
        ::init();
        add_action("do_killing", "kill");
        if((random(20) == 6) && interactive(me = this_player()))
   {
                if(  !me->is_fighting() && userp(me) && me->query("marks/����_��_����֮��") && !me->query("marks/����_��_л����"))
                {
                        if (me->query("marks/yan13xieaction"))
                        {
                                remove_call_out("actthree");
                                call_out("actthree",4,me);
                        }else
                        {
                                remove_call_out("fight_yan13");
                                call_out("fight_yan13",2,me);
                        }
                        add_action("do_answer","answer");
                }
        } 
}
void fight_yan13(object me)
{
        object yan13;
        if (objectp(me) && present(me,environment(this_object())))
        {
                if (!yan13 = present("yan13",environment(this_object())))
                {
                        if (!yan13 = find_living("yan13"))
                                yan13 = new(__DIR__"yan13");    
                        yan13->set("marks/inaction",1);
                        yan13->move(environment());
                        message_vision("$N������������\n\n",yan13);
                        message_vision(HIR"Ϧ������Ѫ������Ҳ����Ѫ����ؼ������ɱ����\n"NOR,this_object());
                        message_vision("$N��춳���̾Ϣ����������ʮ����Ȼ��������ʮ�����벻��������������ˡ���\n\n",this_object());
                        message_vision(HIC"û�����ܿ��ü����ǰν��Ķ��������ǵĽ���Ȼ����Ѿ����������� \n\n�����ݺᣬ������Ҷ���衣\n\n"NOR,this_object());
                        message_vision(HIW"$N�����Լ�����Ľ��棬�۾��ݷ��л�����ȼ�գ����ݷ��к��������ᡣ \n"NOR,yan13);
                        message_vision(HIW"����������Ҷ����Ȼȫ��ɢ�ˣ������ڶ��ģ���Ȼȫ����ֹ�� \n\n"NOR,this_object());
                        me->set("marks/yan13xieaction",1);
                        call_out("acttwo",3,me,yan13);
                }
        }
} 
void acttwo(object me,object yan13)
{
   
        message_vision(RED"$N���Ϻ�Ȼ¶���ֿ־�֮���ı��顣 \n\n"NOR,this_object());
        message_vision(HIR"$N���۾����ȻҲ¶���ֿ־�֮���ı��飬����Զ��л������־塣 
Ȼ�������������κ��˶��벻�����κ��˶��޷�������¡�����Ȼ��ת�˽��棬 
��������Լ����ʺ� \n"NOR,yan13);
         yan13->die();
         if (objectp(me) && present(me,environment(this_object())))
         {
                 call_out("actthree",4,me);
         }
}
void actthree(object me)
{
         if (objectp(me) && present(me,environment(this_object())))
         {
                message_vision( "$N��Ҳ������վ��������ã�����$n�ʵ�������Ϊʲ��Ҫ�������£��� (answer) \n ",this_object(),me);
                me->set_temp("xieask",1);
         }
}
int do_answer(string arg)
{
        object me;
        me = this_player();
        if (!me->query_temp("xieask"))
        {
                return 0;
        }
        me->delete_temp("xieask");
        if (arg == "�����ƶ���" || arg == "����")
        {
                message_vision("$Nƣ��ʧ����۾����Ȼ���˹⣬��Ȼ�����³������૵�:���������ˣ��������ˡ�����\n\n",this_object());
                if (!me->query("marks/�����ƶ���"))
                {
                        me->set("marks/�����ƶ���",1);
                        me->add("combat_exp",10000);
                        me->add("potential",2000);
                        me->add("score",400);
                        tell_object(me,"�㱻�����ˣ�\n ��ǧ��ʵս����\n�İٵ�Ǳ��\n�İٵ��ۺ�����\n\n");
                } 
        }else
   {
                command("shake");
        }
       message_vision("$N��Ȼ��������Ϊ�����������⣬���Ѿ�������������Ϊһ�壬��Ϊ���� 
������������������˵ľ��⣬������Ҫ����������������һ��Ҫ�Ȱ��Լ����𡣡�\n",this_object());
         me->delete("marks/����_��_����֮��");
         me->set("marks/����_��_л����",1);
         return 1;
}
void attempt_apprentice(object me)
{       object book;
        if (me->query("marks/����_��ڳɹ�")) {
                command ("smile");
                command ( "say ��Ħ��ʦ�Ĵ��ˣ��ѵ����Ų�����ǿ��ʤ֮��ô��");
        }       
        else {
        if (me->query("class") == "shaolin" && me->query("marks/����_��_л����"))
        {
                command("smile");
                if (me->query("combat_exp")<2000000)
                        command("say ������츳��ֻ�ǻ�򲻹����úô���������������ҡ�\n");
                else    {
                
                        if ( (random(100)>15 
                                && !me->query("marks/����_��_��ʦ") 
                                && me->query("����B/����_����") 
                              ) 
                             || me->query("family/master_name") == "л����" ) {
                                command("recruit " + me->query("id") );
                                if (!me->query("marks/����_��_��ʦ")) me->add("betrayer", -1);                                
                                me->set("marks/����_��_��ʦ", 2);
                        } else {
                                if ( me->query("marks/����_��_��ʦ") ==1) 
                                        message_vision("$N̾�˿������Ļ������ض�$n˵����̰�ĵ�����ԶҲ���ᶮ��ʮ���Ľ�������\n", this_object() ,me);    
                                else {
                                        me->set("marks/����_��_��ʦ", 1);
                                // Get a book                              
                                        book = new(__DIR__"obj/yanbook" );
                                        book->move(me);
                                        message_vision("$N��Ȼȡ��һ��$n������Ϥ��÷֦��˵������ʮ�������ľ�����������һ���С�\n������Ե�ˣ������ú���ϰ����ɷ�����˽�����\n$N��÷֦����$n���С�\n", this_object(), me);
                           }
                                
                        }
                }
        }
        }
} 

void die()
{
    object yan13;
    if(yan13 = present("yan13",environment(this_object())))
        {
                message_vision("$Nһ�Բ����������뿪��\n",yan13);
                destruct(yan13);
        }
    ::die();
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
        id_class=victim->query("class");
        id=victim->query("id");
        if(id_class == "swordsman"&& userp(victim)&&player!=victim)
        {
            message_vision("$N����$n�ȵ���" + RANK_D->query_rude(player) 
                                                + "����ɱ" + RANK_D->query_self_rude(this_object()) 
                                                + "��ͽ�ܣ�ȥ���ɡ�\n", this_object(), player);
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            player->start_busy(2);
            return 0;
        } 
    }
    return 0;
}       
int accept_object(object who, object ob)
{
	int i;

	if (!(int)who->query_temp("learn_timeb"))      
		who->set_temp("learn_timeb", 0);

	if( !ob->query("money_id") )
		return 0;		


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

int recognize_apprentice(object ob)
{
	if( ob->query_temp("learn_timeb") <= 0) return 0;
else         
ob->add_temp("learn_timeb",-1);
return 1;
}
