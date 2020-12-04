#include <ansi.h>
#include <combat.h>

#define ZHEN "��" HIW "�𾪰���" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;
        int ap, dp;


        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(ZHEN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(ZHEN "ֻ�ܿ���ʹ�á�\n");

        if ((int)me->query_skill("xianglong-zhang", 1) < 150)
                return notify_fail("�㽵��ʮ���ƻ�򲻹�������ʩչ" ZHEN "��\n");


        if ((int)me->query_skill("force") < 300)
                return notify_fail("����ڹ���Ϊ����������ʩչ" ZHEN "��\n");

        if ((int)me->query("max_neili") < 3000)
                return notify_fail("���������Ϊ����������ʩչ" ZHEN "��\n");

        if ((int)me->query("neili") < 500)
                return notify_fail("�����ڵ��������㣬����ʩչ" ZHEN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = WHT "$N" WHT "ʩ������ʮ����֮��" HIW "�𾪰���" NOR +
              WHT "����ȫ�������Ķ���˫������ɽ������ѹ��$n" WHT "��\n"NOR;  

        ap = me->query_skill("xianglong-zhang",1) + me->query("str") * 10;
        dp = target->query_skill("dodge") + target->query("dex") * 10;

         if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
        { 
                damage = ap + random(ap)+100;
                if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
                target->receive_damage("qi", damage*2,me);
                target->receive_wound("qi", damage*2,me);
                msg +=HIR "$n" HIR "ֻ��һ���ӿ����������"
                                           "����ܣ�$N" HIR "˫������ǰ�أ���Ѫ��"
                                           "���������\n" NOR;
                me->add("neili", -100);
                me->start_busy(2);
        } else
        {
                msg += CYN "$n" CYN "�ۼ�$N" CYN "������ӿ��˿����"
                       "��С���æ������һ�ԡ�\n" NOR;
                me->add("neili", -100);
                me->start_busy(2);
        }
        message_combatd(msg, me, target);

        return 1;
}

