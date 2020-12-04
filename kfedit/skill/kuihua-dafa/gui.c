#include <ansi.h>
#include <combat.h>

#define GUI "��" HIR "������" NOR "��"
#define HUI "��" HIW "����" HIR "���" NOR "��"
#define QIONG "��" HIR "�����޾�" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;
        object weapon;
        int ap, dp;
        int skill;
        int count;
        int lvl;
        int i,j;
        int ap1, dp1, damage;



        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! me->is_fighting(target))
                return notify_fail(GUI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (target->is_busy())
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

        skill = me->query_skill("kuihua-dafa", 1);
        lvl = me->query_skill("kuihua-dafa", 1);
        if (skill < 100)
                return notify_fail("��ı�а����������죬����ʩչ" GUI "��\n");

        if (me->query("neili") < 100)
                return notify_fail("�����ڵ��������㣬����ʩչ" GUI "��\n");

       if ((int)me->query_skill("kuihua-xinfa", 1) < 50)
               return notify_fail("��Ŀ����ķ�̫���ˡ�\n");


        if (me->query_skill_mapped("sword") != "kuihua-dafa")
                return notify_fail("��û��׼��ʹ�ÿ����񹦣�����ʩչ" GUI "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIR "$N" HIR "���Ӻ������ˣ��������ȣ����ι����쳣����$n"
              HIR "���Ʈ��������\n" NOR;

        ap = me->query_skill("kuihua-dafa", 1) * 2;
        dp = target->query_skill("parry");

	if (ap / 2 + random(ap) > dp || random(3)==0)
        {
		msg += HIR "$p" HIR "��ʱֻ���ۻ����ң�ֻ�ܽ����Ż�����"
                       "�����Գ�����\n" NOR;
		target->start_busy(ap / 55 + 3);
	} else
        {
		msg += CYN "����$p" CYN "������$P" CYN "��������û����"
                       "���κ�Ӱ�졣\n" NOR;
		me->start_busy(2);
	}
        me->add("neili", -50);
	message_vision(msg, me, target);

if (skill>200 && me && target)
{
  msg = HIR "\n$N" HIR "��Хһ������Ȼ������ǰ��һ�о�ֱϮ$n" HIR "Ҫ�����ٶ�֮�죬��"
              "�˼���δ��������δ�š�\n" NOR;

        ap = me->query_skill("unarmed");
        dp = target->query_skill("force");

        if (ap / 2 + random(ap) > dp || random(3)==0)
        {
                ap = me->query_skill("kuihua-dafa", 1);
                me->start_busy(1 + random(2));


                damage=me->query_skill("kuihua-dafa", 1)*2;	
                damage = damage  + random(damage);
           target->receive_damage("qi",damage*2,me);
           target->receive_wound("qi",damage,me);
                msg +=HIR "��һ���ٶ�֮����ȫ������$n" HIR "������$n" HIR
                                                "��æ�����мܣ����Ǵ���֮�죬���޴Ӷ�����$n" HIR "���"
                                                "һ������Ȼ���С�\n" NOR;

 

   

        } else
                msg += HIM "$n" HIM "���һ������æ�˺󣬾�Ȼ"
                                "���Ҷ㿪����һ�У�\n" NOR;
                       message_vision(msg, me, target);
        me->start_busy(2);

	
}	

if (skill>300 && me && target)
{
   msg = HIR "\n$N" HIR "Ĭ�˿���ħ�������α������ޱȣ�������$n"
              HIR "�������У�\n" NOR;
        i = 4;
        if (lvl / 2 + random(lvl) > (int)target->query_skill("dodge") || random(3)==0)
        {
                msg += HIR "$n" HIR "ֻ������ǰһ�����������ܶ���$N"
                       HIR "����Ӱ�����ɰ������⣬�������ˡ�\n" NOR;
                count = me->query_skill("kuihua-dafa", 1);
                i += random(6);
        } else
        {
                msg += CYN "$n" CYN "��$N" CYN "���ÿ죬����"
                       "�ҵ�������æ������С��Ӧ�ԡ�\n" NOR;
                count = 0;
        }

        message_vision(msg, me, target);
me->set_temp("action_flag", 1);
        me->add_temp("apply/attack", 200);
        me->add_temp("apply/damage", 1800);
j=1;
        while (i--)
        {
                if (! me->is_fighting(target))
                        break;
                if (i > 5 && ! target->is_busy())
                        target->start_busy(1);
	j=j+1;
	msg = HIY "$N��������ޱȣ�������$n������"+chinese_number(j+1)+"�У���\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        }
me->delete_temp("action_flag");
        me->add_temp("apply/attack", -200);
        me->add_temp("apply/damage", -1800);
	me->start_busy(2);
}	

	return 1;
}
