//writen by lnwm
//tang.c

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("�ǿ�", ({"tang kuai","tang"}));
        set_weight(20);
        set("long", "һ�����");
        set("unit", "��");
        set("value", 10);
        set("fruit_remaining", 2); 
        set("food_supply", 20); 
        set("eat_msg", "$N����$n���������ﵹ,Ҳ���»�����\n");
        set("end_msg", "$N�Թ��˴���İ���\n"); 
        set("over_msg", "���Ѿ��Ա���\n");
        set("core", "�տڴ�");    
        set("core_id", ({"dai"}) );
        set("core_unit", "ֻ");    
        set("core_long", "һֻ�տڴ���\n"); 
 
        setup();
}
void init()
{
//    add_action("do_eat","eat");
}

