// Room: /open/dt/hongchanglu2.c

inherit ROOM;

void create()
{
	set("short", "���·");
	set("long", @LONG
���·�������򣬼�֮���߶��ǵ��̣���ס�˴������߹�
���Ŀ�磬���Կ�������Ϊ�ྻ���������ϻ����洦�ɼ�ɳ����
����·���洦�ɼ��������������ؽֶ���һЩС�����������·
��û��ʲô��ĵ��̣�������һ��˽լ��������һ��С��ݡ�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"hongchanglu1",
  "east" : __DIR__"hongchanglu3",
  "south" : __DIR__"chadian",
  "north" : __DIR__"sizhai",
]));

	set("outdoors","datong");

	setup();
	replace_program(ROOM);
}
