// Room: /d/tianshui/sroad1.c

inherit ROOM;

void create()
{
	set("short", "С���Ͻ�");
	set("long", @LONG
�������Ͻ֣��������С�������㳡��ÿ��ϼ������ӣ�
��������ַǷ���������Ϸ̨��������һ�Ҳ�ݣ����ֺ��е���
������Ȳ����졣
LONG
	);
	set("outdoors", "tianshui");
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"cross",
  "west" : __DIR__"xitai",
  "south" : __DIR__"sroad2",
  "east" : __DIR__"chaguan",
]));

	setup();
	replace_program(ROOM);
}
