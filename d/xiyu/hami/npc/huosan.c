// huosang.c     ��ɣ
// Ffox 98-4-30 14:14

inherit NPC;
inherit F_VENDOR;

void create()
{
    set_name( "��ɣ", ({ "huo sang", "huo"  }) );
    set( "gender", "����" );                //�Ա���
    set( "age", 30 );                
    set( "long", @LONG
�����ˡ������ˡ�����
LONG );
    set( "attitude", "friendly" );

    set( "chat_chance", 5 );
    set( "chat_msg", ({
    "��ɣ�����ſڣ�ע�⵽�����Աߣ��ܸ��˵���������ͷ�١�",
    "��ɣ��������ͷ�٣�̧��ͷ����",
     }));

	set("vendor_goods", ({
		__DIR__"obj/matouqin",

	__DIR__"obj/putao_jiu",
	}));
    setup();
    carry_object( "/clone/misc/cloth" )->wear();       //�ֲ���
}


void init()
{
    object ppl;
    ::init();
        add_action("do_list", "list");
        add_action("do_buy", "buy");
    call_out( "do_listen", 1 ,ppl );
}

void do_listen()
{
    write( "������������ڵ�����������Ȼ��һ������......\n");
}
