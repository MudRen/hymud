//writen by lnwm
//yan.c

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("�ο�", ({"yan kuai","salt"}));
        set_weight(200);
        set("long", "��");
        set("unit", "��");
        set("value", 1);
        set("fruit_remaining", 5); 
        set("food_supply", 0);//������-1�� 
        set("eat_msg", "$N����$n���������ﵹ,һ����ë��\n");
        set("end_msg", "$N��Ȼ�Թ��˴�����Σ������.\n"); 
        set("over_msg", "����ҲҪ�Ա�??\n");
        set("core", "�տڴ�");    
        set("core_id", ({"dai"}) );
        set("core_unit", "ֻ");    
        set("core_long", "�տڴ���\n"); 
 
        setup();
}
void init()
{
//    add_action("do_eat","eat");
}

