// Room: /d/lumaji/lu9.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
����һ����·��һЩũ��������·�ϲ�һЩˮ�����������
��������̫��ĳ�����
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"lu8",
  "east" : __DIR__"lu10",
]));
	set("outdoors", "lumaji");
	setup();
	replace_program(ROOM);
}
