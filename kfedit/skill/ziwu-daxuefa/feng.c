#include <ansi.h>
#include <combat.h>

#define FENG "��" HIR "��ʷ�Ѩ" NOR "��"

inherit F_SSERVER;
 
int perform(object me)
{
        string msg;
        object weapon, target;
        int skill, ap, dp, damage;
        string wn;

        int level;


        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! me->is_fighting(target))
                return notify_fail(FENG "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        weapon = me->query_temp("weapon");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "dagger")
                return notify_fail("����ʹ�õ��������ԣ�����ʩչ" FENG "��\n");

        if (target->is_busy())
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");
        if (me->query_skill_mapped("force") != "bluesea-force")
                return notify_fail("��ʹ�õ��ڹ��������Ϻ�������\n");
        skill = me->query_skill("ziwu-daxuefa", 1);

        if (me->query_skill("force",1) < 150)
                return notify_fail("����ڹ�����Ϊ����������ʩչ" FENG "��\n");

        if (skill < 100)
                return notify_fail("��������Ѩ����Ϊ���ޣ�����ʩչ" FENG "��\n");

        if (me->query("neili") < 500)
                return notify_fail("�����ڵ��������㣬����ʩչ" FENG "��\n");

        if (me->query_skill_mapped("dagger") != "ziwu-daxuefa")
                return notify_fail("��û�м��������Ѩ��������ʩչ" FENG "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIR "$N" HIR "����һԾ��������$n" HIR "��ǰ������" +
              weapon->name() + HIR "������䣬���ƻֺ룬�ó�һ������"
              "ֱ��$n" HIR "ҪѨ��\n" NOR;
 
        ap = me->query_skill("dagger");
        dp = target->query_skill("parry");
        if (ap / 2 + random(ap) > dp)
        {
                me->add("neili", -100);
                damage = 500 + ap  + random(ap / 5);
 target->add("qi",-damage);
		target->add("eff_qi",-damage);
		target->apply_condition("no_exert",3);
		//target->start_busy(3);
                msg += HIR "$p" HIR "΢΢һ�㣬ֻ���ؿ�һ�飬"
                                           "�ѱ�$N" HIR "����ҪѨ�������ϰ����ʱ"
                                           "̱������������̱����\n" NOR;


                me->start_busy(1);

        } else
        {
                msg += CYN "����$p" CYN "�Ŀ�����$P" CYN
                       "����ʽ�������һһ��⣬û¶���"
                       "������\n" NOR;
                me->add("neili", -50);
                me->start_busy(3);
        }
        message_combatd(msg, me, target);
if (skill > 300 || !userp(me))
{
	
 wn = weapon->name();
                           
        msg = HIC "$N" HIC "ŭХһ����ʩչ�����С�" HIW "���´�" HIC "��"
              "����" + wn + HIC "����һ�����Σ���$n" HIC "���֡�\n"NOR;

        message_vision(msg, me, target);

        level = me->query_skill("ziwu-daxuefa", 1);

        me->add("neili", -80);

        if (level + random(level) > target->query_skill("dodge"))
        {
		msg = HIY "$N" HIY "������$n" HIY "��ʽ�е���ʵ����æ"
                      "��ס�Լ�ȫ��һʱ������Ӧ�ԣ�\n" NOR; 
                target->start_busy(5);
                me->start_busy(random(2));
	} else
        {
		msg = CYN "����$N" CYN "��������С�Ĳ��У�û�б�"
                      "$n" NOR + CYN "��ʽ������\n" NOR;
                      
                me->start_busy(2);
	}
	message_combatd(msg, target, me);	
}	



        return 1;
}
