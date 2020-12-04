
// waiter.c

inherit NPC;
inherit F_VENDOR;

void create()
{
   set_name("����", ({ "seller" }) );
	set("gender", "����" );
	set("age", 22);
        set("cor", 100);
	set("long",
 "ֻ�����Ӳ�ͣ��æµ�ţ�����ʱ�Ĳ��������������ⲻ��\n");
	set("combat_exp", 15000);
	set("attitude", "friendly");
	set("rank_info/respect", "С����");

	setup();
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
	switch( random(5) ) {
		case 0:
    say( "����Ц�����˵������λ" + RANK_D->query_respect(ob)
  + "��Ҫ��Ҫ��һƥǧ����ѽ?\n");
			break;
		case 1:
    say( "���Ӳ��˲�����˵������λ" + RANK_D->query_respect(ob)
				+ "����������\n");
			break;
		case 2:
       say( "����˵������λ" + RANK_D->query_respect(ob)
    + "������������ƥ�ɡ���Щ�����������ǧ����ѽ\n");
			break;
		case 3:
     say( "���Ӹ���ߺ�ȵ�:��λ" + RANK_D->query_respect(ob)
     + ",���¿���,���ж������۳���. \n");
			break;
		case 4:
     say( "����Ц�Ǻǵ�˵��:��λ" + RANK_D->query_respect(ob)
   + ",������Ҫ������,��¥�����,������! \n");
			break;
	}
}
