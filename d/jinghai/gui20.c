// Room: /d/jinghai/gui20.c

inherit ROOM;

void create()
{
	set("short", "����С·");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"gui19",
  "southeast" : __DIR__"gui11",
]));

	setup();
	replace_program(ROOM);
}
