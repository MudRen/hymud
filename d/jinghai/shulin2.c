// Room: /d/jinghai/shulin2.c

inherit ROOM;

void create()
{
	set("short", "桃花林中");
	set("long", @LONG
这是桃花林中。


LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"shulin3",
  "west" : __DIR__"xuanya",
]));
        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
