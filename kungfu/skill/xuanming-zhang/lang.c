#include <ansi.h>
#include <combat.h>

#define LANG "「" HIM "惊涛骇浪" NOR "」"

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;
        int ap, dp;
        int lvl, p;



        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(LANG "只能对战斗中的对手使用。\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(LANG "只能空手施展。\n");

	if ((int)me->query_skill("shenlong-xinfa", 1) < 165)
		return notify_fail("你的神龙心法火候不够.\n");

        if (me->query_skill_mapped("force") != "shenlong-xinfa")
                return notify_fail("你没有激发神龙心法为内功，无法施展" LANG "。\n");
                
        if ((int)me->query_skill("xuanming-zhang", 1) < 220)
                return notify_fail("你的玄冥神掌不够熟练，无法施展" LANG "。\n");

        if ((int)me->query("max_neili") < 3000)
                return notify_fail("你的内力修为不足，无法施展" LANG "。\n");

        if ((int)me->query("neili") < 800)
                return notify_fail("你的真气不够，无法施展" LANG "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIW "\n$N" HIW "默运玄冥神功，展出绝招「" HIM "惊涛骇浪" HIW "」，猛然间欺身"
              "向前，双掌齐出，掌风阴寒无比，掌未到，风先至，瞬息间双掌已拍向$n" HIW "！\n"NOR;  

        lvl = me->query_skill("xuanming-zhang", 1);

        ap = me->query_skill("strike") + me->query_skill("force");
        dp = target->query_skill("dodge") + target->query_skill("force");

        me->start_busy(3);

        // 第一掌
          
        msg += HIM "\n$N" HIM "右掌向内一转，忽又向前，猛然间直袭$n" HIM "面门。\n" NOR;
        if (ap / 2 + random(ap) > dp)
        { 
                damage=ap*3+100;
                me->add("neili", -300);
        target->apply_condition("xuanming_poison",50);
        target->receive_wound("jing", damage,me);
        target->receive_damage("jing", damage,me);
                msg += HIR "$n" HIR "正欲闪躲，却见$N" HIR "突然绕到$p" HIR "身后，$n" HIR "心中一"
                   "惊，背后中掌，顿觉脊梁处一股寒气升起，尽损三焦六脉。\n" NOR;
                                           
        } else
        {
                msg += HIY "$n" HIY "看见$N" HIY "来势汹涌，急忙提气跃开。\n" NOR;
                me->add("neili", -180);
        }
        message_vision(msg, me, target);
         
        // 第二掌
        msg = HIM "\n$N" HIM "长舒一口气，左掌紧跟而出，风到掌到，正拍向$n" HIM "胸口。\n" NOR;
        if (ap / 2 + random(ap) > dp)
        { 
               damage=ap*4+100;
                me->add("neili", -400);
        target->apply_condition("xuantian_han",50);
       target->receive_wound("qi", damage,me);
        target->receive_damage("qi", damage,me);
                msg += HIR "$n" HIR "但见$N" HIR "右掌已攻出，正欲反击。突然间胸口一震，不禁暗暗"
               "叫苦，顿感胸口处一股寒气升起，尽损三焦六脉。\n" NOR;
                                           
        } else
        {
                msg += HIY "$n" HIY "看见$N" HIY "来势汹涌，急忙提气跃开。\n" NOR;
                me->add("neili", -180);
        }
        message_vision(msg, me, target);

        return 1;
}


