//road9.c.惠和坊
//date:1997.8.26
//by dan 

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",YEL"惠和坊"NOR);
    set("long",@LONG
这里是惠和坊。周围大多是平民住宅，及一些店铺，人来人往，热闹非常。
往东便是景平坊，据说在景平坊那边就是西夏的一品堂总舵所在，这里的也常有
武士来往，经常有斗殴事件发生。由于又要打仗，驿道上负责治安的马鹞军加紧
对来往客商的盘查，以防有细作混入，千万别招惹他们。
LONG);
   
    set("exits",([
        "east"    : __DIR__"road10",
        "west"    : __DIR__"road8",
    ]));
    set("outdoors","xingqing");
    setup();
}

