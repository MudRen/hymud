// xiazi.c
// by dicky

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("�����", ({ "e heshang","heshang"}) );
	
	set("gender", "����" );
	set("age", 40);
	set("long", "���������ɷ�ĺ��У�������һ���˰̣�������һֱ���쵽��͵���ߡ�\n");

	set("combat_exp", 100000);
	set("str", 30);
	set("max_qi",2000);
	set("qi",2000);
	set("max_jing",2000);
	set("jing",2000);
	set("max_sen",2000);
	set("sen",2000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("mana", 2000);
	set("max_mana", 2000);
	set("force_factor", 30);
	set("chat_chance_combat",20);
	set("chat_msg_combat",({
		(: perform_action, "staff.xiangmo" :),
	}));

	set_skill("unarmed",100);
	set_skill("dodge",100);
	set_skill("parry",100);
	set_skill("force",100);
	set_skill("club",100);
	set_skill("iron-cloth",100);
	
	set_skill("yiqiforce",100);
	set_skill("lingboweibu",100);
	set_skill("luohan-quan",100);
	set_skill("weituo-chu",300);

	map_skill("force","yiqiforce");
	map_skill("dodge","lingboweibu");
	map_skill("unarmed","luohan-quan");
	map_skill("club","weituo-chu");
	setup();
	carry_object("/clone/weapon/club")->wield();
	carry_object(__DIR__"obj/jiasha")->wear();
}


void init()
{
	object ob = this_player();
	
	::init();

	if (interactive(ob))
	{
		command("say �󵨿�ͽ�������ƻ�����ү�ĺ���������\n\n");
		command("say ������·�㲻�ߣ�����������ƫ��������\n\n");
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob); 
		ob->delete_temp("ganjiang/heshang",1);
	}       
}
