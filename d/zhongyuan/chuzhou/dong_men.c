// 楚州东门 /d/city/chuzhou/dong_men.c 
// by lala 1997-12-03

inherit ROOM;
#include <ansi.h>
#include <men.h>

void create()
{
    set("short", CYN"楚州东门"NOR);
    set("long", @LONG
楚州位于南北大运河同淮水的交汇处，因而位置十分重要，每年都有无数的
商贾乘船来到这里，楚州作为真楚运河的北端起点很快就发展成为一个重要的商
业城市。这里是城市的东门，比起其它的城门，这里进出城的人要少得多，因为
出了东门没有什么重要的城市，只有些海边的小渔村，偶尔有些贩私货的商人到
渔村去雇船下海，这比从城里码头上雇官船方便得多，而且不会受到检查，不过
因为渔船一般比较小，出远海是很危险的。城门口有几个士兵在站岗，但是显得
十分松懈，大概是因为江淮一带久无战乱的缘故。门洞里贴着张榜文，几个闲汉
正在围观。
LONG
    );
    set("outdoors", "yangzhou");
    set("no_kill",  "yangzhou");
    set("exits", ([
        "east"     :  "/d/zhongyuan/tulu",
        "west"     :  __DIR__"yanxing_jie",
    ]) );
    set("objects", ([
        __DIR__"npc/xiaowei"    :   2,
        __DIR__"npc/shibing1"   :   1,
        __DIR__"npc/shibing2"   :   1,
    ]) );

    
    setup();
}
                               
int valid_leave( object me, string dir )
{
    if( me->query("no_leave_chuzhou")
    && dir == "east" )
        return notify_fail("你现在不能离开楚州。\n");
    return ::valid_leave( me, dir );
}
