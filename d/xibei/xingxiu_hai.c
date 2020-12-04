#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short","星宿海");
    set("long",@LONG
星宿海因为周围湖泊水塘众多，有如天上繁星散落人间而得名；这里气候寒
冷，草甸丛生，沟塘湖泊零星散布；一条浅不及尺却宽十余丈的小河缓缓流过，
周围是缠成辫子一般的许多小河。西面远远可以望见许多直插天际的大雪山，山
顶上冰川纵横，白雪皑皑。东面是一个大湖。
LONG);
    set("exits",([
        "east"    : __DIR__"tianchi1",
        "westup"    : __DIR__"xueshan1",
    ]));
    set("objects",([
         __DIR__"npc/shelu" : 2,
         __DIR__"npc/maoniu0" : 2,
    ]));
    set("outdoors","xibei");
    setup();
}

