// corpse_poison.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;


string name() { return "new_poison7"; }

string chinese_name() { return "ȫ���˺�"; }

int update_condition(object me, int duration)
{
int damage;
        if( duration < 1 ) return 0;

 message("vision", me->name() + CYN"����ʥ��һ��,��ʥ�˺������ˡ�\n"NOR, environment(me), me);
damage=me->query("qi",1)/20;
if (damage> 25000) damage=25000;
if (me->query("shen",1) < 0)
{
damage=damage*3;
me->receive_wound("qi", damage);
me->receive_damage("qi", damage);
tell_object(me, CYN "������ʥ��һ��,��ʥ�˺������ˡ�\n" NOR );
}
        
 message("vision", me->name() + MAG"���ϰ�Ӱһ��,��Ӱ�˺������ˡ�\n"NOR, environment(me), me);
damage=me->query("qi",1)/20;
if (damage> 25000) damage=25000;
if (me->query("shen",1) > 0)
{
damage=damage*3;
me->receive_wound("qi", damage);
me->receive_damage("qi", damage);
tell_object(me, MAG "�����ϰ�Ӱһ��,��Ӱ�˺������ˡ�\n" NOR );
}

 message("vision", me->name() + HIR"���ϻ���һ��,�����˺������ˡ�\n"NOR, environment(me), me);
damage=me->query("qi",1)/20;
if (damage> 25000) damage=25000;
me->receive_wound("qi", damage);
me->receive_damage("qi", damage);
tell_object(me, HIR "�����ϻ���һ��,�����˺������ˡ�\n" NOR );
me->set_temp("apply/defense",-100);
me->set_temp("apply/dodge",-100);

 message("vision", me->name() + BLU"���ϱ�˪һ��,��˪�˺������ˡ�\n"NOR, environment(me), me);
tell_object(me, BLU"�����ϱ�˪һ��,��˪�˺������ˡ�\n" NOR );
if (!me->is_busy()) me->start_busy(6);
me->set_temp("apply/attack",-100);


 message("vision", me->name() + HIG"�����̹�һ��,��Ȼ֮�����˺������ˡ�\n"NOR, environment(me), me);
damage=me->query("qi",1)/30;
tell_object(me, HIG "�����̹�һ��,��Ȼ֮�����˺������ˡ�\n" NOR );
if (damage> 25000) damage=25000;
me->receive_wound("qi", damage);
me->receive_damage("qi", damage);

damage=me->query("jing",1)/30;
if (damage> 25000) damage=25000;
me->receive_wound("jing", damage);
me->receive_damage("jing", damage);


 message("vision", me->name() + WHT"���ϰ׹�һ��,�������˺������ˡ�\n"NOR, environment(me), me);
damage=me->query("neili",1)/20;
if (damage> 25000) damage=25000;
if (damage< 1000) damage=1000;	
if ((int)me->query("neili",1)> damage) 
{
me->add("neili", -damage);
tell_object(me, CYN "�����ϰ׹�һ��,�������˺������ˡ�\n" NOR );
}


        me->apply_condition(name(), duration - 1);

        if( duration < 1 ) return 0;
        return CND_CONTINUE;
}
