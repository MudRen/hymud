// Room: /d/jinghai/gui7.c

inherit ROOM;

void create()
{
	set("short", "木桥");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southup" : __DIR__"gui9",
  "north" : __DIR__"gui6",
]));

	setup();
	replace_program(ROOM);
}
