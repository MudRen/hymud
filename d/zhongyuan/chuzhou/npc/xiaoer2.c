// 楚州酒楼的店小二 /d/city/chuzhou/npc/xiaoer2.c
// by lala, 1997-12-14

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("店小二", ({ "xiao er", "waiter"}) );
        set("gender", "男性" );
        set("age", 22);
        set("long",
        "店小二身穿青布衣衫，肩上搭着块白布巾，正在忙着招呼客人。\n"
        );
        set("combat_exp", 1200);
        set("chat_chance_combat", 5);
        set("chat_msg_combat",({
                "店小二大声喊道：“你不要命了，敢在楚州城里杀人放火了？！！！”\n",
                "店小二边打边喊：“杀人啦！！救命啊！！！”\n",
        }) );
        set("attitude", "friendly");
        set("rank_info/respect", "小二哥");
	set("vendor_goods", ({
		"/d/city/npc/obj/jitui",
		"/d/city/npc/obj/jiudai",
		"/d/city/npc/obj/baozi",
	}));
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
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(5) ) {
        case 0 : case 1 :
                break;
        case 2:
                say( "店小二用肩上的白布巾抹了抹桌子，说道：“这位" + RANK_D->query_respect(ob)
                        + "，请这边坐。”\n");
                break;
        case 3:
                say( "店小二说道：“这位" + RANK_D->query_respect(ob)
                + "，本店有陈年的老酒，不想尝尝？”\n");
                break;
        case 4:
                say("店小二用肩上的白布巾抹了抹桌子，说道：“这位" + RANK_D->query_respect(ob)
                + "，您不尝尝楚州的地方名菜？”\n");
                break;
        }
}
