#include <ansi.h>

#define ZHEN "��" WHT "������" NOR "��"

#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        int damage,attack_time,i;
        string msg;
        object weapon;


        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(ZHEN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (objectp(me->query_temp("weapon")))
                return notify_fail(ZHEN "ֻ�ܿ���ʩչ��\n");

        if ((int)me->query_skill("force") < 100)
                return notify_fail("����ڹ�����㣬����ʩչ" ZHEN  "��\n");

        if ((int)me->query_skill("bagua-bu", 1) < 60)
                return notify_fail("��İ��Բ�������죬����ʩչ" ZHEN  "��\n");
                                
                                
        if ((int)me->query("neili") < 500)
                return notify_fail("�������������㣬����ʩչ" ZHEN  "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = WHT "$N" WHT "����һ������˫�ƽ���һ�С�������ƽƽ�ĳ�����"
              "ͼ����������$n" WHT "��\n" NOR;
        me->add("neili", -50);

        if (random(me->query_skill("force")) > target->query_skill("force") / 2)
        {
                if (!target->is_busy())  target->start_busy(2);

                damage = (int)me->query_skill("wai-bagua", 1)*2;
                damage = damage / 2 + random(damage / 2);

                msg += HIR "���$n" HIR "΢΢һ�㣬û�п�����"
                                           "�а��$N" HIR "˫������������ǰ��\n"
                                           NOR;
                me->add("neili", -50);
               

                damage = 150+damage;
                target->add("qi",-damage);
		target->add("eff_qi",-damage);

        } else 
        {
                me->start_busy(3);
                msg += CYN "����$p" CYN "������$P"
                       CYN "����ͼ����û���ϵ���\n" NOR;
        }
        message_combatd(msg, me, target);

  if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/4 ) {
         attack_time = random((int)me->query_skill("bagua-bu", 1) / 30);
        if (attack_time > 7 ) attack_time=7;
                                me->add_temp("apply/attack", 100);
                me->add_temp("apply/damage", 1200);        
        for(i = 0; i < attack_time; i++){
         msg = HIG "��"+chinese_number(i+1)+"�ƣ�$N�����ذ��Է�λ���ߣ�˫������ʵʵ������$n��" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"), TYPE_REGULAR,msg);
                        }
                                me->add_temp("apply/attack", -100);
                me->add_temp("apply/damage", -1200);
}
        me->add("neili",-150);
        me->start_busy(2);

        return 1;
}
