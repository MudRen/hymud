// Room: /open/dt/jinyangjie4.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��������ͬ�ϱ����ǳ����������һ���֡��ֵ�֮������
�ҷ紵�������궼Ʈ����һ���ɳ�����ֵ����Ե��̼����ƺ���
��ϰ�������ֶ��ӵ���������������ķ�ɳ��û�з������Ǿ�Ӫ
�Ÿ��Ե����⣬·���洦�ɼ�������װ������������ˡ�·����
��һ��С��������Ҹ��֡�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"luzhuxiang3",
  "east" : __DIR__"youfujie1",
  "south" : __DIR__"jinyangjie5",
  "north" : __DIR__"jinyangjie3",
]));

	set("outdoors","datong");

	set("objects",([
	"/clone/npc/man" : 3,
]));

	setup();
	replace_program(ROOM);
}
