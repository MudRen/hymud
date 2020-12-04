#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short","天池外");
    set("long",@LONG
这里已经是高原中腹，气候愈加清爽，四周少有山丘，放眼可一直望到天边
，广阔无垠的大草原上散落着无数晶莹的湖泊，象是满天的星星；有的很大，也
有的方圆还不足十丈。最大的两个方圆百里，湖水湛蓝，深不见底，被当地人称
为“天池”，传说湖底居住着龙怪神仙。湖边到处是吃草的牛羊，有些是牧民养
的，也有的是野生的。身处这样的环境，令人心旷神怡，不禁怀疑自己是在做梦
了。
LONG);
    set("exits",([
         "west" : __DIR__"xingxiu_hai",
         "east" : __DIR__"tianchi2",
    ]));
    set("objects",([
         __DIR__"npc/maoniu0" : 2,
         __DIR__"npc/goat2"   : 1,
    ]));
    set("outdoors","xibei");
    setup();
}

