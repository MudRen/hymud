//writen by lnwm
//jiang.c

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(YEL "生姜"NOR, ({"sheng jiang","jiang"}));
        set_weight(60);
        set("long", "一块长得怪模怪样的生姜");
        set("unit", "块");
        set("value", 1);
        set("fruit_remaining", 3); 
        set("food_supply", 5); 
        set("water_supply", 5); 
        set("eat_msg", "$N拿起$n，咬了一口,马上捂住了腮帮子,好辣呀!\n");
        set("end_msg", "$N啃完了那块姜,已经辣得说不出话来。\n"); 
        set("over_msg", "姜你也把它吃饱?\n"); 
        setup();
}
void init()
{
    add_action("do_eat","eat");
}

