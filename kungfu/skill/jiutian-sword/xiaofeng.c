#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;


int perform(object me, object target)
{
        object weapon, ob;
        string msg;
        int myexp,yourexp,lvl;    
        int myskill, myskill1, tparryb, tparryh, myforce, tforce,  texp, damage;
        object tweapon;
        weapon = me->query_temp("weapon");
        myskill= (int)me->query_skill("sword",1);
        myskill1= (int)me->query_skill("jiutian-sword",1);
                
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ�� �������� ��?\n");
         
if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("ֻ����ս����ʹ�á�\n");

 if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
        return notify_fail(RED"��ʲô��Ц���������ԣ�\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "huiyan-xinfa")
                return notify_fail("��ʹ�û����ķ�!\n");

        if((int)me->query_skill("huiyan-xinfa",1) < 200)
                return notify_fail("��Ļ����ķ�������������\n"); 
        
        if( !me->is_fighting() )
                return notify_fail("�� �������� ��ֻ����ս����ʹ�á�\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");



        if( (int)me->query_skill("jiutian-sword", 1) < 120)
                return notify_fail("��ľ����Ȫ���ȼ�����������ô��ʹ���� �������� ����\n");

        if( (int)me->query("combat_exp",1) < 150000 )
                return notify_fail("��ľ��鲻�㣬����ʹ���� �������� ����\n");

        if (me->query("neili") < 650)
                return notify_fail("���������̣�����ʹ���� �������� ����\n");

        me->clean_up_enemy();
        ob = me->select_opponent();
        myexp = (int) me->query("combat_exp");
        yourexp = (int) target->query("combat_exp");
        lvl = (int)me->query_skill("jiutian-sword",1)/40;
        
        msg = HIC
"\n$N��ɫ����,���н�â�ó���ʹ�â����������$n����Ȧȥ����һ�С��������¡�\n" NOR;
        me->add_temp("apply/attack",200	);
        me->add_temp("apply/damage",3800);
                message_combatd(msg + "\n", me, target, "");
                msg = HIM "$nֻ�����ɽ�����ס�Լ�,��ʱȫ��һ��,��������!!\n" NOR;
                
                message_combatd(msg, me, target, "");
                target->start_busy(2);
                msg=HIM"��һ����ʽ���һ�����紺���µĺ�¶Ϊ֮�ڻ�����$n��̾��"NOR;
                 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

                msg=HIC"�ڶ�����ʽ���һ�����������������ޣ���$n�п���"NOR;
                 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

                msg=HIW"��������ʽ���һ�����ƿں���¶��ȸ�������衢���ۣ���$n���Σ�"NOR;
                 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

                msg=HIW"���Ĺ���ʽ���һ����������ñ���谮�����ˡ���$n��ʹ��"NOR;
                 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
                 
                msg=HIW"�������ʽ���һ�������������ᣬ���������ơ���$n�Ļţ�"NOR;
                 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);                 

        me->add_temp("apply/attack",-200	);
        me->add_temp("apply/damage",-3800);
 
        

if ((int)me->query_skill("jiutian-sword",1)> 360)
{
	    message_vision(HIW"$N���ƽ������˽���Բ��һ�ɹɽ���������������£�\n\n" NOR,me,target);        
      message_vision(HIG"������ϵġ���ָ������Χ����$N��ߣ�\n"NOR,me);
if(random(myexp)>(int)(yourexp/2) || random(3)==0)
{msg = HIR"$n����������һ����͵Ľ���͸�������\n"NOR;
damage=800+(myskill*3);
if(damage<1800)damage = 1800;
target->receive_damage("qi", damage,me);
target->receive_wound("qi", damage,me);
target->start_busy(4);
     message_vision(msg, me, target);
     COMBAT_D->report_status(target);
     }
else{
         msg = HIW"$n��֪���У�����һ��,���Ž���ƽƽ�ķ��˳�ȥ��\n\n"NOR;
            message_vision(msg, me, target);
        COMBAT_D->do_attack(target, me, tweapon);
        }
}        
        
        me->add("neili", -150);
        me->start_busy(2);
        return 1;  

}

