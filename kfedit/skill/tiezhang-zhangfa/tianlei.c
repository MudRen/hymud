// tianlei.c ����--������

#include <ansi.h>


#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	int damage;
        int extra;
        string msg;
        object weapon;
        int ap, dp;
        int count;
        int i,skill;
        
	if( !target ) target = offensive_target(me);
skill=me->query_skill("tiezhang-zhangfa",1);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( objectp(me->query_temp("weapon")) )
		return notify_fail("�������ֲ���ʹ����������\n");

        if( (int)me->query_skill("guiyuan-tunafa", 1) < 119 )
		return notify_fail("�����������δ���ɣ�����ʹ�ã�\n");

        if( (int)me->query("neili", 1) < 600 )
		return notify_fail("�������������㣬����ʹ����������\n");	

	if( (int)me->query_skill("tiezhang-zhangfa", 1) < 119 )
		return notify_fail("��������Ʒ�������죬����ʹ����������\n");

   if (me->query_skill_mapped("unarmed") != "tiezhang-zhangfa"
     ||me->query_skill_prepared("strike") != "tiezhang-zhangfa")
                return notify_fail("��û�а�������Ϊ����ȭ�źͱ�Ϊ�Ʒ���\n");

        extra = me->query_skill("tiezhang-zhangfa",1) / 20;
	extra += me->query_skill("guiyuan-tunafa",1) /20;
    if( (int)me->query_skill("guiyuan-tunafa", 1) > 200 )
    {
        me->add_temp("apply/attack", 100);    
        me->add_temp("apply/damage", 1900);
	    msg = HIC"$N��һ�ƣ�"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIG"$N��һ�ƣ�"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIY"$N��һ�ƣ�"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIR"$N��һ�ƣ�"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIR"$N���һ�ƣ�"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       // me->add("neili",-150);
        me->add_temp("apply/attack", -100);    
        me->add_temp("apply/damage", -1900);

    }


    msg = HIY "\n$N��Ȼ������һ������ �� ������˫����糵������������һ�����������ƿ�쭶������Ʋ��ɵ���\n"NOR;

	if( weapon = target->query_temp("weapon") ){
        if( random(me->query("str")) > (int)target->query("str")/2 ) {  
if (!weapon->query("systemmake") && !weapon->query("ownmake"))
{
    msg += HIM"\n$pֻ���û���һ�ȣ����ƻ��ھ�ʹ������"
                + target->query_temp("weapon")->query("name") + "���ֶ�����\n" NOR;
		message_vision(msg, me, target);
		(target->query_temp("weapon"))->move(environment(target));
		target->start_busy(3);
}
                target->receive_damage("qi", (me->query_skill("tiezhang-zhangfa",1)*2),me);
target->receive_wound("qi", (me->query_skill("tiezhang-zhangfa",1)*2),me);     
	} else {
    msg += HIY"\n$pΣ����ͻȻ���ط����������ܹ���������һ�������ŵ���ɫ�԰ף�\n" NOR;
		message_vision(msg, me, target);
	}
	me->start_busy(1);
        }
        else
        {
if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
	{
		me->start_busy(3);
		target->start_busy(random(3));
		
		damage = (int)me->query_skill("guiyuan-tunafa", 1);
		
                damage = damage*6 + random(damage);
		
         if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
                target->receive_damage("qi",damage,me);
                target->receive_wound("qi",damage,me);
		
		if( damage < 300 ) msg += HIY"\n���$n��ɫһ�±�òҰף��������������˺ü�����\n"NOR;
        	else if( damage < 400 ) msg += HIY"\n������صػ��У�$n���ۡ���һ���³�һ����Ѫ��\n"NOR;
        	else if( damage < 500 ) msg += RED"\n������䡹��һ����$nȫ����Ѫ������������Ѫ���������\n"NOR;
        	else msg += HIR"\n���ֻ���������������죬$nһ���ҽУ���̲�����������ȥ����\n"NOR;
		
	} else 
	{
		me->start_busy(2);
    msg += HIY"\n$pΣ����ͻȻ���ط����������ܹ���������һ�������ŵ���ɫ�԰ף�\n" NOR;
	}
	message_vision(msg, me, target);

        }
        me->add("neili", -200);
if (skill>300 && me && target)
{
   msg = HIR "$N" HIR "һ��ŭ�ȣ���Ȼʩ�������Ʒ�������" NOR + WHT 
              "����ɲ��" NOR + HIR "����������������������ת��˫�۶�"
              "Ȼ\n�������ߡ�ֻ���ƿ�֮�����죬˫�ƻó�������Ӱ������"
              "�ǵ���$n" HIR "�����ĳ���\n\n" NOR;
        ap = me->query("combat_exp",1);
        dp = target->query("combat_exp",1);
        if (ap / 2 + random(ap) > dp || random(3)==0)
        {
                ap = me->query_skill("tiezhang-zhangfa");
                count = ap / 15;
                msg += RED "$n" RED "���$P" RED "����ɽ�������ƣ���ȫ"
                       "�޷��ֵ���Ψ���˺�\n" NOR;
        } else
        {
                msg += HIC "$n" HIC "����Ӧս���߾����ܻ���$P" HIC "��"
                       "���ơ�\n" NOR;
                count = 0;
        }

        message_vision(msg, me, target);
        me->add_temp("apply/attack", 100);
        me->add_temp("apply/damage", 2200);	
        //me->add("neili", -300);
        //me->add("qi", -100);    // Why I don't use receive_damage ?
                                // Becuase now I was use it as a cost
        for (i = 0; i < 7; i++)
        {
                if (! me->is_fighting(target))
                        break;
                if (random(5) < 2 && ! target->is_busy())
                        target->start_busy(2);

                COMBAT_D->do_attack(me, target, 0, 0);
        }

        me->start_busy(2);
        me->add_temp("apply/damage", -2200);	
        me->add_temp("apply/attack", -100);	
}	        
	return 1;
}
