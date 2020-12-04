// dog.c

inherit NPC;

void create()
{
	set_name("ƽ�ܽ���", ({"dog"}));
	set("race", "Ұ��");
	set("age", 4);
	set("long", "һֻ����ͦ�أ����ų���ͷ�Ĵ�񹷡�\n");
	set("attitude", "peaceful");
	
	set("str", 36);
	set("cor", 30);
	set("dex", 30);
       set("max_qi", 5500);
	set("max_jing", 5220);
	set("neili", 5000);
	set("max_neili", 5000);
	
	set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("combat_exp", 1000);
	
	set_temp("apply/attack", 115);
	set_temp("apply/defense", 115);
	set_temp("apply/damage", 516);
	set_temp("apply/armor", 512);

	setup();
}

void init()
{
	object ob;

	::init();
	if (living(this_object()) && interactive(ob = this_player()) &&
		random(ob->query_kar() + ob->query_per()) < 24) {
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, ob); 
	}	
}

void die()
{
	message_vision("$N�Һ�һ�������ˣ�\n", this_object());
	new("/clone/armor/goupi")->move(environment());
	destruct(this_object());
}
