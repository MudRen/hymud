// Room: /d/taiwan/villege.c

inherit ROOM;

void create()
{
	set("short", "С���");
	set("long", @LONG
����һ��С���,��ʮ�䷿���������õ�,����é�ݸ��Ŷ�,ֻ�д�
�ϵ�һ�����ӽ����ʮ�ָ����û�.����ʮ������.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "northwest" : __DIR__"road1",
  "east" : __DIR__"house",
  "south" : __DIR__"road2",
]));
	set("outdoors", "/d/taiwan");

	setup();
	replace_program(ROOM);
}
