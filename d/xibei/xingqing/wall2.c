//wall2.c.宫墙
//date:1997.8.26
//by dan 

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",YEL"宫墙"NOR);
    set("long",@LONG
黄墙内是西夏皇宫，中书省，枢密院，三司等中央行政衙署均设在宫城内。整
个皇宫与元昊宫连成一片，金壁辉煌的宫殿建筑群与平民居住的低矮土屋形成鲜
明对比。
    宫墙外有一条青石路，可直通御道.
LONG);
    set("exits",([
         "north"  : __DIR__"wall3",
         "south"  : __DIR__"wall1",
    ]));
    set("outdoors","xingqing");
    setup();
}

