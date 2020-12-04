// Room: /d/jinghai/moonlu1.c

inherit ROOM;

void create()
{
	set("short", "山间小路");
	set("long", @LONG
这是一条小土路，路上满是杂草和石子，路的两旁是矮小的
荆棘丛，看样子这里很少有人来。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northdown" : __DIR__"moonlu2",
  "southup" : __DIR__"moon23",
]));

	set("outdoors", "jinghai");
	setup();
	replace_program(ROOM);
}
