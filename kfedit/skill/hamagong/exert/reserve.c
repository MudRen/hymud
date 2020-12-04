// reserve.c ��󡹦������ת

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int a_amount, int d_amount);

int exert(object me, object target)
{
	object weapon;
	int skill,istr;
	string msg;

	if( (int)me->query_skill("hamagong", 1) < 40 )
		return notify_fail("��ĸ�󡹦������죬���ᾭ����ת��\n");

	if( (int)me->query("neili") < 200  ) 
		return notify_fail("�������������\n");

	if( (int)me->query_temp("hmg_dzjm") ) 
		return notify_fail("���Ѿ���ת�����ˡ�\n");

	skill = me->query_skill("hamagong",1);
	msg = HIB "$N����˫�ֳŵص��������˾�������ʱ��Ϣ������������������\n"NOR;
	message_combatd(msg, me, target);
istr=skill/15;
if (istr>120) istr=120;
if (istr<10) istr=10;
	//me->add_temp("apply/attack", -skill/6);
	///me->add_temp("apply/dodge", skill/2);
        //me->add_temp("apply/parry", skill/40);
        me->add_temp("apply/strength", istr);

	me->set_temp("hmg_dzjm", 1);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, istr ,istr  :), skill);

	me->add("neili", -100);
	if( me->is_fighting() ) me->start_busy(2);

	return 1;
}

void remove_effect(object me, int istr, int istra)
{
	int skill;
        skill = me->query_skill("hamagong",1);
	//me->add_temp("apply/attack", skill/6);
	//me->add_temp("apply/dodge", -skill/2);
        //me->add_temp("apply/parry", -skill/40);
        me->add_temp("apply/strength", -istr);
	me->delete_temp("hmg_dzjm");
	tell_object(me, HIY "��˫��һ�ţ�һԾ���𣬽������ջص��\n");
}
