
inherit ROOM;

void create()
{
	set("short", "��ͬ��������");
	set("long", @LONG
������Ǵ�ͬ�����������ˣ��ߴ����ϵ�����¥���������
��ǰ��һ�ӹٱ���������Ĳ�����������߹���������������ס
һ������������ʲô��
LONG
	);

	set("exits", ([

  "north" : __DIR__"nanmen",
   "south" : "/d/huanghe/huanghe_3",
]));
	set("objects",([
	"/d/city/npc/bing" : 3,
]));
	set("outdoors","datong");

	setup();


	replace_program(ROOM);
}
