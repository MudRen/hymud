// Room: /d/jinghai/gui18.c

inherit ROOM;

void create()
{
	set("short", "山林中");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southdown" : __DIR__"gui2",
]));

	setup();
	replace_program(ROOM);
}
