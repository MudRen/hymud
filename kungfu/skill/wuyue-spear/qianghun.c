//qianghun.c
//����ǹ��
//Created by wuyou@sk_sjsh
//2003-8-12
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

void npc_attack( object invoker, object target, string npc, object where );



int perform(object me, object target)
{
        string msg;
        object weapon, where; 
        int damage, ap, dp, i,lmt;
        int j,k;
        weapon = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail(CYN"��Ҫ��˭ʩչ������ǹ�꡹��\n"NOR);

        if(!me->is_fighting()) 
                return notify_fail(CYN"������ǹ�꡹ֻ����ս����ʹ�ã�\n"NOR); 
        
       if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("ֻ����ս����ʹ�á�\n");

 if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "club")
        return notify_fail(RED"��ʲô��Ц���������ԣ�\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "hanbing-zhenqi")
                return notify_fail("��ʹ�ú�������!\n");

        if((int)me->query_skill("hanbing-zhenqi",1) < 200)
                return notify_fail("��ĺ�������������������\n"); 

        if( (int)me->query("neili") < 1000 )
                return notify_fail(CYN"����������㣬�ٻ�����������ǹ�꡹��\n"NOR);

        if( me->query("max_neili") < 3000 )
                return notify_fail("���������Ϊ��ǳ���������á�����ǹ�꡹��\n"NOR);
                

        if( (int)me->query("qi") < 200 || (int)me->query("jing") < 200  )
                return notify_fail(CYN"������̫�����ˣ��޷�ʩչ������ǹ�꡹��\n"NOR);

        if( (int)me->query_skill("wuyue-spear", 1) <400 )
                return notify_fail(CYN"���������ǹ�������죬�޷�ʹ�����С�����ǹ�꡹��\n"NOR);
                
        if( (int)me->query_skill("club", 1) <400 )
                return notify_fail(CYN"��Ļ���ǹ���������죬�޷�ʹ�����С�����ǹ�꡹��\n"NOR);           

                
        msg = HIY "\n$N�־�"+ weapon->query("name")+ HIY"ֱָ���죬���쳤Х��"HIW"������ɽ�����ҳ�ħ����\n"NOR;            
        msg += HIY "\nХ���հգ�����һ������ֱ��ǹ�⣬�û���һ��Ѥ�õĹ�â��\n\n" NOR;
        msg += HIR "          ������                          ������\n"NOR;
        msg += HIR "          ��"HIW"�v"HIR"�� ������������������������ ��"HIW"��"HIR"��\n"NOR;
        msg += HIR "          ��"HIW"�M"HIR"�� ��"HIW"��"HIR"����"HIW"�["HIR"����"HIW"��"HIR"����"HIW"��"HIR"�� ��"HIW"��"HIR"��\n"NOR;
        msg += HIR "          ��"HIW"��"HIR"�� ������������������������ ��"HIW"�o"HIR"��\n"NOR;   
        msg += HIR "          ��"HIW"�["HIR"��                          ��"HIW"��"HIR"��\n"NOR;
        msg += HIR "          ������                          ������ \n"NOR;
        
        ap = me->query_skill("wuyue-spear", 1);
        ap = ( ap * ap * ap / (4 * 400) );
        ap = ap*250 + (int)me->query("combat_exp");
        dp = target->query_skill("parry");
        dp = ( dp * dp * dp / (4 * 300) );
        dp = dp*250 + target->query("combat_exp");      
        
        if( random((ap + dp)/200) >  dp/1000 )
        {
                msg += HIY "\n����һ�������⽫$n���֣�$n�������ܶ�����\n"NOR;
                msg += HIY "$N���е�"+ weapon->query("name")+ HIY"����һ�����磬����$n�����壡\n"NOR;
                
                damage = 300+(int)me->query_skill("club",1) / 2 + (int)me->query_skill("wuyue-spear",1) 
                + random((int)me->query_skill("hanbing-zhenqi",1) / 2) + random((int)me->query_skill("force",1) / 2)
                + (int)me->query("str") + me->query("jaili");
                
                //if(!target->is_busy())
                //        target->start_busy(2);
                        
                target->receive_damage("qi", damage,me);
                target->receive_wound("qi", damage,me);   
                target->receive_damage("jing", damage/2,me);
                target->receive_wound("jing", damage/3,me); 
                message_vision(msg, me, target);
                COMBAT_D->report_status(target);                                
                
                me->add("neili", -100);
                me->receive_damage("qi", 100);                
        }
       msg = HIY  "$Nǹ�����࣬�·��紪�ޱʱ�ī��ֽ�����е�\n"+ weapon->name()+  "���籩������$n������\n\n" NOR;
        message_vision(msg,me,target);
        lmt = random(4)+3;
        		       me->add_temp("apply/attack", 150);    
        me->add_temp("apply/damage", 1500);
        for(i=1;i<=lmt;i++)
        {
        msg =  HIC "$N���һ�����ӵ�"+chinese_number(i)+"ǹ��\n" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        }
		       me->add_temp("apply/attack", -150);    
        me->add_temp("apply/damage", -1500);
 
 
                if (random(2)==1 && (int)me->query_skill("wuyue-spear", 1)>= 380)
                {
                        msg += HIY "\n˲�䣬��������������$n����ǰ����$n����������\n"NOR;
                        message_vision(msg, me, target); 
                        where=environment(target);

                  call_out("npc_attack", 1, me, target, "/kungfu/class/songshan/zuo", where);
                  call_out("npc_attack", 1, me, target, "/kungfu/class/henshan/moda", where);
                  call_out("npc_attack", 1, me, target, "/kungfu/class/hengshan/xian", where);
                  call_out("npc_attack", 1, me, target, "/kungfu/class/taishan/tianmen", where);
                  call_out("npc_attack", 1, me, target, "/kungfu/class/huashan/yue-buqun", where);                                                                        
                        me->add("neili", -100);
                        //me->receive_damage("jing", 100);  
                }
                else
                {
                        msg += HIY "\n$n��δ�����ٻ���"HIR"������ǹ�꡹"HIY",����$N����������$N���ò���ǹ��ӭ��\n"NOR;
                        message_vision(msg, me, target); 
                        me->receive_damage("qi", 20);  
                        me->receive_damage("jing", 20); 
                        me->add("neili", -20);
                }
     
     if ((int)me->query_skill("wuyue-spear", 1)>= 680)
     	{
                  
        i=(int)me->query("combat_exp");
        j=(int)target->query("combat_exp");
        k=(int)me->query_skill("wuyue-spear");
        me->add("neili",-100);

        me->delete("env/brief_message");
        target->delete("env/brief_message");
        message_vision(HIM"\n$Nһͦ����"+weapon->name()+NOR+HIB"ֱ��$n��\n"NOR,me,target);

        if (i > random(j)) 
        {
                damage=100+k+(int)me->query("str");
                target->receive_damage("qi",damage);
                target->receive_wound("qi",damage/2);
                COMBAT_D->report_status(target);
        }
        //if (random(i)*7/8> random(j)) 
        if (i > random(j)) 
        {
                message_vision(HIM"\n$Nһǹ�̿գ�����һ�⣬�Ի���"+HIB"$n"+HIM"��\n"NOR,me,target);
                damage=200+k+random(k)+(int)me->query("str");
                target->receive_damage("qi",damage);
                target->receive_wound("qi",damage/2);
                COMBAT_D->report_status(target);
        }
        //if (random(i)*5/6> random(j)) 
        if (i > random(j)) 
        {
                message_vision(HIR"\n$Nһǹ�̿գ�����һ�⣬����δ�����Ի���"+HIB"$n"+HIR"��\n"NOR,me,target);
                message_vision(HIM"\n$Nһ���ֿգ����Բ����У�˫��һ�ɣ�һͷײ��"+HIB"$n"+HIM"��\n"NOR,me,target);
                damage=300+k+random(k)*2+(int)me->query("str");
                target->receive_damage("qi",damage);
                target->receive_wound("qi",damage/2);
                COMBAT_D->report_status(target);
        }
        else 
                if (random(2)) 
                {
                        message_vision(HIR"\n$Nһǹ�̿գ�����һ�⣬�Ի���$n��\n"NOR,me,target);
                        message_vision(HIR"\n$Nһ���ֿգ����Բ����ţ�һͷײ��$n��\n"NOR,me,target);
                        message_vision(HIR"\n$Nһͷ��Ȼײ�գ���$nҲ����ƴ���ľٶ�����һ����\n"NOR,me,target);
                        target->start_busy(5);
                }
                else 
                {
                        message_vision(HIM"\n$Nһǹ�̿գ�����һ�⣬�Ի���$n��\n"NOR,me,target);
                        message_vision(HIM"\n$Nһ���ֿգ����Բ����ţ�һͷײ��$n��\n"NOR,me,target);
                        message_vision(HIW"\n$n������Ц��ֻ��ƥ��ֻ�����к��ã����ɱܿ�\n"NOR,me,target);
                }
	
     
    }
        me->start_busy(3);

        return 1;
       
}
                        
void npc_attack(object invoker, object target, string npc, object where)
{
        object attacker;
        int rd;
        string tid;

        if(!invoker || !target) return;

        if( environment(invoker) != environment(target) ) return;
        if( environment(target) != where) return;

        seteuid(getuid());
        attacker = new(npc);
        attacker->move(environment(invoker));
if (!target->is_busy()) target->start_busy(1);
        COMBAT_D->do_attack(attacker, target, attacker->query_temp("weapon"));

        // give the killing credit to the invoker.
        // so this would be counted as PK if the invoker is user.

        if(target->query_temp("last_damage_from")==attacker)
                target->set_temp("last_damage_from", invoker);
        
        if(target->query_temp("last_fainted_from")==attacker)
                target->set_temp("last_fainted_from", invoker->query("id"));
        
        destruct(attacker);
}
                             
