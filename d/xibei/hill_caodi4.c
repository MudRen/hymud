#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short","山坡草地");
    set("long",@LONG
进入蕃地，四周都是起伏不大的小山，山坡上青草依依，牛羊散处其间，不
可胜数。放牧的人都穿着稀奇古怪的衣服，说起话来也全然不通。这里气候高爽
，土地广阔，漫步在山坡间，说不清到底该往哪儿走才是；信步而走，倒也落得
轻松自在，可要是急着赶路，还是找个向导，或是附在商队中行走才好。
LONG);
    set("exits",([
        "north"   : __DIR__"hill_caodi4",
        "west"    : __DIR__"hill_caodi4",
        "east"    : __DIR__"hill_caodi3",
        "south"   : __DIR__"hill_caodi5",
         
    ]));
    set("outdoors","xibei");
    setup();
}

