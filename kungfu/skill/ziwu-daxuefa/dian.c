#include <ansi.h>
#include <combat.h>

#define DIAN "��" HIM "�ڵ�Ǭ��" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	string msg;
	int ap, dp;
        int i, attack_time,skill;

skill = me->query_skill("ziwu-daxuefa", 1);

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
                return notify_fail(DIAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "dagger")
                return notify_fail("����ʹ�õ��������ԣ�����ʩչ" DIAN "��\n");

	if ((int)me->query_skill("ziwu-daxuefa", 1) < 100)
		return notify_fail("��������Ѩ��������죬����ʩչ" DIAN "��\n");

        if (me->query_skill_mapped("dagger") != "ziwu-daxuefa")
                return notify_fail("��û�м��������Ѩ��������ʩչ" DIAN "��\n");

	if (me->query("neili") < 500)
		return notify_fail("��Ŀǰ����������������ʩչ" DIAN "��\n");
        if (me->query_skill_mapped("force") != "bluesea-force")
                return notify_fail("��ʹ�õ��ڹ��������Ϻ�������\n");
        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	if( target->is_busy() )
		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");


	msg = HIC "$N�����㣬�����Ͻ������½��������£��������棬$n�ϰ���Ѩ�����������С�\n"NOR;

        if( random(me->query("combat_exp",1)) > target->query("combat_exp",1)/3 ) {
		msg += HIW"$p�е�˫�֡��ؿڡ�����������Ѩ��΢΢һʹ����ʱȫ����ľ���ܶ�����\n" NOR;
		target->start_busy( 5);
		me->start_busy(random(2));
		me->add("neili", -100);
	} else {
		msg += HIR"����$p������$P����ͼ����û���ϵ���\n" NOR;
		me->start_busy(2);
	}
	message_vision(msg, me, target);
if (skill > 300 || !userp(me))
{

	msg = HIW "$N" HIW "�����죬����" + weapon->name() + HIW "һ�"
              "ʩ�����С�" HIM "�ڵ�Ǭ��" HIW "������Ȼ�䣬" + weapon->name() + HIW
              "��������$n" HIW "����ҪѨ��" NOR;

        message_vision(msg, me, target);

        attack_time = 4;

	ap = me->query_skill("dagger");
	dp = target->query_skill("dodge");

        attack_time += random(ap / 60);

        if (attack_time > 8)
                attack_time = 8;

	me->add("neili", -attack_time * 10);

                                me->add_temp("apply/attack", 100);
                me->add_temp("apply/damage", 1200);
        for (i = 0; i < attack_time; i++)
        {


                if (! target->is_busy() && random(3) == 1)
                        target->start_busy(1);

	msg = HIR "�ڵ��"+ chinese_number(i+1) +"Ѩ��" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        }
                                        me->add_temp("apply/attack", -100);
                me->add_temp("apply/damage", -1200);

}
	me->start_busy(2);

        return 1;
}
