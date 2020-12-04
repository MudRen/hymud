// Room: /open/stst/sazai/lu5.c

inherit ROOM;

void create()
{
        set("short", "休息室");
        set("long", @LONG
        这就是野羊寨的休息室。寨里的弟兄们从外面抢了红货回来后，平
时没事就在此休息，房间里乱七八糟的摆满了床。你可以在这里休息。

LONG

        );
        set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"qianting",
]));
	set("objects",([
		__DIR__"npc/xiaotong":1,
		__DIR__"npc/chick":1,	
]));

        //set("no_fight", 1);
        set("sleep_room", 1);
        setup();
        replace_program(ROOM);
}


