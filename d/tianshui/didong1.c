// Room: /u/xiaozhen/didong1.c

inherit ROOM;

void create()
{
	set("short", "�ض�");
	set("long", @LONG
������ĵض�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"didong2",
  "up" : __DIR__"linlu4",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
