#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string name() { return HIW "�潣��" NOR; }

int perform(object me, object target)
{
        int damage;
        string msg, wn;
        object weapon;
        int ap, dp;
        int skill;
        int level;
                int i, attack_time;
                
        me = this_player();

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(name() + "ֻ����ս���жԶ���ʹ�á�\n");

         if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");
skill=(int)me->query_skill("wushen-jian", 1);
        if ((int)me->query_skill("wushen-jian", 1) < 160)
                return notify_fail("����ң���񽣷�������죬����ʩչ" + name() + "��\n");

        if (me->query_skill_mapped("sword") != "wushen-jian")
                return notify_fail("��û�м�����ң���񽣷�������ʩչ" + name() + "��\n");

        if ((int)me->query_skill("force", 1) < 160)
                return notify_fail("����ڹ���򲻹�������ʩչ" + name() + "��\n");

        if (me->query("max_neili",1) < 1200)
                return notify_fail("��������Ϊ���㣬����ʩչ" + name() + "��\n");

        if (me->query("neili",1) < 350)
                return notify_fail("�����ڵ���������������ʩչ" + name() + "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        wn = weapon->name();

        msg = HIW "\n$N" HIW "��" + wn + HIW "бָ���գ��͵ط���Ծ��"
              + wn + HIW "������ң�Ʈ����������Ȼ���ƿճ��죬" + wn + HIW
              "ֱָ��$n" HIW "�ʺ�\n��������ң���񽣷�֮��" HIG "�潣��" HIW "����"
              "���������о��棬�����ޱȡ�" NOR;

        //message_combatd(msg, me, target);

        ap = me->query_skill("sword",1) + me->query_skill("dodge");
        dp = target->query_skill("parry",1) + target->query_skill("dodge");

        if (ap / 2 + random(ap) > dp || random(6)==0)
        {
                damage = me->query_skill("sword")+200;
target->add("qi",-damage*2);
target->add("eff_qi",-damage);

                        msg +=HIR "\n$n" HIR "ֻ��һ�����Ӱ��Ϯ����"
                                          "���о������ѣ�����Ѫ�Ѵ�$n�ؿ������\n"
                                          NOR;
                me->start_busy(2);
                me->add("neili", -200);
        } else
        {
                msg = CYN "Ȼ��$n" CYN "�����ֿ죬����һ��"
                      "���$N" CYN "��һ����\n" NOR;

                me->start_busy(2);
                me->add("neili", -200);
        }
        message_combatd(msg, me, target);
if (skill>200 && me && target)
{
 wn = weapon->name();

        msg = HIC "\n$n" HIC "��Ȼ����죬��" HIW "�ɽ���" HIC "�������鶯�ޱȣ�����" + wn + HIC "��"
              "�����ַ���һ�㣬��$N" HIC "�������֡�\n" NOR;

        //message_combatd(msg, me, target);

        level = me->query_skill("sword");


        ap = me->query_skill("sword",1);
        dp = target->query_skill("dodge",1);

        if (ap / 2 + random(ap) > dp || random(3)==0)
        {
                damage = me->query_skill("sword");
target->add("qi",-damage*2);
target->add("eff_qi",-damage);

                        msg +=HIY "\n$N" HIY "������$n" HIY "����ʽ�е���ʵ����æ"
                      "��ס�Լ�ȫ��һʱ������Ӧ�ԣ�\n" NOR;
if (!target->query_condition("zhua_poision")) target->apply_condition("zhua_poision",10);
                target->start_busy(5);
                me->start_busy(random(2));
        } else
        {
                msg = CYN "����$N" CYN "��������С�Ĳ��У�û�б�"
                      "$n" NOR + CYN "��ʽ������\n" NOR;

                me->start_busy(2);
        }
        message_combatd(msg, target, me);
}

if (skill>300 && me && target)
{
 msg = HIW "\n$N" HIW "���һ����Х��ʩ����ѧ��" HIM "�콣��"
              HIW "��������" + weapon->name() + HIW "�������졣��ʱ��"
              "����Ľ�������ӿ����\n" NOR;

        attack_time = 4;

        ap = me->query_skill("sword",1);
        dp = target->query_skill("dodge",1);

        level = me->query_skill("wushen-jian", 1);
        attack_time += random(ap / 60);

        if (attack_time > 9)
                attack_time = 9;


	me->add_temp("apply/attack", 100);	
	me->add_temp("apply/damage", 1000);
        message_combatd(msg, me, target);
me->set_temp("perform_wushenjian/qian", 1);
        for (i = 0; i < attack_time; i++)
        {
                if (! me->is_fighting(target))
                        break;

                if (! target->is_busy() && random(3) == 1)
                        target->start_busy(1);

                COMBAT_D->do_attack(me, target, weapon, 0);
        }
me->delete_temp("perform_wushenjian/qian");        
	me->add_temp("apply/attack", -100);	
	me->add_temp("apply/damage", -1000);

}
        return 1;
}                                                                                                               