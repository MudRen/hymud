// Room: /d/tianshui/eroad1.c

inherit ROOM;

void create()
{
	set("short", "С�򶫽�");
	set("long", @LONG
�����ֵ�����������������ǻ���������������������ܶ���
�����ߵĹ㳡��ȥ��������һ�ҿ�ջ���������˽�������������
������ܺá�������һ��Ǯׯ��
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"kezhan",
  "west" : __DIR__"cross",
  "south" : __DIR__"yinhao",
  "east" : __DIR__"eroad2",
]));
	set("outdoors","tianshui");
	setup();
	replace_program(ROOM);
}
