// modify by shao 2001.12.27
// �������У�̫�������ǣ��������������󻯰��ԣ�����ٺ�̫����
// ��Ҫ����exp��skills������

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
string get_name(string str)
{
        str="̫��";
        return str;
}



int perform(object me, object target)
{
        string msg;
        object weapon;
        int exp1, exp2,sword,parry,damage, wound;

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�㲻��ս������ʲô�ã�\n");

if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("ֻ����ս����ʹ�á�\n");

 if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
        return notify_fail(RED"��ʲô��Ц���������ԣ�\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "honghua-shengong")
                return notify_fail("��ʹ�ú컨��!\n");

        if((int)me->query_skill("honghua-shengong",1) < 200)
                return notify_fail("��ĺ컨�񹦻�����������\n"); 

        exp1 = (int)me->query("combat_exp",1);
        exp2 = (int)target->query("combat_exp");
        sword = (int)me->query_skill("bainiao-jian",1);
        sword = sword * sword * sword / 10;
        parry = (int)target->query_skill("parry",1);
        parry = parry * parry * parry / 10;

        if(me->query_skill("sword",1) < 100 )   
                return notify_fail("��Ļ�������̫���ˣ�\n");
        
        if(me->query_skill("bainiao-jian",1) < 100 )   
                return notify_fail("��İ��񽣷�̫���ˣ�\n");





        if(me->query("max_neili") < 800)
                return notify_fail("���������������̫����������\n");

        if(me->query("neili") < 800)
                return notify_fail("������������ˣ�\n");

        weapon = me->query_temp("weapon");

        if ((int)me->query_skill("bainiao-jian",1) > 100)
        {
                msg = HIW "$N��Ȼ���б��������е�"+ weapon->query("name")+ HIW"������һ��̫�������зֳ�����������           
         $NĬĬ�������̫�������ǣ�\n"NOR;

                message_vision(msg, me, target);
        
                if( random( exp1 + sword )> ( exp2 + parry) / 4)
                {
                        msg = HIR "$nֻ������������֮��ֱ�ƹ�������֪����ζ�������ʱ��$N��"+ weapon->query("name")+ HIR"���˸����ţ�\n\n"NOR;
                        message_vision(msg, me, target);
                        me->add("neili",-30);
                        damage = (100 + me->query_str() + random(me->query_skill("bainiao-jian",1)/2 + me->query("force_factor")) / 2 );
                        wound=random(damage-(int)target->query_temp("apply/armor"));
                        if(wound>0) target->receive_wound("qi", wound);
                        target->receive_damage("qi", damage);
                        COMBAT_D->report_status(target, 0);
 
                }
                else
                {
                        msg = HIG "ֻ��$n�������أ����ɽ��仯�⣡\n\n"NOR;
                        message_vision(msg, me, target);
                        me->add("neili",-30);
                        me->start_busy(1);
                }
        }


        if ((int)me->query_skill("bainiao-jian",1) > 150)
        {
                msg = HIW "���������������е�"+ weapon->query("name")+ HIW"�������󣬴��ĸ���������           
         $NĬĬ�����������������\n"NOR;

                message_vision(msg, me, target);

                if( random( exp1 + sword )> ( exp2 + parry) / 4)
                {
                        msg = HIR "$nһ�����񣬱�$N����޻���֮����\n\n"NOR;
                        message_vision(msg, me, target);
                        me->add("neili",-30);
                        damage = (150 + me->query_str() + random(me->query_skill("bainiao-jian",1)/2 + me->query("force_factor")) );
                        wound=random(damage-(int)target->query_temp("apply/armor"));
                        if(wound>0) target->receive_wound("qi", wound);
                        target->receive_damage("qi", damage);
                        COMBAT_D->report_status(target, 0);
 
                }
                else
                {
                        msg = HIG "$n����������$N�Ĺ���һһ���⣡\n\n"NOR;
                        message_vision(msg, me, target);
                        me->add("neili",-30);
                        me->start_busy(2);
                }
        }



        if ((int)me->query_skill("bainiao-jian",1) > 200)
        {
                msg = HIW "�����漴�����仯��Ϊ���ԣ�           
         $NĬĬ����������󻯰��ԣ�\n"NOR;
       
                message_vision(msg, me, target);
        
                if( random( exp1 + sword )> ( exp2 + parry) / 3)
                {
                        msg = HIR "ֻ����Ӱ��Ǭ�������𡢿����ޡ��롢�㡢�Ұ˷�������$n������æ���ң��˸���λ���ܼ�ˣ�\n\n"NOR;
                        message_vision(msg, me, target);
                        me->add("neili",-50);
                        damage = (250 + me->query_str() + random(me->query_skill("bainiao-jian",1) + me->query("force_factor")) / 2 );
                        wound=random(damage-(int)target->query_temp("apply/armor"));
                        if(wound>0) target->receive_wound("qi", wound);
                        target->receive_damage("qi", damage);
                        COMBAT_D->report_status(target, 0);
 
                }
                else
                {
                        msg = HIG "$n���������������׽��仯�⣡\n\n"NOR;
                        message_vision(msg, me, target);
                        me->add("neili",-30);
                        me->start_busy(2);
                }
        }


        if ((int)me->query_skill("bainiao-jian",1) > 300)
        {
                msg = HIW "�����ֽ����϶�Ϊһ���γ�һ��̫����           
         $NĬĬ����������Ժ�̫����\n"NOR;
       
                message_vision(msg, me, target);
        
                if( random( exp1 + sword )> ( exp2 + parry) / 2)
                {
                        msg = HIR "һ���޴��̫����$n���˹�����$n�մ������������̱����˸����ţ�\n\n"NOR;
                        message_vision(msg, me, target);
                        me->add("neili",-30);
                        damage=(me->query_kar() / 10+          random(me->query_skill("sword",1)) / 20 );
                        if ( damage > 6)
                        damage = 6;
                        target->start_busy(damage);
 
                }
                else
                {
                        msg = HIG "$nһ������̫�����Ľ��仯�⣡\n\n"NOR;
                        message_vision(msg, me, target);
                        me->add("neili",-30);
                        me->start_busy(2);
                }
        }


        me->start_busy(2);

        return 1;
}


