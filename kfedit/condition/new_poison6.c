// corpse_poison.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;


string name() { return "new_poison6"; }

string chinese_name() { return "�����˺�"; }

int update_condition(object me, int duration)
{
int damage;
        if( duration < 1 ) return 0;

 message("vision", me->name() + WHT"���ϰ׹�һ��,�������˺������ˡ�\n"NOR, environment(me), me);

damage=(int)me->query("neili")/20;
if (damage> 25000) damage=25000;
if (damage< 1000) damage=1000;	
if ((int)me->query("neili")> damage)
{
//tell_object(me, WHT "�˺�ֵ:"+damage+"��\n" NOR );
me->add("neili", -damage);
tell_object(me, WHT "�����ϰ׹�һ��,�������˺������ˡ�\n" NOR );
tell_object(me, WHT "��ȫ���������ɢ���˿����С�\n" NOR );
}
       
     if (!me->is_busy()) me->start_busy(2);


        me->apply_condition(name(), duration - 1);

        if( duration < 1 ) return 0;
        return CND_CONTINUE;
}
