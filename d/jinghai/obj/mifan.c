inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("Ŵ�׷�", ({ "mi fan","mi" }) );
        set_weight(350);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ���������Ŵ�׷���\n");
                set("unit", "��");
                set("food_remaining", 4);
                set("food_supply", 30);
        }
        setup();
}

