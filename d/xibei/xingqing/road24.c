//road24.c.景平坊
//date:1997.8.26
//by dan 

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",YEL"景平坊"NOR);
    set("long",@LONG
这里是景平坊。周围大多是平民住宅，及一些店铺. 驿道上负责治安的马鹞
军加紧对来往客商的盘查，以防有细作混入，千万别招惹他们。这里的居民出奇
的少，据说这附近便是西夏一品堂总舵所在，这里来回出入的人都显得很神秘，
平时一般的百姓都不到这儿来。
LONG);
   
    set("exits",([
         "north"   : __DIR__"road25",
         "south"   : __DIR__"road23",
    ])); 
    
    set("outdoors","xingqing");
    setup();
}

