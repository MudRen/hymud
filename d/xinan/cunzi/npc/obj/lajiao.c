//writen by lnwm
//lajiao.c

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(RED "红辣椒"NOR, ({"lajiao"}));
        set_weight(60);
        set("long", "红红的尖尖的辣椒");
        set("unit", "只");
        set("value", 1);
        set("fruit_remaining", 3); 
        set("food_supply", 0); 
        set("water_supply", 0); 
        set("eat_msg", "$N拿起$n，看了看，一狠心咬了一口,马上辣地捂住了嘴\n");
        set("end_msg", "$N吃完了一整只$n,居然一点事没有。\n"); 
        set("over_msg", "辣椒你也把它吃饱?\n"); 
        setup();
}
void init()
{
    add_action("do_eat","eat");
}

