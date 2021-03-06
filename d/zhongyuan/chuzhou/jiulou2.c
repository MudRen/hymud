// 楚州镇淮楼楼上 /d/city/chuzhou/jiulou2.c
// by lala, 1997-12-10
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
    镇淮楼楼下是交通路口，楼上才是客人的雅座，小二站在楼梯口大声的招呼
客人。    
LONG
    );
    set("no_kill",  "yangzhou");
    set("exits", ([
        "down"        : __DIR__"jiulou",
        ]));
    set("objects", ([
        __DIR__"npc/xiaoer2"    :   1,
    ]));        
    setup();
}
