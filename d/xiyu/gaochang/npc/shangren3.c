/* shangren3.c �й�����
 * from XO Lib
 * a npc of gaochang.
 * created by hydra 19980427
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980427
 */

#include <ansi.h>

inherit NPC;

inherit F_VENDOR;

void create()
{
    set_name( "������", ({ "zhongyuan shangren","shangren" }) );
    set( "title",YEL"��ԭ����"NOR );
    set("gender", "����" );
    set( "long", @LONG
����һ�����й�������嫵Ĵ�ɳĮ������������ġ�
LONG
    );
    set( "age",33 );


    set_skill( "unarmed",700+random(300) );
    set_skill( "dodge",700+random(300) );
    set( "combat_exp", 50000 );
    set( "attitude", "friendly" );
	set("vendor_goods", ({
		__DIR__"obj/compass",
		__DIR__"obj/sichou",
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

