#include <ansi.h>
#include <combat.h>

#define GUA "��" HIM "���԰���ȭ" NOR "��"

inherit F_SSERVER;
int perform(object me, object target)
{
        int damage;
        string msg;
        int ap, dp,level;



        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(GUA "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(GUA "ֻ�ܿ���ʩչ��\n");

        if ((int)me->query_skill("wai-bagua", 1) < 70)
                return notify_fail("�������Բ�����죬����ʩչ" GUA "��\n");

        if (me->query_skill_mapped("cuff") != "wai-bagua") 
                return notify_fail("��û�м�������ԣ�����ʩչ" GUA "��\n");

        if (me->query_skill_prepared("cuff") != "wai-bagua") 
                return notify_fail("��û��׼������ԣ�����ʩչ" GUA "��\n");

        if ((int)me->query("neili") < 200)
                return notify_fail("��������������������ʩչ" GUA "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

         level = me->query_skill("wai-bagua", 1);

        msg = HIG "$N" HIG "���²����ӿ죬ʹ�������ơ��֡��־���˫��"
              "���������Ӱ����$n" HIG "�����ڵ��С�\n" NOR;

        me->add("neili", -30);
        if (random(level) > (int)target->query_skill("parry", 1) / 2)
        {
                msg += HIR "$p" HIR "ֻ��������Ӱ���Լ�Ϯ������æ���ң�"
                       "���ڵ��أ���֪�����Ӧ�ԣ�\n" NOR;
                target->start_busy(7);
        } else
        {
                msg += CYN "Ȼ��$p" CYN "������$P" CYN "����ͼ������һԾ��"
                       "��������$P" CYN "�����ơ�\n" NOR;
                me->start_busy(1);
        }
        message_combatd(msg, me, target);

        msg = HIM "$N" HIM "������ ͻȻ����һ�࣬˫������һ������������һ��������$n"
              HIM "��˫��бб����ȥ��\n" NOR;

        ap = me->query_skill("cuff");
        dp = target->query_skill("parry");
        if (ap / 2 + random(ap) > dp)
        {
                damage = me->query_skill("cuff")*2+300;
                me->add("neili", -100);

                msg += HIR "ֻ������ʵ��̫�����$n" HIR "��"
                                           "$N" HIR "���˸����ֲ��������һ������"
                                           "��һ����Ѫ��\n" NOR;
                me->add("neili", -50);

                target->add("qi",-damage);
		target->add("eff_qi",-damage);
		
                //message_combatd(msg, me, target);
                

                me->start_busy(2);
        } else 
        {
                msg += CYN "����$n" CYN "������$N" CYN
                       "����һ�У��򶨽��У�һ˿���ҡ�"
                       "\n" NOR;
                me->add("neili", -50);
                me->start_busy(3);
        }
        message_combatd(msg, me, target);

        return 1;
}
