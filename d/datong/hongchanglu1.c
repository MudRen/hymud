// Room: /open/dt/hongchanglu1.c

inherit ROOM;

void create()
{
	set("short", "���·");
	set("long", @LONG
���·�������򣬼�֮���߶��ǵ��̣���ס�˴������߹�
���Ŀ�磬���Կ�������Ϊ�ྻ���������ϻ����洦�ɼ�ɳ����
����·���洦�ɼ��������������ؽֶ���һЩС�����������·
��û��ʲô��ĵ��̣�������һ�һ�ջ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"hongchanglu2",
  "north" : __DIR__"business",
]));

	set("outdoors","datong");

	set("objects",([
	__DIR__"npc/guard" : 1,
__DIR__"npc/qiaoshou" : 1,]));

	setup();
	replace_program(ROOM);
}
