// Room: /open/dt/hongchanglu4.c

inherit ROOM;

void create()
{
	set("short", "���·");
	set("long", @LONG
���·�������򣬼�֮���߶��ǵ��̣���ס�˴������߹�
���Ŀ�磬���Կ�������Ϊ�ྻ���������ϻ����洦�ɼ�ɳ����
����·���洦�ɼ��������������ؽֶ���һЩС�����������·
��û��ʲô��ĵ��̣������Ǽ���ݣ������Ǵ�ͬ��ݣ����治
Զ������ʮ��·���ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"shizilukou",
  "east" : __DIR__"hongchanglu5",
  "south" : __DIR__"wuguan",
  "north" : __DIR__"mianguan",
]));

	set("outdoors","datong");

	setup();
	replace_program(ROOM);
}
