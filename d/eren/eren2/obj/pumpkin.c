 inherit ITEM;
inherit F_FOOD; 
void create()
{
    set_name("С�Ϲ�", ({ "pumpkin" }) );
    set_weight(4000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("long", "һ��ԲԲ�ģ�ӲӲ��С�Ϲϡ�\n");
        set("unit", "��");
        set("value", 15);
        set("food_remaining", 3);
        set("food_supply", 300);
    }
    
}    
