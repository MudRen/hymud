// Room: /d/jinghai/gui16.c

inherit ROOM;

void create()
{
	set("short", "书房");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southeast" : __DIR__"gui5",
]));

	setup();
	replace_program(ROOM);
}
