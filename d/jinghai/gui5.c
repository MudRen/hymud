// Room: /d/jinghai/gui5.c

inherit ROOM;

void create()
{
	set("short", "Ժ�����");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 6 */
  "north" : __DIR__"gui17",
  "northwest" : __DIR__"gui16",
  "east" : __DIR__"gui6",
  "northeast" : __DIR__"gui15",
  "south" : __DIR__"gui14",
  "west" : __DIR__"gui4",
]));

	setup();
	replace_program(ROOM);
}
