// Room: /d/taiwan/tree1.c

inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
����һ��С·,���ںܳ�ʱ��û���߹�,��·���϶�������Ұ��.һֱ
ͨ��Զ����һƬ����.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"undertree",
  "west" : __DIR__"tree2",
]));
	set("outdoors", "/d/taiwan");

	setup();
	replace_program(ROOM);
}
