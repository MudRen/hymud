//Room: /u/lots/d/ldang2.c
// LOTS 1998/10/15

inherit ROOM;

void create()
{
	set("short", "玩家档案管理室");
	set("long", @LONG
这儿是玩家档案管理室.包大人就是靠这些档案来处理公务的.
LONG
	);
	set("outdoors", "kaifeng");

	set("exits", ([
		"west" : __DIR__"leftroom2",
		"south" : __DIR__"ldang1",
		"north" : __DIR__"ldang3",
	]));

	set("objects", ([
		"/d/kaifeng/npc/wenshu" : 2,
	]));

	setup();
	replace_program(ROOM);
}
