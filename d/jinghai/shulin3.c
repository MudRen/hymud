// Room: /d/jinghai/shulin3.c

inherit ROOM;

void create()
{
	set("short", "桃花林");
	set("long", @LONG
这是桃花林。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"lukou",
  "west" : __DIR__"shulin2",
]));
        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
