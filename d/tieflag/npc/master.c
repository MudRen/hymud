 inherit NPC;
inherit F_MASTER;
void create()
{
    set_name("������", ({ "master tie", "master","tie" }) );
    set("gender", "����" );
    set("age", 26);
    set("int", 30);
    set("cps",50);
    set("per", 15);
    set("agi",35);
    set("cor",40);
    set("pubmaster",1);
    set("apprentice_available", 50);
    create_family("��Ѫ������", 8, "����");
    set("rank_nogen",1);
    set("ranks",({"����","С��","����","����","����","����","Ԫ��","������"})); 
    set("long","����������Ѫ�����ŵĴ��ˡ�\n" ); 
    set("no_busy",10); 
    set("max_neili", 1000);
    set("neili", 1000);
    set("force_factor",60); 
        set("resistance/kee",20);
        set("resistance/sen",60);
        set("resistance/gin",90); 
    set("reward_npc", 1);
    set("difficulty", 15);
    set("attitude", "peaceful");
    
    set("combat_exp", 4800000);
    set("score", random(90000));
    
        
     set("max_neili", 95000);
        set("neili", 95000);
        set("force_factor", 30);
	set("max_qi",99999);
        set("max_jing",99999);
	set("eff_qi",99999);
	set("qi",99999);
	set("eff_jing",99999);
	set("jing",99999);
        set("attitude", "peaceful");
        set("combat_exp", 9999999);
        set("score", 90000);
//        set_skill("dormancy",150);
        set_skill("unarmed", 200);
        set_skill("sword", 100);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("literate", 100);
		set_skill("dodge", 100);
		set_skill("ill-quan", 550);
		set_skill("fy-sword", 500);
		set_skill("cloudsforce", 500);
		set_skill("tie-steps", 550);
    	
		map_skill("unarmed", "ill-quan");
        map_skill("sword", "fy-sword");
        map_skill("force", "cloudsforce");
        map_skill("parry", "fy-sword");
        map_skill("dodge", "tie-steps");


        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
(: perform_action, "sword.fengqiyunyong" :),
                (: perform_action, "unarmed.qiankun" :),
                (: perform_action, "dodge.chansi" :),
        }) );
                set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 600);
    setup();
    carry_object(__DIR__"obj/longsword")->wield();
    carry_object("/clone/misc/cloth")->wear();
}

int recognize_apprentice(object ob)
{
	if( ob->query_temp("learn_timeb") <= 0) return 0;
else         
ob->add_temp("learn_timeb",-1);
return 1;
}

int accept_object(object me, object obj)
{
		int i;
object who,ob;
who=me;
ob=obj;
	if (!(int)who->query_temp("learn_timeb"))      
		who->set_temp("learn_timeb", 0);

	if( ob->query("money_id") )
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
	
    if(obj->query("id")=="silk book" && me->query_temp("mark/silkbook"))
    {
        me->set_temp("mark/can_apprentice_master_tie",1);
        me->delete_temp("mark/silkbook");
        command("say ��⣬�����������\n");
        return 1;
    }
    if(obj->query("id")=="flag" && obj->query("fake"))
    {
        command("say �󵨣����Ķ�Ū��һ����������Ū�Ϸ�\n");
        kill_ob(me);
        return 1;
    }
    return 0;
}   
