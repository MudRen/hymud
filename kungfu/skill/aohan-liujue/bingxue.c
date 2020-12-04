//Created by Wuyou@Sanjie

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int damage, mypot, tapot, ap, dp, def, extra;
        object weapon;
        weapon = me->query_temp("weapon");
        
        damage = (int)me->query_skill("aohan-liujue", 1) + (int)me->query_skill("blade", 1);
        //damage = damage/2 + random(damage/2);
        
 if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("ֻ����ս����ʹ�á�\n");

 if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
        return notify_fail(RED"��ʲô��Ц���������ԣ�\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "panshi-shengong")
                return notify_fail("��ʹ����ʯ��!\n");

        if((int)me->query_skill("panshi-shengong",1) < 200)
                return notify_fail("�����ʯ�񹦻�����������\n"); 
                
        if( !me->is_fighting(target) )
                return notify_fail(HIR"��ǧ���������ѩ��"WHT"ֻ����ս��ʹ�á�\n"NOR);

        if( me->is_busy() )
                return notify_fail(HIR"��������æ��\n"NOR);

                    
            if (me->query_skill("aohan-liujue",1)<200)
                return notify_fail(WHT"��������书�������죬���ü���Ŭ����\n"NOR);     

        if((int)me->query("neili") < 600 )
                return notify_fail(WHT"����������㡣\n"NOR);
        if( me->query("max_neili") < 1000 )
                return notify_fail(WHT"���������Ϊ��ǳ����������"HIR"��ǧ���������ѩ��"WHT"��\n"NOR);     
        if( (int)me->query("qi") < 200 || (int)me->query("jing") < 200  )
                return notify_fail(WHT"������̫�����ˣ��޷�ʩչ"HIR"��ǧ���������ѩ��"WHT"��\n"NOR);


            
        msg = MAG "\n\t�����"HIW"��ѩ"HIG"Ϊ"HIB"��"HIW"��"HIG"Ϊ"HIR"�ǣ�"HIY"����"HIW"��ѩ"HIM"��"HIC"��գ�"NOR""MAG"�����\n" NOR;                      
                     
        me->add("qi", -50);
        me->add("jing", -50);
        me->start_busy(3); 
        msg += WHT "\n\t���������·�˪������\n" NOR;
        msg += WHT "\t\t\tǧ���ѩ˭��Թ��\n" NOR;
        msg += HIC "\n�������գ�������$N����һ������ʱ��ѩ�׷ɣ�Թ�����죡\n" NOR;
        
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/5 ) 
        {
                msg += HIY "$n��֪��������Թ����Χ�ˣ�\n" NOR;
                target->receive_damage("qi",damage);
                target->receive_wound("qi",damage/2);
                message_combatd(msg, me, target, "");
                COMBAT_D->report_status(target); 
                me->add("neili", -50);
        }
        else
        {
                msg += HIY "$n�˹��࿹����Թ����ֹ��������Χ��\n" NOR;
                message_combatd(msg, me, target, "");
        }               
        
        msg = MAG "\n\t��������ѩ���Ρ�����\n" NOR;
        msg += MAG "\t\t\t����ɻ�һ���գ�\n" NOR;
        
        mypot=(int)me->query_skill("aohan-liujue");
        mypot=mypot*mypot*mypot + (int)me->query("combat_exp");

        tapot=(int)target->query_skill("parry");
        tapot=tapot+(int)target->query_skill("dodge")/10;
        tapot=tapot*tapot*tapot/10 + (int)target->query("combat_exp");
        
        msg += HIW "\n�������ϼ�����������ԼԼ$n�����칬��������Ϸ�����ɾ��硣
$n�������ĳ�����Ȼ��һ�ɺ����Ӻ�Ϯ����\n" NOR;
        
        if( random( mypot+tapot ) > tapot/4 || !living(target) ) 
        {
                msg += HIY "$n���ѽ����λ�֮����δ���ѣ�������һ��͸������\n" NOR;
                COMBAT_D->do_attack_damage(me, target);
                damage=100+damage;
                target->receive_damage("qi",damage);
                target->receive_wound("qi", damage/2);
                message_combatd(msg, me, target, "");
                COMBAT_D->report_status(target);                
                me->add("neili", -50);
        }
        else
        {
                msg += HIY "$n�����������Ի󣬱ܿ�����ɺ�����\n" NOR;
                message_combatd(msg, me, target, "");
        }
                
        msg = HIR "\n\t������̤ѩѰ÷������\n" NOR;
        msg += HIR "\t\t\t����֪˭��"HIW"���ģ�\n" NOR;        
        msg += HIM "\n��ѩ��������÷ʢ�������÷��������Ʈ�㡣���÷����Ʈ�䣬���㺮��Ϯ��$n��\n" NOR;
        
        if (me->query_skill("force") > random(target->query_skill("force")))
        {
                msg += HIY "$n��÷�������ı������ˡ�\n" NOR;
                 damage=200+damage;
                target->receive_damage("qi",damage);
                target->receive_wound("qi",damage/2);
                message_combatd(msg, me, target, "");
                COMBAT_D->report_status(target);      
                me->add("neili", -50);
        }
        else
        {
                msg += HIY "$n��Ȼ����˼��Ķ������仨�꣡\n"NOR;
                message_combatd(msg, me, target, "");
        }

                        
