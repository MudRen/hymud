// FOOD in new file_standard. Lin edited in JUNE 1997
inherit ITEM;
inherit F_FOOD;

#include <ansi.h>



void create()
{
    set_name(BLK"何首乌"NOR, ({"he shou wu","shouwu"}));
    set_weight(400);
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("long", "一棵刚刚从地里挖出来的何首乌，两个拳头那么大\n"
                    "略有人形，通体乌黑。\n");
        set("unit", "棵");
set("value", 6000);
set("over_value", 1000);
        set("food_remaining", 4);
        set("food_supply", 120);
        set("eat_msg","$N拿起$n咬了一口，象嚼萝卜一样吃了下去.\n");
        set("end_msg","$N将剩下的$n吃的干干净净.\n");
    }
}
