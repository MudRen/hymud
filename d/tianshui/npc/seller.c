// seller.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("杂货贩", ({ "seller" }) );
        set("title", "杂货铺");
        set("gender", "男性" );
        set("age", 32);
        set("long", "卖杂货的是个年轻汉子，面带微笑。\n");
        set("combat_exp", 1000);
        set("attitude", "friendly");
        set_skill("unarmed", 60);
        set_skill("dodge", 50);
        set_skill("throwing", 30);

	set("vendor_goods", ({
                __DIR__"obj/rope",
		__DIR__"obj/dodge_book",
		__DIR__"obj/unarmed_book",
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
        if( interactive(ob = this_player()) && !is_fighting())
	{
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }



}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(4) ) {
                case 0:
                        say( "杂货贩笑脸相迎，道：这位"
                                + RANK_D->query_respect(ob)
                                + "，要买什么？\n");
                        break;
                case 1:
                        say( "杂货贩正忙着整理货架\n");
                        break;
        }
}
