//writen by lnwm
//gouqi.c

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(RED "���"NOR, ({"gou qi"}));
        set_weight(60);
        set("long", "����ԲԲ����轣��Ǵ�֮�");
        set("unit", "��");
        set("value", 100);
        set("fruit_remaining", 2); 
        set("food_supply", 30); 
        set("water_supply", 0); 
        set("eat_msg", "$N����$n��һ�ڷŽ����\n");
        set("end_msg", "$N������$n,���ϸ���һ����Ρ�\n"); 
        set("over_msg", "���Ѿ��Ա��ˣ��ٶ��Ҳ�����ϻ�\n"); 
        setup();
}
void init()
{
    add_action("do_eat","eat");
}

