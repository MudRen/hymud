 // TIE@FY3
inherit NPC;
inherit F_VENDOR;
void create()
{
    set_name("孙小红", ({ "sun xiaohong","sun" }) );
        set("gender", "女性" );
        set("age", 22);
    set("title", "辫子姑娘" );
        set("long",
        "天机老人的孙女儿,粗粗的辫子,大大的眼睛,可爱动人。\n");
        set("combat_exp", 500000);
        set("attitude", "friendly");
        set("rank_info/respect", "老板娘");
        	set("vendor_goods", ({
                __DIR__"obj/bu1",
                __DIR__"obj/bu2",
                __DIR__"obj/bu3",
                __DIR__"obj/bu4",
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
        switch( random(3) ) {
                case 0:
            say( "孙小红道了个万福，笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，要买什么？\n");
                        break;
           case 1:
            say( "孙小红似乎自言自语道：这位" + RANK_D->query_respect(ob)
                + "，最近有没有听到关于李寻欢大哥的消息？\n");
                        break;
                case 2:
            say( "孙小红向你问道：这位" + RANK_D->query_respect(ob)
                + "，不知道李大哥和上官金虹一战究竟怎么样?\n"); 
                        break;
        }
}   
