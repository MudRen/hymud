#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        int lvl;
        object weapon;
                string msg;
        int extra;
        int i;
        
        lvl = me->query_skill("xuanyin-jian", 1)/2;
        if( !target ) target = offensive_target(me);
        if( !target
         || !target->is_character()
         || !me->is_fighting(target) )
                return notify_fail("��ֻ�ܶ�ս���еĶ���ʹ��ն�־���\n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                        return notify_fail("��ʹ�õ��������ԡ�\n");
        if( (int)me->query_skill("xuanyin-jian", 1) < 200 )
                return notify_fail("�����������������죬�޷�ʩչ��ն�־���\n");
        if ((int)me->query_skill("jiuyin-zhengong", 1) < 150)
                return notify_fail("��ľ����湦��򲻹����޷�ʩչ��ն�־���\n");
        if ((int)me->query_skill("jiuyin-shenfa", 1) < 200)
                return notify_fail("��ľ�������򲻹����޷�ʩչ��ն�־���\n");
        if ( (int)me->query("max_neili") < 2000)
                return notify_fail("��������������޷�ʩչ��ն�־���\n");
        if ( (int)me->query("neili") < 900)
                return notify_fail("��������������޷�ʩչ��ն�־���\n");

        extra = me->query_skill("xuanyin-jian",1) / 40;
        if (extra> 9) extra=9;
        if (extra< 5) extra=5;
        
        message_vision(HIB"$Nʹ��������ն�־���������һ˲�乥��$n��\n"NOR,me, target);

        me->add("neili", -100 );

        me->add_temp("apply/attack",200);
        me->add_temp("apply/damage",2800);

        msg = HIR  "$N��̤�ۻ��������ݣ���Ѹ�ײ����ڶ�֮��ʹ���������������еľ��裡\n���е�"+ weapon->name() + HIR"����һ�����磬�����Ļ���$n��" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg =  HIW "����һ������ʧ��������\n" NOR;
        message_vision(msg, me, target);
        for(i=0;i<extra;i++)
        {
        msg = HIY "$N"+HIY"����ͻת�������طɣ�\n" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        }
        

	if (	random(me->query("combat_exp")) > target->query("combat_exp")/3	)
{
        message_vision(HIB"���$Nһ�е��֣�$n�������Ȼ��ն��������\n"NOR,me, target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
        target->apply_condition("broken_arm",180); 

}
        me->add_temp("apply/attack", -200);
        me->add_temp("apply/damage", -2800);
        me->start_busy(2);
        return 1;
}