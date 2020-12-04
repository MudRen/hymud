// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	if(me->is_busy())
		return notify_fail("你现在没空！！\n");
	extra = me->query_skill("longfenghuan",1) ;
	if ( extra < 80) return notify_fail("你的龙凤双环还不够纯熟！\n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "hammer")
                        return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("neili") < 500  ) 
		return notify_fail("你的内力不够。\n");
        me->add("neili",-200);
		

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("龙凤双飞只能对战斗中的对手使用。\n");
	weapon = me->query_temp("weapon");
	me->add_temp("apply/attack", 1000);	
	me->add_temp("apply/damage", extra);
	msg = HIR "$N双臂一震，一招［龙凤双飞］，手中的"+ weapon->name()+  "飞出击向$n！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -1000);
	me->start_busy(1);
	return 1;
}
