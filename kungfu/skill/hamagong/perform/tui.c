// tui.c ��

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int skill, ap, dp, damage;

        if (! target || target == me)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail("��󡹦������ʽ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");


                
        skill = me->query_skill("hamagong", 1);

        if (skill < 240)
                return notify_fail("��ĸ�󡹦��Ϊ�����������ʹ�á�����ʽ����\n");

        if (me->query("max_neili") < 4000)
                return notify_fail("���������Ϊ��������޷�ʩչ������ʽ����\n");

        if (me->query("neili") < 1000)
                return notify_fail("��������������޷����á�����ʽ����\n");

       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "$N" HIY "���ڵ��ϣ����á���һ����У�˫����"
              "����룬ƽ�ƶ�����һ�ɼ����������ͬ"
              "��ɽ����һ�㱼��$n" HIY "��\n" NOR;

        ap = me->query_skill("force",1) ;
        dp = target->query_skill("force") * 15 + target->query("max_neili") +
             target->query_skill("yiyang-zhi", 1) * 20;
        if (dp < 1) dp = 1;
 if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
        {
                me->add("neili", -200);
                me->start_busy(2);
                damage = ap * 6+random(ap);
                //if (!userp(me) && damage>3000) damage=3000;
                	if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
                target->receive_damage("qi", damage*2,me);
                target->receive_wound("qi", damage,me);
target->apply_condition("snake_poison",10);
target->apply_condition("chanchu_poison",10);
target->apply_condition("qx_snake_poison",20);


                	if (damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
                target->receive_damage("qi", damage,me);
                target->receive_wound("qi", damage,me);


                        msg +=HIR "$n" HIR "�����͵�������$P" HIR "�����ƺ�"
                                           "�Ⱥƴ�$p" HIR "��ʱ������Ѫ���������ۡ���"
                                           "�³���һ����Ѫ��\n" NOR;

        } else
        if (target->query_skill("yiyang-zhi", 1))
        {
                me->start_busy(2);
                me->add("neili", -200);
                msg += HIG "Ȼ��$p" HIG "����һЦ������һָ�̳�������һ"
                       "��ָ�ľ������������׵Ļ�����$P" HIG "�Ĺ��ơ�\n" NOR;
        } else
        {
                me->add("neili",-100);
                msg += CYN "����$n" CYN "�������˵�˫���ϣ�������$P"
                       CYN "��һ��֮ʽ��ֻ�������һ�����������"
                       "�������\n" NOR;
                me->start_busy(3);
                target->start_busy(1);
                if (target->query("neili") > 200)
                        target->add("neili", -200);
                else
                        target->set("neili", 0);
        }
        message_combatd(msg, me, target);

        return 1;
}

