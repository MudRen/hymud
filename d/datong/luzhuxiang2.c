// Room: /open/dt/luzhuxiang2.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����С���Լ���߳߶����������Ҳû���������ӣ���֮
���Խ�����������Ϊ����ԭ����һƬ���֣����ڵ�����С������
�е�С�����������ֱ���˵��̣�С��Ҳ�ͱ��С���ˣ�����ͬ
��Ϊ���ú���֪��ԭ�����ﻹ��Ƭ���֣��Ͱ�����С���������
���ˡ��������ٸ��ң����������мҡ�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"luzhuxiang1",
  "east" : __DIR__"luzhuxiang3",
  "south" : __DIR__"langzhongjia",
  "north" : __DIR__"shaofujia",
]));

	set("outdoors","datong");

	set("objects",([
	"/clone/npc/man" : 3,
]));

	setup();
	replace_program(ROOM);
}
