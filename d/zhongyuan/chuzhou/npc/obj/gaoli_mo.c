// 高丽墨 /d/city/chuzhou/npc/obj/gaoli_mo.c
// by lala, 1997-12-14

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name( RED"高丽"HBWHT BLK"墨"NOR, ({"gaoli mo", "mo", }));
        set_weight(100);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", @LONG
墨也差不多，本来墨是中国先使用的，不过到了高丽以后，高丽的松烟特别的黑
且特别有光泽，所以造出墨来质量也就格外的好。如同高丽纸一样，高丽的墨也
深得中国士大夫的好评。
LONG
    );
                set("unit", "块");
                set("value", 10000);
        }
        setup();
}
