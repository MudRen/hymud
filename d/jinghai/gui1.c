// Room: /d/jinghai/gui1.c

inherit ROOM;

void create()
{
	set("short", "鬼屿码头");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"gui2",
  "south" : __DIR__"gui19",
]));

	setup();
	replace_program(ROOM);
}
