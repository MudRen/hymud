// Room: /d/jinghai/gui16.c

inherit ROOM;

void create()
{
	set("short", "�鷿");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southeast" : __DIR__"gui5",
]));

	setup();
	replace_program(ROOM);
}
