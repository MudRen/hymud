// Room: /open/dt/hongchanglu3.c

inherit ROOM;

void create()
{
	set("short", "���·");
	set("long", @LONG
���·�������򣬼�֮���߶��ǵ��̣���ס�˴������߹�
���Ŀ�磬���Կ�������Ϊ�ྻ���������ϻ����洦�ɼ�ɳ����
����·���洦�ɼ��������������ؽֶ���һЩС�����������·
��û��ʲô��ĵ��̣�������������ջ��������һ���ӻ��̣���
�治Զ����ʮ��·���ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"hongchanglu2",
  "east" : __DIR__"shizilukou",
  "south" : __DIR__"zahuopu",
  "north" : __DIR__"ylinn",
]));

	set("outdoors","datong");

	setup();
	replace_program(ROOM);
}
