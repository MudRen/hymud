#include <ansi.h>
#include <combat.h>

#define HAI "��" HIG "�ຣ�ޱ�" NOR "��"

inherit F_SSERVER;

string final(object me, object target, int damage);

string *finger_name = ({ "������ָ", "��������ָ", "����ʳָ",
                         "������ָ", "��������ָ", "����ʳָ", }); 

int perform(object me, object target)
{
        int damage;
        string msg, name;
        object weapon;
        int lvl, ap, dp;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(HAI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (weapon = me->query_temp("weapon"))
        {
                if (weapon->query("skill_type") != "staff" && weapon->query("skill_type") != "dagger")
                        return notify_fail("�������õ��������ԣ���ôʩչ" HAI "��\n");
        } else
        {

        }

        if ((int)me->query_skill("bluesea-force", 1) < 260)
                return notify_fail("����Ϻ�����������죬����ʩչ" HAI "��\n");

        if ((int)me->query("max_neili") < 3700)
                return notify_fail("���������Ϊ���㣬����ʩչ" HAI "��\n");

        if (me->query("neili") < 300)
                return notify_fail("�����ڵ��������㣬����ʩչ" HAI "��\n");
                
        if (me->query_skill_mapped("force") != "bluesea-force")
                return notify_fail("��ʹ�õ��ڹ����ԡ�\n");


        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");


        if (me->query_temp("weapon"))
                name = "����" + weapon->name();
        else
                name = finger_name[random(sizeof(finger_name))];

        msg = HIB "$N" HIB "����˫�ۣ����һ����һ�����˾��ŷ�ʯ����ΰ�Ϯ��$n" HIB "���Է�����δ��֮�ʣ������������졣\n"
              HIB "��$N" HIB "��" + name + HIB "�����������������Ϯ$n" HIB "������Ѩ������Ѩ������Ѩ������Ѩ����\n\n" NOR;

        ap = me->query_skill("force");
        dp = target->query_skill("dodge");

        if (ap / 2 + random(ap) > dp)
        {
                damage = me->query_skill("force")+500;
                damage = 150+me->query_skill("unarmed");
   target->add("qi",-damage);
		target->add("eff_qi",-damage);
		target->start_busy(3);
                msg += HIY "$n" HIY "ֻ����ǰ��ɳ��ʯ��Ŀ�����ӣ���������ҪѨ"
               "��ʹ������Ѫ�������������\n$p��Ȼ��һ��������"
               "�����õ���֮�ڿ������ȣ�ȫȻ�޷�������\n" NOR;
                me->start_busy(2);
                me->add("neili", -500);
        } else
        {
                msg += CYN "$n" CYN "������һ�����ӷ���Ծ�����ɣ�"
                       "���Ҷ㿪����һ�С�\n" NOR;
                me->start_busy(3);
                me->add("neili", -350);
        }
        message_combatd(msg, me, target);
        return 1;
}

