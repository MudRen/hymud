// Room: /open/dt/luzhuxiang3.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����С���Լ���߳߶����������Ҳû���������ӣ���֮
���Խ�����������Ϊ����ԭ����һƬ���֣����ڵ�����С������
�е�С�����������ֱ���˵��̣�С��Ҳ�ͱ��С���ˣ�����ͬ
��Ϊ���ú���֪��ԭ�����ﻹ��Ƭ���֣��Ͱ�����С���������
���ˡ�������һ����ӣ����治Զ���ǽ����֡�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"luzhuxiang2",
  "east" : __DIR__"jinyangjie4",
  "north" : __DIR__"minju2",
]));

	set("outdoors","datong");

	setup();
	replace_program(ROOM);
}
