#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra,i,lmt,l;
	object weapon;
	int skill, ap, dp, neili_wound, qi_wound;

	
       if( !target ) target = offensive_target(me);
       if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("[���Ӹ���]ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if( (int)me->query_skill("biyun-xinfa", 1) < 60 )
                return notify_fail("��ı����ķ������ߡ�\n");
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "throwing")
		return notify_fail("��ʹ�õ��������ԡ�\n");
		
        if( (int)me->query("neili", 1) < 400 )
                return notify_fail("����������̫����\n");

	weapon = me->query_temp("weapon");
	extra = me->query_skill("zimu-zhen",1);
	skill = me->query_skill("zimu-zhen",1);
	if ( extra < 200) return notify_fail("������Ű������������죡\n");
	msg = GRN  "$Nʹ�����Ű����е����Ӹ��ڣ�����$n" NOR;
	message_vision(msg,me,target);
	me->add_temp("apply/attack",100);
	me->add_temp("apply/damage",1900);
        l=extra/30;
	lmt = random(l)+5;
	for(i=1;i<=lmt;i++)
	{
	msg =  BLU "��"+chinese_number(i)+"��-->" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	}
	        me->add_temp("apply/attack",-100);
        me->add_temp("apply/damage",-1900);
	
if (extra > 200)
{
        target->apply_condition("chanchu_poison", 60);
        target->apply_condition("xiezi_poison", 60);
        target->apply_condition("wugong_poison", 60);
        target->apply_condition("snake_poison", 60);
        target->apply_condition("zhizhu_poison", 60);

}

if (extra > 300)
{
        target->apply_condition("tmzhuihun_poison", 60);
        target->apply_condition("tmpili_poison", 60);
        target->apply_condition("zm_poison", 60);
}
	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 ) {
        target->apply_condition("tmqidu_poison", 60);
	} 


if (skill>350 && me && target)
{
	msg = HIG "$N˫ĿͻȻ���������̹�,��ָ�ڲ��ײ����΢΢һ��,һ������������Ϣ����$nü�ġ�\n"NOR;

	me->start_busy(1);
	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 || random(3)==0) {
		msg += HIR " ���$p��$P�ġ����꡹������ţ�˲����־��ʼ�Ժ�������\n" NOR;
                target->start_busy(8);
	
	target->apply_condition("anqi_poison", 30);
	target->apply_condition("tmzhuihun_poison", 30);
	target->apply_condition("tmpili_poison", 30);
        target->apply_condition("tmqidu_poison", 30);
	} else {
		msg += "����$p��ǧ��һ��֮������������һ����\n" NOR;
	}
	message_vision(msg, me, target);	
}	

if (skill>600 && me && target)
{
	me->add_temp("apply/attack", 100);	
	me->add_temp("apply/damage", 1900);
msg = RED "$N����һ����Ŷ��Ű���----��һ�������ŷ�ɥ�����ƻ���$n���˳�ȥ��\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	
msg = RED "$N����һ����Ŷ��Ű���----�ڶ��������ŷ�ɥ�����ƻ���$n���˳�ȥ��\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	
msg = RED "$N����һ����Ŷ��Ű���----�����������ŷ�ɥ�����ƻ���$n���˳�ȥ��\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -100);
	me->add_temp("apply/damage", -1900);
        me->add("neili",-10);

	msg = HIY "$N��ָ�뵶��ָ��������ö����,Ǳ��������һʽ�������롹��ֱ��$n���ϡ��С��µ����ȥ��\n";
	message_vision(msg, me, target);
 
	ap = me->query_skill("throwing") + skill;
	dp = target->query_skill("force") / 2;
	if( dp < 1 )
		dp = 1;
	if( random(ap) > dp || random(3)==0 )
	{
		msg = "$N�������롹����Ŀ��, $n��ʱ���õ�����һ���ʹ��\n";
		msg += "ȫ��������й������\n" NOR;
	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 || random(3)==0) {
        target->apply_condition("tmqidu_poison", 30);
	} 
		neili_wound = 600 + (skill*3);
		if(neili_wound > target->query("neili"))
			neili_wound = target->query("neili");

		qi_wound = 600 + (skill*5);
		if(qi_wound > target->query("qi"))
			qi_wound = target->query("qi");
if (qi_wound <10) qi_wound=10;
if (qi_wound >30000) qi_wound=30000;
if (neili_wound <10) neili_wound=10;
if (neili_wound >30000) neili_wound=30000;
		target->add("neili", -neili_wound);
;
target->receive_wound("qi",qi_wound,me);
		target->start_busy(2);
        target->apply_condition("tmpili_poison", 30);

//		me->start_busy(random(2));
	}
	else
	{
		msg = "����$n˲�䷴Ӧ��������Ų��Ծ�����������ش���\n"NOR;
		me->start_busy(2);
	}
	message_vision(msg, me, target);	
}
        me->add("neili",-200);
	me->start_busy(3);
	return 1;
}

