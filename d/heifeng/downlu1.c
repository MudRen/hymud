// Room: /d/heifeng/downlu1.c

inherit ROOM;

void create()
{
	set("short", "��ɽС·");
	set("long", @LONG
����һ��ͨ��ɽ��С·��
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "westup" : __DIR__"shanding",
]));

	setup();
	replace_program(ROOM);
}
