 inherit ITEM;
inherit F_FOOD; 
void create()
{
    set_name("糯米糕", ({ "ricecake" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long", "一块又软又香，真想念妈妈的手艺啊。\n");
        set("unit", "块");
        set("value", 50);
        set("food_remaining", 10);
        set("food_supply", 60);
        }
        
} 
