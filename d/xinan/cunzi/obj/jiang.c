//writen by lnwm
//jiang.c

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(YEL "����"NOR, ({"sheng jiang","jiang"}));
        set_weight(60);
        set("long", "һ�鳤�ù�ģ����������");
        set("unit", "��");
        set("value", 1);
        set("fruit_remaining", 3); 
        set("food_supply", 5); 
        set("water_supply", 5); 
        set("eat_msg", "$N����$n��ҧ��һ��,������ס��������,����ѽ!\n");
        set("end_msg", "$N�������ǿ齪,�Ѿ�����˵����������\n"); 
        set("over_msg", "����Ҳ�����Ա�?\n"); 
        setup();
}
void init()
{
    add_action("do_eat","eat");
}

