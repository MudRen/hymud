//writen by lnwm
//luob.c

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(YEL "�ܲ�"NOR, ({"luo bu"}));
        set_weight(60);
        set("long", "һ���Ƴγȵ�ʵо���޲�");
        set("unit", "��");
        set("value", 1);
        set("fruit_remaining", 3); 
        set("food_supply", 15); 
        set("water_supply", 15); 
        set("eat_msg", "$N����$n������ҧ��һ��\n");
        set("end_msg", "$N���������$n��\n"); 
        set("over_msg", "�ܲ��㶼���Ź�?\n"); 
        setup();
}
void init()
{
    add_action("do_eat","eat");
}

