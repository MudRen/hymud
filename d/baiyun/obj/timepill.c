 inherit F_FOOD;
inherit ITEM;
#include <ansi.h>
void create()
{
    set_name(HIY"������"NOR , ({ "time pill" }) );
        set_weight(5);
        if( clonep() )
                set_default_object(__FILE__);
        else {
  set("long", RED
      "ʱ�����������������Ķ�ҩ������ɱ������Ρ�����\n"
      "����ѵ�һ�����鵤����˵����ʱ��Ľ�ҩ��\n"NOR); 
        set("unit", "��");
                set("no_drop", 1);
        set("no_sell", 1);
        set("no_give", 1);
        set("no_put", 1);

        set("lore",1);
        set("value", 0);
                set("food_remaining", 1);
                set("food_supply", 0);
                set("material", "food");
        }
        
}
int finish_eat()
{
        object me;
        int max_jing, max_kee, max_sen;
        int n;
        me = this_player();
        /*if (!me->query_temp("timer/zhuguo") && !me->query_temp("buffup/buffed_kee")) {
        max_jing = (int) me->query("max_jing");
        max_kee = (int) me->query("max_qi");
        max_sen = (int) me->query("max_jing");*/
        message_vision( HIY "\n���ܵľ����Ȼ������ת������$N˫Ŀ�����㯡�����\n"NOR, me);
        message_vision( HIY "\n$N˼�뿪ʼ������ʱ������С�����\n"NOR, me);
        message_vision( HIY "\n�ǳɳ��еĺ���׳������ٵ���񡣡���\n"NOR, me);
        message_vision( HIY "\n�������������ţ��ǹɲ���һ�е�����������\n"NOR, me);
        message_vision( HIY "\n��ͯ�����ǧ�����ϼҵĳ���������\n"NOR, me);
        message_vision( HIY "\nһ�У�һ�С�����\n"NOR, me);
        me->start_busy(5);
        n = random(1544332);
        if (me->query("mud_age") > 1544332) 
            { me->add("mud_age", - n);
            me->unconcious();
        	}else message_vision( HIY "\n$N��Ȼ���ѣ�������һ���亹�����ʲôҲû������\n"NOR, me);
        destruct(this_object());
        return 1;
}    
