// nang.c
//hydra 
inherit ITEM;
inherit F_FOOD;
void create()
{
    set_name("��", ({"nang"}));
    set_weight(100);
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("long", "һ�ֱ�����ʯͷһ��Ӳ\n");
        set("unit", "��");
        set("value", 50);
        set("food_remaining", 4);
        set("food_supply", 50);
    }
}

