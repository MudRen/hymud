#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

string name() { return "xuanming_poison"; }

string chinese_name() { return "��ڤ����"; }

int update_condition(object me, int duration)
{
   int damage,damage2;
damage=me->query("qi")/8;
damage2=me->query("jing")/8;
if (damage > 18000) damage=18000;   
if (damage2 > 18000) damage2=18000;   	

        if( duration < 1 ) return 0;

 message("vision", me->name() + HIW"��ɫ���ϣ�ȫ��ס�Ĳ��������ظ�����졣\n"NOR, environment(me), me);
                tell_object(me, HIW "ֻ�е�һ���溮��������Ȼ����������������������������ڤ����֮�������ˣ�\n" NOR );

        me->receive_damage("jing", damage2);
        me->receive_wound("qi", damage);
        if (!me->is_busy())
        me->start_busy(4);
        me->apply_condition(name(), duration - 1);

        if( duration < 1 ) return 0;
        return CND_CONTINUE;
}
