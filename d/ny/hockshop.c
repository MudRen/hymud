
// Room: /d/snow/hockshop.c

#include <room.h>

inherit HOCKSHOP;

void create()
{
	set("coor",({-10,4700,10}));
	set("short", "��ǵ���");
	set("long",
"����һ���еȹ�ģ�ĵ��̣��ϾɵĹ�̨�Ϸ���һ��ľ��(sign)������Ĺ��߲��Ǻ���������\n"
"�ĳ��ڱ�һ����ɫ���������������С�����Ī�롹��������������һ��ľ����(door)ͨ����\n"
"�֡�\n"
);
    set("rich",40000);
	set("item_desc", ([
		"sign": @TEXT
�����̲����ۺ�ͯ�����ۣ���ӭ�ݹˣ����Ա��ܡ�
���Ŀ���������䵱(pawn)������(sell)���ֻ��ͭǮ���������ƽ���Ʊ
һ��ͨ�á�
TEXT
	]) );
	set("exits", ([
        "west" : __DIR__"hockshop2",
        "east" : __DIR__"sroad1",
	]));
        set("objects", ([
                __DIR__"npc/hocker" : 1,
                 ]) );
	setup();

}
