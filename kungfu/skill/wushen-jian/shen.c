#include <ansi.h>
#include <combat.h>

#define SHEN "��" HIM "����Ԫ��" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg, wn;
        object weapon;
        int ap, dp;
                int count;
	int i, attack_time;
	int skill,level;
        me = this_player();


        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(SHEN "ֻ����ս���жԶ���ʹ�á�\n");
        skill=(int)me->query_skill("wushen-jian", 1);
        if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" SHEN "��\n");

	if( (int)me->query_skill("yunlong-shengong", 1) < 150 )
		return notify_fail("��������񹦲����ߡ�\n");
	if( (int)me->query_skill("wushen-jian", 1) < 150 )
		return notify_fail("�����ң���񽣷����������죡\n");
        if (me->query_skill_mapped("sword") != "wushen-jian")
                return notify_fail("��û�м�����ң���񽣷�������ʩչ��\n");

        if ((int)me->query_skill("force", 1) < 220)
                return notify_fail("����ڹ���򲻹�������ʩչ" SHEN "��\n");

        if ((int)me->query_skill("dodge", 1) < 200)
                return notify_fail("����Ṧ��򲻹�������ʩչ" SHEN "��\n");  

        if ((int)me->query("max_neili") < 5500)
                return notify_fail("���������Ϊ���㣬����ʩչ" SHEN "��\n");

        if ((int)me->query("neili") < 500)
                return notify_fail("�����ڵ���������������ʩչ" SHEN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        wn = weapon->name();

        msg = HIM "\n$N" HIM "һ��ŭ�ȣ��ھ����ǣ�����" + wn +
              HIM "�����ǧ�����Ǽ仯��������̰�������⣬��"
              "����\n$P����ر�죬���Ž���ͬʱ����" HIR
              "ף��" HIM "������" HIY "�ϸ�" HIM "������" NOR
              WHT "ʯ��" HIM "������" HIG "ܽ��" HIM "������"
              HIW "����" HIM "��\n���׽�������ʹ��������ʯ��"
              "��Ϯ��$n" HIM "ȫ��" NOR;

//        message_sort(msg, me, target);
        
        ap = me->query_skill("wushen-jian", 1) +
             me->query_skill("parry", 1);

        dp = target->query_skill("dodge", 1) +
             target->query_skill("parry", 1);

        if (ap * 2 / 3 + random(ap) > random(dp))
        {
                damage = me->query_skill("wushen-jian", 1) +
                         me->query_skill("force", 1) +
                         me->query_skill("parry", 1);

                damage += random(damage / 2);

                // ���֮һ�ļ��ʿɱ��м�
                if (random(10) <= 1 && ap / 2 < dp)
                {
                        damage = damage / 3;

                               target->add("qi",-damage);
		target->add("eff_qi",-damage);
                msg +=HIG "\n$n" HIG "��$N" HIG "������⽣��"
                                                  "���ˣ���æ������������мܡ�\n��֪$P��"
                                                  "�������Ƿ���$pһ���ƺߣ����˼�������"
                                                  "��һ����Ѫ��\n" NOR;
                        me->add("neili", -100);
                        me->start_busy(3);
                } else 
                {
                               target->add("qi",-damage);
		target->add("eff_qi",-damage);
                msg +=HIR "\n$n" HIR "��$N" HIR "��������ͷ�"
                                                  "���䣬�����ݺᣬ��Х�����Լ�Ϯ����\n��"
                                                  "�ײ��ɴ󾪣���ʱ���á����͡�һ������"
                                                  "��͸�������\n" NOR;

                        me->add("neili", -100);
                        me->start_busy(3);
                }
        } else
        {
                msg = CYN "\nȻ��$n" CYN "�Կ�Կ죬����һ��"
                      "��Ȼ���$N" CYN "��һ�С�\n" NOR;
                me->add("neili", -150);
                me->start_busy(3);
        }
        message_vision(msg, me, target);
if (skill>200 && me && target)
{
msg = HIG "\n$N" HIG "ʹ����ң���񽣡�" HIC "�ط�������" HIG "����"
              "����" + weapon->name() + HIG "��Ȼ��ת�������ػع��죬��"
              "��Ϯ��$n" HIG "��\n" NOR;

        message_vision(msg, me, target);

        me->add("neili", -10);
        if (level + random(level) > target->query_skill("dodge", 1))
        {
		msg = HIR "�����ػؼ�$N" HIR "��ʽ��Ȼ��죬$n�ѱ�$N"
                      HIR "����Ŀ��Ͼ�ӣ���æ���ң�\n" NOR;
                if (!target->query_condition("zhua_poision")) target->apply_condition("zhua_poision",10);
                target->start_busy(8);
                me->start_busy(1);
	} else
        {
		msg = CYN "����$n" CYN "������$N"
                      CYN "����ͼ���򶨽��У�һ˿���ҡ�\n" NOR;
                me->start_busy(2);
	}
	message_combatd(msg, me, target);	
	
}	

if (skill>300  && me && target)
{
	msg = HIW "\n$N" HIW "��ת��ң���񽣣�����" + weapon->name() +
              HIW "�ų��������⣬�����ɺ����죬ϯ��$n" HIW "��ȥ��\n" NOR;

         message_vision(msg, me, target);

        ap = me->query_skill("sword",1);
        dp = target->query_skill("dodge",1);
        attack_time = 4;

	if (ap / 2 + random(ap) > dp)
	{
		msg = HIR "���$n" HIR "��$N" HIR "���˸����ֲ�����$n"
                      HIR "��æ�мܣ����нпࡣ\n" NOR;

                count = ap / 20;
                attack_time += random(ap / 45);
        } else
        {
                msg = HIC "$n" HIC "��$N" HIC "�⼸����ʽ������������"
                      "����ֻ�ÿ���мܡ�\n" NOR;
                count = 0;
        }
    	message_combatd(msg, me, target);

        if (attack_time > 9)
                attack_time = 9;
                	
count = ap / 3;
                attack_time += random(ap / 40);


        me->add_temp("apply/attack", 80);
        me->add_temp("apply/damage", 1000);

	me->start_busy(3);

        me->set_temp("perform_wushenjian/qian", 1);
	for (i = 0; i < attack_time; i++)
	{
		if (! me->is_fighting(target))
		       break;

                if (! target->is_busy() && random(3) == 1)
                       target->start_busy(2);
 
	        COMBAT_D->do_attack(me, target, weapon, 0);
	}
        me->delete_temp("perform_wushenjian/qian");

        me->add_temp("apply/attack", -80);
        me->add_temp("apply/damage", -1000);
}
        return 1;
}
