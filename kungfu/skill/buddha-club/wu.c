
#include <ansi.h>
inherit F_SSERVER;

#include "/kungfu/skill/eff_msg.h";

string get_name(string str)
{
        str="������";
        return str;
}

string get_help(string str)                
{
        str="ָ�������������\n"
        +"�������Ͷ������100������������100���������ڹ�100���������Ṧ120���������1200"
        +"��perform�����Ͷ�������ļ��𻮷�Ϊ�����׶Σ�100��һ����220��������280������";        
        return str;
}

int def;

int perform(object me, object target)
{       
        object weapon1;
        string msg;
        int damage, p, time;
        object weapon;
        
        if( !target ) target = offensive_target(me);
        
        if( !target 
        || !target->is_character()
        || !me->is_fighting(target) 
        || !living(target) )
                return notify_fail("�������衹ֻ����ս����ʹ�á�\n");

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���ž�ѧֻ�ܶ�ս���еĶ���ʹ�á�\n");
                
    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "club")
        return notify_fail(RED"��ʲô��Ц���������ԣ�\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "zhanzhuang-gong")
                return notify_fail("��ʹ����ƽ����վ׮��!\n");


        if((int)me->query_skill("yijinjing", 1) < 150)
                return notify_fail("����׽���𻹲�����ʹ����һ�л������ѣ�\n");
                
        if( (int)me->query_skill("club", 1) < 100 ||
           (int)me->query_skill("buddha-club", 1) < 100 )
                return notify_fail("��Ĺ�����������죬����ʹ�á������衹��\n");
                
        if((int)me->query_skill("dodge", 1) <120)
                return notify_fail("�������ڵ��Ṧ��Ϊ��Ρ������衹��\n");
                
        if((int)me->query_skill("force", 1) <100)
                return notify_fail("�������ڵ��ڹ���Ϊ��ʹ�����������衹��\n");
                
        if( (int)me->query("max_neili") < 1200 )
                return notify_fail("�������ڵ��ڹ���Ϊ��ʹ�����������衹��\n");
                
        if( (int)me->query("neili") < 600 )
                return notify_fail("�������������\n");
                
        msg = HIY "\n$Nʹ������ɽ�����������衹������Ȼ�ӿ죡\n" NOR;
        if (random(me->query("combat_exp")) > random(target->query("combat_exp")/3))
        {
                me->start_busy(2);
                target->start_busy(1);
                msg += YEL "\n$N��Ȼ��һ�������հ����裬��$n�����������"NOR;
                if ((int)me->query_skill("force", 1)> random((int)me->query_skill("force", 1)/4) || random(3)==0)
                {
                        msg += HIC "\n����$n���һ����������������,���$nֻ��ס��ʼ���У����޷���ά�����ȵ����衣\n" NOR;
                        damage = (int)me->query_skill("buddha-club", 1);
                        damage = damage + random(damage)+300;
                        //def=(int)target->query_temp("apply/armor_vs_force");
                        //damage -=damage*def/3000;
                        target->receive_damage("qi", damage,me);
                        target->receive_wound("qi", damage/2,me);
                        me->add("neili", -(damage/10));
                        p = (int)target->query("qi")*100/(int)target->query("max_qi");
                        msg += damage_msg(damage, "����");
                        msg += "( $n"+eff_status_msg(p)+" )\n";
                        message_vision(msg, me, target);
                        target->set_temp("last_damage_from", me);
                        if(me->query_skill("club", 1) > 219)
                        {
                                remove_call_out("perform2");
                                call_out("perform2", 0, me, target);    
                        }
                } 
                else 
                {
                        msg += HIC "\n��ʱ�ƺ����ֲ��أ����䲨��״�Ĺ�Ӱ���˻�ǰ�ˣ�һ�˸߹�һ�ˣ����಻����\n"NOR;
                        message_vision(msg, me, target);
                        for (p=1;p<3+random(4);p++)
                        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
                        if(random(me->query_skill("buddha-club", 1))> 219)
                        {
                                remove_call_out("perform2");
                                call_out("perform2", 0, me, target);    
                        }
                }
        } 
        else 
        {       
                me->start_busy(2);
                me->add("neili", -100);                
                msg += HIG"����$p����һ�����㿪�˶��ֵĹ�����\n"NOR;
                if(me->query_skill("buddha-club",1)>219)
                {
                        remove_call_out("perform2");
                        call_out("perform2", 0, me, target);    
                }
                message_vision(msg, me, target);
        }
        return 1;
}



