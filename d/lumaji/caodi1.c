// Room: /d/lumaji/caodi1.c

inherit ROOM;

void create()
{
	set("short", "��ݵ�");
	set("long", @LONG
����һƬ���̵Ĳݵأ�һֻ���������������ȥ��������ȥ
��һƬï�ܵ�Сɭ�֡�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"lu4",
  "east" : __DIR__"caodi2",
]));
	set("outdoors", "lumaji");
	setup();
	replace_program(ROOM);
}
