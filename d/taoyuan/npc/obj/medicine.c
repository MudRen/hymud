 inherit F_FOOD;
inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(HIR"��ת���굤"NOR, ({ "pill", "magic pill" }) );
        set_weight(5);
        if( clonep() )
                set_default_object(__FILE__);
        else {
  set("long", WHT
      "���Ǵ�˵�е�������������Ч�ľ�ת���굤��\n"
      "ֻҪ�㻹��һ�����ڣ������κβ�ʹ���������Σ�\n"NOR); 
                set("unit", "��");
                set("value", 10000);
                set("food_remaining", 1);
                set("food_supply", 0);
                set("material", "food");
        }
        
}
int finish_eat()
{
        object me;
        int gin, kee, sen;
        me = this_player();
        gin = (int) me->query("max_jing");
        kee = (int) me->query("max_qi");
        sen = (int) me->query("max_jing");
        message_vision( HIR "$N�������ɰױ�죬�����Ҫ�γ�Ѫ���������ĺ�ɫ��������ȥ����\n"NOR, me);
        me->set("eff_jing",gin);
        me->set("eff_qi",kee);
        me->set("eff_jing",sen);
        me->set("jing", gin);
        me->set("qi", kee);
        me->set("jing", sen);
        destruct(this_object());
        return 1;
}      
