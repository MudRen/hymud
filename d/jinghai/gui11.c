// Room: /d/jinghai/gui11.c

inherit ROOM;

void create()
{
	set("short", "����ͷ");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"gui20",
  "east" : __DIR__"gui9",
]));

	setup();
	replace_program(ROOM);
}
