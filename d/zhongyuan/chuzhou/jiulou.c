// 楚州镇淮楼 /d/city/chuzhou/jiulou.c
// by lala, 1997-12-04
inherit ROOM;

#include <ansi.h>

void create()
{
    set("short", MAG"镇淮楼"NOR);
    set("long", @LONG
这是全楚州城最大也是最有名的酒楼。原本叫做“镇江都统司酒楼”的，后
来改成现在的名字，含有“镇慑淮水”之意。无论初一还是十五，这里的生意总
是红火的不行。这家酒楼请的都是楚州城内一流的厨子，会做各地的风味菜，当
然还以淮扬菜最为著名，入口清香，余味无穷。吃这样的菜实为人生一大享受。
    镇淮楼地处楚州城的中心，周围是楚州四个市场中的三个：北市、西市和东
市。作为楚州城的交通要道，镇淮楼周围是拥挤喧闹不堪。
LONG
    );
    set("no_kill",  "yangzhou");
    set("outdoors", "chuzhou");
    set("exits", ([
        "west"      : __DIR__"xishi",
        "northeast" : __DIR__"beishi",
        "southeast" : __DIR__"dongshi",
        "up"        : __DIR__"jiulou2",
        ]));
    set("objects", ([
        __DIR__"npc/zuihan" :   1,
    ]));        
    setup();
}
