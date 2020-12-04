// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define JU "��" HIR "�۽���" NOR "��"

inherit F_SSERVER;


int perform(object me, object target)
{
        object weapon;
        int damage, ap, dp;
        string msg;


        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(JU "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" JU "��\n");

        if ((int)me->query_skill("tianyu-qijian") < 130)
                return notify_fail("��������潣������죬����ʩչ" JU "��\n");

        if ((int)me->query_skill("force") < 180)
                return notify_fail("����ڹ�����㣬����ʩչ" JU "��\n");

        if ((int)me->query("neili") < 200)
                return notify_fail("�����ڵ��������㣬����ʩչ" JU "��\n");
                        
        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        ap = me->query_skill("sword");
        dp = target->query_skill("force");
             
        msg = HIR "$N" HIR "��������һ�������е�" + weapon->name() +
              HIR "����һ���ʺ磬�⻪ѣĿ��������$n" HIR "��\n" NOR;

        if (ap / 2 + random(ap) > dp)
        {
                damage = me->query_skill("sword");

                me->add("neili", -160);
  target->add("qi",-damage*2);
		target->add("eff_qi",-damage*2);
                msg += HIR "ֻ��$N" HIR "������Ϊһ�ߣ�����$n"
                                           HIR "��$p" HIR "ֻ��һ���������Ķ�����"
                                           "��ͷһ����Ѫ���������\n" NOR;

                me->start_busy(2);
        } else 
        {
                msg += CYN "����$p" CYN "�͵���ǰһԾ,������$P"
                       CYN "�Ĺ�����Χ��\n"NOR;
                me->add("neili", -80);
                me->start_busy(3);
        }
        message_combatd(msg, me, target);


if ((int)me->query_skill("tianyu-qijian") > 200)
{
	msg = HIY "$N" HIY "����΢΢һ��������һ̽��һ�����⼲������$n��\n" NOR;
	me->add("neili", -10);

	if (random(me->query("combat_exp")) > target->query("combat_exp") / 3)
	{
		target->start_busy((int)me->query_skill("tianyu-qijian", 1) / 50 + 3);
		msg += HIR "$n" HIR "���һ������æ�мܣ���һ�±�ʧ���Ȼ���\n" NOR;
	} else 
	{
		msg += CYN "����$p" CYN "���Ų�æ�������˴���"
                       "��ʵ����û���ܵ����Ӱ�졣\n" NOR;
		me->add("neili", -100);
		me->start_busy(1);
	}
	message_combatd(msg, me, target);

}


if ((int)me->query_skill("tianyu-qijian") > 300)
{
msg = HIG "$N" HIG "��������һ�������е�" + weapon->name() +
	      HIG "����һ���ʺ磬�⻪ѣĿ��������$n" HIG "��\n" NOR;

        ap =  me->query_skill("sword");
        dp =  target->query_skill("dodge");
        
        if (ap / 2 + random(ap) > dp)
        {
                damage =  me->query_skill("sword");
                
		me->add("neili", -10);
  target->add("qi",-damage*2);
		target->add("eff_qi",-damage*2);
                msg += HIR "ֻ��$N" HIR "������Ϊһ�ߣ�����$n"
                                           HIR "��$p" HIR "ֻ��һ���������Ķ�����"
                                           "��ͷһ����Ѫ���������\n" NOR;		

		me->start_busy(2);
	} else 
	{
		msg += CYN "����$p" CYN "�͵���ǰһԾ,������$P"
                       CYN "�Ĺ�����Χ��\n"NOR;
		me->add("neili", -100);
		me->start_busy(4);
	}
	message_combatd(msg, me, target);
}
        return 1;
}

