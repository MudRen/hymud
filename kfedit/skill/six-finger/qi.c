// qi.c ���ν���

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;
        int ap, dp;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail("���ν���ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if ((int)me->query_skill("force") < 360)
                return notify_fail("����ڹ���򲻹���ʹ�������ν�����\n");

        if ((int)me->query_skill("six-finger", 1) < 180)
                return notify_fail("�����ݤ�񽣲�������������ʹ�����ν�����\n");

        if (me->query("max_neili") < 8000)
                return notify_fail("���������Ϊ��������ʹ�����Ϭ�������ν�����\n");
        if ((int)me->query_skill("kurong-changong",1) < 100)
            return notify_fail("��Ŀ�������̫�͡�\n");
        if ((int)me->query("neili") < 500)
                return notify_fail("��������������޷�ʹ�����ν�����\n");

        if (me->query_skill_mapped("finger") != "six-finger")
                return notify_fail("��û�м��������񽣣��޷�ʹ�����ν�����\n");

       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIC "$N" HIC "��ָһ����һ���������׵����ν���ֱ��$n" HIC "��ǰ��ȥ��\n" NOR;  

        ap = me->query_skill("force");
        dp = target->query_skill("force");
        weapon = target->query_temp("weapon");
        me->start_busy(2);
if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
        { 
                damage = ap*2+200;
                me->add("neili", -200);
                if (! objectp(weapon) || weapon->query("skill_type") == "pin")
{
	if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
target->receive_damage("qi", damage*2,me);
target->receive_wound("qi", damage*2,me);
                msg +=HIR "ֻ������ǰһ���ʹ����Ѫ"
                                                   "�Դ��ڼ����������ǰ��ʱһ�ڣ�\n" NOR;
 }
                else
                if (weapon->query("ownmake") || weapon->query("damage") > 800 ||
                    weapon->query("skill_type") == "hammer")
{
	if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
target->receive_damage("qi", damage*2,me);
target->receive_wound("qi", damage*2,me);
                msg +=HIR "$p" HIR "��" + weapon->name() + HIR "��ͼ�мܣ�"
                                                   HIR "������ɽ������Ϭ����͸��" + weapon->name() +
                                                   HIR "ֱ���$p" HIR "������Ѫ������������Ҫ��ת������\n" NOR;
}
                else
                {
                	if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
target->receive_damage("qi", damage*2,me);
target->receive_wound("qi", damage*2,me);
                msg +=HIR "$p" HIR "��ת" + weapon->name() + HIR "��������"
                                                   "ǰ��ֻ��ž��һ����" + weapon->name() +
                                                   HIR "������أ��������죡\n$n" HIR "����"
                                                   "���������ۡ�������һ����Ѫ����ɫ��ĲҰס�\n" NOR;
if (!weapon->query("systemmake") && !weapon->query("ownmake"))
{

                        weapon->move(environment(me));
}
                }
        } else
        {
                msg += CYN "����$p" CYN "�ڹ���Ϊ������Ὣ����������������Ρ�\n" NOR;
        }
        message_combatd(msg, me, target);


me->add_temp("apply/attack",150);
	me->add_temp("apply/damage",2200);
	weapon = me->query_temp("weapon");

        msg = CYN "$N��˼���ң���$n����ңָ�˼��£�����ȴʹ�������������ľ���"HIY"[��������]"CYN"��" NOR;
       	         message_vision(msg, me, target);                
	 msg =  RED  "-------------------------------���̽���" NOR;
	        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = GRN   "-------------------------------��������" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg =  MAG  "-------------------------------�г彣��" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = YEL   "-------------------------------�س彣��" NOR;
             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = WHT   "-------------------------------���󽣣�" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = BLU   "-------------------------------�ٳ彣��" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/attack",-150);
	 me->add_temp("apply/damage",-2200);


        return 1;
}

