// Room: /d/jinghai/gui9.c

inherit ROOM;

void create()
{
	set("short", "��ɽ����ͷ");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "northdown" : __DIR__"gui7",
  "east" : __DIR__"gui10",
  "west" : __DIR__"gui11",
]));

	setup();
	replace_program(ROOM);
}
