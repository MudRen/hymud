// Room: /d/taiwan/tree2.c

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
  "east" : __DIR__"tree1.c",
  "west" : __DIR__"tree3",
]));
	set("outdoors", "/d/taiwan");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/dog.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
