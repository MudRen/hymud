// Room: /d/jinghai/gui12.c

inherit ROOM;

void create()
{
	set("short", "厨房");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"gui4",
]));

	setup();
	replace_program(ROOM);
}
