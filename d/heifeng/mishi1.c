// Room: /d/heifeng/mishi1.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ�����ҡ�
LONG
	);

	set("objects", ([
		"/clone/money/gold" : 1,
		__DIR__"npc/chick" : 1,
	]));

	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"midao2",
]));

	setup();
}
