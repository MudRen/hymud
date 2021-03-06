#include <ansi.h>
#include <combat.h>

#define DIAN "「" HIM "内点乾坤" NOR "」"

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	string msg;
	int ap, dp;
        int i, attack_time,skill;

skill = me->query_skill("ziwu-daxuefa", 1);

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
                return notify_fail(DIAN "只能对战斗中的对手使用。\n");

	if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "dagger")
                return notify_fail("你所使用的武器不对，难以施展" DIAN "。\n");

	if ((int)me->query_skill("ziwu-daxuefa", 1) < 100)
		return notify_fail("你的子午打穴法不够娴熟，难以施展" DIAN "。\n");

        if (me->query_skill_mapped("dagger") != "ziwu-daxuefa")
                return notify_fail("你没有激发子午打穴法，难以施展" DIAN "。\n");

	if (me->query("neili") < 500)
		return notify_fail("你目前的真气不够，难以施展" DIAN "。\n");
        if (me->query_skill_mapped("force") != "bluesea-force")
                return notify_fail("你使用的内功必须是南海玄功。\n");
        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	if( target->is_busy() )
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧。\n");


	msg = HIC "$N大笔虚点，自右上角至左下角弯曲而下，劲力充沛，$n上半身穴道皆笼罩其中。\n"NOR;

        if( random(me->query("combat_exp",1)) > target->query("combat_exp",1)/3 ) {
		msg += HIW"$p感到双手、胸口、腹部、三处穴道微微一痛，顿时全身麻木不能动弹。\n" NOR;
		target->start_busy( 5);
		me->start_busy(random(2));
		me->add("neili", -100);
	} else {
		msg += HIR"可是$p看破了$P的企图，并没有上当。\n" NOR;
		me->start_busy(2);
	}
	message_vision(msg, me, target);
if (skill > 300 || !userp(me))
{

	msg = HIW "$N" HIW "身法陡快，手中" + weapon->name() + HIW "一扬，"
              "施出绝招「" HIM "内点乾坤" HIW "」，猛然间，" + weapon->name() + HIW
              "连连点向$n" HIW "周身要穴。" NOR;

        message_vision(msg, me, target);

        attack_time = 4;

	ap = me->query_skill("dagger");
	dp = target->query_skill("dodge");

        attack_time += random(ap / 60);

        if (attack_time > 8)
                attack_time = 8;

	me->add("neili", -attack_time * 10);

                                me->add_temp("apply/attack", 100);
                me->add_temp("apply/damage", 1200);
        for (i = 0; i < attack_time; i++)
        {


                if (! target->is_busy() && random(3) == 1)
                        target->start_busy(1);

	msg = HIR "内点第"+ chinese_number(i+1) +"穴！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        }
                                        me->add_temp("apply/attack", -100);
                me->add_temp("apply/damage", -1200);

}
	me->start_busy(2);

        return 1;
}
