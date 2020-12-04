// corpse_poison.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;


string name() { return "tmqidu_poison"; }

string chinese_name() { return "���Ŵ���ɢ"; }

int update_condition(object me, int duration)
{
	int damage,damage2,damage3;
        if( duration < 1 ) return 0;

 message("vision", me->name() + HIB"�Һ�һ������ɫ���࣬ȫ������������ס�Ĳ�������\n"NOR, environment(me), me);
                tell_object(me, HIB "��ֻ��ȫ����������ȫ�����Ҫ����һ�㡣��\n" NOR );
damage= (int)me->query("qi",1)/2;
if (damage>=10000) damage=10000;

damage2= (int)me->query("jing",1)/2;
if (damage2>=10000) damage2=10000;

damage3= (int)me->query("neili",1)/2;
if (damage3>=10000) damage3=10000;


if (random(3)==0 )
{
if (me->query("qi") > damage)
        me->add("qi", -damage);
tell_object(me,HIG"�������������!\n"NOR);
}
else if (random(3)==1 )        
{
if (me->query("jing") > me->query("jing")/2)
        me->add("jing", -damage2);
tell_object(me,HIG"��ľ���������!\n"NOR);
}
else 
{
if (me->query("neili") > me->query("neili")/2)
        me->add("neili", -damage3);
tell_object(me,HIG"�������������!\n"NOR);
}
        if (!me->is_busy())
        me->start_busy(4);


        me->apply_condition(name(), duration - 1);

        if( duration < 1 ) return 0;
        return CND_CONTINUE;
}
