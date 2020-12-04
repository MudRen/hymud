// Room: /u/lots/d/road9.c
// LOTS 1998/10/14

inherit ROOM;

void create()
{
	set("short", "开封府通道");
	set("long", @LONG
这里是开封府的通道,路俩边是带刀侍卫的休息处和玩家档案管理处,由此向北,
可以到开封府的公堂,在那儿你可以告状.
LONG
	);
	set("outdoors", "kaifeng");

	set("exits", ([
		"east" : __DIR__"leftroom9",
		"south" : __DIR__"road8",
		"west" : __DIR__"rightroom9",
		"north" : __DIR__"gongtang",
	]));

	setup();
	replace_program(ROOM);
}

