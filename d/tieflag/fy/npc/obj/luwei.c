 inherit F_FOOD;
inherit ITEM; 
void create()
{
        set_name("±ζ��", ({ "luwei", "lu" }) );
        set_weight(350);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ���Ϻõ�±ζ����\n");
                set("unit", "��");
                set("value", 2000);
                set("food_remaining", 5);
                set("food_supply", 60);
                set("material", "food");
        }
        setup();
}
int finish_eat()
{
        set_name("С����", ({"panzi"}));
        set("value",200);
        set("long", "һֻ���׶��񻨵����ӡ�\n");
        return 1;
}
