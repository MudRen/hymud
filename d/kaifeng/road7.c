// Room: /u/lots/d/road7.c
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
		"east" : __DIR__"leftroom7",
		"south" : __DIR__"road6",
		"west" : __DIR__"rightroom7",
		"north" : __DIR__"road8",
	]));

	setup();
	replace_program(ROOM);
}

