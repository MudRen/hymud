//road22.c.瑞应坊
//date:1997.8.26
//by dan

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",YEL"瑞应坊"NOR);
    set("long",@LONG
这里是瑞应坊。周围大多是平民住宅，及一些店铺，人来人往，热闹非常。
远处可见金壁辉煌的宫殿和高耸的承天寺塔。正南方就是元昊宫. 由于又要打仗，
驿道上负责治安的马鹞军加紧对来往客商的盘查，以防有细作混入，千万别招惹
他们。这里是马鹞军的大本营.

LONG);
   
    set("exits",([
        "south"    : __DIR__"road21",
        "north"    : __DIR__"yuanhaogong", 
        "east"     : __DIR__"bingying3",
        "west"     : __DIR__"bingying4",
    ]));
    set("outdoors","xingqing");
    setup();
}

