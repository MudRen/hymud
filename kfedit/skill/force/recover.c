// recover.c

//inherit SSERVER;

int exert(object me, object target)
{
	int n, q,agea,inta,dexa;

	if (me != target)
		return notify_fail("��ֻ�����ڹ������Լ�����Ϣ��\n");

	if( me->is_busy() )
		return notify_fail("����һ��������û����ɣ�\n");

	if ((int)me->query("neili") < 20)
		return notify_fail("�������������\n");

	if ((int)me->query_skill("force",1) < 5)
		return notify_fail("��Ļ����ڹ�������\n");


	q = (int)me->query("eff_qi") - (int)me->query("qi");
	if (q < 10)
		return notify_fail("�������������档\n");
	n = 100 * q / me->query_skill("force",1);
	if (n < 20)
		n = 20;
	if ((int)me->query("neili") < n) {
		q = q * (int)me->query("neili") / n;
		n = (int)me->query("neili");
	}

if (q>= 200000) q=200000;
if (me->query("qi",1) <= me->query("max_qi",1)/2 )
if (userp(me)) q=q+me->query("con")*15;
		
		dexa=me->query("age",1);
		if (dexa >30) dexa=30;
if (userp(me)) q=q+me->query("int")*dexa;


if (me->query("zhuanshen"))
q=q*2;

if (me->query("zhuanbest"))
q=q*2;

if (me->query("4zhuan"))
q=q*2;



if (q>me->query("max_qi",1)) q=me->query("max_qi",1);
	me->add("neili", -n);
	me->receive_heal("qi", q);
	me->set_temp("ishealnb",1);
        message_combatd("$N�������˼���������ɫ�������ö��ˡ�\n", me);
//        me->start_busy(1);
        if( me->is_fighting() ) me->start_busy(2);
	
	return 1;
}
