

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��������ͬ�ϱ����ǳ����������һ���֡��ֵ�֮������
�ҷ紵�������궼Ʈ����һ���ɳ�����ֵ����Ե��̼����ƺ���
��ϰ�������ֶ��ӵ���������������ķ�ɳ��û�з������Ǿ�Ӫ
�Ÿ��Ե����⣬·���洦�ɼ�������װ������������ˡ�·�ϱ�
������̳��������ǻ���·��
LONG
	);
	set("exits", ([

  "east" : __DIR__"huayanlu1",
  "south" : __DIR__"xftrain",
  "north" : __DIR__"jinyangjie5",
]));

	set("outdoors","datong");

	set("objects",([
	"/clone/npc/man" : 2,
__DIR__"npc/bian_laoren" : 1,]));

	setup();


	replace_program(ROOM);
}
