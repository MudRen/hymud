// Room: /d/jinghai/xiaolu1.c

inherit ROOM;

void create()
{
	set("short", "����С·");
	set("long", @LONG
��������С·��


LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"xiuxishi",
  "southeast" : __DIR__"lukou",
]));
        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
