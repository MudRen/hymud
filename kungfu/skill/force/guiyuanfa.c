// lifeheal.c

#include <ansi.h>

int exert(object me, object target)
{
int qi;
    if ((!target))
		return notify_fail("��Ҫ������Ϊ˭���ˣ�\n");

	if( me->is_fighting() || target->is_fighting())
		return notify_fail("ս�����޷��˹����ˣ�\n");


        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("��Ľ������黹�������޷��Ա����书��ͨʹ�ã�\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("�㻹û��ͨ����ɽ�۽�! �޷��Ա����书��ͨʹ�ã�\n");

	if ((int)me->query_skill("force", 1) < 300)
		return notify_fail("����ڹ���Ϊ��������\n");

	if( (int)me->query("max_neili") < 300 )
		return notify_fail("���������Ϊ������\n");

	if( (int)me->query("neili") < 150 )
		return notify_fail("�������������\n");

	if( (int)target->query("eff_qi") >= (int)target->query("max_qi") 
	&& (int)target->query("eff_jing") >= (int)target->query("max_jing"))
		return notify_fail( target->name() + "��δ���ˣ�\n");

        if( (int)me->query_temp("jiuyin/powerup") )
        	return notify_fail("���Ѿ����˾������ˡ�\n");

        if (me->query_skill_mapped("force") == "jiuyin-zhengong")
                return notify_fail("���ڹ��Ѿ����˾������ˡ�\n");
		      if( me->query_temp("fumo")   )
      return notify_fail("������ʹ�ô��ħȭ�����⹥������ħ����\n");
	message_combatd(
		HIG "$N�������������ڹ�������������$n���ģ���ͨ��ѧ���ڹ���ѧ��ʼ�˹�����....\n\n"
		"���˲��ã�$N��ͷ��ð������ĺ��飬$n�³�һ����Ѫ����ɫ������������ˡ�\n" NOR,
		me, target );

	qi=500 + (int)me->query_skill("force")/2;
	
	if (me->query("zhuanshen"))
qi=qi*2;

if (me->query("zhuanbest"))
qi=qi*2;

if (me->query("4zhuan"))
qi=qi*2;

if (qi>me->query("max_qi",1)) qi=me->query("max_qi",1);
	
	target->receive_curing("qi", qi );
	target->add("qi", qi );
	
	if( userp(target) && (int)target->query("qi") > (int)target->query("eff_qi") ) target->set("qi", (int)target->query("eff_qi"));
	if( !userp(target) && (int)target->query("qi") > (int)target->query("max_qi")*5 ) target->set("qi", (int)target->query("max_qi"));


if (qi>me->query("max_jing",1)) qi=me->query("max_jing",1);
	target->receive_curing("jing", qi );
	target->add("jing", qi );
	if( (int)target->query("jing") > (int)target->query("eff_jing") )
		target->set("jing", (int)target->query("eff_jing"));
	me->add("neili", -300);
        if (random(3)==1) target->start_busy(1);
	return 1;
}
