// Room: /d/tianshui/eroad3.c

inherit ROOM;

void create()
{
	set("short", "С�򶫽�");
	set("long", @LONG
�����ֵ�����������������ǻ���������������������ܶ���
�����ߵĹ㳡��ȥ��������һ���ӻ��̣�������һ��ҩ��������
����������������ץҩ��
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"zahuopu",
  "west" : __DIR__"eroad2",
  "south" : __DIR__"yaopu",
  "east" : __DIR__"ekou",
]));
	set("outdoors","tianshui");

	set("objects",([
"/clone/npc/man" : 2,
]));

	setup();
	replace_program(ROOM);
}
