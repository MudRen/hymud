// Room: /d/jinghai/xiuxishi.c

inherit ROOM;

void create()
{
	set("short", "休息室");
	set("long", @LONG
这是一间休息室。

LONG
	);
        set("sleep_room", "1");
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"xiaolu1",
]));

	setup();
	replace_program(ROOM);
}
