#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int damage,extra, mypot, tapot,attp, defp;
        string msg,str; 
               int def,level, ap, dp;

        
        weapon = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С���ѩ��������\n");

        if(!me->is_fighting())
                return notify_fail("����ѩ������ֻ����ս����ʹ�ã�\n");
        if((int)me->query("max_neili") < 1500 )
                return notify_fail("�������������\n");
        if((int)me->query("neili") < 1500 )
                return notify_fail("����������㣡\n");
        if((int)me->query("jing") < 1500 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");
        if((int)me->query_skill("huanhe-dao", 1) < 100)
                return notify_fail("����Ӻյ����𻹲�����ʹ����һ�л������ѣ�\n");
        if((int)me->query_skill("bawang-qiang",1)+100 < (int)me->query_skill("huanhe-dao",1))
                return notify_fail("������Ҫ�������ǹ�����⾳������\n"); 
     if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��ѩ����ֻ����ս����ʹ�á�\n");

    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
        return notify_fail(RED"��ʲô��Ц���������ԣ�\n"NOR);


        if ( !wizardp(me) && me->query_skill_mapped("force") != "taixuan-gong")
                return notify_fail("��ʹ��̫����!\n");
        if((int)me->query_skill("taixuan-gong",1) < 100)
                return notify_fail("���̫����������������\n"); 


        if ((int)me->query_skill("literate", 1)> 5 )
                return notify_fail("������Ӻյ����֮����һʱ��������ᡣ\n");

        message_combatd(HIW"\n$N������������һת�����ܶ�ʱ�������ߣ������к������ˣ�$nֻ�������ǵĵֿ���\n"NOR,me,target,"");
        me->set_temp("noauto",1);
        target->start_busy(1);
        damage=100+random(((int)me->query_skill("blade")))+(int)me->query_skill("blade");

        message_combatd(HIW"\n$N�ٺ�һ����Ц����Ȼ����ѩ��֮�С�$n�󼱣�������Ѱ$N����Ȼ����һ��������\n"NOR,me,target,"");
        message_combatd(HIW"\n�����Ϯ����������\n"NOR,me,target,"");
        
        extra=(int)me->query_skill("huanhe-dao", 1)/5;
        level=(int)me->query_skill("huanhe-dao", 1);
        if (extra> 200) extra=200;
        me->add_temp("apply/attack", extra);
        me->add_temp("apply/damage", 900); 
                
        message_combatd(HIY"Ʈѩʽ---$N����$n"HIY"˳��ѩ��ʹ��һ�У�\n"NOR,me,weapon,"");
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"));
        message_combatd(HIC"��ѩʽ---$N����$n"HIC"�����˷�׷Ӱ���ã�\n"NOR,me,weapon,"");
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"));
        message_combatd(HIB"��ѩʽ---$N����$n"HIB"�������浶��������\n"NOR,me,weapon,"");
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"));
        
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -900);
                
        if(random(me->query("combat_exp",1))>random(target->query("combat_exp",1))/4)
        {
                message_combatd(HIY"\n����,һֻ��ɫ������ԶԶ������$N��$n�������ˣ�\n"NOR,me,target,"");
                message_combatd(HIY"\nͻȻ�������ó��һ��,��ʱ��������\n"NOR,me,target,"");
                if(random(me->query("combat_exp",1))>target->query("combat_exp",1)/4)
                {
                        message_combatd(HIR"\n$N��������ʧ,��æ����һ�У�\n"NOR,me,target,"");
                        target->receive_damage("qi",damage*2); 
                        target->receive_damage("jing",damage*2); 
                        message_combatd(HIR"\n����������ʯ�������,��$n�ҵñ������ˣ�\n"NOR,me,target,"");
                        target->receive_wound("qi",damage);
                        target->receive_wound("jing",damage);
                        COMBAT_D->report_status(target);
                        COMBAT_D->report_sen_status(target);
                 }  
                else 
                if(random(me->query("combat_exp",1))>target->query("combat_exp",1)/2)
                {
                        message_combatd(HIR"\n����������ʯ�������,��$n�ҵñ������ˣ�\n"NOR,me,target,"");
                        target->receive_wound("qi",damage);
                        COMBAT_D->report_status(target);
                }
                else  
                {
                        message_combatd(HIR"\n����������ʯ�������,��$N��$n�ҵñ������ˣ�\n"NOR,me,target,""); 
                        target->receive_wound("qi",damage);
                        target->receive_wound("jing",damage);
                        COMBAT_D->report_status(target);
                        me->receive_damage("qi",damage/10);
                        COMBAT_D->report_status(me);
                }        
        }
        me->delete_temp("noauto");
        me->receive_damage("jing", 100);
        me->add("neili", -100);
