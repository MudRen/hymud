#include <ansi.h>
#include <combat.h>

#define SHENG "「" HIW "天升剑诀" NOR "」"
#define XIAO "「" HIW "剑气冲霄" NOR "」"
#define LIU "「" HIY "流月剑诀" NOR "」"
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        string msg;
        int i;
        int damage;
        string wn;
        int ap, dp;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(SHENG "只能在战斗中对对手使用。\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
              (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对，难以施展" SHENG "。\n");

        if (me->query_skill("force") < 200)
                return notify_fail("你的内功的修为不够，难以施展" SHENG "。\n");

        if (me->query_skill("liuyue-jian", 1) < 150)
                return notify_fail("你的流月剑舞修为不够，难以施展" SHENG "。\n");

        if (me->query("neili") < 300)
                return notify_fail("你的真气不够，难以施展" SHENG "。\n");

        if (me->query_skill_mapped("sword") != "liuyue-jian")
                return notify_fail("你没有激发流月剑舞，难以施展" SHENG "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIW "$N" HIW "手腕一阵疾抖，剑身微颤，剑作龙吟。刹那间剑芒陡涨，"
              "如天河倒泻一般洒向$n"
              HIW "。\n" NOR;

        message_combatd(msg, me, target);
        me->add("neili", -100);
	me->add_temp("apply/attack", 80);	
	me->add_temp("apply/damage", 300);
        for (i = 0; i < 6; i++)
        {

                COMBAT_D->do_attack(me, target, weapon, 0);
        }
	me->add_temp("apply/attack", -80);	
	me->add_temp("apply/damage", -300);

if (me->query_skill("liuyue-jian", 1) > 200)
{
 msg = HIY "$N" HIY "一声清啸，剑法忽变，手中" + weapon->name() + HIY
              "轻轻划出，带出一条无比绚丽的剑芒，遥指$n" HIY "而去。\n" NOR;
        ap = me->query_skill("sword");
        dp = target->query_skill("parry");

        if (ap / 2 + random(ap) > dp)
        {
                damage = ap * 2 / 3 + random(ap)+100;
                me->add("neili", -50);
                me->start_busy(2);
                target->add("qi",-damage);
		target->add("eff_qi",-damage);
                msg +=HIR "$n" HIR "顿时目瞪口呆，一个不慎，被$N"
                                           HIR "精妙的剑招刺中，鲜血飞溅！\n" NOR;
        } else
        {
                me->add("neili", -30);
                me->start_busy(2);
                msg += CYN "可是$p" CYN "并不慌乱，收敛心神，轻轻格挡开了$P"
                       CYN "的剑招。\n"NOR;
        }
        message_combatd(msg, me, target);

}

if (me->query_skill("liuyue-jian", 1) > 300)
{

        ap = me->query_skill("sword")*2;
        dp = target->query_skill("parry");

        if (ap / 2 + random(ap) > dp)
        {
                damage = ap + random(ap / 2)+200;
                target->add("qi",-damage);
		target->add("eff_qi",-damage);
                msg +=HIR "\n" HIR "$n" HIR "只见一道金光闪过，心中" 
                                          "惊骇不已，但鲜血已从$n胸口喷出。\n" 
                                          NOR;
         	me->start_busy(2);
         	me->add("neili", -100);
        } else
        {
         	msg = CYN "然而$n" CYN "眼明手快，侧身一跳"
                      "躲过$N" CYN "这一剑。\n" NOR;

         	me->start_busy(2);
         	me->add("neili", -80);
        }
        message_vision(msg, me, target);

}

        me->start_busy(2);



        return 1;
}