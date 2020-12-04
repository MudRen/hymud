// �������� /d/city/chuzhou/npc/north_seller2.c
// by lala, 1997-12-15

inherit NPC;

inherit F_VENDOR;

#include <ansi.h>

void create()
{
    set_name( "ɽ������", ({ "shandong keshang", "keshang", "seller", }) );
    set( "title", HBYEL BLU"����"WHT"����"NOR );
    set( "gender", "����" );
    set( "age", 25 + random(25) );
    set( "long", @LONG
���Ǹ������������ˣ���������౱�����ز������ڴ����Ľ�����
LONG
    );
    set( "attitude", "friendly" );
	set("vendor_goods", ({
		__DIR__ "obj/zi_yan",
		__DIR__ "obj/juan_hua",
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

    carry_object( "/clone/misc/cloth")->wear();
    carry_object( __DIR__ + "obj/zi_yan" );
    carry_object( __DIR__ + "obj/juan_hua" );
 
    add_money( "coin", 20 + random(31) );
}

void init()
{
    ::init();
 	add_action("do_buy", "buy");
	add_action("do_list", "list");
}
