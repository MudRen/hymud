// xiaofan.c

inherit NPC;

void create()
{
	set_name("С��", ({ "xiao fan","fan" }) );
	set("gender", "����" );
	set("age", 21);
	set("long",
		"���Ŵ�Ҷ�����Ϸ��������ʳ����Ǯ��\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
		case 0:
			message_vision( "С������$N��ͷ��������λ" + RANK_D->query_respect(ob)
				+ "Ҳ����Ϸ�ˡ�\n",ob);
			break;
		case 1:
			message_vision( "С��Ц���еĶ�$N˵������λ" + RANK_D->query_respect(ob)
				+ "Ҫ��Ҫ���Ժȣ�\n",ob);
			break;
	}
}
