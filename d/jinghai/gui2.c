// Room: /d/jinghai/gui2.c

inherit ROOM;

void create()
{
	set("short", "С��·");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "northup" : __DIR__"gui18",
  "east" : __DIR__"gui3",
  "west" : __DIR__"gui1",
]));

	setup();
	replace_program(ROOM);
}
