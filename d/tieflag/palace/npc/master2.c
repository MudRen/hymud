 inherit NPC;
inherit F_MASTER;
#include <ansi.h>
#include <combat.h>
int testing(object me);
void check_answer(object me);
void check_accept(object me);
void create()
{
    set_name("���촸", ({ "master lan", "lan","master" }) );
    set("gender", "����" );
    set("nickname",HIB "��������" NOR);
    set("reward_npc", 1);
    set("difficulty", 2);
    set("age", 45);
    set("int", 30);
    set("str",60);
    set("per", 30);
    set("class","yinshi");
    set("apprentice_available", 50);
    create_family("�촸ɽׯ", 1, "ׯ��");
    set("rank_nogen",1);
    set("ranks",({"����","С��","����","����","����","����","��ʥ","����"})); 
    
    set("long",
        "���촸��һ�����õĳ����뻯������
ÿ�궼�͵�����������һս���½�ʤ�����֣� 
���촸��Ƣ�������һ𣬾�����Ե�޹ʵĽ����Ӵ�����˻����ǽ�ţ�\n"
        );
    set("force_factor", 60);
    set("max_atman", 300);
    set("atman", 300);
    set("max_neili", 1000);
    set("neili", 1000);
    set("max_mana", 300);
    set("mana", 300);
    set("skill_public",1);
    set("chat_chance", 1);
    set("chat_msg", ({
        "���촸Ц�����������϶����ֺ�������ʤ����\n",
            }) );
    set("combat_exp", 2000000);
         set("combat_exp", 99999999);
        set("score", 90000);
        set_skill("unarmed", 100);
        set_skill("hammer", 350);
        set_skill("force", 200);
        set_skill("parry", 100);
        set_skill("literate", 100);
	set_skill("dodge", 100);

	set_skill("pangu-hammer", 550);
	set_skill("pofeng-strike", 520);
	set_skill("putiforce", 550);
	set_skill("nodust-steps", 500);

	map_skill("unarmed", "pofeng-strike");
        map_skill("hammer", "pangu-hammer");
        map_skill("force", "putiforce");
        map_skill("parry", "pangu-hammer");
        map_skill("dodge", "nodust-steps");
	//set_skill("magic",100);
//	set_skill("qiankunwuxing",100);
//	map_skill("magic","qiankunwuxing");
        set("str",35);
        set("int",30);
set("pubmaster",1);
        set("max_neili", 95000);
        set("neili", 95000);
        set("force_factor", 30);
	set("max_qi",99999);
        set("max_jing",99999);
	set("eff_qi",99999);
	set("qi",99999);
	set("eff_jing",99999);
	set("jing",99999);
      set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.luanpofeng" :),
                (: perform_action, "hammer.kaitianpidi" :),
        }) );
	set_temp("apply/attack", 200);set_temp("apply/defense", 200);set_temp("apply/armor", 500);set_temp("apply/damage", 600);setup();

        set_temp("apply/defense", 200);
        set_temp("apply/armor", 2500);
        set_temp("apply/damage", 2200);
        set_temp("apply/attack", 200);

    setup();
    carry_object(__DIR__"obj/bluecloth")->wear();
    carry_object(__DIR__"obj/jumbohammer")->wield();
} 
void init()
{
        add_action("do_challenge","challenge");
        add_action("do_challenge","tiaozhan");
        add_action("do_answer","answer");
        ::init();
} 

