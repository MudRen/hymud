// Room: /open/dt/huaandao2.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ���Ƚ�ƫ�ܵ�С����·��������һ�Ű��������ߴ��
����ʹ����·�Եø��ӵ���խ������һ���ľ���Զ�ĸо���·��
������ɫ�Ҵң������кܶ����µ����ӡ�������Ѳ��ͷ�����
���ļң�������һ�ҵ��̡�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"huaandao1",
  "east" : __DIR__"huaandao3",
  "south" : __DIR__"dangpu",
  "north" : __DIR__"lihongsanjia",
]));

	set("outdoors","datong");

	setup();
	replace_program(ROOM);
}
