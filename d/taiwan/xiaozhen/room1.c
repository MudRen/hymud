// Room: /d/taiwan/room1.c

inherit ROOM;

void create()
{
	set("short", "山洞");
	set("long", @LONG
你一定不会想到,这扇门后居然是个山洞的入口,依红楼依山而建,
当年该处的主人在此建楼,显然含有深意.你一眼看去,山洞深不见底.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"tingtang",
  "northeast" : __DIR__"shandong1",
]));

	setup();
	replace_program(ROOM);
}
