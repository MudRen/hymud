#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon, ob;
	int extra,i,time;
	string msg;
	extra = me->query_skill("xuantie-sword",1);
	time = extra/50+1; 
	if( !target ) target = offensive_target(me);
if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("���ɺ���硹ֻ����ս����ʹ�á�\n");
	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
			return notify_fail("��ʹ�õ��������ԡ�\n");
	if( userp(me) && (string)weapon->query("id") != "xuantiesword" )
		return notify_fail("�������õĲ�����������\n");
	if((int)me->query_skill("sword") < 205)
		return notify_fail("��Ľ�����Ϊ������ Ŀǰ����ʹ�÷ɺ����! \n");
	weapon = me->query_temp("weapon");
	if( (int)me->query("neili") < 500 )
		return notify_fail("�������������\n");
	msg = HIR  "$N���������һ��������̤���沨�����е�"+ weapon->name()+  HIR"�����ػ���һ�������$n������" NOR;
	message_vision(msg,me,target);
        if (time>12) time=12;
        if (extra>200) extra=200;
	me->add_temp("apply/attack",100);
	me->add_temp("apply/damage",2000);
	for(i=1;i<=(int)time;i++)
	{
	msg =  YEL "$N�������飬�����ݺᣡ\n" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	}
        me->add_temp("apply/attack",-100);
        me->add_temp("apply/damage",-2000);
	me->add("neili",-300);
	me->start_busy(3);
	return 1;
}
