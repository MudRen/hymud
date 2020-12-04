//writen by lnwm
//wandou.c

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("豌豆", ({"wandou"}));
        set_weight(30);
        set("long", "长长的豌豆，翠绿欲滴。");
        set("unit", "颗");
        set("value", 1);
        set("fruit_remaining", 5); 
        set("food_supply", 20); 
        set("water_supply", 10); 
        set("eat_msg", "$N拿起$n，放进嘴里大嚼起来。\n");
        set("end_msg", "$N吃完了$n。\n"); 
        set("over_msg", "你已经吃饱了\n"); 
        setup();
}
void init()
{
    add_action("do_eat","eat");
}

