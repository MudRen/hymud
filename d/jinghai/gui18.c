// Room: /d/jinghai/gui18.c

inherit ROOM;

void create()
{
	set("short", "ɽ����");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southdown" : __DIR__"gui2",
]));

	setup();
	replace_program(ROOM);
}
