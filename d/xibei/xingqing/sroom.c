//sroom.c.客房
//date:1997.8.26
//by dan

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short","客房");
    set("long",@LONG
这里是有间客栈的客房，由于客人太多，只好把库房有用来给客人住了。隔
壁几个来往客人在高谈阔论，好象在讨论什么高昌迷宫，稀世珍宝。这屋里
有几个刚来的客人，吃完饭，已休息了。
LONG);
   
    set("exits",([
        "out"   : __DIR__"kezhan",
    ])); 
    set("sleep_room","inn");
    set("outdoors","lanzhou");
    setup();
}

