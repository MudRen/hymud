//road15.c.顺成坊
//date:1997.8.26
//by dan 

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",YEL"顺成坊"NOR);
    set("long",@LONG
这里是顺成坊。周围大多是平民住宅，及一些店铺，人来人往，热闹非常。
远处可见金壁辉煌的宫殿和高耸的承天寺塔。由于又要打仗，驿道上负责治安的
马鹞军加紧对来往客商的盘查，以防有细作混入，千万别招惹他们。
LONG);
   
    set("exits",([
        "east"    : __DIR__"road14",
        "west"    : __DIR__"road16",
    ]));
    set("outdoors","xingqing");
    setup();
}

