// corpse_poison.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;


string name() { return "new_poison8"; }

string chinese_name() { return "ȫ���ָ�"; }

int update_condition(object me, int duration)
{
int damage;
        if( duration < 1 ) return 0;

 message("vision", me->name() + HIG"ʥ��һ��,����ȫ�����˿�ʼ�ָ��ˡ�\n"NOR, environment(me), me);
damage=me->query("max_qi",1)/20;
if (damage> 38000) damage=38000;


if ((int)me->query("qi") <= (int)me->query("max_qi"))
{
	me->add("qi", damage);	
me->receive_curing("qi", damage);
}
if ((int)me->query("jing") <= (int)me->query("max_jing"))
{
me->add("jing", damage);	
me->receive_curing("jing", damage);
}

if (me->query("neili") <me->query("max_neili"))
me->add("neili",damage);

if (me->is_busy()) me->start_busy(1);


tell_object(me, HIG"��ʥ��һ��,����ȫ�����˿�ʼ�ָ��ˡ���\n" NOR );
        me->apply_condition(name(), duration - 1);

        if( duration < 1 ) return 0;
        return CND_CONTINUE;
}
