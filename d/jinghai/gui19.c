// Room: /d/jinghai/gui19.c

inherit ROOM;

void create()
{
	set("short", "����С·");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"gui20",
  "north" : __DIR__"gui1",
]));

	setup();
	replace_program(ROOM);
}
