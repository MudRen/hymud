// Room: /open/dt/jinyangjie3.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��������ͬ�ϱ����ǳ����������һ���֡��ֵ�֮������
�ҷ紵�������궼Ʈ����һ���ɳ�����ֵ����Ե��̼����ƺ���
��ϰ�������ֶ��ӵ���������������ķ�ɳ��û�з������Ǿ�Ӫ
�Ÿ��Ե����⣬·���洦�ɼ�������װ������������ˡ�·����
�Ǵ�ͬ����Ѳ�����š�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"yamen",
  "south" : __DIR__"jinyangjie4",
  "north" : __DIR__"shizilukou",
]));

	set("outdoors","datong");

	setup();
	replace_program(ROOM);
}
