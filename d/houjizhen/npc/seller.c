// seller.c
// by dicky

inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("小贩", ({ "xiao fan","seller" }) );
        set("gender", "男性" );
        set("age", 40);
        set("long",
                "这是个小贩，别看他长的老老实实，可你别想从他那儿掏便宜。\n");
        set("combat_exp", 300);
        set("str", 17);
        set("per", 20);
        set("con", 17);
        set("int", 22);
	set("sell_all_day",1);
        set("attitude", "friendly");
	set("vendor_goods", ({
		__DIR__"obj/fire",
		__DIR__"obj/tanghulu",
		__DIR__"obj/erhu",
	__DIR__"obj/shuinang",	
	}));


        setup();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	object ob;
        ::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");

        if (interactive(ob = this_player()) && !is_fighting()){
               remove_call_out("greeting");
               call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{

	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
		case 0:
			say( "小贩子突然拦住你，神秘地说道：这位" + RANK_D->query_respect(ob)
				+ "，难道不想看看有什么需要的么？\n");
			break;
		case 1:
			say( "小贩子抬头看看天，缓缓说道：这位" + RANK_D->query_respect(ob)
				+ "，看你走得那么匆忙，\n可千万不要错过人生的许多精彩细节。\n");
			break;
	}
}