int perform2(object me, object target)
{
        int damage, p,skill;
        object weapon1;
        string msg,weapon,force_skill,force_skill_name;
        if(!target||!living(target)) return notify_fail("�����Ѿ�������ս���ˡ�\n");
        weapon = me->query_temp("weapon");  
        if( !(weapon1 = me->query_temp("weapon"))
        ||      (string)weapon1->query("skill_type") != "club" )
                return notify_fail("����Ϊ����˭��û��Ҳ�������裡\n");


        if( !target 
        || !target->is_character()
        || !me->is_fighting(target) 
        || !living(target) )
                return notify_fail("�������衹����û������ѽ��\n");
        if( (int)me->query("neili", 1) < 300 )
                return notify_fail("���Ҫ�ٳ��ڶ�����ȴ�����Լ������������ˣ�\n");     
        if (random(5)>2)
                msg = HIC"\n����$N���ϱ���,ͻȻһ������,���һ��,ļ���������,$n��ǰһ��!!\n"NOR;
        else
                msg = HIG"\n����$N���ϱ���,ͻȻ��Хһ��,�չ���ɨ,���Ƹ���,$n�����Ż����ֽ�!!\n"NOR;
        message_vision(msg, me, target); 
        if (random(me->query("combat_exp")) > target->query("combat_exp")/4  || random(3)==0)
        {
                //msg = CYN "$n����֮�£�"NOR+HIR+force_skill_name+NOR+CYN"��ʱ�����ٳ���$n�����޴��мܣ�\n" NOR;
                msg = CYN "$n����֮�£���ʱ�����ٳ���$n�����޴��мܣ�\n" NOR;
                 //message_vision(msg, me, target); 
                me->start_busy(2);
                target->start_busy(2);
                damage = (int)me->query_skill("buddha-club", 1);
                damage = damage+(int)me->query_skill("force", 1);
                damage = damage +400;
                //def=(int)target->query_temp("apply/armor_vs_force");
                //damage -=damage*def/3000;
                target->receive_damage("qi", damage,me);
                target->receive_wound("qi", damage/2,me);
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg += damage_msg(damage, "����");
                msg += "( $n"+eff_status_msg(p)+" )\n";
                message_vision(msg, me, target);
                target->set_temp("last_damage_from", me);
                if(me->query_skill("buddha-club", 1) > 279)
                {
                        remove_call_out("perform3");
                        call_out("perform3", 0, me, target);    
                }
        } 
        else 
        {       
                me->start_busy(2);
//                me->add("neili", -200);                
                msg = WHT"����$p�ϵ�֮��,�������У�����$N�������ˡ�\n"NOR;
                if(me->query_skill("buddha-club", 1) > 279
                && me->query_skill("club", 1) > 279)
                {
                        remove_call_out("perform3");
                        call_out("perform3", 0, me, target);    
                }
        }
        message_vision(msg, me, target);
        return 1;
}


int perform3(object me, object target)
{
        int damage, p,skill;
        object weapon1;
        string msg,weapon,force_skill,force_skill_name,*limbs;
        if(!target||!living(target)) return notify_fail("�����Ѿ�������ս���ˡ�\n");
        weapon = me->query_temp("weapon");  
        if( !(weapon1 = me->query_temp("weapon"))
             ||      (string)weapon1->query("skill_type") != "club" )
                return notify_fail("����Ϊ����˭��û��Ҳ�������裡\n"); 
        if(!living(target)) 
                return notify_fail("�����Ѿ�������ս���ˡ�\n");
        if( !target 
        || !target->is_character()
        || !me->is_fighting(target) 
        || !living(target) )
                return notify_fail("����������û������ѽ��\n");

        if( (int)me->query("neili", 1) < 800 )
                return notify_fail("���Ҫ�ٳ����Ļ���ȴ�����Լ������������ˣ�\n");     
        if (random(5)>2)
        {
                msg = HIC"\n$Nһ��������������Ȼ���ַɳ����������㰿������ƿ�����$n����磡\n"NOR;
                msg += HIC "$n���һ��������$N���������ϣ�˫�����õ��ģ���������֮��!\n" NOR;
        }
        else 
                msg = HIG"\n$N��Хһ����һʽ����غ��衹���ڿշ���ȫ��ų���������Ӱ��������ʣ�\n"NOR;
        message_vision(msg, me, target); 
        if (random(me->query("combat_exp")) > random(target->query("combat_exp")/8)  || random(3)==0)
        {
                //msg = CYN "$n�������Ѿ�����������"NOR+HIR+force_skill_name+NOR+CYN",$N�������һ��\n" NOR;
                msg = CYN "$n�������Ѿ��������м�,$N�������һ��\n" NOR;
                me->start_busy(2);
                target->start_busy(1);
                damage = (int)me->query_skill("unarmed", 1);
                damage = damage+(int)me->query_skill("force", 1)+500;
                
                //damage = damage*(1+random(3))/2+random(damage);
                def=(int)target->query_temp("apply/armor_vs_force");
 //               damage -=damage*def/3000;
                target->receive_damage("qi", damage,me);
                target->receive_wound("qi", damage,me);
                me->add("neili", -100);
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg += damage_msg(damage, "����");
                msg += "( $n"+eff_status_msg(p)+" )\n";
                limbs = target->query("limbs");
                msg = replace_string(msg, "$l", limbs[random(sizeof(limbs))]);
                msg = replace_string(msg, "$w", weapon->name());    
                message_vision(msg, me, target);
                target->set_temp("last_damage_from", me);
                me->start_busy(2);

                        msg += HIC "\n��ʱ�ƺ����ֲ��أ����䲨��״�Ĺ�Ӱ���˻�ǰ�ˣ�һ�˸߹�һ�ˣ����಻����\n"NOR;
                        message_vision(msg, me, target);
                                        me->add_temp("apply/attack",100);
                me->add_temp("apply/damage",1200);  
                        for (p=1;p<3+random(4);p++)
                        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
                                        me->add_temp("apply/attack",-100);
                me->add_temp("apply/damage",-1200);  

        } 
        else 
        {       
                        msg += HIC "\n��ʱ�ƺ����ֲ��أ����䲨��״�Ĺ�Ӱ���˻�ǰ�ˣ�һ�˸߹�һ�ˣ����಻����\n"NOR;
                        message_vision(msg, me, target);
                                                              me->add_temp("apply/attack",100);
                me->add_temp("apply/damage",1200);  
                        for (p=1;p<3+random(4);p++)
                        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
                                        me->add_temp("apply/attack",-100);
                me->add_temp("apply/damage",-1200);  
                me->start_busy(2);

                msg = HIC"����$pһ������,������$N�����Ľ�����\n"NOR;
                message_vision(msg, me, target);
        }

        return 1;
}


