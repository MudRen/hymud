// Room: /d/lumaji/lu8.c

inherit ROOM;

void create()
{
	set("short", "��ʯС��");
	set("long", @LONG
����һ����ʯС·��·�����������˲��١�ǰ�治Զ������
����꣬����һ��С��ջ��������һ�����á�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"lu9",
  "north" : __DIR__"lu7",
  "south" : __DIR__"shutang",
]));
	set("outdoors", "lumaji");
	setup();
	replace_program(ROOM);
}
