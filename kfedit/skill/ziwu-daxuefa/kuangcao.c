// ding.c ȫ�潣-������

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";
int perform(object me, object target)
{
        object weapon;
        int damage,time;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("���ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "dagger")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if( (int)me->query_skill("ziwu-daxuefa", 1) < 140 )
                return notify_fail("��������Ѩ��������죬����ʹ�ÿ�ݡ�\n");

        if (me->query_skill_mapped("force") != "bluesea-force")
                return notify_fail("��ʹ�õ��ڹ��������Ϻ�������\n");

        if( (int)me->query("neili", 1) < 950 )
                return notify_fail("����������̫��������ʹ�ÿ�ݡ�\n");
        
   
           if( (int)me->query_temp("nokc"))
                return notify_fail("����������ʹ�ÿ�ݡ�\n");
       
        msg = HIM "$Nʹ�����Ὣ��ʫ���ʷ�����������������Ὣ������������ϣ��ͽ������ս���������������׳�գ�����\n"NOR;

        //if( !target->is_killing(me) ) target->kill_ob(me);

        if (random(me->query_skill("dagger")) > target->query_skill("dodge")/3 )
        {
                me->start_busy(1);

                damage = (int)me->query_skill("dagger", 1) + (int)me->query_skill("force",1);
                //(ȫ�潣������+�����ڹ�)

                damage = damage/2 + random(damage/2);

                target->receive_damage("qi", damage);
                target->start_busy(4);
                me->add("neili", -100);
               time=8-((int)me->query_skill("ziwu-daxuefa",1)/40);
              if(me->query_skill("ziwu-daxuefa", 1) > 200)
                call_out("perform2", 0, me, target);    
me->set_temp("nokc",1);
                msg += HIR"$n��֪$Nд����ʲô�������˸����ֲ�����\n"NOR;


        }
        else
        {
                me->start_busy(3);
                msg += GRN"$N��·���ÿһ��ֻʹ������,���̱�$n��ס��\n"NOR;
        }
        message_vision(msg, me, target);
        me->start_busy(1);
        return 1;
}
int perform2(object me, object target)
{
 object weapon, ob;
        string msg, string1;
        int count,time;
        
    weapon = me->query_temp("weapon");  
if (!me || !target) 
return 0;              
        if(!living(target)) 
          {
 me->delete_temp("nokc");
          return notify_fail("�����Ѿ�������ս���ˡ�\n");
}
        if( (int)me->query("neili", 1) < 300 )
          {
 me->delete_temp("nokc");
                return notify_fail("���Ҫ�ٳ��ڶ�����ȴ�����Լ������������ˣ�\n");     
}
        if(!objectp(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "dagger")
    return notify_fail("������û��ʹ�����޷���һ��������\n");
             msg = HIY+"$N���һ�����ʷ��Ǳ䣬�������ʲ���ô������������Ǿ����з棬�������أ�����â�ǳ����������ţ��������䲨����̬��\n" NOR;
        
        message_vision(msg, me,target);
        me->clean_up_enemy();
        ob = me->select_opponent();   
        if (!ob->is_busy() && random(2)==0)ob->start_busy(2);
        	                                me->add_temp("apply/attack", 100);
                me->add_temp("apply/damage", 1200);
        	
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);  
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
                                        me->add_temp("apply/attack", -100);
                me->add_temp("apply/damage", -1200);
        
        me->add("neili", -100);
    time= 1+((int)me->query_skill("dagger",1)/50);
        if(me->query_skill("ziwu-daxuefa", 1) > 300)
               call_out("perform3", 0, me, target);    
               //me->start_busy(2);
        return 1;
}

int perform3(object me, object target)
{
 object weapon, ob;
        string msg, string1;
        int count,time,i,damage;
        ob=target;
if (!me || !target) 
return 0;    
    weapon = me->query_temp("weapon");  
              
        if(!living(target)) 
           {
 me->delete_temp("nokc");
          return notify_fail("�����Ѿ�������ս���ˡ�\n");
}
        if( (int)me->query("neili", 1) < 400 )
          {
 me->delete_temp("nokc");
                return notify_fail("���Ҫ�ٳ���������ȴ�����Լ������������ˣ�\n");     
}
        if(!objectp(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "dagger")
    return notify_fail("������û��ʹ�����޷���һ��������\n");
        me->add("neili", -100);
        //me->add("jing", -100);
        message_vision(BLU "\n$N�ʷ��ֱ䣬���顶�������������еĲ��飬�ݺ�Ʈ������ת�޷������мӲ�,�������棬�����ۻ����ң�\n" NOR,me, target);

                                me->add_temp("apply/attack", 100);
                me->add_temp("apply/damage", 1200);
        if (!ob->is_busy() && random(2)==0)ob->start_busy(2);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);  
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);  
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        me->delete_temp("nokc");

                                me->add_temp("apply/attack", -100);
                me->add_temp("apply/damage", -1200);
        //me->set_temp("mr_sanhua", 1); 
        i = (int)me->query_skill("dagger")/30;
        if( 15 - i <= 4) i = 4;
        //call_out("remove_effect", i, me);

                me->start_busy(2);
        return 1;
}
