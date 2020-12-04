// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define DIE "「" WHT "象跌势" NOR "」"

inherit F_SSERVER;


int perform(object me, object target)
{
        object weapon;
        int ap, dp;
        int i, count,damage;
        string msg;



        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(DIE "只能对战斗中的对手使用。\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(DIE "只能空手施展。\n");

        if ((int)me->query_skill("longxiang", 1) < 240)
                return notify_fail("你的龙象般若功修为不够，难以施展" DIE "。\n");

        if (me->query("max_neili") < 4000)
                return notify_fail("你的内力修为不足，难以施展" DIE "。\n");

        if (me->query_skill_mapped("unarmed") != "longxiang")
                return notify_fail("你没有激发龙象般若功为拳脚，难以施展" DIE "。\n");

        if (me->query_skill_mapped("force") != "longxiang")
                return notify_fail("你没有激发龙象般若功为内功，难以施展" DIE "。\n");


        if (me->query("neili") < 500)
                return notify_fail("你现在的真气不足，难以施展" DIE "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIY "$N" HIY "蓦地收回双掌，施出密宗绝学「" NOR + WHT "象跌势"
              HIY "」，双臂再度横移，猛贯向$n" HIY "！\n" NOR;

        ap = me->query_skill("unarmed") + me->query("con") * 20; 
        dp = target->query_skill("parry") + target->query("dex") * 20; 

        if (me->query("max_neili") > target->query("max_neili") * 2)
        {
                msg += HIR "$n" HIR "全然无力阻挡，竟被$N"
                       HIR "一拳击得飞起，重重的跌落在地上。\n" NOR;
                me->add("neili", -50);
                me->start_busy(1);
		damage = 550+me->query_skill("unarmed")+(me->query_skill("longxiang")*3);
		  if (damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
                target->receive_damage("qi", damage,me);
                target->receive_wound("qi", damage,me); 	
                message_combatd(msg, me, target);
if (userp(me) && userp(target))
	{
                target->set("eff_qi", 1);
                target->set("eff_jing", 1);
                target->unconcious();
}
else
	{
		damage = 550+me->query_skill("unarmed")+(me->query_skill("longxiang")*3);
		  if (damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
                target->receive_damage("qi", damage,me);
                target->receive_wound("qi", damage,me); 		

	}	
                return 1;
        } else
        if (ap / 2 + random(ap) > dp)
        {
                count = ap / 10;
                msg += HIR "$n" HIR "见$P" HIR "来势迅猛之极，一时不知该如"
                       "何作出抵挡，竟呆立当场。\n" NOR;
        } else
        {
                msg += HIY "$n" HIY "见$p" HIY "来势迅猛之极，甚难防备，连"
                       "忙振作精神，小心抵挡。\n" NOR;
                count = 0;
        }

        message_combatd(msg, me, target);
        if (count> 200) count=200;
        me->add_temp("apply/attack", count);
 me->add_temp("apply/damage", 1200);
        me->add("neili", -300);

        for (i = 0; i < 7; i++)
        {
                if (! me->is_fighting(target))
                        break;
                if (random(3) ==0 && ! target->is_busy())
                        target->start_busy(2);

                COMBAT_D->do_attack(me, target, 0, 0);
        }

        me->start_busy(1 + random(5));
        me->add_temp("apply/attack", -count);
 me->add_temp("apply/damage", -1200);
        return 1;
}

