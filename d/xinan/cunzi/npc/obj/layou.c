//writen by lnwm
//layou.c

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("������", ({"lajiao you"}));
        set_weight(300);
        set("long", "�ʺ�������ͣ�����������ġ�");
        set("unit", "ƿ");
        set("value", 1);
        set("fruit_remaining", 5); 
        set("food_supply", 0);//������-1�� 
        set("eat_msg", "$N����$n���������ﵹ,һ����ë��\n");
        set("end_msg", "$N��Ȼ�Թ���ƿ��������ͣ������.\n"); 
        set("over_msg", "��������ҲҪ�Ա�??\n");
        set("core", "��ƿ");    
        set("core_id", ({"ping"}) );
        set("core_unit", "ֻ");    
        set("core_long", "��ƿ��\n"); 
 
        setup();
}
void init()
{
    add_action("do_eat","drink");
}

