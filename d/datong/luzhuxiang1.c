// Room: /open/dt/luzhuxiang1.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����С���Լ���߳߶����������Ҳû���������ӣ���֮
���Խ�����������Ϊ����ԭ����һƬ���֣����ڵ�����С������
�е�С�����������ֱ���˵��̣�С��Ҳ�ͱ��С���ˣ�����ͬ
��Ϊ���ú���֪��ԭ�����ﻹ��Ƭ���֣��Ͱ�����С���������
���ˡ�������һ����ӡ�
LONG
	);
	set("exits", ([
  "east" : __DIR__"luzhuxiang2",
  "north" : __DIR__"minju1",
]));

	set("outdoors","datong");

	setup();
	replace_program(ROOM);
}
