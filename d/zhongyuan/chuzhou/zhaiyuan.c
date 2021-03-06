// 楚州宅院 /d/city/chuzhou/zhaiyuan.c
// by lala, 1997-12-10

inherit ROOM;

void create()
{
    set("short", "周氏老宅");
    set("long", @LONG
这是一所不大的老式宅院，分东西两个小院，和驸马巷相通的是东院。这是
本城小有名气的周员外家的宅院。周员外为人方正，在城中颇有好评。而最令人
议论纷纷的是本城上清宫的道士曾经远望周家宅院算了一卦，算得此宅八百年内
必出圣人，虽非真龙天子，却也可做得安邦定国的一代贤相。这无疑给周家又蒙
上了层神秘色彩，大家都觉得：虽然八百年的时间是很久以后的事情了，但是现
在先来结交一下周员外也并没有什么坏处。
LONG
    );
    set("no_kill",  "yangzhou");
    set("exits", ([
        "east"      : __DIR__"fuma_xiang",
        ]));
    set("objects", ([
        __DIR__"npc/zhou_yuanwai"   :   1,
    ]));        
    setup();
}
