//writen by lnwm
//wandou.c

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("�㶹", ({"wandou"}));
        set_weight(30);
        set("long", "�������㶹���������Ρ�");
        set("unit", "��");
        set("value", 1);
        set("fruit_remaining", 5); 
        set("food_supply", 20); 
        set("water_supply", 10); 
        set("eat_msg", "$N����$n���Ž�������������\n");
        set("end_msg", "$N������$n��\n"); 
        set("over_msg", "���Ѿ��Ա���\n"); 
        setup();
}
void init()
{
    add_action("do_eat","eat");
}

