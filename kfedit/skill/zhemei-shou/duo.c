// duo.c ���������
 
#include <ansi.h>
 
inherit F_SSERVER;

int perform(object me)
{
	string msg;
	object weapon, weapon2, target;
	int skill, dp, damage,ap;

	me->clean_up_enemy();
	target = me->select_opponent();

	if( (int)me->query_temp("duo") )
		return notify_fail("���Ѿ��ڶ���˵ı����ˡ�\n");
	skill = me->query_skill("zhemei-shou",1);

	if( !(me->is_fighting() ))
		return notify_fail("���������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
	if (objectp(weapon = me->query_temp("weapon")))
		return notify_fail("�������֡�\n");

	if (!objectp(weapon2 = target->query_temp("weapon")))
	   return notify_fail("�Է�û�б��У��㲻�õ��ġ�\n");

	if( skill < 50)
		return notify_fail("�����ɽ��÷�ֵȼ�����, ���ܿ�������У�\n");

        if (((int)me->query_skill("bahuang-gong", 1) < 50) &&
            ((int)me->query_skill("beiming-shengong", 1) < 50 ))
        return notify_fail(RED"�㱾���ڹ���򲻹���ʹ���������ֶ���С���\n"NOR);

	if( me->query("neili") < 50 )
		return notify_fail("��������������޷���������У�\n");
 
	msg = CYN "$N�����Ϣ������ʩչ��������еľ���. \n";
	message_combatd(msg, me);
     if( weapon2->query("ownmake"))
                return notify_fail("�����������᲻������\n");
     if( weapon2->query("no_get") && weapon2->query("no_drop") )
                return notify_fail("�����������᲻������\n");

	dp = target->query_skill("dodge",1);
	if( dp < 1 )
		dp = 1;
	if( random(skill) > random(dp) )
	{
		if(userp(me))
			me->add("neili",-50);
if (!weapon2->query("systemmake") && !weapon2->query("ownmake"))
{
		msg = "$Nʹ����������еľ���, $n��ʱ������ǰһ��������һ�飬���б������ֶ�����\n" NOR;
		target->start_busy(2);
		weapon2->move(environment(me));

		if (weapon2->query("ownmake")==1)
		{
			weapon2->move(target);
			msg += "�ǿ���$n������һ$n��һ�콫���������\n" NOR;
		}
		
		me->start_busy(2);
}		
	}
	else
	{
		msg = "����$n�Ŀ�����$N����ͼ�����̲�ȡ���ƣ�ʹ$Nû�ܶ��±��С�\n"NOR;
		me->start_busy(2);
	}
	message_combatd(msg, me, target);


if( (int)me->query_skill("liuyang-zhang", 1) > 200 )
{
 msg = HIB "$N" HIB "���ּ��裬ʩ����ң��÷�֡���Ԩʽ�����ַ�"
              "��翣�����ʵʵ����$n" HIB "Ҫ����\n" NOR;

        me->add("neili", -50);
        ap = me->query_skill("hand");
        dp = target->query_skill("dodge");
        if (ap / 2 + random(ap) > dp  || random(3)==0)
        {
                damage = me->query_skill("hand",1)+200;
                me->add("neili", -100);
   target->add("qi",-damage*2);
		target->add("eff_qi",-damage*2);
                msg += HIR "��ʱ������Ӱ��Ϊһץ��$p" HIR "��"
                                           "�ܲ�������$N" HIR "��ָ�������ţ���Ѫ"
                                           "�Ĵ��ɽ���\n" NOR;


                me->start_busy(2);
        } else 
        {
                me->add("neili", -50);
                msg += HIC "����$p" HIC "�������ݣ����μ�ת������Ķ����$P"
                       HIC "�Ĺ�����\n"NOR;
                me->start_busy(2);
        }
        message_combatd(msg, me, target);
}	

if( (int)me->query_skill("liuyang-zhang", 1) > 300 )
{
msg = HIC "$N" HIC "˫������ʵʵ��ץ��$n"
              HIC "��Ҫ��������翣���ʽ���أ���������׽����\n" NOR;

        ap = me->query_skill("hand") + me->query("str") * 20;
        dp = target->query_skill("dodge") + target->query("dex") * 20;
             
        if (ap / 2 + random(ap) > dp || random(3)==0)
	{
		damage = me->query_skill("hand",1)+100;

  target->add("qi",-damage*2);
		target->add("eff_qi",-damage*2);
                msg += HIR "$p" HIR "һ�����ܲ����������$P"
                                           HIR "ץ�˸����У�������Ϣ���ɵ�һ�ͣ���Ѫ��ӿ��\n" NOR;

		me->start_busy(2);
	} else 
	{
		msg += HIC "����$p" HIC "�������ݣ�����Ķ����$P"
                       HIC "�Ĺ�����\n"NOR;

		me->start_busy(3);
	}
	message_combatd(msg, me, target);
}
	return 1;
}
