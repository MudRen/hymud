//��ȥ������ wuying.c
// by godzilla 99.03.06

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";
//inherit F_CLEAN_UP;

void remove_effect(object me, int a_amount, int d_amount);

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon,ob;
        int skill;
	int extra;
        string msg;
int damage,p;        
        string dodge_skill;
        int ap, dp;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��������Ӱ��ֻ����ս����ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
                return notify_fail("��������Ӱ�������ý�����ʩչ��\n");

        if( (int)me->query_skill("wuying-jian", 1) < 150 )
                return notify_fail("��ġ�������Ӱ����������죬����ʹ�á�������Ӱ����\n");

//        if (me->query_skill_mapped("force") != "yijinjing")
//                return notify_fail("����ڹ������׽��\n");

	if( (int)me->query_skill("yijinjing", 1) < 100 )
		return notify_fail("����׽������졣\n");

        if( (int)me->query("neili") < 400  ) 
                return notify_fail("�������������\n");

        skill = me->query_skill("wuying-jian");
	extra = me->query_skill("wuying-jian",1) / 10;
	extra += me->query_skill("wuying-jian",1) /10;
	me->add_temp("apply/attack", 80);	
	me->add_temp("apply/damage", (extra*5));

        msg = HIG "$N����ͻ�䣬˲������ֳ�������Ӱ��������$n��ȥ��\n"NOR;
        message_vision(msg, me, target);

        me->add("neili", -200);
if (random(2)==0 && !target->is_busy()) target->start_busy(2);
        msg = HIR"���־���-+-----\n"NOR;
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR,msg);
        msg = HIY"ȥ�־���-+-----\n"NOR;
        
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR,msg);
        msg = HIG"���־���-+-----\n"NOR;
        
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR,msg);
        msg = HIB"���־���-+-----\n"NOR;
        
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR,msg);
        msg = HIW"���־���-+-----\n"NOR;
       
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR,msg);

if (me->query_skill("wuying-jian",1)>200 )
{
	msg = HIG "$Nʹ����������Ħ��������������Ȼ�ӿ죡\n" NOR;     
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 msg =  HIC  "$N���μӿ죬��������һ���� \n" NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg =  HIC  "$N������ת������$n����һ���� \n" NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
}	 
        me->start_busy(2);
	me->add_temp("apply/attack", -80);
	me->add_temp("apply/damage", -(extra*5));
if (me->query_skill("wuying-jian",1)>300 && me->query("neili")>500)
{
  msg = HIG "$N" HIG "������" + weapon->name() +
              HIG "����һ�񣬽����������죬���ν���ֱָ$n"
              HIG "����ҪѨ��\n" NOR;

        ap = me->query_skill("sword") + me->query_skill("force");
        dp = target->query_skill("force") * 2;

	if (ap / 3 + random(ap) > dp || random(3)==0)
        {
                damage = ap / 3 + random(ap / 3)+200;

target->add("qi",-damage);
target->add("eff_qi",-damage/2);
target->add("jing",-damage/2);
msg += HIR "���$n" HIR "ֻ������Ѩ��һʹ����ǰһ��"
               "�ڣ�������ѣ�����Լ���ս����\n" NOR;
                me->start_busy(2);
               
	} else
        {
		msg += CYN "����$n" CYN "�������ʹ��$P"
                       CYN "��һ��û�����κ����á�\n" NOR;
		me->start_busy(2);
                
	}
	message_combatd(msg, me, target);	
}	

if (me->query_skill("wuying-jian",1)>400 && me->query("neili")>500)
{
        msg = HIR "\n$N" HIR "��ؽ�" + weapon->name() +
              HIR "��ǰһ�ͣ���ʱһ���⻪�Խ�������ֱ��$n"
              HIR "�����ȥ��\n" NOR;

        ap = me->query_skill("sword") + me->query_skill("force");
        dp = target->query_skill("force") * 2;

	if (ap / 3 + random(ap) > dp || random(3)==0)
        {
                damage = ap / 3 + random(ap / 3)+300;
msg += HIR "ͻȻ$n" HIR "ֻ�������Ȼһ�ȣ��漴�����"
               "������������ʧɫ��\n" NOR;

target->add("qi",-damage);
target->add("neili",-damage);
                me->start_busy(2);
               
	} else
        {
		msg += CYN "����$n" CYN "�������ʹ��$P"
                       CYN "��һ��û�����κ����á�\n" NOR;
		me->start_busy(2);
                
	}
	message_combatd(msg, me, target);	
}

if (me->query_skill("wuying-jian",1)>500 && me->query("neili")>500)
{
	msg = HIM "\n$N" HIM "��ת���棬����" + weapon->name() +
              HIM "�Ϲ⵴�����������������ν�������$n"
              HIM "ȫ��\n" NOR;

        ap = me->query_skill("sword") + me->query_skill("force");
        dp = target->query_skill("force") * 2;

	if (ap / 3 + random(ap) > dp || random(3)==0)
        {
                damage = ap / 3 + random(ap / 3)+500;
msg += HIR "��ʱ$n" HIR "��ͷһ���Ի����ڵ�������ʱ"
                "����ʹ�����Ĵ����ߡ�\n" NOR;

target->add("qi",-damage);
target->add("eff_qi",-damage);
                me->start_busy(2);
                
	} else
        {
		msg += CYN "����$n" CYN "�������ʹ��$P"
                       CYN "��һ��û�����κ����á�\n" NOR;
		me->start_busy(2);
                
	}
	message_combatd(msg, me, target);
	
}	


        return 1;
}
