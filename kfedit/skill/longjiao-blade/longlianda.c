// ����ն�޵�.������.��,�� �
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon, ob;
        string msg, string1;
        int extra;
        int count;
  if( !target ) target = offensive_target(me);

	if( !me->is_fighting() )
		return notify_fail("������ն�޵�.������ֻ����ս����ʹ�á�\n");
 	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("�������򡹿�ʼʱ��������һ�ѵ���\n");


	if( (int)me->query("neili") < 500 )
		return notify_fail("�������������\n");


	if((int)me->query_skill("longjiao-blade",1) < 90)
		return notify_fail("��ĸ���ն�޵�����Ϊ����, ����ʹ����һ���� !\n");
	if((int)me->query_skill("blade") < 90)
		return notify_fail("��ĵ�����Ϊ������ Ŀǰ����ʹ��! \n");

	if( (int)me->query("neili") < 400  ) 
		return notify_fail("�������������\n");
	extra = me->query_skill("longjiao-blade",1) / 10;
	extra += me->query_skill("longjiao-blade",1) /10;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", 900);

	msg = HIR "$N�����Ϸ�������׵����,Ȼ�����·���������������" NOR;
        message_combatd(msg, me, target);
	 msg =  YEL  "�� ��׵��! ���� " NOR;	
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 msg =  YEL  "�� ������! ���� " NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 msg =  HIY  "�� ����������! ���� " NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 msg =  HIY  "�� ����������! ���� " NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg =  HIY  "�� ������.�! ���� " NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -900);
	me->add("neili", -100);
	me->start_busy(2);
	return 1;
}
