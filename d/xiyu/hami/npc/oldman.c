// oldman 老人
// Ffox 98-4-25 17:26


inherit NPC;
inherit F_VENDOR;

void create()
{
    set_name( "老人", ({ "lao ren", "laoren", "waiter" }) );
    set( "gender", "男性" );                //性别：男
    set( "age", 60 );                       //年龄：22
    set( "attitude", "friendly" );          //态度：友善
    set( "rank_info/respect", "老人家" );   //敬称：小二哥
    set( "long", @LONG
老人家身形佝偻，自己在这里维持着可怜的生计。
LONG );

    set_skill( "unarmed",  100 );  //拳脚修为：    零级
    set( "combat_exp",  7500 );             //战斗经验：7500
    set( "talk_msg", ({
     "“这里不是经常有人来的，一般就附近的山里人偶尔到这里买一点土货。”",
    }) );
	set("vendor_goods", ({
		"/d/xingxiu/npc/obj/yangrou",
		"/d/lanzhouchen/npc/obj/paomo",
		"/d/city/npc/obj/jiudai",
		"/d/lanzhou/npc/obj/jiouhulu",
		"/d/lanzhou/npc/obj/maoniurou",
	}));

    setup();
    carry_object( "/clone/misc/cloth" )->wear();       //青布衣衫
}

void init()
{
    object ppl;
    ::init();
        add_action("do_list", "list");
        add_action("do_buy", "buy");
    if ( !userp( ppl = this_player() ) )
        return;
    remove_call_out( "Greeting" );
    call_out( "Greeting", 1, ppl );
}

void Greeting( object ppl )
{
    if ( !ppl || environment( ppl ) != environment() ) 
        return;
    switch(random(3)){
    case 0:
     message_vision("老人对$N说道：“这位"+RANK_D->query_respect( ppl )+"到这里来是想买东西呢还是要喝点酒？”\n",ppl);
     break;
    case 1:
     message_vision("老人对$N点了点头，算是打了个招呼。\n", ppl);
     break;
    case 2:
     message_vision("老人说到：“这位"+ RANK_D->query_respect( ppl )+"不买一点土货么？”\n",ppl);
     break;
    default:
     break;
    }
}

