#include <ansi.h>
#include <combat.h>

#define DING "��" HIC "͸�Ƕ�" NOR "��"

inherit F_SSERVER;
 
int perform(object me)
{
        string msg;
        object weapon, target;
        int skill, ap, dp, damage;

	int  neili_wound, qi_wound;

        int  i;
	


        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! me->is_fighting(target))
                return notify_fail(DING "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        weapon = me->query_temp("weapon");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "dagger")
                return notify_fail("����ʹ�õ��������ԣ�����ʩչ" DING "��\n");

        skill = me->query_skill("ziwu-daxuefa", 1);
        if (me->query_skill_mapped("force") != "bluesea-force")
                return notify_fail("��ʹ�õ��ڹ��������Ϻ�������\n");
        if (me->query_skill("force",1) < 150)
                return notify_fail("����ڹ���Ϊ����������ʩչ" DING "��\n");

        if (me->query("neili") < 500)
                return notify_fail("�����ڵ��������㣬����ʩչ" DING "��\n");

        if (skill < 100)
                return notify_fail("�������Ѩ����Ϊ���ޣ�����ʩչ" DING "��\n");

        if (me->query_skill_mapped("dagger") != "ziwu-daxuefa")
                return notify_fail("��û�м��������Ѩ��������ʩչ" DING "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIC "$N" HIC "��������" + weapon->name() + HIC "б�̶�����һʽ��"
              HIR "͸�Ƕ�" NOR + HIC "������ź�����������$n" HIC "��Χ������\n" NOR;
 
        ap = me->query_skill("dagger");
        dp = target->query_skill("parry");
        if (ap / 2 + random(ap) > dp)
        {
                me->add("neili", -100);
                damage = 500 + ap / 3 + random(ap / 3);
                 damage = 500 + ap  + random(ap / 5);
 target->add("qi",-damage);
		target->add("eff_qi",-damage);
		//target->start_busy(3);
                		target->apply_condition("no_perform",2);
                msg += HIR "��ʱֻ���á����͡�һ����$n" HIR
                                           "�ؿڱ�$N" HIR "��һ�д��У�����һ����Ѫ��\n" NOR;
 

                me->start_busy(1);
                if (ap / 3 + random(ap) > dp && ! target->is_busy())
                        target->start_busy(ap / 25 + 1);
        } else
        {
                msg += CYN "����$p" CYN "�Ŀ�����$P" CYN
                       "����ʽ�������һһ��⣬û¶���"
                       "������\n" NOR;
                me->add("neili", -50);
                me->start_busy(3);
        }
        message_combatd(msg, me, target);

if (skill>300 || !userp(me))
{
msg = HIR "������ $N���һ����$n�����������㣬�����ǡ��ᡱ�ֵ��������ʣ����϶��µĻ���������\n";
	message_vision(msg, me, target);
 
	ap = me->query_skill("dagger") + skill;
	dp = target->query_skill("force") / 3;
	if( dp < 1 )
		dp = 1;
	if( random(ap) > dp )
	{
		if(userp(me))
			me->add("neili",-100);
		msg = HIR"$N�ʼ�˿������ĵ��жԷ�Ҫ��, $n��ʱ���õ�����һ���ʹ��\n";
		msg += HIR"ȫ��������й������\n" NOR;

		neili_wound = 1000 + (skill*2);
		if(neili_wound > target->query("neili"))
			neili_wound = target->query("neili");

		qi_wound = neili_wound / 5;
		if(qi_wound > target->query("qi"))
			qi_wound = target->query("qi");
		if(qi_wound < 0) qi_wound = 0;
		target->apply_condition("no_perform",3);
		target->add("neili", -neili_wound);
		target->add("qi", -qi_wound);
		target->add("eff_qi", -qi_wound);
		target->start_busy(3);

}
	else
	{
		if(userp(me))
			me->add("neili",-80);
		msg = HIW"����$n˲�䷴Ӧ��������Ų��Ծ�����������ش���\n"NOR;
		me->start_busy(2);
	}
	message_vision(msg, me, target);	
	
}	

if (skill>600 || !userp(me))
{
 msg = HIY "$N" HIY "һ��߳�ȣ���Ы���� ����" + weapon->name() + HIY "������̣�����"
              "����������㳯$n" HIY "��ȥ��\n" NOR;
        message_combatd(msg, me, target);
        me->add("neili", -80);
                                me->add_temp("apply/attack", 100);
                me->add_temp("apply/damage", 1200);
        for (i = 0; i < 5; i++)
        {

	msg = HIR "��Ы��"+ chinese_number(i+1) +"�̣�" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        }
                                me->add_temp("apply/attack", -100);
                me->add_temp("apply/damage", -1200);    
        return 1;
}
        me->start_busy(3);
        return 1;
}