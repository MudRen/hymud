// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	int i,a;
	object weapon;
        int ap, dp;
        int damage;	
	
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("̫�������������־�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if( (int)me->query("neili") < 400  ) 
		return notify_fail("�������������\n");

	if( (int)me->query_skill("taiji-jian", 1) < 50 )
		return notify_fail("���̫������������죬�����á������־���\n");

	if( (int)me->query_skill("taiji-shengong", 1) < 60 )
		return notify_fail("���̫���񹦲�����죬����ʹ�á������־���\n");

	extra = me->query_skill("taiji-jian",1) / 20;
	extra += me->query_skill("taiji-shengong",1) /20;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", 300);
	msg = HIR  "$N�����̫���񹦣ݣ�ͬʱʹ����̫�������Уݵġ������־������е�"+ weapon->name() +" һ������һ�л���Ȧ���������Ļ���$n��" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	msg =  HIW "����һ������ʧ��������\n" NOR;
        message_vision(msg, me, target);
a=extra/3;
if (a> 16) a=16;


	for(i=0;i<a;i++)
	{
       if (random(2)==0 && !target->is_busy()) target->start_busy(2);
		
	msg = HIY "$N�ý�����һ��Ȧ��һ��������������\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	}
	i = extra/4;
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -300);
	me->add("neili", - 20 * i);
	me->start_busy(3);
	

    if( (int)me->query_skill("taiji-jian", 1) > 200 )
    {
        msg = HIG "$Nʹ��̫�������������־�������Ȧת�����಻������������������ͼ����$n�Ĺ��ơ�\n";

        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 || random(3)==0) {
                msg += HIR " ���$p��$P�ָ���æ���ң�����ʧ�룬���ڵ�������֪���Ӧ�ԣ�\n" NOR;
                target->start_busy(6);
        } else {
                msg += "����$p������$P����ͼ������㣬ȫ��Ӧ�����硣\n" NOR;
                me->start_busy(2);
        }
        message_combatd(msg, me, target);
    
    
    if( (int)me->query_skill("taiji-jian", 1) > 300 )
    {
    	me->add_temp("apply/attack", 100);	
	me->add_temp("apply/damage", 300);
    msg = HIC"$n����������һ������������$n�������˵�һ��Ȧ��"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIG"$n����������һ������������$n���жλ��˵ڶ���Ȧ��"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIY"$n����������һ������������$n�������˵�����Ȧ��"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    	me->add_temp("apply/attack", -100);	
	me->add_temp("apply/damage", -300);

    }
}

    if( (int)me->query_skill("taiji-jian", 1) > 600 )
    {
   msg = HIW "$N" HIW "һ����ߣ�����" + weapon->name() +
              HIW "һ�񣬽���΢������������������Я����������"
              "ͬʱ����$n" HIW "��\n" NOR;

        
        ap = me->query_skill("sword");
        dp = target->query_skill("parry");
        if ((int)target->query("shen") < 0) ap += ap / 5;

        me->start_busy(3);
        if (ap / 2 + random(ap) > dp || random(3)==0)
        {
                damage = me->query_skill("sword",1)+me->query_skill("taiji-jian",1)+500;
                target->add("qi",-damage);
		target->add("eff_qi",-damage);
                msg += HIR "ֻ��$n" HIR "һ���ҽУ�����һ�����ض��룬��"
                "ʱ��Ѫ�Ĵ��ɽ���\n" NOR;
        } else
        {
                msg += HIC "��$n" HIC "ȴ������㣬һ˿���ң�"
                       "ȫ�񽫴��л��⿪����\n" NOR;
        }
        message_combatd(msg, me, target);

}	
	return 1;
}

