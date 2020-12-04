// wolfdog.c

inherit NPC;

void create()
{
	set_name("���ǹ�", ({ "wolf dog", "dog" }) );
	set("race", "Ұ��");
	set("age", 4);
	set("long", "һֻ����ͦ�أ����ų���ͷ�Ĵ��ǹ������ǲ����������ĳ��\n");
	set("attitude", "peaceful");
	
	set("str", 88);
	set("dex", 88);
	set("cor", 30);
  set("max_qi",3000);
  set("max_jing",3000);
  set("max_neili",3000);
	set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("combat_exp", 1000000);
//	set("shen_type", -1);

//	set("chat_chance", 6);
//	set("chat_msg", ({
//		(: this_object(), "random_move" :),
//	}) );
	
	set("chat_msg_combat", ({
		(: this_object(), "random_move" :),
		"���ǹ������ͽУ�������������������������\n",
		"���ǹ�ͻȻ����������������ҧ��ȴ��֪������ҧ˭��\n"
	}) );
		
	set_temp("apply/defense", 115);
	set_temp("apply/attack", 115);
	set_temp("apply/damage", 116);
	set_temp("apply/armor", 512);

	setup();
}

void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) &&
		random(ob->query_kar() + ob->query_per()) < 30) {
			remove_call_out("kill_ob");
			call_out("kill_ob", 0, ob); 
	}	
}
