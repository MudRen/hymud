#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int ap, dp;
object weapon;
        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail("���ݺ᡹ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (target->is_busy())
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");
                
        if ((int)me->query_skill("six-finger", 1) < 120)
                return notify_fail("��������񽣻�򲻹�������ʹ�á��ݺ᡹��\n");

        if (me->query("neili") < 100)
                return notify_fail("��������������޷�ʩչ���ݺ᡹��\n");

        if (me->query_temp("weapon"))
                return notify_fail("�������ֲ���ʩչ���ݺ᡹��\n");
        if ((int)me->query_skill("kurong-changong",1) < 100)
            return notify_fail("��Ŀ�������̫�͡�\n");
        if (me->query_skill_mapped("finger") != "six-finger")
                return notify_fail("��û�м��������񽣣��޷�ʩչ���ݺ᡹��\n");

       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "ֻ��$N" HIW "һ����Ц��ʮָ�׵��������籼�������޾������ƽ�����Ȼ����$n" HIW "��\n" NOR;

        ap = me->query_skill("six-finger", 1) +
             me->query_skill("finger", 1) / 2;
        dp = target->query_skill("force");

        if (ap / 2 + random(ap) > dp || random(3)==0)
        {
                msg += HIR "���$p" HIR "�����ݺύ��Ľ����Ƶ���æ���ң�Ӧ�Ӳ�Ͼ��\n" NOR;
                target->start_busy(8);
        } else
        {
                msg += CYN "����$p" CYN "�������ţ������ڹ���$P"
                       CYN "�Ľ����������⡣\n" NOR;
                me->start_busy(1);
        }
        message_combatd(msg, me, target);


me->add_temp("apply/attack",150);
	me->add_temp("apply/damage",1200);
	weapon = me->query_temp("weapon");

        msg = CYN "$N��˼���ң���$n����ңָ�˼��£�����ȴʹ�������������ľ���"HIY"[��������]"CYN"��" NOR;
       	         message_vision(msg, me, target);                
	 msg =  RED  "-------------------------------���̽���" NOR;
	        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = GRN   "-------------------------------��������" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg =  MAG  "-------------------------------�г彣��" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = YEL   "-------------------------------�س彣��" NOR;
             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = WHT   "-------------------------------���󽣣�" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = BLU   "-------------------------------�ٳ彣��" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/attack",-150);
	 me->add_temp("apply/damage",-1200);

        return 1;
}