if (level>300)
{
   msg = HIC "\n$N���˼����������һ�ӣ���Χ��ʱ��������ޱȣ�
$N������Ѫ�񹦣�һ�Ŵ̹ǵĺ�����$nֱ�ƶ�����\n" NOR;
        
        
        if( random((int)me->query("max_neili")*4) > (int)target->query("max_neili") || random(3)==0)
        {
                
                msg += HIW"\n$n��$N���������ź������˸����ţ�\n\n" NOR;
                
                target->start_busy(2+random(3)); 
                
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
                        damage = damage + 100;
   						 if (damage > 5000) damage=5000;
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
                        damage = damage + random(200);
                        if (damage > 5000) damage=5000;
                        if(damage<1)damage = 1;
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
                me->start_busy(2);
                me->add("neili", -50);
               
        }       
}               

if (level>600)
{
  damage = (int)me->query_skill("huanhe-dao", 1) + (int)me->query_skill("blade", 1);
        damage = damage/2 + random(damage/2);
  if (damage > 5000) damage=5000;
  msg = MAG "\n\t�����"HIW"��ѩ"HIG"Ϊ"HIB"��"HIW"��"HIG"Ϊ"HIR"�ǣ�"HIY"����"HIW"��ѩ"HIM"��"HIC"��գ�"NOR""MAG"�����\n" NOR;                      
                     
        me->add("jing", -50);
        me->add("qi", -50);
        
        msg += WHT "\n\t���������·�˪������\n" NOR;
        msg += WHT "\t\t\tǧ���ѩ˭��Թ��\n" NOR;
        msg += HIC "\n�������գ�������$N����һ������ʱ��ѩ�׷ɣ�Թ�����죡\n" NOR;
        
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/5 || random(3)==0 ) 
        {
                msg += HIY "$n��֪��������Թ����Χ�ˣ�\n" NOR;
                target->receive_damage("qi",damage);
                target->receive_wound("qi",damage);
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
        
        mypot=(int)me->query_skill("huanhe-dao");
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
                target->receive_wound("qi", damage);
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
                target->receive_damage("qi",damage);
                target->receive_wound("qi",damage);

                message_combatd(msg, me, target, "");
                COMBAT_D->report_status(target);      
                me->add("neili", -50);
        }
        else
        {
                msg += HIY "$n��Ȼ����˼��Ķ������仨�꣡\n"NOR;
                message_combatd(msg, me, target, "");
        }
        
}               

if (level > 1000)
{
  msg = HIW
 "\n$N��Ӱ�����ĸ���������ǰ��ֻ��$N����������Ө��͸��"RED"ѩ����"NOR"\n"HIW"Χ��������Χ�����⽣Ӱ��������ʱ�����������͵�ѩ��֮�У���һ������\n�����"HIG"����ѩ"NOR"\n"HIM"����ɽˮ�䣬���������!\n"NOR;

        ap = me->query_skill("huanhe-dao", 1);
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
                damage = 500+(int)me->query_skill("huanhe-dao",1)  +
        (int)me->query("jing") / 200 + random((int)me->query("jing") / 150 ) +
        (int)me->query("qi") / 200 + random((int)me->query("qi") / 150 );
                if (damage > 15000) damage=15000;
                
                msg += HIR "\n$n��ʱ����������һ��ľ���֮�У���������б�ѩ��������ˣ�\n\n" NOR;
                damage +=random(10);
                target->receive_damage("jing", damage/2);
                target->receive_damage("qi",damage);
                target->receive_wound("qi", damage);
                me->improve_skill("huanhe-dao", 1, 1);
                message_combatd(msg, me, target, "");
                COMBAT_D->report_status(target);
        }
}
        me->start_busy(3);
        
        return 1;
}
