// ���� ��ĸ�����⼼

#include <ansi.h>
#include <combat.h> 
inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	string msg;
int extra;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�����꡹ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "throwing")
			return notify_fail("��ʹ�õ��������ԡ�\n");

	if( target->is_busy() )
		return notify_fail(target->name() + "�Ѿ���־��㱣��ŵ�������.\n");
		
	if( (int)me->query_skill("zimu-zhen", 1) < 30 )
		return notify_fail("�����ĸ�뷨������죬����ʹ�á����꡹��\n");

	if( (int)me->query_skill("biyun-xinfa", 1) < 60 )
                return notify_fail("��ı����ķ������ߡ�\n");

        if( (int)me->query("neili", 1) < 300 )
                return notify_fail("����������̫����\n");

 extra = me->query_skill("zimu-zhen",1) / 3;
	me->add_temp("apply/attack", 100);	
	me->add_temp("apply/damage", 1800);
msg = RED "$N����һ����Ŷ��Ű���----��һ�������ŷ�ɥ�����ƻ���$n���˳�ȥ��\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	
msg = RED "$N����һ����Ŷ��Ű���----�ڶ��������ŷ�ɥ�����ƻ���$n���˳�ȥ��\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	
msg = RED "$N����һ����Ŷ��Ű���----�����������ŷ�ɥ�����ƻ���$n���˳�ȥ��\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	
	me->add_temp("apply/attack", -100);
	me->add_temp("apply/damage", -1800);
        me->add("neili",-50);
        
	msg = HIG "$N˫ĿͻȻ���������̹�,��ָ�ڲ��ײ����΢΢һ��,һ������������Ϣ����$nü�ġ�\n"NOR;

	me->start_busy(1);
	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
		msg += HIR " ���$p��$P�ġ����꡹������ţ�˲����־��ʼ�Ժ�������\n" NOR;
                target->start_busy( (int)me->query_skill("zimu-zhen") / 50+2 );
        target->apply_condition("tmzhuihun_poison", 60);
	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
        target->apply_condition("tmqidu_poison", 60);
	} 
	} else {
		msg += "����$p��ǧ��һ��֮������������һ����\n" NOR;
	}
	message_vision(msg, me, target);
	
	
	        msg = HIB  "$N����Ȼ�ӿ죬����ɰ�Ƶ���а��ʽ����$n��ͷ���״���һ�飡\n\n" NOR;
	message_vision(msg,me,target);
        me->add_temp("apply/attack", 100);
        me->add_temp("apply/damage", 1900);
        msg = GRN  "�������ǣ�\n"NOR + HIG"$N������ϣ����ƴ�������$n"NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = YEL  "���Ƹ��꣡\n"NOR + HIY"$N���ƻ���Ϊʵ����$n"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = RED  "�������룡\n"NOR + HIR"$Nһ������$n"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = BLU  "����ǵأ�\n"NOR + HIB"$N˫��һ����������$n"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = MAG  "�������У�\n"NOR + HIM"$N����������ǰ�������Ƴ�����$n"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = CYN  "���κ��ˣ�\n"NOR + HIC"$N������շ��𣬴ӿ��е�ͷ���ƹ���$n"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/attack", -100);
        me->add_temp("apply/damage", -1900);
	return 1;
}
