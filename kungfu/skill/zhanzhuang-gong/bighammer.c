// bighammer.c
#include <ansi.h>


#include <combat.h>


inherit F_SSERVER;


int exert(object me)
{
	object target;
	int success_adj, damage_adj;
        object weapon;
        int damage,p;
        string msg,dodge_skill;
//	success_adj = 150;
//	damage_adj = 140;
        success_adj = 170;
        damage_adj = 170;// xintai 1/29/2001 �������������bighammerҲ̫NB��һ��:)
 

        if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���ž�ѧֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( !target 
         || !me->is_fighting(target) 
         || !living(target)
         || environment(target)!=environment(me))
                return notify_fail(WHT"��������ħ�ơ�ֻ�ܶ�ս���еĶ���ʹ�á�\n"NOR);
        if( (int)me->query_skill("buddhism", 1) < 50 )
                return notify_fail("��������ķ��ȼ�������\n");

	if((int)me->query("neili") < 500 )
		return notify_fail("�������������\n");

	if((int)me->query("jing") < 120 )
		return notify_fail("���޷����о������������Լ��ˣ�\n");
	if( me->is_busy() )
		return notify_fail("��������æ���أ����п��˹���\n");
	me->add("neili", -250);
	me->receive_damage("jing", 50);




        msg = HIC "$N�������˼������ģ�������ֳ����У���Ҷ�����ߣ�������ִ\nһ���޴��ޱȵĽ�ħ�ƣ�������һ����$n��ͷ���£�\n" NOR;
        message_combatd(msg, me,target);		
if (random(me->query("combat_exp")) > target->query("combat_exp")/3 && living(target)){
            damage = (int)me->query_skill("zhanzhuang-gong");  //�Ի����ڹ��;����񹦵ĸߵͣ�ȡ��ɱ�����Ĵ�С��
            damage = damage + random(damage);
            damage +=(int)(me->query_skill("buddhism", 1)*8);
if (damage < target->query("qi") || userp(target))
{
	if ( userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
            target->receive_damage("qi", damage,me);
            target->receive_wound("qi", damage,me);
}
		msg=HIC "����Ҹ����ţ����û��$n�ұ⣡\n" NOR;
}
else
{
		msg="����$n��ǧ��һ��֮�ʶ��˿�����\n" NOR; 
}
message_combatd(msg, me,target);		
			//backfire hit message. note here $N and $n!!!

	me->start_busy(3);
	return 3+random(5);
}

