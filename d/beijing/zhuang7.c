#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "庄府大厅");
	set("long", @LONG
这是一间灵堂。堂上供了七八个牌位，看来一座灵堂上供的是一家
死人。一阵阴风吹过，蜡烛突然灭了。
LONG );
	set("exits", ([
		"east" : __DIR__"zhuang5",
	]));
	set("objects", ([
		__DIR__"npc/dizi": 3,
	]));
	set("outdoors", "huabei");
	set("coor/x", 90);
	set("coor/y", 4720);
	set("coor/z", 0);
	setup();
	replace_program(ROOM); 
}
