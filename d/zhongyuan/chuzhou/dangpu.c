// 楚州当铺 /d/city/chuzhou/dangpu.c
// by lala, 1997-12-05

inherit HOCKSHOP;

#include <ansi.h>

void create()
{
    set("short",YEL"当铺"NOR);
    set("long",@LONG
这里是楚州的当铺。许多人愁眉不展地走进来，他们当中有些人本来就是这
里的常客，平日里就以典当家产过活，而有些人前不久还囊中颇丰，甚至有家财
万贯，然而钱财如流水样花出，这些人也不得不到当铺来受伙计的窝囊气了。
LONG);
    set("exits",([
        "east"   : __DIR__"wuhua_jie",
    ]));
    set("dangpu_location","chuzhou");
    set("no_kill", "yangzhou");
    setup();
}
