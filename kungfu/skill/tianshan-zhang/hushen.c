// chan.c ̫�������������־�

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��ɽ�ȷ�������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "staff")
            return notify_fail("��ʹ�õ��������ԡ�\n");

	if( (int)me->query("neili") < 200 )
		return notify_fail("�������������\n");

        if( target->is_busy() )
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɢ�\n");
                
        if( (int)me->query_skill("tianshan-zhang", 1) < 40 )
                return notify_fail("�����ɽ�ȷ�������죬����ʹ�á�������\n");

        msg = HIY "$Nʹ����ɽ�ȷ���������ƴ�����趯���е���������������ס,��ͼ����$n�Ĺ��ơ�\n";
        me->add("neili",-50);
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
                msg += HIG " ���$p��$P�ָ���æ���ң�����ʧ�룬���ڵ�������֪���Ӧ�ԣ�\n" NOR;
        target->apply_condition("xx_poison",20);
	 target->apply_condition("x2_sandu",20);
	 target->apply_condition("sanpoison",20);
target->apply_condition("corpse_poison",60);
                target->start_busy( (int)me->query_skill("tianshan-zhang",1) / 50 + 2 );
        } else {
                msg += HIR"����$p������$P����ͼ������㣬ȫ��Ӧ�����硣\n" NOR;
                me->start_busy(2);
        }
        message_combatd(msg, me, target);

 if (me->query_skill("tianshan-zhang",1) > 250)
        {
        me->add_temp("apply/attack", 100);    
        me->add_temp("apply/damage", 500);        	
        message_vision(HIY"$N����ͷ��ð�����̹�$n���̹�ɨ�У�ȫ����һ��!\n"NOR,me,target);
        target->apply_condition("xx_poison",60);
        target->apply_condition("corpse_poison",60);
	 msg =  HIR  "����ʬ����" NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        target->apply_condition("x2_sandu",60);
	 msg =  HIR  "����ɰ�ơ�" NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        target->apply_condition("sanpoison",60);
	 msg =  HIR  "�����ζ���" NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add("neili", -150);
        if (random(me->query("combat_exp")) >target->query("combat_exp")/2)
        {
       	 msg =  HIR  "����Ц��ңɢ��" NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR"$NͻȻ�����һЦ��$n��Ȼ����Ц��Ц!\n"NOR,me,target);
        target->apply_condition("sanxiao_poison",6);
        me->add("neili", -50);
        }
        me->add_temp("apply/attack", -100);    
        me->add_temp("apply/damage", -500);        	

}
        return 1;
}

