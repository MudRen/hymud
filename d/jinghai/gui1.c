// Room: /d/jinghai/gui1.c

inherit ROOM;

void create()
{
	set("short", "������ͷ");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"gui2",
  "south" : __DIR__"gui19",
]));

	setup();
	replace_program(ROOM);
}
