// tulong.c ����ױ�������

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int skill, ap, dp;
        int force_wound, kee_wound ;
         string msg;
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С�����ױ�����������\n");

  if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("ֻ����ս����ʹ�á�\n");

 if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
        return notify_fail(RED"��ʲô��Ц���������ԣ�\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "lengyue-shengong")
                return notify_fail("��ʹ��������!\n");

        if((int)me->query_skill("lengyue-shengong",1) < 200)
                return notify_fail("��������񹦻�����������\n"); 
        if((int)me->query("neili") < 500 )
                return notify_fail(WHT"����������㡣\n"NOR);

        if(!me->is_fighting())
                return notify_fail("������ױ���������ֻ����ս����ʹ�ã�\n");

        if((int)me->query("max_neili") < 500 )
                return notify_fail("�������������\n");

	if((int)me->query("neili") < 500 )
		return notify_fail("����������㣡\n");

        if((int)me->query("jing") < 500 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");

        if((int)me->query_skill("zileidao", 1) < 200)
                return notify_fail("������׵������𻹲�����ʹ����һ�л������ѣ�\n");

 
        me->delete("env/brief_message");
	target->delete("env/brief_message");

	message_vision(HIC"\n$N���㾫������һת��������������$n���������У�\n"NOR,me,target);
        me->add_temp("apply/attack", 100);
        me->add_temp("apply/damage", 800);
            target->start_busy(1);
        message_vision(HIC"\n$N��һ�С������ױ�����"NOR,me,target);
        me->set_temp("QJB_perform", 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        message_vision(HIC"\n$N�ڶ��С������׵�����"NOR,me,target);
        me->set_temp("QJB_perform", 2);  
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 

        message_vision(HIC"\n$N�����С��������׺䣡"NOR,me,target);
        me->set_temp("QJB_perform", 3);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
        message_vision(HIC"\n$N�����С�������������"NOR,me,target);
        me->set_temp("QJB_perform", 4);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
        message_vision(HIC"\n$N�����С��������������"NOR,me,target);
        me->set_temp("QJB_perform", 5);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
        message_vision(HIC"\n$N�����С������ױ�������"NOR,me,target);
        me->set_temp("QJB_perform", 6);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
        message_vision(HIC"\n$N�����С���ŭ��˺���ѵأ�"NOR,me,target);
        me->set_temp("QJB_perform", 7);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->delete_temp("QJB_perform");

        me->add_temp("apply/attack", -100);
        me->add_temp("apply/damage", -800);
        me->add("qi", -100);



me->start_busy(3);

if ((int)me->query_skill("zileidao",1)>= 380)
	{
  msg = HIC "$N�������ƣ�ʹ��һ�С��׻��ɱ������$n���ؿڻ�ȥ��\n"NOR;

        message_vision(msg, me, target);

        ap = me->query("combat_exp") + skill * 800;
        dp = target->query("combat_exp") ;

        if( dp < 1 )
                dp = 1;
        if( random(ap+dp) > (dp*3/7) )
        {
                if(userp(me))
                        me->add("neili",-100);

                msg = HIG "$nֻ������ǰһ�ڣ����ۡ���һ�����һ����Ѫ��\n"NOR;

                force_wound = 200 + random(skill)*3;
                if(force_wound > target->query("neili"))
                        force_wound = target->query("neili");


                    kee_wound = force_wound /2;
                              
                if(kee_wound > target->query("eff_qi"))
                        kee_wound = target->query("eff_qi");
        if (kee_wound < 0) kee_wound=100;
if (kee_wound> 8000) kee_wound=8000;
                target->receive_damage("qi", kee_wound);
                target->receive_wound("qi", kee_wound/3);
                me->start_busy(2);
                target->start_busy(2);
             

       }
        else
        {
                msg = HIG "ֻ��$n���Ų�æ������һ���������$N�ı�ɱһ����\n"NOR;
                if(userp(me))
                        me->add("neili",-100);
                me->start_busy(2);
        }
        message_vision(msg, me, target);
}
  
        return 1;
}

