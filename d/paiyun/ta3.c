// Room: /d/paiyun/ta3.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�ֲڵ���ľ�����������һ����ª��ľ��ͨ����һ�㡣
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"lu5",
  "up" : __DIR__"ta3up",	
]));
	set("outdoors", "paiyun");
	setup();
	replace_program(ROOM);
}
