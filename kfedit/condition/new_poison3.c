// corpse_poison.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;


string name() { return "new_poison3"; }

string chinese_name() { return "�����˺�"; }

int update_condition(object me, int duration)
{
int damage;
        if( duration < 1 ) return 0;

 message("vision", me->name() + HIR"���ϻ���һ��,�����˺������ˡ�\n"NOR, environment(me), me);
damage=me->query("qi")/20;
if (damage> 25000) damage=25000;

me->receive_wound("qi", damage);
me->receive_damage("qi", damage);
tell_object(me, HIR "�����ϻ���һ��,�����˺������ˡ�\n" NOR );

me->set_temp("apply/defense",-100);
me->set_temp("apply/dodge",-100);

tell_object(me, HIR "�㱻�յ����ʹ��,�����˷�����\n" NOR );


        



        me->apply_condition(name(), duration - 1);

        if( duration < 1 ) return 0;
        return CND_CONTINUE;
}
