// mie.c  ������

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        int damage;
        string msg;
        object weapon;

        if (!target ) target = offensive_target(me);
        
        if (!target ||  me==target )
                return notify_fail("��������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if ((int)me->query_condition("boss-ai"))
                return notify_fail(WHT"���ڲ���ʹ�á�\n"NOR);


        msg = RED "$N"RED"��������������������.���н���������һ�Ż���.���򽥴�.\n"NOR;
        msg += RED"$N"RED"��������,��֪�������Ѷ�׼��$n��$n���������⣬�����Ծ��ֻ��һɲ��\n"NOR;
        msg += RED"$N"RED"���һ��  ������!!  ,���еĻ���ֱ��$n��ȥ���������.��\n"NOR;
        if ( random(me->query("combat_exp"))>(int)target->query("combat_exp")/3)
        {
                damage = (int)me->query_skill("boss-ai", 1)*10;
                target->receive_damage("qi", damage,me);
                target->receive_wound("qi", damage,me);
        msg += HIR"$n"HIR"����û����ܣ�һ���޴����,�˶���\n"NOR;
        msg += HIR"������$n"HIR"�����ϣ�$n"HIR"ȫ����������!!\n"NOR;
		message_vision(msg, me, target);
		COMBAT_D->report_status(target);
        } else
        {
		message_vision(msg, me, target);
        }
me->apply_condition("boss-ai",1);

        return 1;
}