void check_answer(object me)
{
        if (me)
        {
                me->delete_temp("answering_lan");
                if (present(me,environment()))
                {
                        message_vision("$N��$n���ͷ����������ɷ���һ˵һ���ж�˵��������������ʲô����\n",this_object(),me);
                        message_vision("$NŤ��ͷ������$n��\n",this_object(),me);
                } 
        }
} 
int do_answer(string arg)
{
        object me;
   me=this_player();
        
        if(!me->query_temp("answering_lan"))
                return 0;
        if (arg !="yes" && arg !="no")
        {
                return notify_fail("��ֻ�ɴ�yes/no");
        } 
        remove_call_out("check_answer");
        me->delete_temp("answering_lan");
        if (arg == "yes")
        {
                message_vision(HIW"$NЦ�ø������ˣ�������Ͱ���Ϊʦ�ɣ��ټ������϶����ҵúú���������
��ͽ�ܶ�£��ס�ˣ��� \n"NOR,this_object());
                  command("recruit " + me->query("id") ); 
                  me->add("betrayer",-1);

//                me->set_temp("despite_xiao",1);
        }
        if (arg == "no")
        {
                message_vision( HIW"$N˫Ŀ��������$n�������϶���ͽ��Ҳ����ݹ������š����� 
�����Լս(challenge)��ʦ�����Ҿͽ������֣���(accept yes/no) \n"NOR,this_object(),me );
                add_action("do_accept","accept");
                me->set_temp("accepting_lan",1);
                call_out("check_accept",40,me);
        }
        return 1;
} 
void check_accept(object me)
{
        if (me)
        {
                delete_temp("accepting_lan");
                if (present(me,environment()))
                {
                        message_vision("$N��$n�ӻ��֣���������Ը������ˡ���\n",this_object(),me);
                }
        }
} 
int do_accept(string arg)
{
        object me;
   me = this_player();
        if(!me->query_temp("accepting_lan"))
                return 0;
        if (arg !="yes" && arg !="no")
        {
                return notify_fail("��ֻ�ɽ���yes/no");
        }
        remove_call_out("check_accept");
        me->delete_temp("accepting_lan");
        if (arg == "yes")
        {
                message_vision(HIW"$N���ͷ��˵�������ã��Ҿ������������ \n"NOR,this_object());
                me->set("marks/challenge_xiao_forlan",1);
        }
        if (arg == "no")
        {
                message_vision(HIW"$N��ɫ��������Ϊʦ֮��������������ɽҰ����ս�������������ܴ�Ӧ����\n"NOR,me);
        }
        return 1;
}  

int do_challenge(string arg)
{
        object me;
        me = this_player(); 
        if (arg != "master" && arg != "master lan" && arg != "���촸" && arg != "lan")
        {
                return 0;
        }
        if (!me->query("marks/challenge_lan") || (string) me->query("class") != "yinshi")
        {
                message_vision(HIW"$N��мһ�˶�$n˵����������ʲô������Ҫ�Ϸ���֣��� \n"NOR,this_object(),me);
                return 1;
        }
        message_vision(HIG"$n��$N��������"+RANK_D->query_self(me) + me->name() + "Ը��ʦ��ս��\n"NOR,this_object(),me);
   if((int)me->query("marks/failed_lan") + 10800 > time())
    {
        say(HIW"\���촸˵�����㲻��ǰ������ң��������ٱȰɣ�\n"NOR);
        return 1;
    }
        if (!me->query("marks/fight_lan"))
        {
                message_vision(HIW"$N����Ķ�$n˵��������ô���㡣����Ҳ�ã����аɣ��� \n"NOR,this_object(),me);
        }else
        {
                message_vision(HIW"$N��$n���һ�������õģ��е����� \n"NOR,this_object(),me);
        }
        testing(me);    
        return 1;       
}  
int testing(object me)
{
        object weapon,skl;
    if (this_object()->is_fighting() || this_object()->is_busy())
        command("say ��������æ���Ȼ�ɡ�����"); 
    me->set("marks/fight_lan",1);
        delete_temp("last_damage_from");
    heal_up();
        weapon =me->query_temp("weapon");   
        COMBAT_D->do_attack(me,this_object(),me->query_temp("weapon"));
        say(HIR"\n��������˵������һ�У�������\n"NOR);
    if(query_temp("last_damage_from") == me)
    {
                if(!weapon ||weapon->query("skill_type")!="whip"||me->query_skill_mapped("whip")!="thunderwhip")
                {
                        say("\n���������૵�����ԭ�������ϻ�����ô�������书�������� \n");
                        say("\n���������Ļ������̾�˿����� \n");
                }else
                {
                        message_vision(HIG"����������$N˵�����������ƹ�Ȼ�����贫�������ҵ��书ȴǡǡ�ܿ���������ѧ�Ļ����Ҿͽ��㡣��\n"NOR,me);
                me->set("marks/master_lan",1);
                        
                }
                return 1;
    }
   
   COMBAT_D->do_attack(me,this_object(),me->query_temp("weapon"));
        say(HIR"\n��������˵�����ڶ��У�������\n"NOR);
    if(query_temp("last_damage_from") == me)
    {
                if(!weapon ||weapon->query("skill_type")!="whip"||me->query_skill_mapped("whip")!="thunderwhip")
                {
                        say("\n���������૵�����ԭ�������ϻ�����ô�������书�������� \n");
                        say("\n���������Ļ������̾�˿����� \n");
                }else
                {
                        message_vision(HIG"����������$N˵�����������ƹ�Ȼ�����贫�������ҵ��书ȴǡǡ�ܿ���������ѧ�Ļ����Ҿͽ��㡣��\n"NOR,me);
                me->set("marks/master_lan",1);
                        
                }
                return 1;
    }  
COMBAT_D->do_attack(me,this_object(),me->query_temp("weapon"));
        say(HIR"\n��������˵���������У�������\n"NOR);
        if(query_temp("last_damage_from") == me)
    {
                if(!weapon ||weapon->query("skill_type")!="whip"||me->query_skill_mapped("whip")!="thunderwhip")
                {
                        say("\n���������૵�����ԭ�������ϻ�����ô�������书�������� \n");
                        say("\n���������Ļ������̾�˿����� \n");
                }else
                {
                        message_vision(HIG"����������$N˵�����������ƹ�Ȼ�����贫�������ҵ��书ȴǡǡ�ܿ���������ѧ�Ļ����Ҿͽ��㡣��\n"NOR,me);
                me->set("marks/master_lan",1);
                        
                }
                return 1;
    }
        me->set("marks/failed_lan",time());
        if(!weapon ||weapon->query("skill_type")!="whip"||me->query_skill_mapped("whip")!="thunderwhip")
        {
                say("\n��������ҡ��ҡͷ��˵����������ֻ��ֻ�������ƿ��Ժ��ҵĴ������⡣�� \n");                 
        }else
        {
                command("shake");
           command("say ����书̫���Ҫ�����ֿ���ˡ��������������ɡ�");
        }
        return 1;
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