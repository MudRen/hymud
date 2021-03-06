// 楚州码头 /d/city/chuzhou/matou.c
// by lala, 1997-12-13

inherit ROOM;
#include <ansi.h>
#include <men.h>

void create()
{
    set("short", CYN"码头"NOR );
    set("long", @LONG
这里是楚州的运河码头，是这个城市最繁忙最热闹的地方。不时有大大小小
的客货船只靠岸，大量的货物和商人、旅客在这里上下船只。许多商贩在趁机叫
卖自己的货物，几个士兵在这里巡逻，懒洋洋的看着这繁忙的景象。向东就进了
城了。码头的墙上也贴着张榜文，但是谁也没有站下来看它。
LONG
    );
    set("exits", ([
        "east"      : __DIR__"xishi",
        ]));
    set("objects", ([
        __DIR__"npc/xiaowei"    :   2,
        __DIR__"npc/shibing1"   :   1,
        __DIR__"npc/shibing2"   :   1,
        __DIR__"npc/kuli"       :   3,
    ]) );

    set( "outdoors", "yangzhou" );       
    set( "no_kill",  "yangzhou" );
    setup();
}
