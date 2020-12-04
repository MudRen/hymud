//road17.c.顺成坊
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
马鹞军加紧对来往客商的盘查，以防有细作混入，千万别招惹他们。南面就是平
民区，由于常年征战，所以西夏的百姓生活很苦.....
LONG);
   
    set("exits",([
        "south"   : __DIR__"room2",
        "east"    : __DIR__"road16",
        "west"    : __DIR__"road18",
    ]));
    set("objects",([
         __DIR__"npc/keshang" : 1,
    ]));
    set("outdoors","xingqing");
    setup();
}

