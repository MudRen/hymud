// Room: /d/taiwan/tree4.c

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
  "northeast" : __DIR__"tree3",
  "north" : __DIR__"tree5",
  "west" : __DIR__"tree5",
  "east" : __DIR__"tree4",
]));
	set("outdoors", "/d/taiwan");

	setup();
	replace_program(ROOM);
}
