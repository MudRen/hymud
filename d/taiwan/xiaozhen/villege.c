// Room: /d/taiwan/villege.c

inherit ROOM;

void create()
{
	set("short", "小渔村");
	set("long", @LONG
这是一个小渔村,几十间房子破破烂烂的,都用茅草盖着顶,只有村
南的一栋房子建造得十分富丽堂皇.看来十分惹眼.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "northwest" : __DIR__"road1",
  "east" : __DIR__"house",
  "south" : __DIR__"road2",
]));
	set("outdoors", "/d/taiwan");

	setup();
	replace_program(ROOM);
}
