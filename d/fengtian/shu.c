// Room: /d/fengtian/shu.c

inherit ROOM;

void create()
{
	set("short", "�鷿");
	set("long", @LONG
����һ�䲻����鷿�����е��鲢���ࡣ
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"jjf5",
]));

	setup();
	replace_program(ROOM);
}
