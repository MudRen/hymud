// Room: /d/lumaji/juan.c

inherit ROOM;

void create()
{
	set("short", "��Ȧ");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"yuan",
]));
	set("outdoors", "lumaji");
	setup();
	replace_program(ROOM);
}
