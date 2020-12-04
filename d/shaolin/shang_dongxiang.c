// Room: /city/dongxiang.c
// YZC 1995/12/04 

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "商家地牢");
	set("long", @LONG
这是一个昏暗的地牢，窗户都被钉死。地上放着皮鞭、木棍等刑具。
LONG );
	set("exits", ([
		"south" : __DIR__"shang_lianwun",
	]));
	set("objects", ([
		__DIR__"npc/shang_zhao" : 1,
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

