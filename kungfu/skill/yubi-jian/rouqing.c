#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra,mk,ms,mp,yk,ys,yp;
        object weapon;
        extra = me->query_skill("yubi-jian",1);
        if ( extra < 80) return notify_fail("�������»����������������죡\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("���������ȣ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("ʹ�á��������ȡ���������һ�ѽ���\n");
        if ((int)me->query("neili")<250)
                return notify_fail("�������������\n"); 
        me->add("neili",-100);
        weapon = me->query_temp("weapon");
        message_vision(HIM"$Nʹ������»��������еľ��У��������ȣݣ�һ�������˽������е�"+weapon->name()+"�������$n������һ����\n\n" NOR,me,target);        
//      if (random(me->query("combat_exp"))>(int)target->query("combat_exp")/2 ) 
        mk=me->query("kar");
        ms=me->query("str");
        mp=me->query("per");
        yk=target->query("kar");
        ys=target->query("str");
        yp=target->query("per");
        me->add_temp("apply/attack", 100);
        me->add_temp("apply/damage", 500);
        COMBAT_D->do_attack(me,target, weapon); 
        COMBAT_D->do_attack(me,target, weapon);
        COMBAT_D->do_attack(me,target, weapon);
        COMBAT_D->do_attack(me,target, weapon);
        COMBAT_D->do_attack(me,target, weapon);
        COMBAT_D->do_attack(me,target, weapon);
        COMBAT_D->do_attack(me,target, weapon); 
        COMBAT_D->do_attack(me,target, weapon);         
                me->add_temp("apply/attack", -100);
        me->add_temp("apply/damage", -500);
        message_vision(WHT"$N�����˽������$n�����˸���æ���ң�\n" NOR,me,target);
        me->start_busy(2);
      
        return 1;
}

