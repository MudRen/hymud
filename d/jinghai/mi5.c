// Room: /d/jinghai/mi5.c

inherit ROOM;

void create()
{
	set("short", "地道");
	set("long", @LONG
这是一条宽敞的地下通道，通道两面的墙壁上点着碗口粗的
火把，地上的细砂有些潮湿。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"mi4",
  "out" : __DIR__"wm15",
]));

	setup();
	replace_program(ROOM);
}
