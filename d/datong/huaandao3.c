// Room: /open/dt/huaandao3.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ���Ƚ�ƫ�ܵ�С����·��������һ�Ű��������ߴ��
����ʹ����·�Եø��ӵ���խ������һ���ľ���Զ�ĸо���·��
������ɫ�Ҵң������кܶ����µ����ӡ�������һ�Ҷ�������
������һ�����ϵ����á�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"huaandao2",
  "east" : __DIR__"kongzici",
  "south" : __DIR__"doufufang",
]));

	set("outdoors","datong");

	setup();
	replace_program(ROOM);
}
