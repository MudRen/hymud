//Room: /u/lots/d/leftroom3.c
// LOTS 1998/10/14

inherit ROOM;

void create()
{
	set("short", "带刀侍卫休息处");
	set("long", @LONG
这里是带刀侍卫的休息处,请保持安静.
LONG
	);
	set("outdoors", "kaifeng");

	set("exits", ([
		"west" : __DIR__"road3",
		"east" : __DIR__"ldang3",
		"north" : __DIR__"leftroom4",
		"south" : __DIR__"leftroom2",
	]));

	set("objects", ([
		"/d/kaifeng/npc/shiwei" : 2,
	]));

	setup();
	replace_program(ROOM);
}
