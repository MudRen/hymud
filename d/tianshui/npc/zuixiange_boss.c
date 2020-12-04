// zuixiange_boss.c

inherit NPC;

void create()
{
	set_name("����", ({ "liu fu","boss" }) );
	set("title","���ɸ��ƹ�");
	set("gender", "����" );
	set("age", 45);
	set("long",
		"���������ɸ���ϰ壬�������ڿ죬��Ե�ֺã�
�洫��С�굽������Խ��Խ��\n");
	set("combat_exp", 10000);
	set("attitude", "friendly");

	setup();
	add_money("silver",10);
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
	if( !ob || environment(ob) != environment() || ob->query_temp("rent_paid")) return;
	switch( random(2) ) {
		case 0:
			say( "�ƹ��Ц�����˵���������÷��ɣ��������롣\n");
			break;
		case 1:
			say( "�ƹ��Ц�����˵�����������������÷��������⡣\n");
			break;
	}
}