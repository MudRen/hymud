//zhenhuo.c ��̫�����weiqi...980305

#include <ansi.h>

inherit F_SSERVER;

int exert(object me)
{
        int success_adj, damage_adj;
        //object target;
        //int success_adj, damage_adj;
        object weapon;
        int damage,p;
        string msg,dodge_skill;
        object target;
        success_adj = 110;
        damage_adj = 100;

        if( !target ) target = offensive_target(me);

if (environment(me)->query("no_fight"))  return notify_fail("��ȫ���ڽ�ֹʩչ������\n"); 

        if( !target
   

        ||   !target->is_character()
        ||   target->is_corpse()
        ||   target==me)
                return notify_fail("��Ҫ��˭��̫�����\n");


        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("���ž�ѧֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if((int)me->query_skill("taiyi",1) < 100)
                return notify_fail("���̫�ҵ���������������\n");

        if((int)me->query_skill("kongdong-xinfa",1) < 100)
                return notify_fail("�������ķ�������������\n"); 
                

        if((int)me->query("neili") < 500 )
                return notify_fail("��������������޷�����������\n");

        if((int)me->query("jing") < 10 )
                return notify_fail("���������ǲ��壬����Լ������ˣ�\n");
   


        me->add("neili", -200);

        me->receive_damage("jing", 10);

        if( random(me->query("max_neili")) < 50 ) 
        {
                write("��һ�κ����顣\n");
                return 1;
        }

       msg = HIR "$N����ָͷѸ������ͻȻ����һ�磡��Ȼ��������������һ����$n��ȥ��\n" NOR;
        message_combatd(msg, me,target);                
if (random(me->query("combat_exp")) > target->query("combat_exp")/3 && living(target)){
            damage = 100+(int)me->query_skill("kongdong-xinfa",1); 
            damage = damage + random(damage);
            damage +=(int)(me->query_skill("taiyi", 1)*8);
                        	if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
                target->receive_damage("qi", damage,me);
                target->receive_wound("qi", damage,me);
                msg=RED "���$n���յý�ͷ�ö\n" NOR;
   

}
else
{
                msg="���ǻ��汻$n������һ�ƣ�����$N�ؾ��ȥ��\n" NOR; 
}
message_combatd(msg, me,target);                



        me->start_busy(3);
        return 3+random(5);
}


