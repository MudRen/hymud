//road4.c.中心广场
//date:1997.8.26
//by dan 

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",YEL"中心广场"NOR);
    set("long",@LONG
这里是兴庆府的中心，南来北往的人们都经此过，平时热闹非凡，往北便是
西夏皇宫。由于要打仗了，显得冷冷清清。负责城市治安的马鹞军加紧对来往客
商的盘查，以防有细作混入，千万别招惹他们。这里连接着兴庆城的其他四大部
分，东有高台寺，西有元昊宫，南为商业区，正北则是皇城了.
LONG);
   
    set("exits",([
        "north"   : __DIR__"road3",
        "south"   : __DIR__"road5",
        "east"    : __DIR__"road7",
        "west"    : __DIR__"road14",
    ]));
    set("objects",([
            __DIR__"npc/bing2"   : 2,
            __DIR__"npc/keshang" : 1,
    ]));
    set("outdoors","xingqing");
    setup();
}

