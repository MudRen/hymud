
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

string *dodge_msg = ({
     "$N��ͷϸ��ȹ�ޣ���˼��������������֮���ƺ�����������ȴ��$n����ۻ����ҡ�\n",
     "ֻ��$Nһ��ת����Ȼ����һЦ��$nһ��֮�£����ﻹ�����ڡ�\n",
     "$N���һЦ�����˷��������ξ���$NƮ����\n$nֻ��һ��������ǣ���һ�о�������֮����\n",
     "$N�����飬��֫��š����Ȼ�ó��߲���Ӱ��$n��һ��������ֵó����ˣ���Ӱ��\n",
     "$Nȹ��ƮƮ�������橣���Ȼ��$nͷ���ɹ������Ů�����֮�ˣ��������֮�Σ�$n���ɵÿ����ˣ�\n",
     "$N�Ų���ӯ��������Ȼ�����ӱ�����ˮ����Ʈ��һ���ӹ�������$n����Ϯ��������Ȼ��ȥ��$n˫��һ�ڡ�\n",
     "$N����΢����������磬���Ὣ$n��������һ�ԣ��������⡣$n˫��һ�ڡ�\n",
});

int perform(object me, object target)
{
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("[��Ů�·�]ֻ����ս����ʹ�á�\n");

  if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("ֻ����ս����ʹ�á�\n");



        if ( !wizardp(me) && me->query_skill_mapped("force") != "bitao-shengong")
                return notify_fail("��ʹ�ñ����ķ�!\n");

        if((int)me->query_skill("bitao-shengong",1) < 30)
                return notify_fail("��ı����ķ�������������\n"); 

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
