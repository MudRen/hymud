// Room: /d/heifeng/first.c

inherit ROOM;

void create()
{
	set("short", "��կ������");
	set("long", @LONG
������Ǵ�կ�����ҡ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"xiaolu2",
]));
	set("objects", ([
		"/clone/npc/npc1" : 1,
	]));
	setup();
	replace_program(ROOM);
}
