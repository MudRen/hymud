// Room: /city/shaolin.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "少林");
	set("long", @LONG
shao lin
需要更多的说明……
LONG );

	set("exits", ([
		"east" : __DIR__"road8",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

