// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	int i,a;
	object weapon;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���齣���������־�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if( (int)me->query("neili") < 400  ) 
		return notify_fail("�������������\n");

	if( (int)me->query_skill("kongling-jian", 1) < 50 )
		return notify_fail("��Ŀ��齣��������죬�����á������־���\n");

	if( (int)me->query_skill("kongdong-xinfa", 1) < 60 )
		return notify_fail("����ڹ��񹦲�����죬����ʹ�á������־���\n");

	extra = me->query_skill("kongling-jian",1) / 20;
	extra += me->query_skill("kongdong-xinfa",1) /20;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", 500);
	msg = HIR  "$N���������ķ��ݣ�ͬʱʹ���ۿ��齣���Уݵġ������־������е�"+ weapon->name() +" һ������һ�л���Ȧ���������Ļ���$n��" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	msg =  HIW "����һ������ʧ��������\n" NOR;
        message_vision(msg, me, target);
a=extra/3;
if (a> 16) a=16;
	for(i=0;i<a;i++)
	{
	msg = HIG "$N�ý�����һ�����ԣ�������ͻȻ͸��һ����\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	}
	i = extra/4;
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -500);
	me->add("neili", - 20 * i);
	me->start_busy(3);
	return 1;
}

