// shanlu1.c
// by dicky

inherit ROOM;

void create()
{
	set("short", "山间小路");
	set("long", @LONG
你走在一条蜿蜒而上的山间小路上，这里十分荒凉，偶尔听见几声鸟鸣。
你的心不由的绷紧了。
LONG
	);
        set("outdoors", "houjizhen");

	set("exits", ([
		"southup" : __DIR__"shanpo",
	        "northup" : __DIR__"shanlu2",
	        "westup" : __DIR__"songlin2",
	]));

	setup();
	replace_program(ROOM);
}

