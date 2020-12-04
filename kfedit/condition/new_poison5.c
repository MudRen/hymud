// corpse_poison.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;


string name() { return "new_poison5"; }

string chinese_name() { return "��Ȼ�˺�"; }

int update_condition(object me, int duration)
{
int damage;
        if( duration < 1 ) return 0;

 message("vision", me->name() + HIG"�����̹�һ��,��Ȼ֮�����˺������ˡ�\n"NOR, environment(me), me);
damage=me->query("qi")/30;
tell_object(me, HIG "�����̹�һ��,��Ȼ֮�����˺������ˡ�\n" NOR );
if (damage> 25000) damage=25000;
me->receive_wound("qi", damage);
me->receive_damage("qi", damage);
tell_object(me, HIG "���³��ļ�����ɫ��ѪҺ,ȫ��������\n" NOR );

damage=me->query("jing")/30;
if (damage> 25000) damage=25000;
me->receive_wound("jing", damage);
me->receive_damage("jing", damage);
tell_object(me, HIG "��ȫ��ʹ��,������һЩ�����ˣ�\n" NOR );


        
     if (!me->is_busy()) me->start_busy(2);


        me->apply_condition(name(), duration - 1);

        if( duration < 1 ) return 0;
        return CND_CONTINUE;
}
