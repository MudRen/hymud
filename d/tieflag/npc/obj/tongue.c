#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
    set_name(HIG"山雀舌"NOR, ({"bird tongue","tongue"}) );
    set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "山雀的舌头，鲜嫩无比，传说是宫廷里的膳食之一。\n");
                set("lore",1);
                set("unit", "条");
                set("value", 3000);
                set("food_remaining", 10);
                set("food_supply", 60);
        }
    
}      
