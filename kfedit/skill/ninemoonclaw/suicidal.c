
#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;
int j,j2;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��Ψ�Ҷ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");


	msg = RED "$N˫Ŀ���࣬���������׹�צ���һʽ��Ψ�Ҷ��𡹣�";
j=(int) me->query("max_qi")/2;
j2=(int) me->query("max_jing")/2;
if (j >25000) j=25000;
if (j2>23000) j2=23000;

	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
		msg += "���$p��$P���˸����ֲ�����\n" NOR;
		target->receive_damage("qi",j,me);
		target->receive_wound("jing",j2,me );
	} else {
		msg += "����$p���Ƕ����$P�����һ������\n" NOR;
	}
	message_vision(msg, me, target);
        me->unconcious();
	return 1;
}
