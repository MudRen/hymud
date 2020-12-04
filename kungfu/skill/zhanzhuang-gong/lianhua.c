#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me)
{
        int skill;
        me=this_player();


        if( (int)me->query_skill("buddhism", 1) < 50 )
                return notify_fail("��������ķ��ȼ�������\n");

        if( (int)me->query("neili") < 300 )     
                return notify_fail("�������������\n");
        if( (int)me->query("qi") < 300 )
                return notify_fail("�����Ѫ���㡣\n");
        if( (int)me->query("jing") < 300 )
                return notify_fail("��ľ����㡣\n");
        if( (int)me->query_temp("anti_magic") ) 
                return notify_fail("���Ѿ����˹����ˡ�\n");
	if( me->is_busy() )
		return notify_fail("��������æ���أ����п��˹���\n");
        skill = me->query_skill("buddhism");

        me->add("neili", -100);
if (me->query("qi") <= me->query("max_qi")*2)
        me->add("qi", 150+me->query_skill("buddhism",1)*3);
if (me->query("eff_qi") <= me->query("max_qi")*2)
        me->add("eff_qi", 150+me->query_skill("buddhism",1)*3);
if (me->query("jing") <= me->query("max_jing")*2)
        me->add("jing", 150+me->query_skill("buddhism",1)*3);
if (me->query("eff_jing") <= me->query("max_jing")*2)
        me->add("eff_jing", 150+me->query_skill("buddhism",1)*3);
        message_vision(
                HIC"$N΢һ���񣬱���ó�һ���������ɫ�������֡�\n" NOR, me);

        me->set_temp("anti_magic", skill);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 8 :), skill);

        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

void remove_effect(object me, int amount)
{
        me->delete_temp("anti_magic");
        tell_object(me, "�����İ���������ȥ�ˡ�\n");
        return;
}

