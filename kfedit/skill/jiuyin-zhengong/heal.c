// heal.c

#include <ansi.h>

int exert(object me, object target)
{
    if( me->is_fighting() )
   return notify_fail("ս�����˹����ˣ�������\n");

    if ((int)me->query_skill("jiuyin-zhengong", 1) < 20)
   return notify_fail("��ľ����湦��Ϊ��������\n");
    if( (int)me->query("neili") < 50 ) // - (int)me->query("max_neili") < 50)
   return notify_fail("�������������\n");

    if( (int)me->query("eff_qi") >= (int)me->query("max_qi") && (int)me->query("eff_jing") >= (int)me->query("max_jing") )
   return notify_fail("�㲢δ���ˣ�\n");
   
    if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 3 )
   return notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�\n");

    write( HIB "��ȫ����ɣ����վ����ͽ�ƪ��ʼ�˹����ˡ�\n" NOR);
    message("vision",
   HIB + me->name() + "�³�һ����Ѫ����ɫ�������ö��ˡ�\n" NOR,
   environment(me), me);
target=me;
if (target->query("eff_qi",1) < target->query("max_qi",1))
{
	target->receive_curing("qi", 10 + (int)me->query_skill("force") );
	target->add("qi", 10 + (int)me->query_skill("force") );
	if( (int)target->query("qi") > (int)target->query("eff_qi") )
		target->set("qi", (int)target->query("eff_qi"));
}

if (target->query("eff_jing",1) < target->query("max_jing",1))
{
	target->receive_curing("jing", 10 + (int)me->query_skill("force") );
	target->add("jing", 10 + (int)me->query_skill("force") );
	if( (int)target->query("jing") > (int)target->query("eff_jing") )
		target->set("jing", (int)target->query("eff_jing"));
}
    me->add("neili", -5);

    return 1;
}

