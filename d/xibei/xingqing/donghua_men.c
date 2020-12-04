//donghua_men.c.东化门
//date:1997.8.26
//by dan 

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",YEL"东化门外"NOR);
    set("long",@LONG
这是兴庆府的东门，向西的大路直通兴庆府中心广场。自李德明迁都到这里，
谴官筹划经营，扩建城池，构筑门阙宫殿及宗社坛庙，兴庆府已具规模，与宋汴
京、辽上京鼎足而立. 城门口人来人往，不时有商人经过。东门内不远便是高台
寺，西夏都城整体呈人字形，这里恰好是头部。往东过黄河，便是中原了。
    往城外看，不远处就是黄河西岸.            
LONG);
    set("exits",([
        "west"   : __DIR__"door3",
    ]));
    set("objects", ([
          __DIR__"npc/bing1" : 3,
    ]) ); 
    set("outdoors","xingqing");
    setup();
}

