// �����ϰ� /d/city/chuzhou/npc/bookboss.c
// by lala, 1997-12-13

inherit NPC;

inherit F_VENDOR;

#include <ansi.h>

void create()
{
    set_name( "���Գ�", ({ "zhang yancheng", "zhang", "boss", }) );
    set( "title", MAG"����"GRN"�ϰ�"NOR );
    set( "gender", "����" );
    set( "age", 48 );
    set("qi",400);
    set("max_qi",400);
    set("eff_kee",400);
    set("sen",400);
    set("max_sen",400);
    set("eff_sen",400);
    set( "long", @LONG
���Գ��Ǹ���Ϊ�Źֵ��ˣ�ƽ��Ĭ���������������������������й��ʱ�򣬾�
�о�������Ŀ���ڽ����Ķ�����ĺ󱳣�����һ�ֵֹֹĸо����ܲ������
LONG
    );
    set( "attitude", "friendly" );

    
	set("vendor_goods", ({
		__DIR__"obj/shanhai_jing",
		__DIR__"obj/dili_zhi",
		__DIR__"obj/xiyu_ji",
	}));    
    
    set( "talk_msg",({
       "����������飬�����Ǹ���Щ����������׼���ġ���",
       "�������ҵ��飬�ܳ���ʶ�ģ����Ҷ��ȽϺö�����",
       "���Լ��������ɣ���Ҫ������ˡ���",
       "����ǰ�������Ժ�Ҫ������������",
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

