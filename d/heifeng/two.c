// Room: /d/heifeng/two.c

inherit ROOM;

void create()
{
	set("short", "��կ������");
	set("long", @LONG
�����Ƕ�կ�����ҡ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"xiaolu1",
]));
	set("objects", ([
		"/clone/npc/npc" : 1,
	]));
	setup();
	replace_program(ROOM);
}
