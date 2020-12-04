// dog.c

inherit NPC;



void create()
{
	set_name("����Ȯ", ({ "lang quan","dog","quan" }) );
	set("race", "Ұ��");
	set("age", 3);
	set("long", "һֻ�׶�Ĵ���Ȯ���������ﲻʱ�������µĵͺ�����\n");
	
	set("str", 100);
	set("cor", 100);
	set("max_qi",1400);
	set("qi",1400);
	set("max_jing",1300);
	set("jing",1300);

	set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
	set("verbs", ({ "bite", "claw" }) );
	
	set("combat_exp", 100000);

	set_temp("apply/attack", 15);
	set_temp("apply/damage", 6);
	set_temp("apply/armor", 2);
	setup();
}


void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) &&
		random(ob->query_kar() + ob->query_per()) < 30) {
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, ob); 
	}	
}
