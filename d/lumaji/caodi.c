// Room: /d/lumaji/caodi.c

inherit ROOM;

void create()
{
	set("short", "�ݵ�");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"lu4",
]));
	set("outdoors", "lumaji");
	setup();
	replace_program(ROOM);
}