// 
// nx.c ��Ѫ��ץ
// by secret
 
#include <ansi.h>
 
inherit F_SSERVER;
 
int perform(object me)
{
	string msg;
	object weapon, target;
        int skill;
        int neili_wound, qi_wound ;

	me->clean_up_enemy();
	target = me->select_opponent();

        skill = me->query_skill("unarmed",1);

	if( !(me->is_fighting() ))
                return notify_fail("����Ѫ��ץ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 

	if (objectp(weapon = me->query_temp("weapon")))
                return notify_fail("��Ѫ��ץ�������ʹ�á�\n");


        if( skill < 150)
                return notify_fail("��ġ���Ѫ��ץ���ȼ�����, ����ʹ������Ѫ��ץ����\n");

        if( me->query("neili") < 1000 )
                return notify_fail("��������������޷�ʹ����Ѫ��ץ��\n");
 
        msg = HIC "$N���������ʹ��һ�С���Ѫ��ץ������$n���ؿ�ץȥ��\n"NOR;

	message_vision(msg, me, target);

	{
		if(userp(me))
                        me->add("neili",-800);

        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 )
         {
                msg = HIG "$nֻ������ǰһ�ڣ����ۡ���һ�����һ����Ѫ��\n"NOR;

                neili_wound = 1000 + random(skill);
		if(neili_wound > target->query("neili"))
			neili_wound = target->query("neili");


                qi_wound = neili_wound;
if (qi_wound <100) qi_wound=100;
if (neili_wound <100) neili_wound=100;
if (qi_wound <10) qi_wound=10;
if (qi_wound >100000) qi_wound=100000;
if (neili_wound <10) neili_wound=10;
if (neili_wound >100000) neili_wound=100000;
		target->add("neili", -neili_wound);
		target->add("qi", -qi_wound);
	        target->add("eff_qi",-qi_wound);
                me->start_busy(random(4)+1);
        } else {
                msg += "����$p������$P����ͼ���ӳ���$P��һץ��\n" NOR;
                me->start_busy(3);
        }
	}
	message_vision(msg, me, target);

	return 1;
}
