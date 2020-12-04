// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	int orforce;
	object weapon;
	extra = me->query_skill("dahong-quan",1);
	if( extra < 100) return notify_fail("你的大洪拳还不够纯熟！\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［玉环鸳鸯拳］只能对战斗中的对手使用。\n");
        if (me->query_temp("weapon"))
                        return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("neili") < 500  ) 
		return notify_fail("你的内力不够。\n");
        me->add("neili",-100);

	me->add_temp("apply/attack",80);
	me->add_temp("apply/damage",600);
	weapon = me->query_temp("weapon");
	msg = HIY  "$N使出大洪拳中的［玉环鸳鸯拳］，一招连环七式向$n攻出！\n" NOR;
	message_vision(msg,me,target);
	msg = HIY  "上一拳！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIY  "下一拳！" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIY  "左一拳！" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIY  "右一拳！" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIY  "前一拳！" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIY  "后一拳！" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIY  "最后再一拳！！" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->start_busy(3);
       me->add_temp("apply/attack",-80);
       me->add_temp("apply/damage",-600);
	return 1;
}
