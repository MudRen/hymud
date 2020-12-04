//road6.c.宣平坊
//date:1997.8.26
//by dan 

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",YEL"宣平坊"NOR);
    set("long",@LONG
这里是宣平坊。周围大都是店铺，人来人往，热闹非常。远处可见金壁辉煌
的宫殿和高耸的承天寺塔。由于又要打仗，驿道上负责治安的马鹞军加紧对来往
客商的盘查，以防有细作混入，千万别招惹他们。这里是兴庆府的民间商业区, 
在紧靠皇宫处有西夏官方作坊。路东面是一家药铺，据说是兰州老字号分店，路
西则是全城最大的商号.
LONG);
   
    set("exits",([
        "south"   : __DIR__"road20",
        "north"   : __DIR__"road5",  
        "east"    : __DIR__"yaopu",
        "west"    : __DIR__"shanghao",
    ])); 
    
    set("outdoors","xingqing");
    setup();
}

