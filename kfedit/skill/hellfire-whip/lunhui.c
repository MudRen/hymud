//Cracked by Roath

//�����ֻ�

#include <ansi.h>
 
inherit F_DBASE;
inherit F_SSERVER;
 
void delay_effect(object me, object target, object weapon,int power);
 
int perform(object me, object target)
{
        int delay,skill;
        object weapon=me->query_temp("weapon");
        
        if( !target ) target = offensive_target(me);
        if( !target 
        ||      !target->is_character() 
        ||      target->is_corpse() 
        ||      target==me) 
                return notify_fail("��Ҫ��˭ʩչ����������\n"); 
        if (!target) return notify_fail("��˭��\n");
        if(environment(me)!=environment(target))
                return notify_fail("��Ҫ�������˲������\n");
        if (!me->is_fighting(target))
                return notify_fail("���ǲ��ڴ�ܡ�\n");

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���ž�ѧֻ�ܶ�ս���еĶ���ʹ�á�\n");
		
        skill=me->query_skill("buddhism",1);        
        if (skill<160) return notify_fail("��������ķ��������졣\n");

    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "whip")
        return notify_fail(RED"��ʲô��Ц���������ԣ�\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "zhanzhuang-gong")
                return notify_fail("��ʹ����ƽ����վ׮��!\n");
                if((int)me->query_skill("yijinjing", 1) < 150)
                return notify_fail("����׽���𻹲�����ʹ����һ�л������ѣ�\n");
        if((int)me->query("neili") < 1000 )
                return notify_fail("�������������\n");

        if((int)me->query("qi") < 300 )
                return notify_fail("�����Ѫ���㣬û����ʩ���⹦��\n");

        if((int)me->query_skill("hellfire-whip", 1) < 100)
                return notify_fail("��������һ�޼��𻹲�����ʹ����һ�л������ѣ�\n");
                
        skill=me->query_skill("whip");
        if (skill<100) 
                return notify_fail("��ı޷�̫��ˡ�\n"); 
        if( (int)me->query("neili") < 300 )      
                return notify_fail("�������������\n");
        if( (int)me->query_temp("lunhui_delay") )
                return notify_fail("���Ѿ���ʩչ�����ˡ�\n");
        
        me->add("neili", -200);
        delay=random(2)+1;
        message_vision(HIB"$N��������һЦ������"+weapon->name()+
             HIB"ͻȻ����������$nһ����ϲ��ץס���ᣬ��ǰ����һ�ּ�����\n"NOR, me,target);
        me->start_busy(delay);
        //tell_object(me,delay+"\n");
        me->set_temp("lunhui_delay", 1);
        me->start_call_out( (: call_other, __FILE__, "delay_effect", 
me, target,weapon,delay:), delay);
 
        return 1;
}
 
void delay_effect(object me,object target,object weapon,int power)
{
        mapping action;
        mapping new_act=([]);
        int attack,damage;
        
        me->delete_temp("lunhui_delay");
        if (!target) return;
        if (environment(me)!=environment(target)) return;
        if (me->query_temp("weapon")!=weapon) return;

        message_vision(HIR"$N����ͻȻһ�䣬����"+weapon->name()+
            HIR"���������Ӱ����$n����·ȫ��������\n"NOR,me,target);
        message_vision(HIR"$N���������������������ܶ������ܹ�������ֻ�֮�࣬������͸��������\n"NOR,target);

        me->set("actions", (: call_other, SKILL_D("hellfire-whip"), "query_pfm_action" :) );

        attack=me->query_temp("apply/attack");
        damage=me->query_temp("apply/damage");
        me->add_temp("apply/attack",me->query_skill("hellfire-whip",1));
        me->add_temp("apply/damage",1200);
        COMBAT_D->do_attack(me, target, weapon);
        COMBAT_D->do_attack(me, target, weapon);
        COMBAT_D->do_attack(me, target, weapon);
        COMBAT_D->do_attack(me, target, weapon);
        COMBAT_D->do_attack(me, target, weapon); 
        COMBAT_D->do_attack(me, target, weapon); 
        me->add_temp("apply/attack",-me->query_skill("hellfire-whip",1));
        me->add_temp("apply/damage",-1200);
        message_vision(HIR"\n$N���ƽ�����$n���ܵĹ�𽥽���ʧ��ѹ�����᲻�٣�\n"NOR,me,target);
        me->reset_action();
        me->start_busy(1);
        target->start_busy(2);
}

