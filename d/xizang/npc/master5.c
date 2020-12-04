 inherit NPC;
inherit F_MASTER;
#include <ansi.h> 

int leave(); 
void create()
{
set_name(YEL"����"NOR, ({ "master gelun", "master","gelun" }) );
	set("gender", "����" );
	set("age", 99);
	set("int", 30);
	set("dex", 99);
	set("str", 90);
        set("apprentice_available", 20);

	set("long",
		"���׸�ɮ���ڴ��������ֶ��ꡣ��Ů���ӱ鲼���⡣\n"
		);
	set("inquiry", ([
		"������": "��....������.....���������\n",
		"����": "�����ڴ����µ�ľ���",
	]) );
	        create_family("������", 20, "����");
    set("rank_nogen",1);
    set("ranks",({"����","�޺�","��ɮ","��ʦ","ʥɮ",YEL"����"NOR,YEL"���"NOR,HIY"����"NOR}));
        set("combat_exp", 9000000);
        set("score", 90000);
         set("max_neili", 93500);
        set("neili", 93500);
        set("force_factor", 30);
	set("max_qi",92999);
        set("max_jing",92999);
	set("eff_qi",92999);
	set("qi",92999);
	set("eff_jing",92999);
	set("jing",92999);
       set_skill("unarmed", 50);
	set_skill("staff", 300);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("literate", 80);
	set_skill("iron-cloth", 150);

	set_skill("bloodystrike", 500);
	set_skill("cloudstaff", 500);
	set_skill("bolomiduo", 500);
	set_skill("buddhism", 500);
        set_skill("jin-gang", 550);


	map_skill("unarmed", "bloodystrike");
        map_skill("force", "bolomiduo");
        map_skill("literate", "buddhism");
        map_skill("iron-cloth", "jin-gang");
        map_skill("staff", "cloudstaff");
        map_skill("parry", "cloudstaff");
        set("agi",25);
        set("int",30);
        set("chat_chance", 5);
        set("chat_msg", ({
                (: random_move :),
        }) );
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "staff.siqijinlong" :),
                (: perform_action, "staff.longxianyuye" :),
        }) );
set("pubmaster",1);
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 5500);
        set_temp("apply/damage", 5600);              
        setup();
        carry_object(__DIR__"obj/redcloth")->wear();
        carry_object(__DIR__"obj/9staff")->wield();
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
