// jingheal.c

#include <ansi.h>

int exert(object me, object target)
{
	if( !target )
		return notify_fail("��Ҫ������Ϊ˭���ˣ�\n");

	if( me->is_fighting() || target->is_fighting())
		return notify_fail("ս�����޷��˹����ˣ�\n");

	if ((int)me->query_skill("jiuyin-zhengong", 1) < 100)
		return notify_fail("��ľ����湦��Ϊ��������\n");

	if( (int)me->query("max_neili") < 300 )
		return notify_fail("���������Ϊ������\n");

	if( (int)me->query("neili") < 150 )
		return notify_fail("�������������\n");

	if( (int)target->query("eff_jing") >= (int)target->query("max_jing") )
		return notify_fail( target->name() + "���ھ������棡\n");

	message_vision(
		HIB "$N��������˿���������������$n���ģ�����������תһ����....\n\n"
		"���˲��ã�$N��ͷ��ð������ĺ��飬$n����һ�������������ö��ˡ�\n" NOR,
		me, target );

	target->receive_curing("jing", 10 + (int)me->query_skill("force") );
	target->add("jing", 10 + (int)me->query_skill("force") );
	if( (int)target->query("jing") > (int)target->query("eff_jing") )
		target->set("jing", (int)target->query("eff_jing"));

if (target->query("eff_qi",1) < target->query("max_qi",1))
{
	target->receive_curing("qi", 10 + (int)me->query_skill("force") );
	target->add("qi", 10 + (int)me->query_skill("force") );
	if( (int)target->query("qi") > (int)target->query("eff_qi") )
		target->set("qi", (int)target->query("eff_qi"));
}

	me->add("neili", -50);
        target->start_busy(2);
	return 1;
}

