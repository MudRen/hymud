//writen by lnwm
//tea.c

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("花茶", ({"hua cha","cha"}));
        set_weight(300);
        set("long", "清香的茉莉花茶");
        set("unit", "杯");
        set("value", 1);
        set("fruit_remaining", 5); 
        set("water_supply", 20);
        set("eat_msg", "$N拿起$n，喝了一口，一股清香扑鼻。\n");
        set("end_msg", "$N喝光了杯里的茶.\n"); 
        set("over_msg", "你你已经喝不下了.\n");
        set("core", "杯子");    
        set("core_id", ({"bei"}) );
        set("core_unit", "只");    
        set("core_long", "空杯。\n"); 
 
        setup();
}
void init()
{
    add_action("do_eat","drink");
}

