// zhemei.c
// /kungfu/skill/zhemei-shou/
// Program by ying

#include <ansi.h>
#define ZHE "��" HIC "��÷ʽ" NOR "��"
inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;

        object weapon2;
        int skill, ap, dp;
        skill=(int)me->query_skill("zhemei-shou", 1);
        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() )
                return notify_fail("��÷չֻ�ܶԶ���ʹ�á�\n");
       if( environment(me)->query("no_fight") )
                       return notify_fail("���ﲻ�ܹ�������! \n");
        if( (int)me->query_skill("zhemei-shou", 1) < 80 )
                return notify_fail("�����÷�ֲ�����죬����ʹ����÷չ��\n");
	if( !(me->is_fighting() ))
		return notify_fail("��÷��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( (int)me->query_skill("beiming-shengong", 1) < 120 && (int)me->query_skill("bahuang-gong", 1)<120 )
                return notify_fail("��ı����ڹ�������죬����ʹ����÷չ��\n");

        if( (int)me->query("neili", 1) < 350 || (int)me->query("max_neili",1)<200 )
                return notify_fail("����������̫��������ʹ����÷չ��\n");

        msg = HIC "$N�ַ�ͻȻ�ӿ죬Ѹ������$n��ץס$nһֻ�ֱۣ��������ۡ�\n"NOR;

       // if( !target->is_fighting(me) ) me->kill_ob(target);

        if (random(me->query("combat_exp")) > target->query("combat_exp")/3 )
        {
                me->start_busy(3);

                damage = (int)me->query_skill("zhemei-shou", 1) + (int)me->query_skill("force",1);

                damage = damage/2 + random(damage/2 + 30) ;

                target->receive_damage("qi", damage );
		target->receive_damage("qi", damage );
                target->start_busy(6);
                me->add("neili", -200);

                msg += HIR"���$n���ֱ۱�$N���۵��޷�������ֻ��һ����ʹ���̡�\n"NOR;
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);
        }
        else
        {
                me->start_busy(2);
                msg += CYN"����$p����һ�����˿�ȥ��\n"NOR;
		message_combatd(msg, me, target);
		target->start_busy(1);
        }

if (skill>300 && me && target)
{
 msg = HIC "\n$N" HIC "����ң��÷�����仯Ϊһʽ����������ӳ�������"
              "ʵʵ����$n" HIC "ȫ���ҪѨ��\n" NOR;
 
        ap = me->query_skill("hand");
        dp = target->query_skill("parry");
        

        if (ap / 2 + random(ap) > dp || random(3)==0)
        {
               
                msg += HIR "$n" HIR "��ͷһ�����벻���ƽ�֮������æ��"
                      "��������һʱ���޷�������\n" NOR;
                target->start_busy(7);
        } else
        {
                msg += CYN "����$p" CYN "�Ŀ�����$P" CYN "����ͼ��˿"
                      "����Ϊ��������$P" CYN "������û������κ����á�\n" NOR;
                me->start_busy(2);
        }
        message_combatd(msg, me, target);
	
}	

if (skill>500 && me && target)
{
msg = HIB "\n$N" HIB "���ּ��裬ʩ����ң��÷�֡���Ԩʽ�����ַ�"
              "��翣�����ʵʵ����$n" HIB "Ҫ����\n" NOR;

        
        ap = me->query_skill("hand");
        dp = target->query_skill("dodge");
        if (ap / 2 + random(ap) > dp || random(3)==0)
        {
                damage = me->query_skill("hand",1) * 2+200;

   target->add("qi",-damage*2);
		target->add("eff_qi",-damage*2);
                msg += HIR "��ʱ������Ӱ��Ϊһץ��$p" HIR "��"
                                           "�ܲ�������$N" HIR "��ָ�������ţ���Ѫ"
                                           "�Ĵ��ɽ���\n" NOR;


                me->start_busy(2);
        } else 
        {
      
                msg += HIC "����$p" HIC "�������ݣ����μ�ת������Ķ����$P"
                       HIC "�Ĺ�����\n"NOR;
                me->start_busy(2);
        }
        message_combatd(msg, me, target);	
}

if (skill>600 && me && target)
{
	msg = HIC "\n$N" HIC "˫������ʵʵ��ץ��$n"
              HIC "��Ҫ��������翣���ʽ���أ���������׽����\n" NOR;

        ap = me->query_skill("hand") + me->query("str") * 20;
        dp = target->query_skill("dodge") + target->query("dex") * 20;
             
        if (ap / 2 + random(ap) > dp || random(3)==0)
	{
		damage = me->query_skill("hand",1)*2+300;
		me->add("neili", -100);
                target->add("qi",-damage*2);
		target->add("eff_qi",-damage*2);
                msg += HIR "$p" HIR "һ�����ܲ����������$P"
                                           HIR "ץ�˸����У�������Ϣ���ɵ�һ�ͣ���Ѫ��ӿ��\n" NOR;

		me->start_busy(2);
	} else 
	{
		msg += HIC "����$p" HIC "�������ݣ�����Ķ����$P"
                       HIC "�Ĺ�����\n"NOR;
		me->add("neili", -50);
		me->start_busy(3);
	}
	message_combatd(msg, me, target);
}
        return 1;
}
