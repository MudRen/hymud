// Room: /d/jinghai/gui10.c

inherit ROOM;

void create()
{
	set("short", "����ͷ");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"gui9",
]));

	setup();
	replace_program(ROOM);
}
