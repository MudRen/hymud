// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	       int i,a;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�۾��غ����ƣ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if( (int)me->query("neili") < 500  ) 
		return notify_fail("�������������\n");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("ֻ�ܿ���ʹ�á�\n");		

        me->add("neili",-100);

	weapon = me->query_temp("weapon");
	extra = me->query_skill("zhuifeng-quan",1) / 10;

        if (extra> 80) extra=80;

	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", 600);
	msg = HIR  "$Nʹ���۾��غ����ƣݣ�ȫ�������ת��˫��һǰһ�������Ļ���$n��" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
a=extra/5;
if (a<5) a=5;
if (a>9) a=9;	
        for(i=0;i<extra/5;i++)
        {
        msg = HIR "$N"+HIR"����ͻת��˫ȭ�����\n" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        }

	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -600);
	me->start_busy(1);
	return 1;
}
