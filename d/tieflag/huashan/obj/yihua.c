 inherit F_FOOD;
inherit ITEM;
#include <ansi.h>
void create()
{
    set_name(CYN"������"NOR , ({ "flower" }) );
        set_weight(5);
        if( clonep() )
                set_default_object(__FILE__);
        else {
  set("long", 
      CYN"һ�䲻֪����С�������ʵ�������ɫ�������˱ǡ�\n"NOR);
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
        int max_gin, max_kee, max_sen;
        me = this_player();
        if (!me->query_temp("timer/yihua") && !me->query_temp("buffup/buffed_kee")) {
        max_gin = (int) me->query("max_jing");
    max_kee = (int) me->query("max_qi");
    max_sen = (int) me->query("max_sen");
    message_vision( CYN "$Nֻ������ů�����ʮ��������߿�֮��ɢ����һ�������������\n"NOR, me);
    max_gin = max_gin * 11/10;
    max_kee = max_kee * 11/10;
    max_sen = max_sen * 11/10;
        me->set("max_jing", max_gin);
        me->set("max_qi", max_kee);
        me->set("max_sen", max_sen);
        me->set_temp("timer/yihua",1);
        destruct(this_object());
        return 1;
        } else 
        message_vision( CYN "$N��Ȼ���ø���ů�����ʮ���������ʲôҲû������\n"NOR, me);
        destruct(this_object());
        return 1;
}    
