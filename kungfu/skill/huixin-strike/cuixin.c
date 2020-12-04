#include <ansi.h>
#include <combat.h>
 
inherit F_SSERVER;
 
int perform(object me)
{
        string msg;
        object weapon, target;
        int skill, ap, dp;
        int damage, lvl;

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail("��������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon"))
                return notify_fail("������ǿ��ֲ���ʹ�ö������ģ�\n");
 
        lvl = me->query_skill("huixin-strike", 1);

        if (lvl < 120)
                return notify_fail("��Ķ��Ҵ����ƻ��������죡\n");

        if (me->query_skill("force") < 120)
                return notify_fail("����ڹ����̫�ͣ��޷�ʹ���������ġ�\n");

        if (me->query("neili") < 800)
                return notify_fail("��������������޷�ʹ���������ġ�\n");
 
        msg = HIR "$N" HIR "�������ƣ�����һ����Х��ɲ�Ǽ�˫�ƽ���һ��"
                  "���������ġ����������ھ�ֱ��$n" HIR "��\n"NOR;

        ap = me->query_skill("strike") + lvl;
        dp = target->query_skill("parry");

        if (dp < 1) dp = 1;

        if ( ap / 2 + random(ap) > dp + random(dp) )
        {
        me->add("neili", -300);
        damage = lvl * 4 + random(lvl);
target->apply_condition("cuixin_zhang",35 );
   target->add("qi",-damage);
		target->add("eff_qi",-damage);
                msg += HIR "ֻ��$n" HIR "�ҽ�һ����ֻ��������"
               "����Ŀ��������һ�����Ѫ������̱����\n" NOR;

        me->start_busy(2);
        }
    else
        {
        msg += HIY "$p��$P������ӿ����æ����һԾ���𣬶㿪����������һ����\n" NOR;
        me->add("neili", -300);
        me->start_busy(3);
        }
        message_combatd(msg, me, target);
if( (int)me->query_skill("huixin-strike", 1) >200 )
{
  msg = HIY "$N" HIY "����ȫ��������ʱ�����ŷ���ȫ�������ž��"
              "�죬��Ȼһ����$n" HIY "\nȫ���ĳ�������һ���еУ�����һ"
              "�С�������ա���\n" NOR;
         
        ap = me->query_skill("hand") +
             me->query_skill("force") +
             me->query("str") * 10;

        dp = target->query_skill("dodge") +
             target->query_skill("force") +
             me->query("con") * 10;

        damage = me->query_skill("hand")*2;

        if (target->query_skill_mapped("force") == "jiuyang-shengong")
        {
                me->add("neili", -200);
                me->start_busy(5);
                msg += HIW "ֻ����Ȼһ�����죬$n" HIW "�ѱ�һ�����У���$N"
                       HIW "ֻ��ȫ���������罭����\n��������ˮ�齻�ڣ���"
                       "ʱ��ʧ����Ӱ���١�\n" NOR; 
        } else
        if (ap / 2 + random(ap) > dp)
        {
                me->add("neili", -200);
                me->start_busy(3);
   target->add("qi",-damage*2);
		target->add("eff_qi",-damage*2);
                msg += HIR "ֻ����Ȼһ�����죬$n" HIR "��$N"
                                           HIR "һ�����У����ӱ��絾�ݰ�ƽƽ�ɳ�"
                                           "����\n��ˤ�ڵ��£�Ż��һ�����Ѫ����"
                                           "Ҳ������\n" NOR;

        } else 
        { 
                me->add("neili", -200);
                me->start_busy(3);
                msg += CYN "����$p" CYN "������񣬼�ʱ������" 
                       CYN "$P" CYN "������ǣ�����㿪����һ����\n" NOR; 
        }
        message_combatd(msg, me, target);
}	
        return 1;
}

