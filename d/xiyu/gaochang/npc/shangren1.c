/* shangren1.c 印度商人
 * from XO Lib
 * a npc of gaochang.
 * created by hydra 19980427
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980427
 */

#include <ansi.h>

inherit NPC;
inherit F_VENDOR;

string * india_name = ({
"沙杰汗","巴布尔","阿克巴","索汉拉尔","拉杰夫",
});


void create()
{
    seteuid( getuid() );
    set_name( india_name[random(5)], ({ "yindu shangren", "shangren","india" }) );
    set( "title",GRN"印度商人"NOR );
    set("gender", "男性" );
    set( "long", @LONG
他是一名从印度不远万里，长途跋涉到这里来做生意的。
LONG
    );
    set( "age",33 );


    set_skill( "unarmed",700+random(300) );
    set_skill( "dodge",700+random(300) );
    set( "combat_exp", 10000 );
    set( "attitude", "friendly" );
;       
	set("vendor_goods", ({
		__DIR__"obj/hujiao",
		__DIR__"obj/jibei_cao",
		__DIR__"obj/zhetang",
		__DIR__"obj/sheyao",
		__DIR__"obj/fanwen_book",
	}));
    setup();
    carry_object("/clone/misc/cloth")->wear();
    add_money( "silver",5+random(3) );
}

void init()
{       
    ::init();
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
