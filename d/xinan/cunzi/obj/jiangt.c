//writen by lnwm
//jiangt.c

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIR "����"NOR, ({"jiang tang","tang"}));
        set_weight(200);
        set("long", "ð�������Ľ���,���žͽ�������ů��");
        set("unit", "��");
        set("value", 1);
        set("fruit_remaining", 3); 
        set("food_supply", 3);
        set("water_supply", 30); 
        set("eat_msg", "$N����$n�������غ���һ��,��ʱ����ů������\n");
        set("end_msg", "$N�ȹ�������Ľ���\n"); 
        set("over_msg", "���Ѿ��ȱ���\n");
   set("core", "��");    
   set("core_id", ({"wan"}) );
        set("core_unit", "ֻ");    
        set("core_long", "һֻ���롣\n"); 
 
        setup();
}
void init()
{
    add_action("do_eat","drink");
}

