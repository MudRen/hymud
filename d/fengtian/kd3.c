// Room: /d/fengtian/kd3.c

inherit ROOM;

void create()
{
	set("short", "康定路");
	set("long", @LONG
康定路是盛京南城的主要街道，康定路贯串东西是盛京城的
一条老街，街道的青石由于人走的年头久了都变的又滑又亮，这
条街上有不少小商店，经营百姓衣食住行以及日杂的货物。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"fruit",
  "west" : __DIR__"kd4",
  "east" : __DIR__"kd2",
  "north" : __DIR__"book",
]));
        set("outdoors", "fengtian");

	setup();
	replace_program(ROOM);
}
