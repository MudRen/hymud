// 楚州西市 /d/city/chuzhou/xishi.c
// by lala, 1997-12-04

inherit ROOM;
#include <ansi.h>

void create()
{
    set("short", GRN"西市"NOR );
    set("long", @LONG
西市是楚州城里最主要的市场，这是因为楚州是水路交通要道，码头对于这
个城市至关重要，大批的客商和货物都是从水路来的，其中包括从新罗来的商人。
他们有的是贩卖新罗的特产，有的是贩卖从日本等国收购来的货物，冒着漂洋过
海的巨大危险以赚取厚利，这些新罗商人居住在市场南面的“新罗坊”，他们也
在那里做生意。市场的北面是条名叫驸马巷的小巷。西面就是运河码头了。
LONG
    );
    set("exits", ([
        "north"     : __DIR__"fuma_xiang",
        "west"      : __DIR__"matou", 
        "east"      : __DIR__"jiulou",
        "south"     : __DIR__"xinluo_fang",
        ]));
    set("objects", ([
        __DIR__"npc/xunbu"  :   1,
        __DIR__"npc/west_seller" + random(3)  : 1,
        __DIR__"npc/north_seller" + random(4) : 1,
        __DIR__"npc/south_seller" + random(5) : 1,
    ]));        
    set( "outdoors", "yangzhou" );       
    set( "no_kill",  "yangzhou" );
    setup();
}
