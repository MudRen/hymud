// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// gu.c ��עһ��

#include <ansi.h>

inherit F_SSERVER;


int perform(object me, object target)
{
        int damage;
        string msg;
        int ap, dp;
        object weapon;

        damage = me->query_skill("strike");

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("����עһ����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("�������ֲ���ʹ�á���עһ������\n");              

        if( (int)me->query_skill("huixin-strike", 1) < 60 )
                return notify_fail("��Ķ��Ҵ����Ʋ�����죬����ʹ�á���עһ����!\n");

        if( (int)me->query("neili", 1) < 300 )
                return notify_fail("����������̫��������ʹ�á���עһ����!\n");

        msg = CYN "$NĬ���񹦣�ʹ����"RED"��עһ��"CYN"����˫��ƽ�ƹ���$n��\n"NOR;

        ap = me->query_skill("strike");
        dp = target->query_skill("force");
             
        if (ap / 2 + random(ap) > dp)
        {
                me->start_busy(random(2));
                target->start_busy(random(3));

                target->receive_damage("qi", damage,me);
                target->receive_wound("qi", damage,me);
                me->add("neili", -150);

                if( damage < 40 )
                        msg += HIY"���$n��$N˫�ƴ����ؿڣ��ƺ�һ����\n"NOR;
                else if( damage < 80 )
                        msg += HIY"���$n��$N��˫�ƴ����ؿڣ����١���һ������������\n"NOR;
                else if( damage < 160 )
                        msg += RED"���$n��$N��˫�ƴ����ؿڣ������ܵ�һ���ش�����������������\n"NOR;
                else
                        msg += HIR"���$n��$N��˫�ƴ����ؿڣ���ǰһ�ڣ���һ������һ���ɳ�ȥ�ü���Զ��\n"NOR;
                
        }
        else 
        {
                me->start_busy(1 + random(2));
                msg += CYN"����$p������$P����ͼ������һת�����ƻػ���\n"NOR;
        }
        message_combatd(msg, me, target);


if( (int)me->query_skill("huixin-strike", 1) >100 )
{
msg = 
YEL "$Nʹ�����ָѨ�����������ָѨ�����ع������������������۾�һ�㣬��
��ʳ�ж�ָ��$n������ȥ��һ����ָ��ȫ�Ƕ���$n��ͷ����ǰ����Ѩ��\n";
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 )
	{
		msg +=  NOR "���$p��$Pָ�����м���Ѩ��! \n" ;
		target->start_busy( 5);
		me->add("neili", -100);
	}
	else
	{
		msg += NOR "$p�鼱����������һԾ���˳���Զ��\n";
		me->start_busy(2);
	}
	message_combatd(msg, me, target);

	
}	
if( (int)me->query_skill("huixin-strike", 1) >200 )
{
	   msg = HIW "$N" HIW "һ�����ȣ���Ȼʩ��Ʈѩ�����־������ƺ����ơ���˲"
              "�������������С�\n" NOR;
        message_combatd(msg, me);

        me->add("neili", -100);
me->add_temp("apply/damage", 600);
me->add_temp("apply/attack", 180);
        // ��һ��
        COMBAT_D->do_attack(me, target, weapon, 0);
        // �ڶ���
        COMBAT_D->do_attack(me, target, weapon, 0);
        // ������
        COMBAT_D->do_attack(me, target, weapon, 0);
                COMBAT_D->do_attack(me, target, weapon, 0);
                        COMBAT_D->do_attack(me, target, weapon, 0);
        // ������������
        me->add_temp("apply/attack", -180);
me->add_temp("apply/damage", -600);
	
}	
        return 1;
}
