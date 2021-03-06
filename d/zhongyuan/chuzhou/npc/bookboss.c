// 书屋老板 /d/city/chuzhou/npc/bookboss.c
// by lala, 1997-12-13

inherit NPC;

inherit F_VENDOR;

#include <ansi.h>

void create()
{
    set_name( "张言成", ({ "zhang yancheng", "zhang", "boss", }) );
    set( "title", MAG"书屋"GRN"老板"NOR );
    set( "gender", "男性" );
    set( "age", 48 );
    set("qi",400);
    set("max_qi",400);
    set("eff_kee",400);
    set("sen",400);
    set("max_sen",400);
    set("eff_sen",400);
    set( "long", @LONG
张言成是个颇为古怪的人，平素默不做声，但是你在书屋里来回闲逛的时候，就
感觉到他的目光在紧紧的盯着你的后背，给你一种怪怪的感觉，很不舒服。
LONG
    );
    set( "attitude", "friendly" );

    
	set("vendor_goods", ({
		__DIR__"obj/shanhai_jing",
		__DIR__"obj/dili_zhi",
		__DIR__"obj/xiyu_ji",
	}));    
    
    set( "talk_msg",({
       "“我这儿的书，都不是给那些考功名的人准备的。”",
       "“看看我的书，很长见识的，而且都比较好懂。”",
       "“自己翻翻看吧，不要打搅别人。”",
       "“以前来过吗？以后要经常来啊。”",
    }));
     
    setup();
      
    carry_object( "/clone/misc/cloth")->wear();
}          

void init()
{       
    ::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