if ((int)me->query_skill("aohan-liujue",1)> 380)
{                         
      msg = HIW
 "\n$N��Ӱ�����ĸ���������ǰ��ֻ��$N����������Ө��͸��"RED"ѩ����"NOR"\n"HIW"Χ��������Χ�����⽣Ӱ��������ʱ�����������͵�ѩ��֮�У���һ������\n�����"HIG"����ѩ"NOR"\n"HIM"����ɽˮ�䣬���������!\n"NOR;

        ap = me->query_skill("aohan-liujue", 1);
        ap = ( ap * ap * ap / (3 * 350) );
        ap = ap*250 + (int)me->query("combat_exp");
        dp = target->query_skill("parry");
        dp = ( dp * dp * dp / (7 * 400) );
        dp = dp*250 + target->query("combat_exp");
        //if( random((ap + dp)/800+1) <  dp/2200 ) 
        if( random((ap + dp)/600+1) <  dp/2500 ) 
        {
                msg += HIY "��$n��û�б���Ѥ����ѩ��������,��Ȼ������ѩ������Ļþ��У�\n\n"NOR;
                message_combatd(msg, me, target, "");
        } 
        else 
        {
                damage = 300+(int)me->query_skill("aohan-liujue",1)*5 ;
                msg += HIR "\n$n��ʱ����������һ��ľ���֮�У���������б�ѩ��������ˣ�\n\n" NOR;
                damage +=random(10);
                target->receive_damage("jing", damage/3);
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/2);
                message_combatd(msg, me, target, "");
                COMBAT_D->report_status(target);
        }
}           

if ((int)me->query_skill("aohan-liujue",1)> 680)
{
       msg = HIC "\n$N���˼����������һ�ӣ���Χ��ʱ��������ޱȣ�
$N�����񹦣�һ�Ŵ̹ǵĺ�����$nֱ�ƶ�����\n" NOR;
        
        
        if( random((int)me->query("max_neili")*4) > (int)target->query("max_neili"))
        {
                
                msg += HIW"\n$n��$N���������ź������˸����ţ�\n\n" NOR;
                
                target->start_busy(3); 
                
                msg +=  HIC ">>$N����"+ weapon->name() + HIC"����һ��������Ҳ�����ڿն���
�漴һʽ"HIW"������ն��"HIC"�ó�����������$nӭ��������\n\n"NOR;
                                
                if (me->query_skill("parry") > random(target->query_skill("parry")))
                {
                        msg += HIC"$n��û������������У�һ��Ѫ���Ѿ�������һ�㣬���������\n"NOR;
                        damage = (int)me->query_skill("parry", 1);
                        damage = damage + random(damage);
                        def=(int)target->query_temp("apply/armor");
                        //damage -=damage*def/3000;
                        damage -=damage*def/6000;
                        damage =  damage+100;
                        damage = damage + me->query("jiali");
                        if (damage > 6000) damage=6000;
                        target->receive_damage("qi", damage);
                        target->receive_wound("qi", damage/2);
                        message_combatd(msg, me, target, "");
                        COMBAT_D->report_status(target);
                }
                else 
                {
                        msg += HIC"$næһ�˹�������һ���������л��������е�������\n"NOR;
                        message_combatd(msg, me, target, "");
                } 
                
                msg =   HIC">>$N����"+ weapon->name() +""HIW"--����������"HIC"$NҲ�ɾ�ת����
һ���㼱��磬��̤���ţ��������У�ʽʽ��$n���벻���ķ�λ���������\n" NOR;                
                       
                if (random(me->query("combat_exp")) > (target->query("combat_exp"))/4)
                {
                        msg += HIC"$nһ����æ���ң���֪�����ȥ�м��⾲��ˮ�������ĵ�����\n"NOR;
                        damage = damage + random(200)+200;
                        if(damage<1)damage = 1;
                        if (damage > 6000) damage=6000;
                        target->receive_damage("qi",damage*3/2);
                        target->receive_wound("qi", damage);
                        message_combatd(msg, me, target, "");
                        COMBAT_D->report_status(target);
                }
                else
                {
                        msg += HIC"$nȴ�ľ���ˮ�����в��У��߽���$N�������Ĺ��ơ�\n"NOR;
                        message_combatd(msg, me, target, "");
                        
                }

                me->add("neili", -50);

        }
        else 
        {
                msg = WHT"\n$n���Ѿ�����$N����ͼ������һ�����ѱܿ������ź�����\n" NOR;
                message_combatd(msg, me ,target, "");
                me->add("neili", -50);
        }

}
                     
me->start_busy(3);                        

        return 1;
}



