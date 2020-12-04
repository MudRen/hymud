// majiu.c
// by dicky

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", YEL"马厩"NOR);
        set("long", @LONG
这是客栈对面的马厩，常年供应新鲜草料。客人只要住店，马夫们就
会把马牵到马厩好生照看，将它们喂饱饮足，再洗刷得干乾净净。一直伺
候到客人离店上路。马厩中堆放著几堆草料，正中有一口泔槽。
LONG
        );

	set("outdoors", "houjizhen");

       set("objects", ([
		__DIR__"obj/r_horse" : 2,
		__DIR__"obj/q_horse" : 2,
		__DIR__"npc/mafu" : 1,

        ]));

        set("exits", ([ 
		"north" : __DIR__"shilu1",
        ]));

        set("resource/water",1);
        set("cost",1);

        setup();
        replace_program(ROOM);
}
