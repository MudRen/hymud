//yuan2.c.工技院
//date:1997.8.26
//by dan 

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",YEL"工技院"NOR);
    set("long",@LONG
西夏专设有生产武器装备和军备物资的官府手工业作坊，直接为军队服务。
城市平民的商业活动也很活跃。“工技院”专门制攻城弩炮，云梯冲车及对垒战
车等。这里一到打仗前，就特别热闹，一队队士兵在检修和试用军械。平时可一
个人也没有。
LONG);
   
    set("exits",([
        "east"    : __DIR__"road3",
    ]));
     set("objects", ([
          __DIR__"npc/guan2" : 1,
    ]) );
    setup();
}

