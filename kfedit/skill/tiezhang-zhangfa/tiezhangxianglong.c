// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

#define ZHUI "��" HIW "����׶" NOR "��"
#define KAI "��" HIW "�Ƽ���ɽ" NOR "��"
#define CHU "��" HIM "�����Ⱥ" NOR "��"

int perform(object me, object target)
{
	string msg;
	int extra;
	int i,a,ap,dp;
	int skill;
	object weapon;
        int damage;

	if( !target ) target = offensive_target(me);
        skill=(int)me->query_skill("tiezhang-zhangfa", 1);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���ƽ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	 
    if( (int)me->query("neili", 1) < 600 )
		return notify_fail("�������������㣬����ʹ�ã�\n");	
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�����ƽ�����ֻ�ܿ���ʹ�á�\n");		

	if( (int)me->query_skill("tiezhang-zhangfa", 1) < 50 )
		return notify_fail("��������Ʒ�������죬���������ƽ�����\n");

	if( (int)me->query_skill("guiyuan-tunafa", 1) < 60 )
		return notify_fail("��Ĺ�Ԫ���ɷ�������죬����ʹ�����ƽ�����\n");

   if (me->query_skill_mapped("unarmed") != "tiezhang-zhangfa"
     ||me->query_skill_prepared("strike") != "tiezhang-zhangfa")
                return notify_fail("��û�а�������Ϊ�����мܺͱ�Ϊ�Ʒ���\n");

	extra = me->query_skill("tiezhang-zhangfa",1) / 20;
	extra += me->query_skill("guiyuan-tunafa",1) /20;
 i = extra/4;
    if( (int)me->query("neili", 1) <  (80 * i) )
		return notify_fail("�������������㣬����ʹ�ã�\n");	
        me->add_temp("apply/attack", 100);    
        me->add_temp("apply/damage", 1900);
	msg = HIR  "$N����۹�Ԫ���ɷ��ݣ�ͬʱʹ�������ƽ�����һ��һ����������糱ˮ��Ļ���$n��" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg =  HIW "��һ����������������\n" NOR;
        message_vision(msg, me, target);
a=extra/3;
if (a> 11) a=11;
        for(i=0;i<a;i++)
	{
	msg = HIC "$N����ͻת��һ���ִ��˹�����\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	}
i = extra/4;
        me->add_temp("apply/attack", -100);
        me->add_temp("apply/damage", -1900);
me->start_busy(3);
me->add("neili", - 30 * i);
if (skill>200 && me && target)
{
 msg = HIY "\n$N" HIY "һ����Ц��˫��һ����Ȼʩ��һ��"
              "��" HIW "����׶" HIY "�����ó�ǧ��֮����һ��"
              "����$n" HIY "��" NOR;

if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
        {
                me->start_busy(1);
                damage = me->query_skill("tiezhang-zhangfa",1)+100;
                damage = damage  + random(damage);
         if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
                target->receive_damage("qi",damage*2,me);
                target->receive_wound("qi",damage*2,me);
                msg +=HIR "\n���$p" HIR "û�ܱܿ�$P" HIR
                                          "���Ī����Ʒ����ƾ���ʱ͸�ض�����"
                                          "������Ѫ������ˤ����\n" NOR;
        } else
        {
                me->start_busy(2);
                msg = CYN "\n����$p" CYN "ʶ����$P"
                      CYN "��һ�У�ббһԾ�ܿ���\n" NOR;
        }
        message_combatd(msg, me, target);
	
}	

if (skill>300 && me && target)
{
        ap = me->query("combat_exp",1);
        dp = target->query("combat_exp",1);

        msg = HIC "\n$N" HIC "��Хһ����ʩ�����С�" HIW "��ɽ��" HIC "����һ"
              "ȭ�ӳ����ƿն��죬ֱ��$n" HIC "���ź��ؿڡ�\n" NOR;
        


if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
        {
                damage = (int)me->query_skill("tiezhang-zhangfa", 1)+100;
                damage += random(damage)+300;
         if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
                target->receive_damage("qi",damage*2,me);
                target->receive_wound("qi",damage*2,me);
                msg +=HIR "\n $N" HIR "���ּȿ죬��λ���棬$n"
                                          HIR "���ܲ������ƺ�һ������Ȼ��ȭ��\n" NOR;


	        me->start_busy(1);                                         
        } else
        {
                msg = CYN "$n" CYN "���Ų�æ���Կ��죬��$N"
                      CYN "���л�ȥ��\n" NOR;


	        me->start_busy(2);
        }
        message_combatd(msg, me, target);
	
}	

if (skill>400 && me && target)
{

        ap = me->query("combat_exp",1);
        dp = target->query("combat_exp",1);

        msg = HIC "\n$N" HIC "�ڿն���ʩչ�����С�" HIM "�����Ⱥ" HIC "����"
              "\n����һֻ�����ٿն��£�˫���͵�����$n" HIC "��\n" NOR;


if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
        {
                damage = (int)me->query_skill("strike", 1)+(int)me->query_skill("tiezhang-zhangfa", 1);
                damage = damage+300+random(300);
         if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
                target->receive_damage("qi",damage*2,me);
                target->receive_wound("qi",damage*2,me);
                msg +=HIR "����$N" HIR "˫���������Ʒ����죬"
                                           "����Ѹ���ޱȡ�$n" HIR "�پ��ľ���ս��"
                                           "�����м�֮����΢�����ɼ�$N" HIR "\n����"
                                           "������$n" HIR "�ؿڣ��ٽ�$p����������"
                                           " \n" NOR;
                target->apply_condition("tiezhang_yang",50);
target->apply_condition("tiezhang_yin",50);
                me->start_busy(1);

        } else
        {
                msg = CYN "$n" CYN "��$N" CYN "��������������"
                      "��ӯ��ֻ�����һ�ݣ��Ŷ����һ�ơ�\n" NOR;

                me->start_busy(2);

        }
        message_vision(msg, me, target);
}
	return 1;
}
