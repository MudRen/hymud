//1997-3-10 by qyz
#include <room.h>

inherit ROOM;



void create()
{
        set("short","庭院");
        set("long",@LONG
这里是一个庭院，院内香樟成林，古木参天，浓荫郁绿，中间一条石甬道，
古朴典雅，甬道中有一古井，名为灵泉井，传说是前辈先师白玉蟾奉天师法旨所
开。大院西墙下立着一块石碑，由于年代已久，上面的字迹已经看不清楚了，院
里还栽了一棵九里香，虬枝劲干，叶茂花盛，不时发出一阵阵淡淡的清香。
LONG);
        set("exits",
        ([
          "south" : __DIR__"shanmen",
          "north" : __DIR__"zhaohe_tang",
        ]));
        set("need_clean", "崆峒派");
        set("outdoors","kongdong");
        create_door("south","红漆木门","north",DOOR_CLOSED);
        set("objects",([
                __DIR__"npc/ke" : 2,
                __DIR__"npc/zl1" : 1,
                	__DIR__"npc/zl2" : 1,
                		__DIR__"npc/zl3" : 1,
                			__DIR__"npc/zl4" : 1,
                				__DIR__"npc/zl5" : 1,	
                ]) );
        setup();
 
}
