 //XXDER
inherit F_FOOD;
inherit ITEM;
#include <ansi.h>
void create()
{
    set_name(HIR"�󻹵�"NOR, ({ "dan" }) );
    set_weight(5);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("long", "����������������Ч�Ĵ󻹵���\n");
        set("unit", "��");
        set("value", 0);
        set("food_remaining", 1);
        set("food_supply", 0);
        set("material", "food");
    }
        setup();
} 
int finish_eat()
{
    object me;
    int gin, kee, sen, c;
    me = this_player();
    gin = (int) me->query("max_jing");
    kee = (int) me->query("max_qi");
    sen = (int) me->query("max_sen");
    if(me->query("force") >=1500)
        message_vision( HIR "$N��������һ�������˹���ҩ��������\n"NOR, me);
    else
    {
        message_vision(HIB"$N���������޷�����ҩ����\n"NOR, me);
        gin/=2;kee/=2;sen/=2;
    }
    c=random(3);
    if(c==0)
    {
        me->set("eff_jing",gin);
        me->set("jing", gin);
    }
    else if(c==1)
    {
        me->set("eff_qi",kee);
        me->set("qi", kee);
    }
    else
    {
        me->set("eff_sen",sen);
        me->set("sen", sen);
    }
    return 0;
}    
