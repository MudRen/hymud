#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
        string msg;
	int extra,damage;
	object weapon,ob;
        int ap, dp,skill;
        
	if(me->is_busy())
		return notify_fail("������û�գ���\n");
	extra = me->query_skill("six-finger",1);
	skill = me->query_skill("six-finger",1);
        if( !target ) target = offensive_target(me);
if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("����������ֻ����ս����ʹ�á�\n");
 
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("����������ֻ�ܿ���ʹ�á�\n");		

        if (me->query_skill("kurong-changong", 1)<70)
                return notify_fail("��ı����ڹ����δ������\n");
       	if(me->query_skill_mapped("force") != "kurong-changong")
		return notify_fail("û�п���������Ϊ׼�����޷�ʹ����\n"); 
	 if( (int)me->query("neili") < 600 )
                return notify_fail("�������������\n");

        if( (int)me->query_skill("six-finger",1) < 180 )
                return notify_fail("��������񽣻�򲻹����޷�ʹ�á��������񡹣�\n");

        if( (int)me->query_skill("force",1) < 150 )
                return notify_fail("����ڹ���Ϊ�������޷�ʹ�á��������񡹣�\n");
	damage=extra*3;
	if (damage<=1500) damage=1500;
	me->add_temp("apply/attack",150);
	me->add_temp("apply/damage",1200);
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
	 me->add_temp("apply/damage",-1200);
if (skill>300 && me && target)
{
 msg = HIW "\nֻ��$N" HIW "һ����Ц��ʮָ�׵��������籼�������޾������ƽ�����Ȼ����$n" HIW "��\n" NOR;

        ap = me->query_skill("six-finger", 1) +
             me->query_skill("finger", 1) / 2;
        dp = target->query_skill("force");

        if (ap / 2 + random(ap) > dp || random(3)==0)
        {
                msg += HIR "���$p" HIR "�����ݺύ��Ľ����Ƶ���æ���ң�Ӧ�Ӳ�Ͼ��\n" NOR;
                target->start_busy(4);
        } else
        {
                msg += CYN "����$p" CYN "�������ţ������ڹ���$P"
                       CYN "�Ľ����������⡣\n" NOR;
                me->start_busy(1);
        }
        message_combatd(msg, me, target);	
	
}

if (skill>350 && me && target)
{
   msg = HIC "\n$N" HIC "��ָһ����һ���������׵����ν���ֱ��$n" HIC "��ǰ��ȥ��\n" NOR;  

        ap = me->query_skill("force");
        dp = target->query_skill("force");
        weapon = target->query_temp("weapon");
        me->start_busy(2);
        if (ap / 2 + random(ap) > dp || random(3)==0)
        { 
                damage = ap + random(ap / 2)+500;
                if (! objectp(weapon) || weapon->query("skill_type") == "pin")
{
	if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
target->receive_damage("qi", damage*2,me);
target->receive_wound("qi", damage,me);
                msg +=HIR "ֻ������ǰһ���ʹ����Ѫ"
                                                   "�Դ��ڼ����������ǰ��ʱһ�ڣ�\n" NOR;
 }
                else
                if (weapon->query("ownmake") || weapon->query("damage") > 800 ||
                    weapon->query("skill_type") == "hammer")
{
	if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
target->receive_damage("qi", damage*2,me);
target->receive_wound("qi", damage,me);
                msg +=HIR "$p" HIR "��" + weapon->name() + HIR "��ͼ�мܣ�"
                                                   HIR "������ɽ������Ϭ����͸��" + weapon->name() +
                                                   HIR "ֱ���$p" HIR "������Ѫ������������Ҫ��ת������\n" NOR;
}
                else
                {
                	if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
target->receive_damage("qi", damage*2,me);
target->receive_wound("qi", damage,me);
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
	
}	
	
        me->add("neili", -300);
        me->start_busy(2);

        return 1;
}

