// Room: /d/taiwan/tree7.c

inherit ROOM;

void create()
{
	set("short", "�粨��");
	set("long", @LONG
̧����ȥ,���涼�Ǹ߸ߵ͵͵�����.��ͷ��·�Ѿ���������,ǰ���
·��û�������é����.Զ����������һ��Ů�˵Ŀ���.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"tree5",
  "south" : __DIR__"tree6",
  "east" : __DIR__"tree7",
  "north" : __DIR__"tree8",
]));
	set("outdoors", "/d/taiwan");

	setup();
	replace_program(ROOM);
}
