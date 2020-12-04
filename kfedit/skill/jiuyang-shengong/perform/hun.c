// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>
 
inherit F_SSERVER;


#define HUN "「" HIR "混沌一阳" NOR "」"

int perform(object me, object target)
{
        string msg;
        int ap, dp,i;
        int damage;



        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(HUN "只能对战斗中的对手使用。\n");
 
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(HUN "只能空手施展。\n");

        if (me->query_skill("jiuyang-shengong", 1) < 180)
                return notify_fail("你的九阳神功还不够娴熟，难以施展" HUN "。\n");

        if (me->query_skill_mapped("unarmed") != "jiuyang-shengong")
                return notify_fail("你现在没有激发九阳神功为拳脚，难以施展" HUN "。\n");

        if (me->query_skill_mapped("force") != "jiuyang-shengong")
                return notify_fail("你现在没有激发九阳神功为内功，难以施展" HUN "。\n");
        if(me->is_busy())
        return notify_fail("你现在正忙。\n");

        if (me->query("neili") < 300)
                return notify_fail("你的内力不够，难以施展" HUN "。\n");
 
        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIR "$N" HIR "跨前一步，双手回圈，颇得太极之意。掌心顿时闪"
              "出一个气团，向$n" HIR "电射而去。\n" NOR;
 
        ap = me->query_skill("force") + me->query("con") * 10;
        dp = target->query_skill("force") + target->query("con") * 10;

        me->add("neili", -50);

        if (ap / 2 + random(ap) < dp)
        {
                msg += HIY "然而$n" HIY "全力抵挡，终于将$N" HIY
                       "发出的气团拨开。\n" NOR;
                me->start_busy(3);
        } else
        {
                me->add("neili", -100);
                me->start_busy(1);
                damage = me->query_skill("force")*3+200;
            		target->add("qi",-damage);
		target->add("eff_qi",-damage);
                me->add("neili", -150);
		msg +=   HIR "$n" HIR "急忙抽身后退，可是气团射"
                                           "得更快，只听$p" HIR "一声惨叫，鲜血飞"
                                           "溅！\n" NOR;

        }
        message_combatd(msg, me, target);
if (random(me->query("combat_exp",1))> target->query("combat_exp",1)/3 && me->query("jiuyangok"))
 {
 me->add_temp("apply/attack", 200);
        me->add_temp("apply/damage", 2200);
        for (i = 0; i < 5; i++)
        {

                if (random(3) ==0 )
                        target->start_busy(3);

COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        }
        me->add_temp("apply/attack", -200);
        me->add_temp("apply/damage", -2200);
}
        return 1;
}

