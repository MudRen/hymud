// Room: /d/jinghai/gui4.c

inherit ROOM;

void create()
{
	set("short", "Ժ�����");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"gui12",
  "east" : __DIR__"gui5",
  "south" : __DIR__"gui13",
  "west" : __DIR__"gui3",
]));

	setup();
	replace_program(ROOM);
}
