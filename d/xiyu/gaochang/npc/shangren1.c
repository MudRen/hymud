/* shangren1.c ӡ������
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
"ɳ�ܺ�","�Ͳ���","���˰�","��������","���ܷ�",
});


void create()
{
    seteuid( getuid() );
    set_name( india_name[random(5)], ({ "yindu shangren", "shangren","india" }) );
    set( "title",GRN"ӡ������"NOR );
    set("gender", "����" );
    set( "long", @LONG
����һ����ӡ�Ȳ�Զ�����;���浽������������ġ�
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
