#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short","万鸟湖");
    set("long",@LONG
迎面是一片望不到边的湖水，路北百余里，皆是水天一片，湖中矗立着几座
高山，云雾缭绕，颇似仙境；不远处一个小岛上白茫茫一片，细看去竟是大群大
群的飞鸟。鸟叫声此起彼伏，不绝于耳。天上也是数不清的飞鸟，颜色各异，大
小有别，皆是叫不出名字的。东面是日月山，南面是一片平缓的山地草场。
LONG);
    set("exits",([
        "eastup"    : __DIR__"riyue_shan",
        "southwest"    : __DIR__"hill_caodi1",
    ]));
    set("outdoors","xibei");
    setup();
}

