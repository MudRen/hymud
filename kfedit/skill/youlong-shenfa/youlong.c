
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

string *dodge_msg = ({
	"$Nһ��"HIC"��������졹"NOR"���ҽ������أ����塸ಡ������ϱ�ֱ������
���ࡣ\n",
	"$Nһ��"HIY"�������ĺ���"NOR"��˫��һ�ţ�������ˮ������ݳ���\n",
	"$Nʹ��"MAG"���������衹"NOR"�����β�ס������\n",
	"$Nʹ��"BLU"��������Ӱ��"NOR"��$n��ǰһ�����Ѳ���$n��Ӱ��\n",
});

int perform(object me, object target)
{
        string msg;

int count;
        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("[����]ֻ����ս����ʹ�á�\n");

  if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("ֻ����ս����ʹ�á�\n");



        if ( !wizardp(me) && me->query_skill_mapped("force") != "honghua-shengong")
                return notify_fail("��ʹ�ú컨��!\n");

	if( (int)me->query_skill("honghua-shengong", 1) < 10 )
	return notify_fail("��ĺ컨�񹦲������죬�޷������������\n");

        if((int)me->query("neili") < 500)
                return notify_fail(HIY "�������������㡣\n" HIY);
        if((int)me->query("qi") < 500)
                return notify_fail(HIY "�����������㡣\n" HIY);

        if( target->is_busy() )
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");

	msg = HIG+dodge_msg[random(sizeof(dodge_msg))]+NOR;
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 ) {
                msg += HIR "���$p��$P�Ƶò�֪���룡\n" NOR;
                target->start_busy(5);
                me->add("neili", -100);
                       } else {
                msg +=  GRN"���$P�Լ����˸�ͷ���ۻ���\n"NOR;
                me->add("neili", -100);
                me->start_busy(2);
        }
        message_combatd(msg, me, target);

        return 1;
}
