// 楚州驸马巷 /d/city/chuzhou/fuma_xiang.c
// by lala, 1997-12-04

inherit ROOM;

void create()
{
    set("short", "驸马巷");
    set("long", @LONG
驸马巷是西市北，镇淮楼西北的一条小巷，为什么会得到现在这个名字是无
从可考了，大概是以前这里出过或者住过一个驸马吧。这里和喧闹的西市相比起
来，显得非常幽静，很少看见有人出入。小巷旁都是住家，路西是所比较大的宅
院。
LONG
    );
    set("no_kill",  "yangzhou");
    set("outdoors", "yangzhou");
    set("exits", ([
        "west"      : __DIR__"zhaiyuan",
        "south"     : __DIR__"xishi",
    ]));
    set("item_desc",    ([
        "west"      : "西边宅院的黑漆大门虚掩着，看不清里面的情况。\n",
    ]));        
    set("objects", ([
    ]));
    setup();
}
        
