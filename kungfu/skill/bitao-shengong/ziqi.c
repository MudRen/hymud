// drainerbolt.c
//2001,lestat
#include <ansi.h>

inherit F_SSERVER;

int exert(object me)
{
	string msg;
	int damage, ap, dp;
	int extradam;
object target;
        if( !target ) target = offensive_target(me);	




	if( !target
	||	!target->is_character()
	||	target->is_corpse()
	||	target==me)
		return notify_fail("��Ҫ��˭ʩչ��������\n");

 if((int)me->query("neili") < 200)
                return notify_fail("�������������\n");

        if((int)me->query("jing") < 200 )
                return notify_fail("���޷����о�����\n");

      if( !target ) target = offensive_target(me);
   	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���ž�ѧֻ�ܶ�ս���еĶ���ʹ�á�\n");
		
		        if((int)me->query_skill("buddhism",1) < 100)
                return notify_fail("��������ķ�������������\n");

        if((int)me->query_skill("bitao-shengong",1) < 100)
                return notify_fail("��ı����ķ�������������\n"); 

	me->add("neili", -25);
	me->receive_damage("jing", 20);

	if( random(me->query("max_neili")) < 20 ) {
		write("��ʧ���ˡ�\n");
		return 1;
	}

	msg = HIM "$N�����૵��������ģ�����һ�ӣ����о���һ����������$n��\n\n" NOR;

message_vision(HIY"\n�۽�Ը�в���������������Ψ���档"NOR,me,target);
message_vision(HIY"\n��������ʮԸ��������������ʥ��"NOR,me,target);
message_vision(HIY"\n���������߶���������������ˡ�"NOR,me,target);
message_vision(HIY"\nǧɮ��������������ڭʱ��ʥ����\n"NOR,me,target);

	ap = me->query_skill("buddhism");
	extradam = ap/2;
	ap = ( ap * ap /100 * ap / 4 ) * (int)me->query("jing") ;
	dp = target->query("combat_exp");
	if( random(ap + dp) > dp ) {
		damage = (int)me->query("max_neili") / 10 + random((int)me->query("eff_jing") / 20) + random(extradam);
		damage -= (int)target->query("max_neili") / 30 + random((int)me->query("eff_jing") / 15);
		if( damage > 0 ) {
			msg +=  MAG "������͡���һ����������$p����͸��������ϳ�һ���������߲ʹ�������������\n"
					"��ת�����ִ�$N����ע��$P�����ڣ�\n" NOR;
			me->receive_heal("jing", damage/3);
			target->receive_wound("jing", damage/3);

			me->receive_heal("qi", damage/2);
			target->receive_wound("qi", damage/2);

			me->improve_skill("bitao-shengong", 1, 1);
		} else
			msg += HIB"������͡���һ����������$p����͸�������������Ϣ��������£�\n"NOR;
	} else
		msg += "���Ǳ�$n�㿪�ˡ�\n";

	message_vision(msg, me, target);
	if( damage > 0 ) COMBAT_D->report_status(target);


	me->start_busy(3);
	return 1;
}

