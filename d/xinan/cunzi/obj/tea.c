//writen by lnwm
//tea.c

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("����", ({"hua cha","cha"}));
        set_weight(300);
        set("long", "��������򻨲�");
        set("unit", "��");
        set("value", 1);
        set("fruit_remaining", 5); 
        set("water_supply", 20);
        set("eat_msg", "$N����$n������һ�ڣ�һ�������˱ǡ�\n");
        set("end_msg", "$N�ȹ��˱���Ĳ�.\n"); 
        set("over_msg", "�����Ѿ��Ȳ�����.\n");
        set("core", "����");    
        set("core_id", ({"bei"}) );
        set("core_unit", "ֻ");    
        set("core_long", "�ձ���\n"); 
 
        setup();
}
void init()
{
    add_action("do_eat","drink");
}

