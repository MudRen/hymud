// writted by jie
// 2/2001

#include <ansi.h>
#include <combat.h>


inherit F_SSERVER;

int perform(object me, object target)
{       
        string msg="";
        int damage,wound;
        object weapon=me->query_temp("weapon");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ���ȹ��նɡ���\n");

        if(!me->is_fighting())
                return notify_fail("���ȹ��նɡ�ֻ����ս����ʹ�ã�\n");
        
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���ž�ѧֻ�ܶ�ս���еĶ���ʹ�á�\n");

    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "staff")
        return notify_fail(RED"��ʲô��Ц���������ԣ�\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "zhanzhuang-gong")
                return notify_fail("��ʹ����ƽ����վ׮��!\n");
                        if((int)me->query_skill("yijinjing", 1) < 150)
                return notify_fail("����׽���𻹲�����ʹ����һ�л������ѣ�\n");
        if( (int)me->query("bellicosity") > 300 )
        return notify_fail("���ɱ��̫�أ��޷�ʩչ���ž�����\n");
                

                
        if((int)me->query("max_neili") < 500 )
                return notify_fail("�������������\n");

        if((int)me->query("neili") < 300 )
                return notify_fail("����������㣡\n");
        
        if((int)me->query("jing") < 300 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");
        
        
        if((int)me->query_skill("lunhui-zhang", 1) < 80)
                return notify_fail("����ֻ�����Ϊ��������ʹ����һ�л������ѣ�\n");
        
        message_vision(HIY"$N������������ջ�����⣬��ת�������ھ��С��ȹ��նɡ�����$n��������������\n"NOR,me,target);
                        me->add_temp("apply/attack",200);
                me->add_temp("apply/damage",1200);  
        me->set("ciguangpudu", 6);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
        me->set("ciguangpudu", 7);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
        me->set("ciguangpudu", 8);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
        me->set("ciguangpudu", 9);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
                        me->add_temp("apply/attack",-200);
                me->add_temp("apply/damage",-1200);  
        me->delete("ciguangpudu");
        me->start_busy(2);
        message_vision(HIW"$N�����������ӷ𣡡����ȹ��նɡ��ù���ϣ����ϵ����Ľ��������ȥ.\n"NOR,me,target);

        me->add("neili", -50);
        return 1;
}

