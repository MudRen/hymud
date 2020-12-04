#include <ansi.h>
#include <combat.h>

#define ZHUO "「" WHT "捕风捉影" NOR "」"

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;


        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(ZHUO "只能对战斗中的对手使用。\n");

        if ((int)me->query_skill("qingyun-shou", 1) < 50)
                return notify_fail("你的青云手不够娴熟，难以施展" ZHUO "。\n");

        if ((int)me->query_skill("force") < 100)
                return notify_fail("你的内功修为不够，难以施展" ZHUO "。\n");

        if ((int)me->query("neili") < 100)
                return notify_fail("你现在真气不够，难以施展" ZHUO "。\n");


        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = WHT "$N" WHT "划身错步，单手拂过，手影虚虚实实，难辨真伪，完"
              "全笼罩$n" WHT "。\n" NOR;

 if (random(me->query("combat_exp")) > target->query("combat_exp") / 3)
        {
                me->start_busy(2);
                damage = me->query_skill("hand");
                damage = damage / 3 + random(damage / 3);
                target->add("qi",-damage);
		target->start_busy(5);
                msg +=HIR "$p" HIR "一时辨别不清虚实，被$P"
                                           HIR "手影划过气门，气血翻滚，几乎窒息。\n" NOR;
                me->add("neili", -50);
        } else
        {
                me->start_busy(2);
                me->add("neili", -30);
                msg += CYN "可是$p" CYN "识破了$P"
                       CYN "这一招，斜斜一跃避开。\n" NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}
