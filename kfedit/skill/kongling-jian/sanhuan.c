#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        int i = me->query_skill("kongling-jian", 1)/5;
        int j = me->query("jiali")/4 + 10;
        
        if( !target ) target = offensive_target(me);

        if( !target
        ||  !target->is_character()
        ||  !me->is_fighting(target) 
        || !living(target))
                return notify_fail("���������¡�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if( (int)me->query_skill("kongling-jian", 1) < 50 )
                return notify_fail("��Ŀ��齣������̫ǳ���������ˡ�\n");

        if( (int)me->query_skill("sword", 1) < 120 )
                return notify_fail("��Ļ�����������̫ǳ���������ˡ�\n");

        if( (int)me->query_skill("kongdong-xinfa", 1) < 120 )
                return notify_fail("����ڹ�����̫ǳ���������ˡ�\n");
                
        if( (int)me->query("max_neili") < 500 )
                return notify_fail("�������̫ǳ���������ˡ�\n");
        if( (int)me->query("neili") < 500 )
                return notify_fail("��������������������ˡ�\n");
        if( (int)me->query("jing") < 100 )
                return notify_fail("��ľ��������������ˡ�\n");
        if (me->query_skill_mapped("force") != "kongdong-xinfa")
                return notify_fail("����ʲôΪ�ڹ�������ʹ���������¡�?\n");
        if (!objectp(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "sword"
            || me->query_skill_mapped("sword") != "kongling-jian")
                return notify_fail("��ʹ���ˡ��������¡�ô?\n");
                 
        me->add("neili", -100);
        //me->add("jing", -40);
        me->set_temp("tjj/sanhuan", 4); 
        me->add_temp("apply/attack", i);
        me->add_temp("apply/damage", 600);
if (random(2)==0) target->start_busy(2);
message_vision( HIW "$Nʹ�����������¡�����ʽһ�䣬���ָ����ѣ������н������������������һ��Բ����������$n����������\n"NOR, me, target );
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        if(me->is_fighting(target))
message_vision( HIW "Ȼ��$N�ƽ�һ�����������У��������У�ͬ��һ�����Żӳ�����������������һ��ͣ�ٵĺۼ���\n"NOR, me, target );
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
message_vision( HIW "������ӣ�$N���еĳ�����һ�λӳ�����$n���������������������������������ͬ�����ϵ�������֮����\n"NOR, me, target );
       if(me->is_fighting(target))
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);        

if( me->is_fighting() ) me->start_busy(2);
        me->add_temp("apply/attack", -i);
        me->add_temp("apply/damage", -600);   
        me->start_busy(2);
           me->delete_temp("tjj/sanhuan"); 
//        me->start_perform(4, "���������¡�");
        return 1;
}
