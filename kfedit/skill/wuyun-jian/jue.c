//by dewbaby@sk_sjsh
//�Ž������

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        int lvl;
        object weapon;
        weapon = me->query_temp("weapon");
        if( !target ) target = offensive_target(me);
        if( !target
         || !target->is_character()
         || !me->is_fighting(target) )
                return notify_fail("��ֻ�ܶ�ս���еĶ���ʹ���������\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");

        if( (int)me->query_skill("wuyun-jian", 1) < 120 )
                return notify_fail("������Ž���������죬�޷�ʩչ�����������\n");
        if ( !wizardp(me) && me->query_skill_mapped("force") != "wuzheng-xinfa")
                return notify_fail("��ʹ�������ķ�!\n");
        if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���ž�ѧֻ�ܶ�ս���еĶ���ʹ�á�\n");
		
        if ( (int)me->query("max_neili") < 2000)
                return notify_fail("��������������޷�ʩչ�����������\n");
        if ( (int)me->query("neili") < 500)
                return notify_fail("��������������޷�ʩչ�����������\n");
        if ((int)me->query("qi") < 500)
                return notify_fail("�����Ѫ�������޷�ʩչ�����������\n");
     
        lvl = me->query_skill("wuyun-jian", 1);
     message_vision(WHT"$N��������ؿ���$n��\n\n"NOR,me,target);
     message_vision(WHT"$N��������ͻȻ����"+ weapon->name() +HIY"��Ϊ�ŵ���ɫ������$n��ȥ��\n"NOR,me, target);
 
        me->add("neili", -100 );
        me->add("qi", -50);
        if (lvl >500) lvl=500;
        me->add_temp("apply/attack",100);
        me->add_temp("apply/damage",1800);
        //me->add_temp("apply/sword", 800);

        message_vision(HIY"$N������磬���н���Ӱ�䲻�ϣ�\n"NOR,me,target);
message_vision(WHT"$n"+WHT"����ӭ������Ľ����Ƶ��������ˣ��ƺ���Ϊ������\n"NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1); 
message_vision(HIY"һ��                  "+BLINK+HIC+"����������\n"NOR,me,target); 
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
message_vision(HIY"����             "+BLINK+WHT+"����������\n"NOR,me,target); 
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
message_vision(HIY"����             "+BLINK+HIB+"����������\n"NOR,me,target); 
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
message_vision(HIY"�Ľ�             "+BLINK+HIW+"�޵�������\n"NOR,me,target); 
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
message_vision(HIY"�彣             "+BLINK+BLU+"�ٱ�Ӱ��Ѱ\n"NOR,me,target);
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
message_vision(HIY"����             "+BLINK+HIR+"��¥����Ъ\n"NOR,me,target);
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
message_vision(HIY"�߽�             "+BLINK+HIC+"�����״���\n"NOR,me,target);
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
message_vision(HIY"�˽�             "+BLINK+HIM+"ȥ�������\n"NOR,me,target);
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
message_vision(HIY"�Ž�             "+BLINK+WHT+"���������\n"NOR,me,target);
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);

        me->start_busy(2);
        me->add_temp("apply/attack", -100);
        me->add_temp("apply/damage", -1800);
        //me->add_temp("apply/sword", -lvl/3);
        return 1;
}


