// ill_fashao.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

string name() { return "xuantian_han"; }

int min_qi_needed() { return 10; }

int update_condition(object me, int duration)
{
	int damage;
        if( duration < 1 ) return 0;

 message("vision", me->name() + "ʹ���������һ�������Ͼ�������һ�ɱ����ĺ�˪����\n"NOR, environment(me), me);
                tell_object(me, HIB "��Ȼһ�����Ե���Ķ�������͸����"
               "֫���࣬͸�������⡣��\n" NOR );

damage = me->query("qi")/20;
if (damage > 20000) damage=20000;
 me->receive_wound("qi", damage);
 
        if (!me->is_busy())
        me->start_busy(3);
        me->apply_condition(name(), duration - 1);

        if( duration < 1 ) return 0;
        return CND_CONTINUE;
}
