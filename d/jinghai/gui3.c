// Room: /d/jinghai/gui3.c

inherit ROOM;

void create()
{
	set("short", "�����׻��ô���");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"gui4",
  "west" : __DIR__"gui2",
]));

	setup();
	replace_program(ROOM);
}
