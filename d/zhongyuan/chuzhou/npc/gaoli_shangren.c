// ��������� /d/city/chuzhou/npc/gaoli_shangren.c
// by lala, 1997-12-13

inherit NPC;

inherit F_VENDOR;

#include <ansi.h>

string *name = ({
"������", "�Ӻ���", "¬̫��", "�����", "�޳ʺ�",
});

void create()
{
    set_name( name[random(sizeof(name))], ({ "gaoli shangren", "shangren", "corean", }) );
    set( "title", RED"����"WHT"����"NOR );
    set( "gender", "����" );
    set( "age", 33 );
    set( "long", @LONG
һ���������ˣ����ŵ��͵ĸ����˵���ס����˴�����ǧ����ഩ���ձ�������
���й���������������ȫ�ĵ��ˣ��Ȳ������Ƿ��ܰ�ȫ�Ļ�ȥ�������Լ����ں�
��Ҳ��������������������ĵ�����ô�ܰ��������������Ļ�������ü�Ǯ��
LONG
    );
    set( "attitude", "friendly" );


	set("vendor_goods", ({
		__DIR__"obj/gaoli_renshen",
		__DIR__"obj/gaoli_zhi",
		__DIR__"obj/gaoli_mo",
		__DIR__"obj/tigercloth",
		__DIR__"obj/riben_zheshan",
		__DIR__"obj/wodao",
	}));    
    set( "talk_msg",({
    }));
        set("qi",400);
        set("max_qi",400);
        set("eff_kee",400);
        set("sen",400);
        set("max_sen",400);
        set("eff_sen",400);

    set("combat_exp", 100000);
    set("social_exp", 100000);
    set("positive_score", 5000);
    set("negative_score", 1000);
    setup();
          
    carry_object( "/clone/misc/cloth")->wear();
    add_money( "silver", 10 + random(5) );
}          

void init()
{       
    ::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

