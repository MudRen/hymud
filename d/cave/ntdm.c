 // Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", "南天东门");
        set("long", @LONG
一人多高的紫蘑菇一大片，这种植物的表皮极硬，而且特别
的粗糙。这条路几乎就是从蘑林中砍出来的，路面虽然不宽，但
可以看出造这路一定花了很大的功夫。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"ntdl",
  "south" : __DIR__"dnj",
]));
        set("indoors", "cave");
        set("coor/x",-30);
        set("coor/y",-22);
        set("coor/z",-20);
//        set("objects", ([
     //   __DIR__"npc/fishseller": 1,
//      __DIR__"npc/fishbuyer": 1,
//                        ]) );
        setup(); 
}  
