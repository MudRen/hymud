// Room: /d/jinghai/dating.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������ɽׯ����

LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"guodao2",
  "north" : __DIR__"damen",
  "southwest" : __DIR__"guodao1",
]));
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/master5.c" : 1,
  __DIR__"npc/master3.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
