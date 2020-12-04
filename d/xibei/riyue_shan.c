#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short","日月山");
    set("long",@LONG
日月山东瞰湟中，西接大山，是由西北经湟中进吐蕃的必经之路，宫里及中
原深宅巨富所用的麝香，大药铺中被传为妇科圣药的雪莲，都是由这条路运至中
原的。登上日月山，西面竟是一碧万顷的无边大海！？只有当你看到远远地平线
处浅浅的山影时，才知道那不过是个大湖。
LONG);
    set("exits",([
        "eastdown"   : __DIR__"huangshui2",
        "westdown"    : __DIR__"wanniao_lake",
    ]));
    set("outdoors","xibei");
    setup();
}

