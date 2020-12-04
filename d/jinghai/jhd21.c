// Room: /d/jinghai/jhd21.c

inherit ROOM;

void create()
{
	set("short", "卧房");
	set("long", @LONG
这里是靖海派开山祖师之一，靖海公的夫人林月光的卧室，
房间的布置整洁淡雅。却又不失飒爽之风，林夫人号称东海玉蛟
不论武功韬略，比起她夫君靖海公都不遑多让，所以在靖海派及
江湖中都有很高的威望。
LONG
	);

	

	set("sleep_room", 1);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"jhd20",
]));

	setup();
	replace_program(ROOM);
}
