#include <ansi.h>
#include <combat.h>

#define SHENG "��" HIW "��������" NOR "��"
#define XIAO "��" HIW "��������" NOR "��"
#define LIU "��" HIY "���½���" NOR "��"
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        string msg;
        int i;
        int damage;
        string wn;
        int ap, dp;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(SHENG "ֻ����ս���жԶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
              (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" SHENG "��\n");

        if (me->query_skill("force") < 200)
                return notify_fail("����ڹ�����Ϊ����������ʩչ" SHENG "��\n");

        if (me->query_skill("liuyue-jian", 1) < 150)
                return notify_fail("������½�����Ϊ����������ʩչ" SHENG "��\n");

        if (me->query("neili") < 300)
                return notify_fail("�����������������ʩչ" SHENG "��\n");

        if (me->query_skill_mapped("sword") != "liuyue-jian")
                return notify_fail("��û�м������½��裬����ʩչ" SHENG "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "$N" HIW "����һ�󼲶�������΢��������������ɲ�Ǽ佣â���ǣ�"
              "����ӵ�кһ������$n"
              HIW "��\n" NOR;

        message_combatd(msg, me, target);
        me->add("neili", -100);
	me->add_temp("apply/attack", 80);	
	me->add_temp("apply/damage", 300);
        for (i = 0; i < 6; i++)
        {

                COMBAT_D->do_attack(me, target, weapon, 0);
        }
	me->add_temp("apply/attack", -80);	
	me->add_temp("apply/damage", -300);

if (me->query_skill("liuyue-jian", 1) > 200)
{
 msg = HIY "$N" HIY "һ����Х���������䣬����" + weapon->name() + HIY
              "���Ữ��������һ���ޱ�Ѥ���Ľ�â��ңָ$n" HIY "��ȥ��\n" NOR;
        ap = me->query_skill("sword");
        dp = target->query_skill("parry");

        if (ap / 2 + random(ap) > dp)
        {
                damage = ap * 2 / 3 + random(ap)+100;
                me->add("neili", -50);
                me->start_busy(2);
                target->add("qi",-damage);
		target->add("eff_qi",-damage);
                msg +=HIR "$n" HIR "��ʱĿ�ɿڴ���һ����������$N"
                                           HIR "����Ľ��д��У���Ѫ�ɽ���\n" NOR;
        } else
        {
                me->add("neili", -30);
                me->start_busy(2);
                msg += CYN "����$p" CYN "�������ң�������������񵲿���$P"
                       CYN "�Ľ��С�\n"NOR;
        }
        message_combatd(msg, me, target);

}

if (me->query_skill("liuyue-jian", 1) > 300)
{

        ap = me->query_skill("sword")*2;
        dp = target->query_skill("parry");

        if (ap / 2 + random(ap) > dp)
        {
                damage = ap + random(ap / 2)+200;
                target->add("qi",-damage);
		target->add("eff_qi",-damage);
                msg +=HIR "\n" HIR "$n" HIR "ֻ��һ���������������" 
                                          "�������ѣ�����Ѫ�Ѵ�$n�ؿ������\n" 
                                          NOR;
         	me->start_busy(2);
         	me->add("neili", -100);
        } else
        {
         	msg = CYN "Ȼ��$n" CYN "�����ֿ죬����һ��"
                      "���$N" CYN "��һ����\n" NOR;

         	me->start_busy(2);
         	me->add("neili", -80);
        }
        message_vision(msg, me, target);

}

        me->start_busy(2);



        return 1;
}