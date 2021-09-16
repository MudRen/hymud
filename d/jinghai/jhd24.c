// Room: /d/jinghai/jhd24.c

inherit ROOM;

void create()
{
	set("short", "山庄后门");
	set("long", @LONG
这是一扇不起眼的木板门，主要是供厨房的师傅们搬运菜蔬
和倾倒垃圾用的，出了门就是一条通向后山菜地的小路。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"jhd23",
]));
        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
