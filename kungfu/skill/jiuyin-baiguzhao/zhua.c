// zhua.c  �����׹�צ������һ����
// Modified by Venus Oct.1997

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
    int extra;
    string msg;
    
    extra = me->query_skill("jiuyin-baiguzhao",1);
    if( !target ) target = offensive_target(me);
    if( !target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("������һ����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

    if( (int)me->query("shen", 1) > 0)
        return notify_fail("�����������ʿ�������ܡ�����һ�������������书��\n");

    if( (int)me->query_skill("jiuyin-baiguzhao", 1) < 85 )
        return notify_fail("��ľ����׹�צ������죬��ʹ����������һ������\n");
    if( (int)me->query("neili") < 300 )
    return notify_fail("�����������ˡ�\n");
    if( (int)me->query_skill("force", 1) < 85 )
        return notify_fail("����ڹ��ķ���򲻹���ʹ�á�����һ�����������Լ��ľ�����\n");
        me->add_temp("apply/attack",extra*2);
	 me->add_temp("apply/damage",extra*2);
    msg = HIR "$NͻȻ��˫�Ʊ�צ������ǰ��Ȼ����糵�㼱ת��Ȧ������ʩչ��������һ������˫צ����һ�����������$n��ת��Ȧ���ֻص�ԭ�ء�"NOR;

    COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    target->apply_condition("jy-poison",10);
    me->add("neili", -100);
	me->start_busy(2);
        me->add_temp("apply/attack",-extra*2);
	 me->add_temp("apply/damage",-extra*2);
    return 1;
}
