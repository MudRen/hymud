//writen by lnwm
//lajiao.c

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(RED "������"NOR, ({"lajiao"}));
        set_weight(60);
        set("long", "���ļ�������");
        set("unit", "ֻ");
        set("value", 1);
        set("fruit_remaining", 3); 
        set("food_supply", 0); 
        set("water_supply", 0); 
        set("eat_msg", "$N����$n�����˿���һ����ҧ��һ��,����������ס����\n");
        set("end_msg", "$N������һ��ֻ$n,��Ȼһ����û�С�\n"); 
        set("over_msg", "������Ҳ�����Ա�?\n"); 
        setup();
}
void init()
{
    add_action("do_eat","eat");
}

