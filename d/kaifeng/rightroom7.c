//Room: /u/lots/d/rightroom7.c
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
		"east" : __DIR__"road7",
		"west" : __DIR__"rdang7",
		"south" : __DIR__"rightroom6",
		"north" : __DIR__"rightroom8",
	]));

	set("objects", ([
		"/d/kaifeng/npc/shiwei" : 2,
	]));

	setup();
	replace_program(ROOM);
}
