
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��������ͬ�ϱ����ǳ����������һ���֡��ֵ�֮������
�ҷ紵�������궼Ʈ����һ���ɳ�����ֵ����Ե��̼����ƺ���
��ϰ�������ֶ��ӵ���������������ķ�ɳ��û�з������Ǿ�Ӫ
�Ÿ��Ե����⣬·���洦�ɼ�������װ������������ˡ�·����
�Ǵ�ͬ��������Ӫ������פ���Ķ��Ǵ󽫾���������µľ�����
LONG
	);
	set("exits", ([

 /* sizeof() == 3 */
  "west" : __DIR__"shouweiying",
  "south" : __DIR__"jinyangjie2",
  "north" : __DIR__"beimen",
]));
	set("objects",([
	"/clone/npc/man" : 2,
]));
	set("outdoors","datong");

	setup();


	replace_program(ROOM);
}
