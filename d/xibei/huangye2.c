#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short","荒野");
    set("long",@LONG
一片荒无人烟的土地，脚下是碎石和黄土，石缝中长着些低矮的小草。南北
地平线处都有一些绵延起伏的山脉，东南面是黄河，渡过黄河就是兰州城。天上
不时有几只野雁飞过，除此以外，四周了无生迹；野风吹过，越发显得凄凉。
LONG);
    set("exits",([
        "east"   : __DIR__"huangye1",
        "southeast"   : __DIR__"huangye1",
        "north"   : __DIR__"huangye2",
        "west"  : __DIR__"lianglu1",
    ]));
    set("outdoors","xibei");
    setup();
}

