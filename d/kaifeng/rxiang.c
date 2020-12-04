// Room: /u/lots/d/rxiang.c
// LOTS 1998/10/19

inherit ROOM;

void create()
{
	set("short", "厢房");
	set("long", @LONG
平常包大人升堂或下堂的时候会在此小憩片刻,考虑案情.
LONG
	);
	set("outdoors", "kaifeng");

	set("exits", ([
		"east" : __DIR__"gongtang",
		"northwest" : __DIR__"hualang1",
	]));

	set("objects", ([
		"/d/kaifeng/npc/yahuan" : 2,
	]));

	setup();
	replace_program(ROOM);
}
