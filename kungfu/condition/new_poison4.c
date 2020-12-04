// corpse_poison.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;


string name() { return "new_poison4"; }

string chinese_name() { return "��˪�˺�"; }

int update_condition(object me, int duration)
{
int damage;
        if( duration < 1 ) return 0;

 message("vision", me->name() + BLU"���ϱ�˪һ��,��˪�˺������ˡ�\n"NOR, environment(me), me);
tell_object(me, BLU"�����ϱ�˪һ��,��˪�˺������ˡ�\n" NOR );
tell_object(me, BLU"�����ϱ�˪һ��,�㱻��˪��ס�ˡ�\n" NOR );
if (!me->is_busy()) me->start_busy(6);
me->set_temp("apply/attack",-100);
tell_object(me, BLU"�㱻����ȫ�����,�������˺ܶ࣡\n" NOR );





        me->apply_condition(name(), duration - 1);

        if( duration < 1 ) return 0;
        return CND_CONTINUE;
}
