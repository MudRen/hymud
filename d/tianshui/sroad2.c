// Room: /d/tianshui/sroad2.c

inherit ROOM;

void create()
{
	set("short", "С���Ͻ�");
	set("long", @LONG
�������Ͻ֣��������С�������㳡��ÿ��ϼ������ӣ�
��������ַǷ�����������һ�����׸������ļҡ��ſ�������
��ʯʨ�ӣ�һ���������ɡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"sroad1",
  "east" : __DIR__"caizhu1",
  "south" : __DIR__"skou",
  "west" : __DIR__"business",
]));

	set("outdoors","tianshui");

	set("objects",([
"/clone/npc/man" : 2,
]));

	setup();
	replace_program(ROOM);
}
