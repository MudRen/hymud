// Room: /open/dt/hongchanglu5.c

inherit ROOM;

void create()
{
	set("short", "���·");
	set("long", @LONG
���·�������򣬼�֮���߶��ǵ��̣���ס�˴������߹�
���Ŀ�磬���Կ�������Ϊ�ྻ���������ϻ����洦�ɼ�ɳ����
����·���洦�ɼ��������������ؽֶ���һЩС�����������·
��û��ʲô��ĵ��̣���������һ��С�Ե꣬�����Ǽ����̡�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"hongchanglu4",
  "east" : __DIR__"hongchanglu6",
  "south" : __DIR__"tiejiangpu",
  "north" : __DIR__"renyili",
]));

	set("outdoors","datong");

	set("objects",([
	"/clone/npc/man" : 3,
]));

	setup();
	replace_program(ROOM);
}
