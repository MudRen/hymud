//writen by lnwm
//tang.c

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("糖", ({"sweet"}));
        set_weight(200);
        set("long", "一袋白糖");
        set("unit", "袋");
        set("value", 1);
        set("fruit_remaining", 2); 
        set("food_supply", 20); 
        set("eat_msg", "$N拿起$n，就往嘴里倒,也不怕坏了牙\n");
        set("end_msg", "$N吃光了袋里的白糖\n"); 
        set("over_msg", "你已经吃饱了\n");
        set("core", "空口袋");    
        set("core_id", ({"dai"}) );
        set("core_unit", "只");    
        set("core_long", "一只空口袋。\n"); 
 
        setup();
}
void init()
{
    add_action("do_eat","eat");
}

