#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int damage;
        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("��ɷֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( (int)me->query_skill("dafumo-quan", 1) < 200 )
                return notify_fail("��Ĵ��ħȭ������죬�޷�ʹ����ɷ��\n");
        if( (int)me->query_skill("jiuyin-zhengong", 1) < 200 )
                return notify_fail("��ľ����湦������죬�޷�ʹ����ɷ��\n");

        if ( (int)me->query("max_neili") < 6000)
                return notify_fail("��������������޷�ʹ����ɷ��\n");

        if ( (int)me->query("neili") < 10000)
                return notify_fail("��������������޷�ʹ����ɷ��\n");

      msg = HIR "$N˫ȭ������˲Ϣ��������ȭ���ֻ�$nȫ�����Ǵ���ȭ���������Ǿۻ᡹��\n" NOR;

        message_vision(msg, me, target);
        me->add_temp("apply/attack", 200);
        me->add_temp("apply/damage", 3000);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1); 
              msg = HIR "$Nһȭ�ȳ�������һת������$n��࣬˫ȭ���٣�ͬʱ�򵽡�\n" NOR;
        message_vision(msg, me, target);
              COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
              
              msg= HIR "$N˫ȭ�����������꣬����$n�硢�ۡ��ء���������λ������������ݡ�\n" NOR;
        message_vision(msg, me, target);
              COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
              COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
              COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
                 COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
              COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);  
        me->add_temp("apply/attack", -200);
        me->add_temp("apply/damage", -3000);
        
        msg = HIY"$NͻȻ�۾�һ��������һ������ʹ��ȫ���������ȭ��$n��ȥ��\n";
        //me->start_perform(10,"��ɷ");

	if (	random(me->query("combat_exp")) > target->query("combat_exp")/3	)
{
	damage=target->query("neili")/3;
	if (damage>60000) damage=60000;
                msg += HIR"$n��������������С����$nֻ����һ��ǿ���ľ������������Լ���������\n";
                msg += HIR"$nֻ���õ������絶���Ϣֱ����������\n"NOR;
                target->add("max_neili",-(random(me->query_skill("dafumo-quan",1)/20)+5));
                target->add("neili",-damage);
                //target->set("jiali",0);
                me->add("neili", -100);
                //me->set("jiali", 0);
        } 
        else {
                msg += HIG"$n���������ң���æ����һ�ԡ�\n" NOR;
        }
        message_vision(msg, me, target);
        me->start_busy(2);
 me->add("neili", -100);
        return 1;
}

