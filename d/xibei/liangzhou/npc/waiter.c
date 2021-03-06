/* waiter.c
 * from XO Lib
 * a npc of gaochang
 * copied from lanzhou 19980427
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980427
 */


inherit NPC;
inherit F_VENDOR;

void create()
{
    set_name( "茶博士", ({ "cha boshi", "waiter" }) );
    set( "gender", "男性" );                //性别：男
    set( "age", 22 );                       //年龄：22
    set( "attitude", "friendly" );          //态度：友善
    set( "rank_info/respect", "老爷子" );   
    set( "long", @LONG
    茶博士手里端着一杯茶，笑眯眯地正在慢慢品尝。
LONG
    );


    set( "combat_exp",  7500 );             //战斗经验：7500

	set("vendor_goods", ({
		"/d/city/npc/obj/jitui",
		"/d/city/npc/obj/jiudai",
		"/d/city/npc/obj/baozi",
	}));

    setup();
    carry_object( "/clone/misc/cloth" )->wear();       //青布衣衫
}

void init()
{
    object ppl;

    ::init();

	add_action("do_buy", "buy");
	add_action("do_list", "list");

    if ( !userp( ppl = this_player() ) 
        )
        return;
    remove_call_out( "Greeting" );
    call_out( "Greeting", 1, ppl );
}

void Greeting( object ppl )
{
    if ( !ppl 
        || environment( ppl ) != environment() ) 
        return;
     command( "say 这位" + RANK_D->query_respect( ppl ) + "，进来喝口茶，"
"歇歇腿吧。”\n");
}



