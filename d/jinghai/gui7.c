// Room: /d/jinghai/gui7.c

inherit ROOM;

void create()
{
	set("short", "ľ��");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southup" : __DIR__"gui9",
  "north" : __DIR__"gui6",
]));

	setup();
	replace_program(ROOM);
}
