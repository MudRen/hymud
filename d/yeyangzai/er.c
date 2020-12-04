// Room: /open/stst/sazai/er.c

inherit ROOM;

void create()
{
        set("short", "二寨主卧室");
        set("long", @LONG
        这是二寨主卧室，墙上挂着一把奇形大刀，看来非常锋利。书架上
摆着一些红货，可能是二寨主刚从外面抢来的。

LONG

        );
        set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"dating",
]));

	set("objects",([
		"/clone/money/gold":1,
		"/d/qianjin/npc/funu":2,	
]));

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

