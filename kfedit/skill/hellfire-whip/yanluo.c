#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        int ap,dp,damage,chance;
        string msg;
        object weapon;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ�����޸��衹��\n");
        if(!me->is_fighting())
                return notify_fail("�����޸��衹ֻ����ս����ʹ�ã�\n");
   	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���ž�ѧֻ�ܶ�ս���еĶ���ʹ�á�\n");
   
    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "whip")
        return notify_fail(RED"��ʲô��Ц���������ԣ�\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "zhanzhuang-gong")
                return notify_fail("��ʹ����ƽ����վ׮��!\n");
                
        if((int)me->query("max_neili") < 1000 )
                return notify_fail("�������������\n");
        if((int)me->query("neili") < 1000 )
                return notify_fail("����������㣡\n");
        if((int)me->query("jing") < 300 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");

    if ((int)me->query_skill("hellfire-whip", 1) < 60)
        return notify_fail("��������һ�޵ȼ�������ʹ����һ�л������ѣ�\n");
        if((int)me->query_skill("yijinjing", 1) < 150)
                return notify_fail("����׽���𻹲�����ʹ����һ�л������ѣ�\n");
    if ((int)me->query_skill("buddhism", 1) < 60)
        return notify_fail("��������ķ���������ʹ����һ�л������ѣ�\n");
        
        if((int)me->query_skill("hellfire-whip", 1) < 60)
                return notify_fail("��������һ����Ϊ��������ʹ����һ�л������ѣ�\n");
        msg = HIR"\n$N����ζ��缲�磬�Լ�����ٶ�˲������$nת�˾�ǧ�Űپ�ʮ��Ȧ,ͻȻ���һ�ޣ�\n"NOR;
        ap = me->query("combat_exp"); 

        dp = target->query("combat_exp"); 

        if( random(ap)> (dp/4)) 
        {
                damage = me->query_skill("whip",1) * 2 + me->query("force_factor");
                if (damage > 20000) damage = 19900+random(100);
                target->receive_damage("qi",damage,me);
                target->receive_wound("qi",damage,me);
         target->start_busy(5);
                msg += CYN"���$n��$N�ġ����޸��衹�Ի�δ�ܶ�����\n"NOR;
        }
        else 
                msg += "���Ǳ�$n�㿪�ˡ�\n"NOR;
        message_vision(msg, me, target);
        if( damage > 0 ) COMBAT_D->report_status(target);
        me->add("neili",-200);
        me->start_busy(2);
        return 1;
}

