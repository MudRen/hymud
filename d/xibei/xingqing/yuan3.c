//yuan3.c.金工院
//date:1997.8.26
//by dan 

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",YEL"金工院"NOR);
    set("long",@LONG
西夏专设有生产武器装备和军备物资的官府手工业作坊，直接为军队服务。
城市平民的商业活动也很活跃。“金工院”负责打制兵器、护甲, 据说又要打仗
了，工匠们忙得热火朝天。院里放着一捆捆刀枪和一堆堆盔甲，一名主管正在指
派士兵清点，搬运。
LONG);
   
    set("exits",([
        "west"    : __DIR__"road2",
    ])); 
    set("objects", ([
          __DIR__"npc/guan3" : 1,
    ]) );
    setup();
}

