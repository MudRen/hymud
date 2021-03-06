// 楚州茶肆 /d/city/chuzhou/chasi.c
// by lala, 1997-12-06

inherit ROOM;

#include <ansi.h>

void create()
{
    set("short", MAG"茶肆"NOR);
    set("long", @LONG
一般的说来，茶肆这种地方是一个城市里消息流通最快的地方，这里充斥着
各种各样的小道消息，上至军国大事，下至谁家的母鸡生了双黄蛋。各种消息在
这里一传十、十传百，很快就满城尽知了。因此，如果你要打听什么消息的话，
到这种场合既容易打听到结果，又不易暴露身份。
LONG
    );
    set("no_kill",  "yangzhou");
    set("exits", ([
        "east"      : __DIR__"nanshi",
        ]));
    set("objects", ([
        __DIR__"npc/cha_boshi"  :   1,
        __DIR__"npc/chake"      :   1,
    ]));        
    setup();
}
