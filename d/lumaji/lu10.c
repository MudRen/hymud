// Room: /d/lumaji/lu10.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
����һ��·�ڣ���һ�����ϵ�С·ͨ����⡣·������һЩ
����������������������������һ�����̡�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"s_kou",
  "west" : __DIR__"lu9",
  "east" : __DIR__"lu11",
  "north" : __DIR__"roupu",
]));
	set("objects", ([
		"/clone/npc/man" : 2,
	]));
	set("outdoors", "lumaji");
	setup();
	replace_program(ROOM);
}
