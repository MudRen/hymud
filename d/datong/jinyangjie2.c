// Room: /open/dt/jinyangjie2.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��������ͬ�ϱ����ǳ����������һ���֡��ֵ�֮������
�ҷ紵�������궼Ʈ����һ���ɳ�����ֵ����Ե��̼����ƺ���
��ϰ�������ֶ��ӵ���������������ķ�ɳ��û�з������Ǿ�Ӫ
�Ÿ��Ե����⣬·���洦�ɼ�������װ������������ˡ�·����
��һ��ˮ���꣬���������������Ĵ�ͬ���ߵꡣ
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"shuiguodian",
  "east" : __DIR__"fangjudian",
  "south" : __DIR__"shizilukou",
  "north" : __DIR__"jinyangjie1",
]));

	set("outdoors","datong");

	setup();
	replace_program(ROOM);
}
