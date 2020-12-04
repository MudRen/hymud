// Room: /d/huanggong/ciningmen.c
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���ǻʹ���̫����ӹ�Ժ��������Ժ��. �����Ǹ�СԺ, Ժ��С��
԰���и��ɻ���, �������Ŵ�����. 
LONG
	);
	set("outdoors", "huanggong");
	set("exits", ([
		"east"     : __DIR__"longzongmen",
		"west"     : __DIR__"dao8",
		"north"    : __DIR__"cininggong",
		"south"    : __DIR__"bukufang",
	]));
	set("objects", ([
		__DIR__"npc/dongjinkui" :1,
	]));
	set("coor/x", -220);
	set("coor/y", 5270);
	set("coor/z", 0);
	setup();
//	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	if ( objectp(present("dong jinkui", environment(me))) && 
		dir == "north")
		return notify_fail("�������ס�����ȥ·��\n");
	return ::valid_leave(me, dir);
}