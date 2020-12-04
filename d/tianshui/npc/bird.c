// bird.c
inherit NPC;

void create()
{
	set_name("С��", ({ "bird" }) );
        set("race", "Ұ��");
        set("age", 1);
        set("gender", "����");
        set("long", "һֻ�ɰ���С��\n");

	set("str", 10);
	set("combat_exp", 500);
        set("attitude","peaceful");

        set("limbs", ({ "ͷ��", "����","���" }) );
	set("verbs", ({ "bite","claw" }) );
        set_temp("apply/dodge", 100);

        setup();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 0, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	message_vision("$Nߴߴ�Ľ���!\n",this_object());
}