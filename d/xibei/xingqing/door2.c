//door2.c.南薰门
//date:1997.8.26
//by dan 

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",YEL"南薰门"NOR);
    set("long",@LONG
这是兴庆府的南门，向北的大路直通兴庆府中心广场。自李德明迁都到这里，
谴官筹划经营，扩建城池，构筑门阙宫殿及宗社坛庙，兴庆府已具规模，与宋汴
京、辽上京鼎足而立. 城门口人来人往，不时有商人经过。南门内就是兴庆府的
民间商业区－－宣平坊, 在紧靠皇宫处有西夏官方作坊。
LONG);
    set("exits",([
        "north"   : __DIR__"road20",
    ]));
    set("objects", ([
          __DIR__"npc/bing1" : 3,
    ]) ); 
    set("outdoors","xingqing");
    setup();
}

