// Room: /d/taiwan/road.c

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
	set("exits", ([ /* sizeof() == 2 */
  
  "west" : "/d/taiwan/zhenbeifang",
  "north" : __DIR__"matou",
  "south" : __DIR__"road1",
]));
	set("outdoors", "/d/taiwan");

	setup();
	replace_program(ROOM);
}
