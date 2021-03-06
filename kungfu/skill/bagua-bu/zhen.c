#include <ansi.h>

#define ZHEN "「" WHT "八卦震" NOR "」"

#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        int damage,attack_time,i;
        string msg;
        object weapon;


        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(ZHEN "只能对战斗中的对手使用。\n");

        if (objectp(me->query_temp("weapon")))
                return notify_fail(ZHEN "只能空手施展。\n");

        if ((int)me->query_skill("force") < 100)
                return notify_fail("你的内功火候不足，难以施展" ZHEN  "。\n");

        if ((int)me->query_skill("bagua-bu", 1) < 60)
                return notify_fail("你的八卦步不够娴熟，难以施展" ZHEN  "。\n");
                                
                                
        if ((int)me->query("neili") < 500)
                return notify_fail("你现在真气不足，难以施展" ZHEN  "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = WHT "$N" WHT "深吸一口气，双掌交错，一招「八卦震」平平拍出，企"
              "图以内力震伤$n" WHT "。\n" NOR;
        me->add("neili", -50);

        if (random(me->query_skill("force")) > target->query_skill("force") / 2)
        {
                if (!target->is_busy())  target->start_busy(2);

                damage = (int)me->query_skill("wai-bagua", 1)*2;
                damage = damage / 2 + random(damage / 2);

                msg += HIR "结果$n" HIR "微微一楞，没有看破招"
                                           "中奥妙，$N" HIR "双掌正好拍在胸前。\n"
                                           NOR;
                me->add("neili", -50);
               

                damage = 150+damage;
                target->add("qi",-damage);
		target->add("eff_qi",-damage);

        } else 
        {
                me->start_busy(3);
                msg += CYN "可是$p" CYN "看破了$P"
                       CYN "的企图，并没有上当。\n" NOR;
        }
        message_combatd(msg, me, target);

  if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/4 ) {
         attack_time = random((int)me->query_skill("bagua-bu", 1) / 30);
        if (attack_time > 7 ) attack_time=7;
                                me->add_temp("apply/attack", 100);
                me->add_temp("apply/damage", 1200);        
        for(i = 0; i < attack_time; i++){
         msg = HIG "第"+chinese_number(i+1)+"掌！$N脚下沿八卦方位疾走，双掌虚虚实实地拍向$n。" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"), TYPE_REGULAR,msg);
                        }
                                me->add_temp("apply/attack", -100);
                me->add_temp("apply/damage", -1200);
}
        me->add("neili",-150);
        me->start_busy(2);

        return 1;
}
