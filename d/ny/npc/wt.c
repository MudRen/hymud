
// waiter.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("店小二", ({ "waiter" }) );
	set("gender", "男性" );
	set("age", 22);
	set("long",
		"这位店小二正笑咪咪地忙著，还不时拿起挂在脖子上的抹布擦脸。\n");
	set("combat_exp", 150);
	set("attitude", "friendly");
	set("rank_info/respect", "小二哥");
	set("vendor_goods", ({
		"/d/city/npc/obj/jitui",
		"/d/city/npc/obj/jiudai",
		"/d/city/npc/obj/baozi",
	}));
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

	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(5) ) {
		case 0:
			say( "店小二笑咪咪地说道：这位" + RANK_D->query_respect(ob)
				+ "，进来喝杯茶，歇歇腿吧。\n");
			break;
		case 1:
			say( "店小二用脖子上的毛巾抹了抹手，说道：这位" + RANK_D->query_respect(ob)
				+ "，请进请进。\n");
			break;
		case 2:
			say( "店小二说道：这位" + RANK_D->query_respect(ob)
				+ "，进来喝几盅小店的红酒吧，这几天才从窖子里开封的哟。\n");
			break;
		case 3:
			say( "店小二高声吆喝道:这位" + RANK_D->query_respect(ob)
				+ ",本店新开张,所有东西八折出售. \n");
			break;
		case 4:
			say( "店小二皮笑肉不笑地说道:这位" + RANK_D->query_respect(ob)
				+ ",本店要倒闭了,跳楼大减价,快来买啊! \n");
			break;
	}
}
