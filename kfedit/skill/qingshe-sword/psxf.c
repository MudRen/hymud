// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	extra = me->query_skill("qingshe-sword",1);
	if ( extra < 70) return notify_fail("你的[这门武功]还不够纯熟！\n");
        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");

        if( (int)me->query("neili", 1) < 600 )
                return notify_fail("你现在内力太弱，不能使用绝招。\n");

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［萍水相逢］只能对战斗中的对手使用。\n");
	weapon = me->query_temp("weapon");
if (extra>=200) extra=200;
me->add_temp("apply/damage", 800);
me->add_temp("apply/attack", 80);
	msg =  HIW "$N大喝一声：萍--水--相--逢！\n"+HIR "萍---手中的"+ weapon->name()+ HIR "如灵蛇般的向$n砍去！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR "水---只见"+ weapon->name()+ HIR"似有灵性，划向$n的左肩！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
     msg =  HIR "相---$N凌空一劈，"+ weapon->name()+ HIR"火光四起，削向$n的胸口！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
   msg = HIR "逢---$N图穷匕现，居高临下，手中"+ weapon->name()+ HIR"朝$n的大腿劈去！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
me->add_temp("apply/damage", -800);
me->add_temp("apply/attack", -80);
                me->add("neili", -50);
	me->start_busy(2);
	return 1;
}
