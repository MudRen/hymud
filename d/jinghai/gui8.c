// Room: /d/jinghai/gui8.c

inherit ROOM;

void create()
{
	set("short", "ɽ����");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "westdown" : __DIR__"gui6",
]));

	setup();
	replace_program(ROOM);
}
