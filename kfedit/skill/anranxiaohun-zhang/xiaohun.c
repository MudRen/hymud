// xiaohun.c ��Ȼ����
// By Kayin @ CuteRabbit Studio 99-4-16 19:18 new
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
        string msg;
	int extra;
	object weapon,ob;
	
        int ap, dp;
        int count;
        int i,skill,damage;
	
	if(me->is_busy())
		return notify_fail("������û�գ���\n");
	extra = me->query_skill("anranxiaohun-zhang",1);
	skill = me->query_skill("anranxiaohun-zhang",1);
        if( !target ) target = offensive_target(me);
if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("����Ȼ���꡹ֻ����ս����ʹ�á�\n");
 
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("����Ȼ���꡹ֻ�ܿ���ʹ�á�\n");		
       
	 if( (int)me->query("neili") < 1000 )
                return notify_fail("�������������\n");
    if(me->query_skill_mapped("force") != "yunv-xinfa" )
        return notify_fail("��Ҫ����Ů�ķ���Ϊ�ڹ������á�\n");

        if( (int)me->query_skill("anranxiaohun-zhang",1) < 300 )
                return notify_fail("�����Ȼ�����ƻ�򲻹����޷�ʹ�á���Ȼ���꡹��\n");
	if( (int)me->query_skill("xuantie-sword",1) < 100 )
                return notify_fail("�������������򲻹����޷�������Ȼ���꡹��\n");
        if( (int)me->query_skill("force",1) < 200 )
                return notify_fail("����ڹ���Ϊ�������޷�ʹ�á���Ȼ���꡹��\n");
	weapon = me->query_temp("weapon");
	if (extra>200) extra=200;
	me->add_temp("apply/attack",100);
	me->add_temp("apply/damage",2000);

        msg = HIM "$N����ֹˮ������˼����$N�İ��ˣ�����֮��ʹ����"HIR"����Ȼ���ꡱ��\n" NOR;
        msg += HIM   "���ư����ң�̣���ʱ��ؼ����һ˿��ɬ��\n" NOR;
	         message_vision(msg, me, target);                
	 msg = HIC  "\n   �� \n" NOR;
	        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "\n      Ȼ\n" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "\n        ��\n" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "\n          ��\n" NOR;
             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB "\n             ��\n" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/attack",-100);
	 me->add_temp("apply/damage",-2000);

        if( me->query("shen") > 10000
        && target->query("shen") < 10000 )
{
msg = HIG "\n$Nŭ��$n,��һ�����������һ�ƣ����ư����ң�̣���ʱ��ؼ����һ˿��ɬ��\n"NOR;
 if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
	 {

                msg += RED"\n������䡹��һ����$nȫ����Ѫ������������Ѫ���������\n"NOR;
damage=300+((int)me->query_skill("anranxiaohun-zhang")*5);
                if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
                target->receive_damage("qi", damage,me);
                target->receive_wound("qi", damage,me);

// should not busy target if he already in busy (by xbd)
                if (!target->is_busy()) target->start_busy(4);
//             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
		message_combatd(msg, me, target);
                COMBAT_D->report_status(target);
	} else {
		msg += HIY"����$p�������ǣ����ط����������ܹ���������һ��,���˿�ȥ��\n" NOR;
		message_combatd(msg, me, target);
	}
}
        me->add("neili", -200);
        me->start_busy(2);
