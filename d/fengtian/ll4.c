// Room: /d/fengtian/ll4.c

inherit ROOM;

void create()
{
	set("short", "李林街");
	set("long", @LONG
李林街是盛京的一条辅助街道，不过随着城区的不断扩大，
以及近几年的安定这里也逐渐繁华起来，逐渐成为盛京的一个主
要商业街了。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"kd1",
  "west" : __DIR__"jiulou",
  "east" : __DIR__"caifeng",
  "north" : __DIR__"ll3",
]));
        set("outdoors", "fengtian");
	setup();
	replace_program(ROOM);
}
