// �Ϸ����� /d/city/chuzhou/npc/south_seller4.c
// by lala, 1997-12-15

inherit NPC;

inherit F_VENDOR;

#include <ansi.h>

void create()
{
    set_name( "��������", ({ "fujian keshang", "keshang", "seller", }) );
    set( "title", HBYEL RED"�Ϸ�"WHT"����"NOR );
    set( "gender", "����" );
    set( "age", 25 + random(25) );
    set( "long", @LONG
���Ǹ��Ϸ��������ˣ�����������Ϸ����ز������ڴ����Ľ�����
LONG
    );
    set( "attitude", "friendly" );
	set("vendor_goods", ({
		"/d/city/npc/obj/jitui",
		"/d/city/npc/obj/jiudai",
		 __DIR__ + "obj/babao_yinni",
	}));

    set( "talk_msg",({
    }));
    set("qi",400);
    set("max_qi",400);
    set("eff_kee",400);
    set("sen",400);
    set("max_sen",400);
    set("eff_sen",400);
    set( "max_force",   500 );
    set( "force",       500 );
    set( "force_factor", 20 );
    set( "combat_exp",  10000 + random( 5000 ) );
    set( "social_exp",  20000 + random( 5000 ) );
    set( "positive_score",  100 + random( 500 ) );
    set( "negative_score",  100 + random( 500 ) );


    setup();

    carry_object( "/clone/misc/cloth" )->wear();

    add_money( "coin", 20 + random(31) );
}

void init()
{
    ::init();

	add_action("do_buy", "buy");
	add_action("do_list", "list");
}
