// Ӧdxh���� �Ķ������ʺ��˺�

#include <ansi.h>
inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";

int def;
int perform(object me, object target)
{       
        string msg;
object weapon;
        int damage, p,time;
        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character()
        || !me->is_fighting(target) || !living(target) )
                return notify_fail("���׶����졹ֻ����ս����ʹ�á�\n");
       
        if( (int)me->query_skill("dragonfight", 1) < 100 
        ||  (int)me->query_skill("unarmed", 1) < 100 )
                return notify_fail("���еĹ��򻹲�����죬����ʹ�á��׶����졹��\n");

 if( !target ) target = offensive_target(me);
        
       
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��\n");

        if( !wizardp(me) && me->query_temp("weapon") )
                return notify_fail("�������ֲ���ʹ�ñ��ž�ѧ!\n");

    if( (string)me->query_skill_mapped("force")!= "jinghai-force")
     return notify_fail("���뾸���񹦲��С�\n");

      if( (int)me->query_skill("jinghai-force", 1) < 60 )
                return notify_fail("��ľ����񹦻���Щ���\n");

        if(me->query_skill("force", 1) <100)
                return notify_fail("�������ڵ��ڹ���Ϊ��ʹ�������׶����졹��\n");        
        if (me->query_skill_mapped("unarmed") != "dragonfight")
                return notify_fail("�������޷�ʹ�á��׶����졹���й�����\n");                                                                                 
        if( (int)me->query("max_neili") < 1200 )
                return notify_fail("���������Ϊ̫��������ʹ�á��׶����졹��\n");
        if( (int)me->query("neili") < 600 )
                return notify_fail("�������������\n");
        msg = RED "\n ͻȻ$N���һ��:���׶���,��ɫ৵ı��ͨ��,�뷢�Է�,�������³���ɱ��,\n" NOR;
        message_vision(msg, me, target); 
        msg = YEL "\n        ���ˡ���һ����һ����ջ���$n���ؿڣ�\n" NOR;
        //if (random(me->query("combat_exp")) > random((target->query("combat_exp")/2))
        if (random(me->query("combat_exp")) > random((target->query("combat_exp")/3)) || random(3)==0)
        {
                me->start_busy(2);
                target->start_busy(2);
                damage = (int)me->query_skill("dragonfight", 1);
                damage = damage + random(damage/2);
                def=(int)target->query_temp("apply/armor");
                //damage -=damage*def/3000;
                target->receive_damage("qi", damage,me);
                target->receive_wound("qi", damage,me);               
                me->add("neili", -(damage/4));
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg += damage_msg(damage, "����");
                msg += "( $n"+eff_status_msg(p)+" )\n";
                target->set_temp("last_damage_from", me);
                if(me->query_skill("dragonfight", 1) > 119)
                        call_out("perform2", 0, me, target);    
        } 
        else 
        {       
                //me->start_busy(3);
                me->start_busy(2);
                me->add("neili", -200);                
                msg += HIY"����$p����һ�����㿪�˶��ֵĹ�����\n"NOR;
        }
        message_vision(msg, me, target);
        return 1;
}

int perform2(object me, object target)
{
        int damage, p,skill;
        string msg,weapon;
        weapon = me->query_temp("weapon");  
        
        if (!target || !me ) return notify_fail("�����Ѿ�������ս���ˡ�\n");
        if(!living(target)) 
                return notify_fail("�����Ѿ�������ս���ˡ�\n");
        if( (int)me->query("neili", 1) < 300 )
                return notify_fail("���Ҫ�ٳ��ڶ�����ȴ�����Լ������������ˣ�\n");     
        msg = MAG "\nֻ��$N���۹������Է��裬������շ�������һ����𡸾��졹��\n" NOR;
        message_vision(msg, me, target); 
        msg = CYN "\n       �������Ļӳ��Ÿ���Ȧ���Ӹ����£�ֱ��$n������\n" NOR;
        //me->start_busy(1);
        //target->start_busy(2);
        damage = (int)me->query_skill("dragonfight", 1);
        damage = damage+(int)me->query_skill("unarmed", 1);
        damage = damage+(int)me->query_skill("jinghai-force", 1);
        damage = (damage + random(damage))/2;
                
        def=(int)target->query_temp("apply/armor");
        //damage -=damage*def/4000;
        target->receive_damage("qi", damage,me);
        target->receive_wound("qi", damage,me);
        me->add("neili", -random(damage/10));
        p = (int)target->query("qi")*100/(int)target->query("max_qi");
        msg += damage_msg(damage, "����");
        msg += "( $n"+eff_status_msg(p)+" )\n";
        target->set_temp("last_damage_from", me);
        message_vision(msg, me, target);
        return 1;
}

