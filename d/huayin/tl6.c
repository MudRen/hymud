// Room: /d/huayin/tl6.c

inherit ROOM;

void create()
{
	set("short", "上山路");
	set("long", @LONG
这是一条青石板铺就的狭窄的上山小路，石阶很高，大概由
于年代的久远，石板都被磨成了斜坡，走起来格外困难。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"tl7",
  "southwest" : __DIR__"tl5",
]));

	set("outdoors","huayin");
	setup();
	replace_program(ROOM);
}
