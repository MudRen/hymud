// bo.c �̺��岨

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;
        int ap, dp;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("�̺��岨ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (target->is_busy())
		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");
		
	if ((int)me->query_skill("bluesea-force", 1) < 100)
		return notify_fail("����Ϻ�����������񣬲���ʹ�ñ̺��岨��\n");

        if (me->query_skill_mapped("force") != "bluesea-force")
                return notify_fail("��ʹ�õ��ڹ����ԡ�\n");

       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIC "$N" HIC "����������ң��γ�һ�����������粨��һ�������$n"
              HIC "��ȥ��\n" NOR;

        ap = me->query_skill("force");
        dp = target->query_skill("parry");

        if (ap / 2 + random(ap) > dp)
        {
		msg += HIR "���$p" HIR "��$P" HIR "�Ƶ�ʩչ���������ʽ��\n" NOR;
                target->start_busy(6);
	} else
        {
		msg += CYN "����$p" CYN "������$P" CYN "��������·��"
                       "��������Ӧ�����硣\n" NOR;
		me->start_busy(2);
	}
	message_combatd(msg, me, target);

	return 1;
}
