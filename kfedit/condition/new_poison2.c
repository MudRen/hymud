// corpse_poison.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;


string name() { return "new_poison2"; }

string chinese_name() { return "��Ӱ�˺�"; }

int update_condition(object me, int duration)
{
int damage;
        if( duration < 1 ) return 0;

 message("vision", me->name() + MAG"���ϰ�Ӱһ��,��Ӱ�˺������ˡ�\n"NOR, environment(me), me);
damage=me->query("qi")/20;
if (damage> 25000) damage=25000;
if (me->query("shen",1) > 0)
{
damage=damage*3;
me->receive_wound("qi", damage);
me->receive_damage("qi", damage);
tell_object(me, MAG "�����ϰ�Ӱһ��,��Ӱ�˺������ˡ�\n" NOR );
tell_object(me, MAG "������Լ������ĺ���û���κ����壬����ʹ����֣�\n" NOR );
}
        
        if (!me->is_busy()) me->start_busy(2);


        me->apply_condition(name(), duration - 1);

        if( duration < 1 ) return 0;
        return CND_CONTINUE;
}
