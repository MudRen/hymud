// chan.c �򹷰����������־�

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�������־�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "staff")
			return notify_fail("��ʹ�õ��������ԡ�\n");

	if( target->is_busy() )
		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɢ�\n");
		
	if( (int)me->query("neili") < 100  ) 
		return notify_fail("�������������\n");

	if( (int)me->query_skill("dagou-bang",1) < 100 )
		return notify_fail("��Ĵ򹷰���������죬����ʹ�á������־���\n");
        if (me->query_skill("huntian-qigong", 1)<70)
                return notify_fail("��ı����ڹ����δ������\n");

	msg = HIG "$Nʹ���򹷰����������־�����ͷ�ڵ������㣬���಻��������$n��С�Ⱥͽ��ס�\n";

	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 ) {
		msg += HIR " ���$p��$P���ı�����ͣ����æ���ң�\n" NOR;
		target->start_busy( (int)me->query_skill("dagou-bang",1) / 50 +3 );
	} else {
		msg += "����$p������$P����ͼ���򶨽��У�һ˿���ҡ�\n" NOR;
	me->start_busy(2);
}
	message_combatd(msg, me, target);
	me->add("neili", - 60);
	
	 me->add_temp("apply/attack", 100);
        me->add_temp("apply/damage", 500);
       msg = WHT  "$Nת��"+ weapon->name()+HIG"��ˢˢˢ��������������������ף����Ǵ򹷰����е�ɱ�У�" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = WHT  "����������" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC  "$NͻȻ�ɳ�"+ weapon->name()+HIG"��ӭ������$n������������£�������ʱ֮��ֵ�$p�ؿ�������Ѩ��" NOR;
             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIC  "�������£�" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = RED "$N����ӳ�������Ϊ�������ӳ��򹷰����еĹ��֣�����������ɱ�У�" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = RED  "����ɱ�У�" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/attack", - 100);
        me->add_temp("apply/damage", - 500);
	
	return 1;
}
