//shanghao.c.商号
//date:1997.8.26
//by dan 

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",MAG"商号"NOR);
    set("long",@LONG
西夏设有官方的手工作坊，也一些平民开设的店铺，经营生活用品等，以作
为补充。这家商号可是兴庆老字号了，经营一些本地土特产，但您若想买一些比
较明贵的东西，这可没有。不过店主手里经常有一些稀罕物品。
LONG);
   
    set("exits",([
        "east"    : __DIR__"road6",
    ])); 
    set("objects", ([
          __DIR__"npc/dianzhu" : 1,
    ]) );
    setup();
}

