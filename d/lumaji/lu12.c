// Room: /d/lumaji/lu12.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
����һ�����С·��·��������ũ�һЩũ�����������
�����·���Ĵ����˼����㶼���������ʺã�������Ϊ������
���˶��е�İ����
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"lu14",
  "southwest" : __DIR__"lu11",
  "north" : __DIR__"lu13",
]));
	set("outdoors", "lumaji");
	setup();
	replace_program(ROOM);
}
