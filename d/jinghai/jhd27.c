// Room: /d/jinghai/jhd27.c

inherit ROOM;

void create()
{
	set("short", "山冈上");
	set("long", @LONG
这是山冈上。

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "northeast" : __DIR__"jhd6",
]));
        set("outdoors", "jinghai");

	setup();
	replace_program(ROOM);
}
