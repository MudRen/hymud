// mmaiti.c    买买提
// Ffox 98-4-30 14:14

#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

void create()
{
    set_name( "买买提", ({ "mai maiti", "maiti"  }) );
    set( "gender", "男性" );                //性别：男
    set( "age", 40 );                
    set( "long", @LONG
本地人……以种植果品为生……
LONG );
    set( "attitude", "friendly" );
	set("vendor_goods", ({
		__DIR__"obj/hamigua",
		__DIR__"obj/putao",
		__DIR__"obj/xianggua",
						__DIR__"obj/xigua",
	}));
    set( "chat_chance", 5 );
    set( "chat_msg", ({
    "买买提叫道：哎，来看一看我种植的新品种葡萄了哦。 ",
    "买买提很高兴的对你说： 哈哈，我种的哈密瓜熟啦！",
}) );

    setup();
    carry_object( "/clone/misc/cloth" )->wear();       //粗布衣
}

void init()
{
//    object ppl;
    ::init();
        add_action("do_list", "list");
        add_action("do_buy", "buy");
//    call_out( "do_listen", 1 ,ppl );
}

