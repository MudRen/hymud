// Room: /d/jinghai/gui19.c

inherit ROOM;

void create()
{
	set("short", "林中小路");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"gui20",
  "north" : __DIR__"gui1",
]));

	setup();
	replace_program(ROOM);
}
