 inherit ITEM;
inherit F_FOOD; 
void create()
{
    set_name("Ŵ�׸�", ({ "ricecake" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long", "һ���������㣬��������������հ���\n");
        set("unit", "��");
        set("value", 50);
        set("food_remaining", 10);
        set("food_supply", 60);
        }
        
} 
