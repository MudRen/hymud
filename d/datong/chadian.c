// Room: /open/dt/chadian.c

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
����һ��СС��ꡣ��Ϊ��ͬ���������䣬��������Ŀ���
���Ǻܶ࣬������ļ��������ϻ���һ�㱡���Ļ�ɳ��һ������
���׺���������������۾������α���Ʒ�裬���������������
����Ը��վ�����������ǲ������ݺ��衣
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"hongchanglu2",
]));

	setup();
	replace_program(ROOM);
}
