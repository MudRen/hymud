//dangpu.c.当铺
//date:1997.8.28
//by dan

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", MAG"兴庆当铺"NOR);
        set("long", @LONG
这是老字号当铺，三开间的门面，写着『兴庆当铺』四个金字的黑匾，足足
七尺高的紫檀木的柜台被磨得光可照人，柜台后的朝奉头也不抬的只顾拨拉着算
盘，柜台上方挂着一块牌子，上书：你情我愿，概不赊欠。南来北往的客商想要
钱周转或存钱都到这里来。
LONG
        );
    set("exits", ([ 
                "east"  : __DIR__"road5",
        ]));
        set("dangpu_location","xingqing");

        set("objects",([
                __DIR__"npc/chaofeng" : 1,
                ]) );
        setup();
}                       


