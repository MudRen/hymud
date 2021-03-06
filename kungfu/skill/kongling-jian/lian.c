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
		return notify_fail("空灵剑法「连」字诀只能对战斗中的对手使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	if( (int)me->query("neili") < 400  ) 
		return notify_fail("你的内力不够。\n");

	if( (int)me->query_skill("kongling-jian", 1) < 50 )
		return notify_fail("你的空灵剑法不够娴熟，不能用「连」字诀。\n");

	if( (int)me->query_skill("kongdong-xinfa", 1) < 60 )
		return notify_fail("你的内功神功不够娴熟，不能使用「连」字诀。\n");

	extra = me->query_skill("kongling-jian",1) / 20;
	extra += me->query_skill("kongdong-xinfa",1) /20;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", 500);
	msg = HIR  "$N运起［崆峒心法］，同时使出［空灵剑法中］的「连」字诀，手中的"+ weapon->name() +" 一招连着一招画起圈来，闪电般的击向$n！" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	msg =  HIW "剑光一闪，消失．．．．\n" NOR;
        message_vision(msg, me, target);
a=extra/3;
if (a> 16) a=16;
	for(i=0;i<a;i++)
	{
	msg = HIG "$N用剑画出一个八卦，八卦中突然透出一剑！\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	}
	i = extra/4;
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -500);
	me->add("neili", - 20 * i);
	me->start_busy(3);
	return 1;
}

