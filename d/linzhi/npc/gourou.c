// turou.c ���չ���

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("��������", ({"xian rou", "xianrou"}));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ��Ѫ���ܵĶ������⡣\n");
                set("unit", "��");
                set("value", 200+random(300));
                set("food_remaining", 4);
                set("food_supply", 80);
        }
}

