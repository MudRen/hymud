// Room: /open/dt/jinyangjie5.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��������ͬ�ϱ����ǳ����������һ���֡��ֵ�֮������
�ҷ紵�������궼Ʈ����һ���ɳ�����ֵ����Ե��̼����ƺ���
��ϰ�������ֶ��ӵ���������������ķ�ɳ��û�з������Ǿ�Ӫ
�Ÿ��Ե����⣬·���洦�ɼ�������װ������������ˡ�·����
�Ǵ������Ľ�������
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"jiangjunfu",
  "south" : __DIR__"jinyangjie6",
  "north" : __DIR__"jinyangjie4",
]));

	set("outdoors","datong");

	setup();
	replace_program(ROOM);
}
