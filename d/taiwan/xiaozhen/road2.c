// Room: /d/taiwan/road2.c

inherit ROOM;

void create()
{
	set("short", "渔村中");
	set("long", @LONG
小渔村中的房子建造得零零落落,时不时有嬉笑的顽童在此间跑来跑
去,到处都晒满了各类大小渔网.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "southwest" : __DIR__"undertree.c",
  "north" : __DIR__"villege",
  "east" : __DIR__"house3",
]));
	set("outdoors", "/d/taiwan");

	setup();
	replace_program(ROOM);
}