if (skill>300 && target && me)
{
 msg = "\n"+ HIM "$N" HIM "һ����̾������ֹˮ����Ȼ���ˣ��ڲ���������"
              "��ʹ����" HIR "����Ȼ���꡻" HIM "��\n" NOR;

        ap = 100+me->query_skill("unarmed") +
             me->query_skill("force");

        dp = target->query_skill("parry") +
             target->query_skill("force");
             
 if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
        {
damage=ap;
                if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
                target->receive_damage("qi", damage*3,me);
                target->receive_wound("qi", damage*2,me);
                        msg +=HIR "ֻ��$n" HIR "һ���ƺߣ����ۡ���һ"
                                           "������һ�����û���$p" HIR "��ͷ�� \n"
                                           NOR;
                msg += HIY "$n" HIY "��$P" HIY "��һ�б仯Ī�⣬�����"
                       "�������ɴ��һ��������������������\n" NOR;
        } else
        {
                msg += HIC "$n" HIC "����С��$P" HIC
                       "�����У���Ų������С���мܡ�\n" NOR;
        }

        message_combatd(msg, me, target);
	
	
}	        
if (skill>400 && target && me)
{
                msg = "\n"+ HIR "$N" HIR "���������ң���Ȼ������"
                      HIR "����һ�ۣ������������ˣ����Լ����ء���\n"
                      "����ʧ�����ǣ�����һ�У�ǡ��ʹ������Ȼ��������"
                      "�ġ������ˮ����\n" NOR;

        ap = 300+me->query_skill("unarmed") +
             me->query_skill("force");

        dp = target->query_skill("parry") +
             target->query_skill("force");
             
 if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
        {
damage=ap;
                if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
                target->receive_damage("qi", damage*3,me);
                target->receive_wound("qi", damage*3,me);

                        msg +=HIR "ֻ��$n" HIR "һ���ƺߣ����ۡ���һ"
                                           "������һ�����û���$p" HIR "��ͷ�� \n"
                                           NOR;

        } else
        {
                msg += HIC "����$p" HIC "С��Ӧ���������мܣ���������һ�С�\n"
                       NOR;
        }

        message_combatd(msg, me, target);
	
	
}	
        
if (skill>500 && target && me)
{
 ap = me->query_skill("force") + me->query_skill("unarmed") + me->query_skill("anranxiaohun-zhang");
	dp = target->query_skill("force") + target->query_skill("parry");
	
        skill=me->query_skill("anranxiaohun-zhang",1);

        message_vision(HIW"\n$N���Ʒ��������ų�ӿ֮�����Ʒ�ĵ��������п�ӿ���������������������ں��������ľ����� \n\n"NOR,me,target);
	
 if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
	{
		message_vision(HIR"$n�����ܵÿ��������Ѿ���$N���Ʒ�ӡ���ؿڣ�һ����Ѫ���������\n\n",me,target);
damage=ap;
                if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
                target->receive_damage("qi", damage,me);
                target->receive_wound("qi", damage,me);
	} else
	{
		message_vision(HIY"$n��״������̾͵�һ���������Ȼ�����ѿ��Լ�����������ܿ���$N��һ�ơ�\n\n"NOR,me,target);
	}

        message_vision(HIW"\n$N���Ʒ�ﵽ����֮ʱ�����š��겻���ᡱ����������ʩ������������ʧ�����������С�\n\n"NOR,me,target);
	
	if (ap/2 + random(ap/2) > dp || random(3)==0)
	{
		message_vision(HIR"$n����δ����������֮�ʣ��������һ�����ҵ������������������$N�Ʒ��ش���\n\n",me,target);
damage=ap;
                if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
                target->receive_damage("qi", damage,me);
                target->receive_wound("qi", damage,me);

	} else
	{
		message_vision(HIY"$n�˲��÷���������������ɣ����ո�$N���Ʒ�ɨ����΢΢���죬��������ܿ���$N�����ơ�\n\n"NOR,me,target);
	}
	
        message_vision(HIW"����$N�������һ�С���ʬ���⡱��������߳�һ�š�\n\n"NOR,me);
 if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
	{
		message_vision(HIR"$n�ۿ�������������һ�ţ���Ȼ�����˵ֿ�������������$N�������ϣ����ݽ��飬��ĿѪɫ������\n\n",me,target);
damage=ap;
                if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
                target->receive_damage("qi", damage*2,me);
                target->receive_wound("qi", damage*2,me);

	} else
	{
		message_vision(HIY"$n˫���أ�������𣬴�$N��ͷ���ӹ������¾�����Х������������֮���գ�\n\n"NOR,me,target);
	}
	
}	

        return 1;
}

