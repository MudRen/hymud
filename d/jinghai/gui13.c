// Room: /d/jinghai/gui13.c

inherit ROOM;

void create()
{
	set("short", "������Ϣ��");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"gui4",
]));

	setup();
	replace_program(ROOM);
}
