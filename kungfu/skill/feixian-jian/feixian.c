 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        int i;
        object weapon;
        if( !target ) target = offensive_target(me); 
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        weapon = me->query_temp("weapon");
        if (!weapon) return notify_fail("�������ֻ�ܺͷ��ɽ�����ͣ�\n");
        if( (string)weapon->query("skill_type") != "sword" )
        return notify_fail("��ʹ�õ��������ԣ�\n");


	if( (int)me->query("neili") < 500  ) 
		return notify_fail("�������������\n");
        me->add("neili",-100);

        extra = me->query_skill("feixian-jian",1) / 20;
        extra += me->query_skill("feixian-jian",1) /20;
        if (extra> 80) extra=80;

        me->add_temp("apply/attack", extra);    
        me->add_temp("apply/damage", 200);
        msg = HIR  "$N��̤�۷��ɲ����ݣ���Ѹ�ײ����ڶ�֮��ʹ���۷��ɽ������еľ��裭��������ɣ�\n���е�"+ weapon->name() + HIR"����һ�����磬�����Ļ���$n��" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg =  HIW "����һ������ʧ��������\n" NOR;
        message_vision(msg, me, target);
        for(i=0;i<extra/5;i++)
        {
        msg = HIY "$N"+HIY"����ͻת�������طɣ�\n" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        }
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -200);
        me->start_busy(2);
        return 1;
}      
