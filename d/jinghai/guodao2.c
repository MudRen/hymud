// Room: /d/jinghai/guodao2.c

inherit ROOM;

void create()
{
	set("short", "��Ժ����");
	set("long", @LONG
���Ǻ�Ժ������


LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"dating",
  "east" : __DIR__"laofang",
]));
	set("outdoors", "jinghai");

	setup();
	replace_program(ROOM);
}
