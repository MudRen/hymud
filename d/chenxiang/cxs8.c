 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "乡间小路");
        set("long", @LONG
往北是沉香城南门，往南是沼泽边缘，很多英雄好汉从这里
再往南走就再也没有回来了。除非你武艺高强，最后不要再往南
走了。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"cxs7",
  "south" : "/d/zhaoze/edge",
]));
        set("outdoors", "chenxiang");
        set("coor/x",-500);
        set("coor/y",-590);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}  
