// Room: /d/paiyun/ta1.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�ֲڵ���ľ�����������һ����ª��ľ��ͨ����һ�㡣
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"lu1",
  "up" : __DIR__"ta1up",	
]));
	set("outdoors", "paiyun");
	setup();
	replace_program(ROOM);
}
