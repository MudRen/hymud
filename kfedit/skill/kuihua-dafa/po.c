#include <ansi.h>
#include <combat.h>

#define PO "��" HIW "��Ԫ����" NOR "��"

inherit F_SSERVER;

string final(object me, object target, int damage);

string *finger_name = ({ "������ָ", "��������ָ", "����ʳָ",
                         "������ָ", "��������ָ", "����ʳָ", }); 

int perform(object me, object target)
{
        int damage,neili;
        string msg, name;
        object weapon;
        int lvl, ap, dp;

        int i,j;
        int skill;
        int count;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(PO "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        weapon = me->query_temp("weapon");
        skill = me->query_skill("kuihua-dafa", 1);
        lvl = me->query_skill("kuihua-dafa", 1);
        
        if (weapon && weapon->query("skill_type") != "sword"
           && weapon->query("skill_type") != "pin")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" PO "��\n");

        if ((int)me->query_skill("kuihua-dafa", 1) < 180)
                return notify_fail("��Ŀ����񹦲�����죬����ʩչ" PO "��\n");
       if ((int)me->query_skill("kuihua-xinfa", 1) < 50)
               return notify_fail("��Ŀ����ķ�̫���ˡ�\n");
               
        if ((int)me->query("max_neili") < 2600)
                return notify_fail("���������Ϊ���㣬����ʩչ" PO "��\n");

        if (me->query("neili") < 300)
                return notify_fail("�����ڵ��������㣬����ʩչ" PO "��\n");

        if (weapon && me->query_skill_mapped("sword") != "kuihua-dafa")
                return notify_fail("��û��׼��ʹ�ÿ����񹦣�����ʩչ" PO "��\n");


        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");


        if (me->query_temp("weapon"))
                name = "����" + weapon->name();
        else
                name = finger_name[random(sizeof(finger_name))];

        msg = HIW "$N" HIW "һ����ߣ�˫����͸��һ˿������" + name +
              HIW "����ǧ�ٸ����ƣ��ó�������ɫ�ʣ�\n" NOR;

        ap = me->query_skill("sword") +
             me->query_skill("dodge");

        dp = target->query_skill("parry") +
             target->query_skill("dodge");
neili=target->query("neili")/2;
if (neili>28000) neili=28000;
        if (ap / 2 + random(ap) > dp)
        {
                damage = ap + random(ap)+100;
                target->add("qi",-damage);
		target->add("eff_qi",-damage/2);
                target->add("neili",-neili);
                msg +=HIR "$n" HIR "ֻ����ǰ��âһ���������漴ȫ��һ��"
               "��ʹ������Ѫ�������������\n$p��Ȼ��һ��������"
               "�����������������ƻ�ɢһ�㣬ȫȻ�޷����ơ�\n" NOR;
                me->start_busy(3);
                me->add("neili", -100);
        } else
        {
                msg += CYN "$n" CYN "��֮��ȫȻ�޷��мܣ���æ"
                       "���������ߣ��㿪����һ�С�\n" NOR;
                me->start_busy(3);
                me->add("neili", -150);
        }
        message_vision(msg, me, target);

if (skill>300 && me && target)
{
        msg = HIR "\n$N" HIR "һ����Х��������Ȼ��ת������" + name +
              HIR "��ʱ������������������ǧ������룬�������$n" HIR "��\n" NOR;
        i = 4;
        if (lvl / 2 + random(lvl) > (int)target->query_skill("dodge") || random(3)==0)
        {
                msg += HIR "$n" HIR "ֻ����ǰ���������������漴ȫ��һ��"
               "��ʹ������Ѫ�������������\n$p��Ȼ��һ��������"
               "�����������������ƻ�ɢһ�㣬ȫȻ�޷����ơ�\n" NOR;
                count = me->query_skill("kuihua-dafa", 1);
                i += random(6);
        } else
        {
                msg += CYN "$n" CYN "��$N" CYN "���ÿ죬����"
                       "�ҵ�������æ������С��Ӧ�ԡ�\n" NOR;
                count = 0;
        }

        message_vision(msg, me, target);
me->set_temp("action_flag", 1);
        me->add_temp("apply/attack", 200);
        me->add_temp("apply/damage", 1800);
j=1;
        while (i--)
        {
                if (! me->is_fighting(target))
                        break;
                if (i > 5 && ! target->is_busy())
                        target->start_busy(1);
j=j+1;
	msg = HIY "$N��������ޱȣ�������$n������"+chinese_number(j+1)+"�У���\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        }
me->delete_temp("action_flag");
        me->add_temp("apply/attack", -200);
        me->add_temp("apply/damage", -1800);
	
}	
	
	

        return 1;
}

