// Room: /d/taiwan/road1.c

inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
һ������·,·�и��й��ĳ���ѹ������������ĳ���.���������� 
�����õ�С����·����׷�Ҹϵ���ˣ.·�����������ˮ����. 
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/taiwan");
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"villege",
  "north" : __DIR__"road",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/kid.c" : 2,
]));

	setup();
	replace_program(ROOM);
}
