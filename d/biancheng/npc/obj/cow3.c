 inherit F_FOOD;
inherit ITEM; 
void create()
{
        set_name("牛三星", ({ "cow san", "cow" }) );
        set_weight(350);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一碗鲜美的牛三星。\n");
                set("unit", "碗");
                set("value", 2000);
                set("food_remaining", 5);
                set("food_supply", 60);
                set("material", "food");
        }
        
}
int finish_eat()
{
        set_name("雕花大碗", ({"wan"}));
        set("value",200);
        set("long", "一只雕花大碗。\n");
        return 1;
} 
