// Room: /d/jinghai/shulin1.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���������С�


LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"houmen",
  "northeast" : __DIR__"xuanya",
]));
        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
