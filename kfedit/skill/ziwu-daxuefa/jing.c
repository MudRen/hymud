#include <ansi.h>
#include <combat.h>
#define TONG "��" HIR "��Ԫͨ��" NOR "��"
#define JING "��" HIM "����һ��" NOR "��"

inherit F_SSERVER;

string *finger_name = ({ "������ָ", "��������ָ", "����ʳָ",
                         "������ָ", "��������ָ", "����ʳָ", }); 
 
int perform(object me)
{
        string msg,wp;
        object weapon, target;
        int skill, ap, dp, damage,i;



        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! me->is_fighting(target))
                return notify_fail(JING "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        weapon = me->query_temp("weapon");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "dagger")
                return notify_fail("����ʹ�õ��������ԣ�����ʩչ" JING "��\n");

        skill = me->query_skill("ziwu-daxuefa", 1);

        if (me->query_skill("force",1) < 150)
                return notify_fail("����ڹ���Ϊ����������ʩչ" JING "��\n");
        if (me->query_skill_mapped("force") != "bluesea-force")
                return notify_fail("��ʹ�õ��ڹ��������Ϻ�������\n");
        if (me->query("neili") < 500)
                return notify_fail("�����ڵ��������㣬����ʩչ" JING "��\n");

        if (skill < 100)
                return notify_fail("�������书��Ϊ���ޣ�����ʩչ" JING "��\n");

        if (me->query_skill_mapped("dagger") != "ziwu-daxuefa")
                return notify_fail("��û�м��������书������ʩչ" JING "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIM "$N" HIM "����" + weapon->name() + HIM "�󿪴�ϣ�����������"
              "�գ��Ѳ�����������һ������������$n" HIM "��\n" NOR;
 
        ap = me->query_skill("dagger");
        dp = target->query_skill("parry");
        if (ap / 2 + random(ap) > dp)
        {
                me->add("neili", -200);
                damage = 300 + ap / 2 + random(ap / 2);

   target->add("qi",-damage);
		target->add("eff_qi",-damage);
		//target->start_busy(3);
                msg += HIR "��ʱֻ���á����͡�һ����$n" HIR
                                           "�ؿڱ�$N" HIR "һ�ʴ��У�����һ����Ѫ��\n" NOR;
  

                me->start_busy(1);
                if (ap / 3 + random(ap) > dp && ! target->is_busy())
                        target->start_busy(7);
        } else
        {
                msg += CYN "����$p" CYN "�Ŀ�����$P" CYN
                       "����ʽ�������һһ��⣬û¶���"
                       "������\n" NOR;
                me->add("neili", -50);
                me->start_busy(3);
        }
        message_combatd(msg, me, target);

if (skill >300 || !userp(me))
{

        msg = HIW "$N" HIW "�ݲ���ǰ�� ʫ���ݺ� ����" + weapon->name() + HIW "�󿪴�"
              "�ϣ��������಻���������س���˲����$n" HIW "�������У�\n" NOR;
        message_combatd(msg, me, target);
        me->add("neili", -50);
                                me->add_temp("apply/attack", 100);
                me->add_temp("apply/damage", 1200);
        for (i = 0; i < 5; i++)
        {
if (!target->is_busy()) target->start_busy(2);
	msg = HIR "�����"+ chinese_number(i+1) +"�ʣ�" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        }	
                                me->add_temp("apply/attack", -100);
                me->add_temp("apply/damage", -1200);
}

if (skill >600 || !userp(me))
{

 if (weapon)
                wp = "����" + weapon->name();
        else
                wp = finger_name[random(sizeof(finger_name))];

        msg = HIG "$N" HIG "��ת" + wp + HIG "�������仯���ִ�Ѩ�ַ���һʽ��"
              HIR "��Ԫͨ��" HIG "��ֱ��$n" HIG "��ǰҪѨ��\n" NOR;

        ap = me->query_skill("ziwu-daxuefa", 1);
        dp = target->query_skill("force", 1);

        if (ap / 2 + random(ap) > dp)
        {
                  damage = ap*3 + random(ap)+1000;
     target->add("qi",-damage);
		target->add("eff_qi",-damage);
		//target->start_busy(3);
                msg += HIR "$n" HIR "ֻ���ؿ�һ�飬�ѱ�$N" HIR "����"
                "ҪѨ����ʱȫ���������ͣ��಻���ԣ�\n" NOR;

        
                me->add("neili", -50);
                me->start_busy(3);
        } else
        {
                msg += CYN "����$n" CYN "���ѿ���$N"
                       CYN "������ʵ������һ�ӣ��ǽ����л������Ρ�\n" NOR;
                me->add("neili", -50);
                me->start_busy(4);
        }
        message_combatd(msg, me, target);	
	
}

me->start_busy(2);
        return 1;
}
