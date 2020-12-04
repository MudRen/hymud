
// Room: /d/snow/mstreet3.c

#include <room.h>

inherit ROOM;

void create()
{
    set("coor",({-70,4770,10}));
	set("short", "��Զ������");
	set("long",
"��������Զ�ǵĴ�֣�������һ���¾ɵĽ���������������ʲ����̣��ſ��Ϸ�����һ��ľ\n"
"�ң�����д�š��ּ����ӡ��ĸ����֣���������һ��С¥ͤ����������������������졣\n"
);

	set("exits", ([
        "south" : __DIR__"tfyard",
        "north" : __DIR__"herbshop",
        "east"  : __DIR__"mstreet2",
        "west"  : __DIR__"mstreet4",
	]));
	set("outdoors", "ny");

	setup();



	replace_program(ROOM);
}
