
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int damage,extra, attp, defp;
        string msg,str; 
        weapon = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С���ѩ��������\n");
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
                
		
        if(!me->is_fighting())
                return notify_fail("����ѩ������ֻ����ս����ʹ�ã�\n");
        if((int)me->query("max_neili") < 500 )
                return notify_fail("�������������\n");
        if((int)me->query("neili") < 500 )
                return notify_fail("����������㣡\n");
        if((int)me->query("jing") < 500 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");

        if((int)me->query_skill("aohan-liujue", 1) < 100)
                return notify_fail("������ŵ������𻹲�����ʹ����һ�л������ѣ�\n");

        message_combatd(HIW"\n$N������������һת�����ܶ�ʱ�������ߣ������к������ˣ�$nֻ�������ǵĵֿ���\n"NOR,me,target,"");
        me->set_temp("noauto",1);
        target->start_busy(1);
        damage=100+random(((int)me->query_skill("blade",1)))+(int)me->query_skill("aohan-liujue",1);

        message_combatd(HIW"\n$N�ٺ�һ����Ц����Ȼ����ѩ��֮�С�$n�󼱣�������Ѱ$N����Ȼ����һ��������\n"NOR,me,target,"");
        message_combatd(HIW"\n�����Ϯ����������\n"NOR,me,target,"");
        
        extra=(int)me->query_skill("aohan-liujue", 1)/2;
        if (extra> 200) extra=200;
        me->add_temp("apply/attack", extra);
        me->add_temp("apply/damage", extra); 
                
        msg=HIY"Ʈѩʽ---$N����$n"HIY"˳��ѩ��ʹ��һ�У�\n"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg=HIC"��ѩʽ---$N����$n"HIC"�����˷�׷Ӱ���ã�\n"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg=HIB"��ѩʽ---$N����$n"HIB"�������浶��������\n"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -extra);
                
        if(random(me->query("combat_exp"))>random(target->query("combat_exp"))/4)
        {
                message_combatd(HIY"\n����,һֻ��ɫ������ԶԶ������$N��$n�������ˣ�\n"NOR,me,target,"");
                message_combatd(HIY"\nͻȻ�������ó��һ��,��ʱ��������\n"NOR,me,target,"");
                if(random(me->query("jiali"))>target->query("jiali")/4)
                {
                        message_combatd(HIR"\n$N��������ʧ,��æ����һ�У�\n"NOR,me,target,"");
                        target->receive_damage("qi",damage*2); 
                        target->receive_damage("jing",damage/2); 
                        message_combatd(HIR"\n����������ʯ�������,��$n�ҵñ������ˣ�\n"NOR,me,target,"");
                        target->receive_wound("qi",damage);
                        target->receive_wound("jing",damage/2);
                        COMBAT_D->report_status(target);

                }  
                else 
                if(random(me->query("jiali"))>target->query("jiali")/2)
                {
                        message_combatd(HIR"\n����������ʯ�������,��$n�ҵñ������ˣ�\n"NOR,me,target,"");
                        target->receive_wound("qi",damage);
                        COMBAT_D->report_status(target);
                }
                else  
                {
                        message_combatd(HIR"\n����������ʯ�������,��$N��$n�ҵñ������ˣ�\n"NOR,me,target,""); 
                        target->receive_wound("qi",damage);
                        target->receive_wound("jing",damage/2);
                        COMBAT_D->report_status(target);
                        me->receive_damage("qi",damage/10);
                        COMBAT_D->report_status(me);
                }        
        }
        me->delete_temp("noauto");
        //me->receive_damage("jing", 100);
        me->add("neili", -100);

if ((int)me->query_skill("aohan-liujue",1)> 680)
{
       message_combatd( HIR "$N�����ڵ���Ĭ��������ֻ�������һ������Ȼ��������ҫ��$N����"+ weapon->name() + HIR"����Ϊ����\n"
         + "�أ���������ư���$n���������\n"NOR, me, target, "");

        attp = me->query_skill("panshi-shengong",1) + me->query_skill("aohan-liujue",1);
        defp = target->query_skill("dodge");

//      if( random( attp ) > random( defp ) )
        if(  attp  > random( defp ) )
        {
                damage =500+me->query_skill("aohan-liujue",1) + me->query_skill("blade",1)+ (int)me->query_skill("panshi-shengong", 1)*2;
                damage = damage - random( target->query_skill("dodge")/3 );
if (damage > 6000) damage=6000;
                target->receive_wound("jing", random( damage ));
                target->receive_damage("qi", 20 + random(damage)+damage);
                target->receive_wound("qi", 20 + damage);
                me->start_busy(3);
                target->start_busy(3 + random(4));
        }
        else 
        {
                message_combatd( HIY "����$p�ζ����Σ�Ѹ�ٵ�������������м��\n" NOR, me, target, "" );
                me->start_busy(2);
        }
}
      
        me->start_busy(4);
        
        return 1;
}


