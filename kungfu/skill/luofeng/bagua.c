
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

string *dodge_msg = ({
	"$N����һ�ˣ�̤�������Ǭ�ţ�$n˫��һ����\n",
	"����$N����һ�Σ�ͻȻ֮��ת�������ţ�������$n�����$n˫��һ�ڡ�\n",
	"ֻ��$N���ż��������Կ����룬�����������ţ�����һ�����������ţ�$n˫��һ�ڡ� \n",
	"˵ʱ����ʱ�죬$N��ǧ��һ��֮�ʲ��˷�������������֮�У�$n˫��һ��$n˫��һ�� \n",
	"$N����һת�������Ҳ࿲��֮�У�$n˫��һ����\n",
	"$N������Ц������һ����ͷ������ţ����Ὣ���ƾ������⡣$n˫��һ�ڣ�$n˫��һ��\n",
	"����$N����һ�ݣ���ʱû����Ӱ��$n����һ����ԭ��$N��㵽������֮�У�$n˫��һ�ڡ�\n",
	"$N����б�ɣ���������֮�У������������ƻ���$n�Ĳ�����$n˫��һ�ڡ�\n"
});

int perform(object me, object target)
{
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("[���Է�ħ]ֻ����ս����ʹ�á�\n");

  if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("ֻ����ս����ʹ�á�\n");



        if ( !wizardp(me) && me->query_skill_mapped("force") != "kongdong-xinfa")
                return notify_fail("��ʹ������ķ�!\n");

        if((int)me->query_skill("kongdong-xinfa",1) < 30)
                return notify_fail("�������ķ�������������\n"); 

        if((int)me->query("neili") < 400)
                return notify_fail(HIY "�������������㡣\n" HIY);

        if( target->is_busy() )
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");

	msg = HIW+dodge_msg[random(sizeof(dodge_msg))]+NOR;
        if( me->query("combat_exp") > random((int)target->query("combat_exp")) ) {
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
