// Room: /d/jinghai/jhd4.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���������С�

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southwest" : __DIR__"jhd3",
]));
        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
