// powerup.c

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
	int skill,sktime;
        
	if (target != me)
		return notify_fail("��ֻ�����Ϻ����������Լ���ս������\n");

	if ((int)me->query("neili") < 100)
		return notify_fail("�����������!");

	if ((int)me->query_temp("powerup"))
		return notify_fail("���Ѿ����˹����ˡ�\n");

	skill = me->query_skill("bluesea-force",1)/20;

	me->add("neili", -100);
	me->receive_damage("qi", 0);

        if (skill>200) skill=200;
        sktime=skill*3;
	message_combatd(HIC "$N" HIC "���һ����һ�����˵�ʱ�粨"
                        "��һ��ɢ��������ֱ�������ܷ�ɳ��ʯ��\n" NOR, me);

	me->add_temp("apply/attack", skill );
	me->add_temp("apply/defense", skill );
	me->set_temp("powerup", 1);

	me->start_call_out((: call_other, __FILE__, "remove_effect",
                           me, skill  :), sktime);

	if (me->is_fighting()) me->start_busy(3);

	return 1;
}

void remove_effect(object me, int amount)
{
        if ((int)me->query_temp("powerup"))
        {
	        me->add_temp("apply/attack", -amount);
	        me->add_temp("apply/defense", -amount);
	        me->delete_temp("powerup");
                tell_object(me, "����Ϻ�����������ϣ��������ջص��\n");
        }
}
