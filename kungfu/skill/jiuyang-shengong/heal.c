// heal.c
// Modified by Java Feb.21 1998

#include <ansi.h>

int exert(object me, object target)
{
    if( me->is_fighting() )
           return notify_fail("ս�����˹����ˣ�������\n");

    if ((int)me->query_skill("force", 1) < 20)
           return notify_fail("����ڹ���Ϊ��������\n");
    if( (int)me->query("neili") < 50 )
           return notify_fail("�������������\n");

    if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 3 )
           return notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�\n");

    write( HIW "��ȫ�����ɣ���������ʼ�˹����ˡ�\n" NOR);
    message("vision",
           HIW + me->name() + "�³�һ�ڽ�Ӳӵ���Ѫ����ɫ�������ö��ˡ�\n" NOR,
           environment(me), me);

    me->receive_curing("qi", 10 + (int)me->query_skill("force")/5 );
    me->add("neili", -50);
    me->set("jiali", 0);

    return 1;
}
