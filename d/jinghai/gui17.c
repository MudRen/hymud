// Room: /d/jinghai/gui17.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"gui5",
]));

	setup();
	replace_program(ROOM);
}
