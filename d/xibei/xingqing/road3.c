//road3.c.御道
//date:1997.8.26
//by dan

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",YEL"御道"NOR);
    set("long",@LONG
这里是御道。周围大多是官府宅第，及一些官家作坊，人来人往，热闹非常。
远处可见金壁辉煌的宫殿和高耸的承天寺塔。正南方就是皇宫。御道上戒备森严，
到处都是皇家侍卫军。没事你最好别到这里来。东西分别是工技院和文思院。
LONG);
   
    set("exits",([
        "east"    : __DIR__"yuan1",
        "west"    : __DIR__"yuan2",
        "south"   : __DIR__"road4",
        "north"   : __DIR__"road2",
    ]));  
    set("objects", ([
          __DIR__"npc/bing3" : 1,
    ]) );
    set("outdoors","xingqing");
    setup();
}

