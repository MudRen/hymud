//Ѹ�� 
//by junhyun@SK 

#include <ansi.h> 
#include <skill.h> 
#include <combat.h> 
#include <weapon.h> 


inherit F_SSERVER;

#include "/kungfu/skill/eff_msg.h";
string *zhaoshi_name = ({ 
        RED"$N����$w�ζ������׺���ա�ʹ��������������������$n�Ƶ��ľ���ѣ����֪$N�������˶�����"NOR, 
        GRN"$N����$w���������ͻȻ���ڿ���һ����һ�С�����ӭ�͡������а�������֮����$w��·������ȣ���̼侹Ȼ���Ƶ���$n����"NOR, 
        YEL"$N$w������仯������һ�С�������������������֮���£������޶�������׽����$n��һ���ۻ����ң��ٸ����Ӧ���� "NOR, 
        BLU"$NͻȻ��������б��ܳ���ʹ�����з����ǡ�����$w�����Ȼ֮���������⻷��ת����ʱ֮���ѽ�$n����һ�Ž���֮��"NOR, 
        MAG"$Nȫ�����Է�������·��ʹ��һ�С������ϸǡ����仯Ī��ع���$n�����ƾ���˿�������Ѱ"NOR, 
}); 
 
int perform(object me,object target) 
{ 
        object weapon; 
        mapping fam = me->query("family"); 
        mapping my_fam = me->query("family"); 
        int i=me->query_skill("canxin-jian",1); 
        int d=me->query_skill("baiyun-xinfa",1); 
        
        if( !target ) target = offensive_target(me); 

        if( !target || !me->is_fighting(target) || !living(target) 
        || environment(target)!=environment(me)) 
                return notify_fail(HIW"[Ѹ��]"NOR"ֻ�ܶ�ս���еĶ���ʹ�á�\n"); 

if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("ֻ����ս����ʹ�á�\n");

 if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
        return notify_fail(RED"��ʲô��Ц���������ԣ�\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "baiyun-xinfa")
                return notify_fail("��ʹ�ð����ķ�!\n");

        if((int)me->query_skill("baiyun-xinfa",1) < 200)
                return notify_fail("��İ����ķ�������������\n"); 
                

        if( (int)me->query_skill("canxin-jian", 1) < 380 ) 
                return notify_fail("��Ĳ��Ľ�����δ���ɣ�����ʹ��[Ѹ��]��\n"); 


        if (!objectp(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "sword" 
        || me->query_skill_mapped("sword") != "canxin-jian") 
                return notify_fail("�������޷�ʹ��[Ѹ��]��\n"); 
        if(me->query_temp("shushan/xunlei")  ) 
                return notify_fail("������ʹ��[Ѹ��]��\n"); 
        
        if((int)me->query("max_neili") < 5000 ) 
                return notify_fail("���������Ϊ����������ʹ��[Ѹ��]��\n"); 
        if((int)me->query("neili") < 2000 ) 
                return notify_fail("�������������㣬����ʹ��[Ѹ��]��\n"); 
        if((int)me->query("jing") < 1500 ) 
                return notify_fail("��ľ���״̬̫���ˣ�����ʹ��[Ѹ��]��\n"); 
        if((int)me->query("qi") < 1500 ) 
                return notify_fail("�����Ѫ̫���ˣ�����ʹ��[Ѹ��]��\n"); 
        message_vision(HIG" 
        $N����һ����Х��б�ж�ǰ��������������ֱ����������Ѹ�׽���������Ѹ���ޱ�. 
        δ�������У��������ѷ��������������߰��к�$N�Ѻ������϶�Ϊһ�� 
        ��̼佣�⽣���缱�籩�����$n�����к���\n"NOR, me,target); 
        me->set_temp("shushan/xunlei", 1); 
        target->start_busy(3); 
        call_out("check_fight", 2, me, 6); 
        return 1; 
} 

void remove_effect(object me) 
{ 
        if(!me) return; 
        me->delete_temp("shushan/xunlei"); 
        me->delete_temp("combat_yield"); 
        if(!living(me)) return; 
        message_vision(HIG"\n$N��"HIW"��Ѹ�ס�"HIG"����������ϣ��������С�\n"NOR, me); 
        me->start_perform(3,"��Ѹ�ס�"); 
        
} 

void check_fight(object me, int i) 
{ 
        object weapon, target; 
        string msg; 
        
        if (!me ) return;       
        target = offensive_target(me); 
         
        if( !living(me)  
        || !target  
        || !me->is_fighting(target)  
        || !living(target) 
        || environment(target)!=environment(me) 
        || !me->query_temp("shushan/xunlei")) 
                return remove_effect(me); 
        else if(me->query_skill_mapped("sword") != "canxin-jian"){ 
                tell_object(me, HIR"����ʱ�Ļ�����������ʹ�á�Ѹ�ס�������\n"); 
                remove_effect(me); 
        } 

/*
        else if(me->query_skill_mapped("parry") != "canxin-jian"){ 
                tell_object(me, HIR"����ʱ�Ļ��мܣ�����ʹ�á�Ѹ�ס�������\n"); 
                remove_effect(me); 
        } 
*/
        else if (!objectp(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "sword"){ 
                tell_object(me, HIR"����ʱ�Ļ�����������ʹ�á�Ѹ�ס�������\n"); 
                remove_effect(me); 
        } 
       else if (i <=0 ){ 
                tell_object(me, HIR"��һ����������,����ʹ�á�Ѹ�ס�������\n"); 
                remove_effect(me); 
        }         
        else if(me->is_busy())  
                call_out("check_fight", 0, me, i); 
        else{ 
                message_vision(HIW"�Թ�����ֻ���������ˣ����ϡ����ϱ�����ε��������ۣ����������ĺ��ˡ�\n"NOR, me,target); 
                me->add_temp("apply/attack",200); 
                me->add_temp("apply/damage",3000);  
                me->set_temp("combat_exp",1); 
                me->set_temp("shushan/xunlei",1); 
                msg = zhaoshi_name[random(sizeof(zhaoshi_name))]; 
                COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg); 
                msg = zhaoshi_name[random(sizeof(zhaoshi_name))]; 
                COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg); 
                msg = zhaoshi_name[random(sizeof(zhaoshi_name))]; 
                COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg); 
                msg = zhaoshi_name[random(sizeof(zhaoshi_name))]; 
                COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg); 
                msg = zhaoshi_name[random(sizeof(zhaoshi_name))]; 
                COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg); 
                me->add_temp("apply/attack",-200); 
                me->add_temp("apply/damage",-3000); 
if (!me->is_busy()) me->start_busy(2);
        
                me->add("neili",-50); 
                if(me->query("gender")=="Ů��") me->add("neili",-30); 
                call_out("check_fight", 2, me, i-1); 
        } 
}          
