// Room: /d/tianshui/eroad2.c

inherit ROOM;

void create()
{
	set("short", "С�򶫽�");
	set("long", @LONG
�����ֵ�����������������ǻ���������������������ܶ���
�����ߵĹ㳡��ȥ��������һ���ھ֣��ſ���������ʯʨ�ӡ���
����һ�������̣���ʱ�������������Ĵ�������
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"biaoju",
  "south" : __DIR__"tiejiangpu",
  "west" : __DIR__"eroad1",
  "east" : __DIR__"eroad3",
]));
	set("objects",([
	__DIR__"npc/cleaner" : 1,
]));
	set("outdoors","tianshui");
	setup();
	replace_program(ROOM);
}
