// cuixin.c  �������ơ����ƴ��ġ�

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	int damage;
	string msg;

	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("�����ƴ��ġ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if( me->query_temp("weapon"))
                return notify_fail("������������ô��ʹ�á����ƴ��ġ���\n");   

        if(me->query_skill("jiuyin-zhengong",1) < 150 )
                return notify_fail("��ľ����湦������죬��ʹ���������ƴ��ġ���\n");
	if( (int)me->query_skill("jiuyin-shenzhang", 1) < 150 )
		return notify_fail(WHT"��ľ������Ʋ�����죬��ʹ���������ƴ��ġ���\n"NOR);
	if( (int)me->query_skill("force", 1) < 180 )
		return notify_fail(RED"����ڹ��ķ���򲻹���ʹ�á����ƴ��ġ��������Լ��ľ�����\n"NOR);
	//if( !target->is_busy() )
	//	return notify_fail(RED"�����ƴ��ġ�ֻ�ܳ�æ���жԶ���ʹ�á�\n"NOR);
	if( (int)me->query("neili") < 900 )
		return notify_fail("�����������ˡ�\n");
        me->add_temp("apply/attack", 200);
        me->add_temp("apply/damage", 3000);
        message_vision(
        HIW "\n$N˫����������ת�˸�ԲȦ��������$n���˹�������\n"
        +"$N����δ����$n�Ѹ��ؿں������������֮�䣬$N��������ŭ������ӿ����������\n" NOR, me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
                me->add_temp("apply/attack", -200);
        me->add_temp("apply/damage", -3000);

	msg = HIB"$N����$n��æ����֮ʱ��ʹ�������ƴ��ġ�����������ֱ͸$n������\n"NOR;
	me->start_busy(2);
        //me->start_perform(3, "���ƴ���");

	damage = target->query("eff_qi")/2;
	if (damage>50000) damage=50000;

	if (	random(me->query("combat_exp")) > target->query("combat_exp")/3	)
{
		target->receive_damage("qi", damage/3);
		target->receive_wound("qi", damage/3);
		msg += HIR"$nֻ������һ��һ����Ѫ�������������\n"NOR;
	} else if (random(me->query("combat_exp")) > target->query("combat_exp")/3) {
		target->receive_damage("qi", damage/2);
		target->receive_wound("qi", damage/3);
		msg += HIR"$n����һ��������ס������һƴ֮�£� ���в�������һ˿��Ѫ��\n"NOR;
	} else {
		target->add("neili", -100);
		msg += HIY"$Nֻ��$n������񣬾��������޷����롣\n"NOR;
	}
	message_combatd(msg, me, target);


	return 1;
}
