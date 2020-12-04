// shanlu2.c
//by dicky

inherit ROOM;

void create()
{
	set("short", "山间小路");
	set("long", @LONG
你走在一条蜿蜒而上的山间小路上，这里十分荒凉，前面不远处就是
一些小树林，东面有条小路通向树林深处。
LONG
	);
        set("outdoors", "houjizhen");

	set("exits", ([
		"southdown" : __DIR__"shanlu1",
		"northwest" : __DIR__"shanlu4",
		"east" : __DIR__"shanlu3",
	]));
	setup();
	replace_program(ROOM);
}

