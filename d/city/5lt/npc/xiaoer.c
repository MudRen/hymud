// Room: /d/5lt/npc/xiaoer.c �Ƶ�С��

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("��С��", ({ "xiao er", "xiao", "waiter" }) );
	set("gender", "����" );
	set("age", 22);
	set("long",
		"��λ��С����Ц���е�æ��������ʱ������ڲ����ϵ�Ĩ��������\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("rank_info/respect", "С����");
	set("vendor_goods", ({
		"/d/city/npc/obj/jitui",
		"/d/city/npc/obj/jiudai",
		"/d/city/npc/obj/baozi",
		__DIR__"obj/wuliangye",
	}));
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{	
	object ob = this_player();
	mapping myfam; 

	::init();
	if( interactive(ob) && !is_fighting() )
	{
		if ( (myfam = ob->query("family")) &&
			myfam["family_name"] == "ؤ��" &&
			ob->query_skill("begging",1) > 10 )
		{
			remove_call_out("saying");
			call_out("saying", 0, ob);
		}
		else
		{ 
			remove_call_out("greeting");
			call_out("greeting", 1, ob);
		}
	}
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
		case 0:
			say( "��С��Ц���е�˵������λ" + RANK_D->query_respect(ob) + "����ӭ�����û���¥��\n");
			break;
		case 1:
			say( "��С���ò����ϵ�ë��Ĩ��Ĩ�֣�˵������λ" + RANK_D->query_respect(ob) + "����������\n");
			break;
	}
}


