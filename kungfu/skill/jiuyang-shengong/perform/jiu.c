// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define JIU "「" HIR "九曦混阳" NOR "」"

inherit F_SSERVER;

 
int perform(object me, object target)
{
        string msg;
        int ap, dp;
        int count;
        int i;
 
        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }



        if (! target || ! me->is_fighting(target))
                return notify_fail(JIU "只能对战斗中的对手使用。\n");
 
        //if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        //        return notify_fail(JIU "只能空手施展。\n");
         if(me->is_busy())
        return notify_fail("你现在正忙。\n");               
        if (me->query("max_neili") < 6000)
                return notify_fail("你的内力的修为不够，现在无法使用" JIU "。\n");

        if (me->query_skill("jiuyang-shengong", 1) < 200)
                return notify_fail("你的九阳神功还不够娴熟，难以施展" JIU "。\n");

        if (me->query_skill_mapped("unarmed") != "jiuyang-shengong")
                return notify_fail("你现在没有激发九阳神功为拳脚，难以施展" JIU "。\n");

        if (me->query_skill_mapped("force") != "jiuyang-shengong")
                return notify_fail("你现在没有激发九阳神功为内功，难以施展" JIU "。\n");



        if ((int)me->query("neili") < 500)
                return notify_fail("你的真气不够，无法运用" JIU "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIR "$N" HIR "大喝一声，顿时一股浩荡无比的真气至体内迸发，双掌"
              "猛然翻滚，朝$n" HIR "闪电般拍去。\n" NOR;

        ap = me->query_skill("force") + me->query("con") * 20;
        dp = target->query_skill("force") + target->query("con") * 20;

        if (ap / 2 + random(ap) > dp)
        {
                count = ap / 9;
                msg += HIR "$n" HIR "只觉周围空气炽热无比，又见无数气团向"
                       "自己袭来，顿感头晕目眩，不知该如何抵挡。\n" NOR;
        } else
        {
                msg += HIY "$n" HIY "只见$N" HIY "无数气团向自己袭来，连"
                       "忙强振精神，勉强抵挡。\n" NOR;
                count = 0;
        }

        message_vision(msg, me, target);


        me->add("neili", -200);
        me->add_temp("apply/attack", 200);
        me->add_temp("apply/damage", 1800);
        for (i = 0; i < 9; i++)
        {

                if (random(3) ==0 )
                        target->start_busy(3);

COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        }
        me->add_temp("apply/attack", -200);
        me->add_temp("apply/damage", -1800);

        me->start_busy(3);


        return 1;
}

