// Room: /open/dt/huaandao1.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ���Ƚ�ƫ�ܵ�С����·��������һ�Ű��������ߴ��
����ʹ����·�Եø��ӵ���խ������һ���ľ���Զ�ĸо���·��
������ɫ�Ҵң������кܶ����µ����ӡ����߲�Զ������̹��
·��������һ�ҳ��ׯ�������Ǻͼ�Ǯׯ��
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"tanhuanglu1",
  "east" : __DIR__"huaandao2",
  "south" : __DIR__"hejiqianzhuang",
  "north" : __DIR__"chouduanzhuang",
]));

	set("outdoors","datong");

	setup();
	replace_program(ROOM);
}
