// Room: /d/jinghai/gui6.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣


LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "eastup" : __DIR__"gui8",
  "south" : __DIR__"gui7",
  "west" : __DIR__"gui5",
]));

	setup();
	replace_program(ROOM);
}
