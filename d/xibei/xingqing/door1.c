//door1.c.皇宫
//date:1997.8.26
//by dan 

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",YEL"皇宫"NOR);
    set("long",@LONG
面前是西夏皇宫，中书省，枢密院，三司等中央行政衙署均设在宫城内。整
个皇宫与元昊宫连成一片，金壁辉煌的宫殿建筑群与平民居住的低矮土屋形成鲜
明对比。宫门关闭，有侍卫把守，戒备森严。
LONG);
    set("exits",([
         "south"  : __DIR__"road1",
         "north"  : __DIR__"huanggong",
         "west"   : __DIR__"wall7",
         "east"   : __DIR__"wall1",
    ]));
    set("objects", ([
          __DIR__"npc/bing3" : 3,
    ]) ); 
    set("outdoors","xingqing");
    setup();
}

