// mmaiti.c    ������
// Ffox 98-4-30 14:14

#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

void create()
{
    set_name( "������", ({ "mai maiti", "maiti"  }) );
    set( "gender", "����" );                //�Ա���
    set( "age", 40 );                
    set( "long", @LONG
�����ˡ�������ֲ��ƷΪ������
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
    "������е�����������һ������ֲ����Ʒ��������Ŷ�� ",
    "������ܸ��˵Ķ���˵�� ���������ֵĹ��ܹ�������",
}) );

    setup();
    carry_object( "/clone/misc/cloth" )->wear();       //�ֲ���
}

void init()
{
//    object ppl;
    ::init();
        add_action("do_list", "list");
        add_action("do_buy", "buy");
//    call_out( "do_listen", 1 ,ppl );
}

