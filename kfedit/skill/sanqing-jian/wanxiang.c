//Created by Wuyou@Sanjie

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;



int perform(object me, object target)
{
        string msg;
        int damage, ap, dp, size, num, extra, i;
        object weapon;
        weapon = me->query_temp("weapon");
        extra=(int)me->query_skill("sanqing-jian", 1);
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail(WHT"��Ҫ��˭ʩչ"RED"����������"WHT"��\n"NOR);
        if( !me->is_fighting(target) )
   

                return notify_fail(RED"����������"WHT"ֻ����ս��ʹ�á�\n"NOR);

        if (me->query_skill("sanqing-jian",1)<100)
                return notify_fail(WHT"������彣���������죬���ü���Ŭ����\n"NOR);     
        
        if (me->query_skill("taiyi",1)<100)
                return notify_fail(WHT"���̫�ҵ����������죬���ü���Ŭ����\n"NOR);                                          


      if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��������ֻ����ս����ʹ�á�\n");

    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
        return notify_fail(RED"��ʲô��Ц���������ԣ�\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "kongdong-xinfa")
                return notify_fail("��ʹ������ķ�!\n");

   

        if((int)me->query_skill("kongdong-xinfa",1) < 100)
                return notify_fail("�������ķ�������������\n"); 


                 
        if((int)me->query("neili") < 800 )
                return notify_fail(WHT"����������㡣\n"NOR);
        if( me->query("max_neili") < 1000 )
                return notify_fail(WHT"���������Ϊ��ǳ����������"RED"����������"WHT"��\n"NOR);  
        if( (int)me->query("qi") < 200 || (int)me->query("jing") < 200  )
                return notify_fail(WHT"������̫�����ˣ��޷�ʩչ"RED"����������"WHT"��\n"NOR);
        if( time()-(int)me->query_temp("wanxiang_end") < 4 ) 
                return notify_fail(WHT"��������Ϣ��δƽ�������ô˾���������Ԫ����\n"NOR); 
                                
        msg = HIY "\n$N��"HIR"̫�ҵ���"HIY"���������ޣ������ʱ�������ơ�$N��˫��Խ��Խ������ǵص�����$n��\n"
             +"$n��$N��˫����ȥ��ֻ�����������ܲ�����ת���ƣ�����"HIW"���������"HIY"һ�㡣\n" NOR,
      
        me->add("qi", -50);


        me->add("neili", -150);
        ap =(int)me->query_skill("sanqing-jian", 1)+(int)me->query_skill("taiyi", 1);
        damage=300+(ap*3);
        ap = ap * ap * ap /10;
   

        ap = ap + (int)me->query("combat_exp");
        dp =  (int)target->query_skill("parry")
             +(int)target->query_skill("sword");
        dp = dp * dp * dp /10;   
        dp = dp + (int)target->query("combat_exp");
  
         if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 ) 
        {
   

                target->receive_damage("qi",damage,me);
                target->receive_wound("qi",damage,me);
                msg += HIW "$n��ã������"HIR"��õ������ǳ�"HIW"����$N��˫���ָ����ţ����������ܶ���������һƬ���֮�С�\n"NOR;
                message_combatd(msg, me, target, "");
                COMBAT_D->report_status(target); 
                target->start_busy(3+random(3));

        }
      else if( random(7000*ap/dp) <  20 ) 
        {
                msg += HIW "$n����"HIR"̫�ҵ���"HIW"�е�"HIC"������Ǭ����"HIW"��ͬ���죬��æ���λ�λ��ƮȻ���ˡ�"
                    +"$N��˫����գ���̾��Ϊ��ǳ��\n"NOR;
                message_combatd(msg, me, target, "");
        } 
        else if( random(7000*ap/dp) <  40 ) 
        {
                msg += HIY "$n����������������ǰӭ���������$N��˫��ɨ��ͷ������ʱͷʹ���ѣ���ð���ǡ�\n"NOR;
                message_combatd(msg, me, target, "");
                target->receive_damage("qi",damage,me);
                target->receive_wound("qi",damage,me);
                COMBAT_D->report_status(target); 
                if(!target->is_busy()) 
                        target->start_busy(random(2));
        } 
if (extra> 200) extra=200;
        if (me->query_skill("sanqing-jian",1)>=300 || !userp(me))
        {
                
                me->add_temp("apply/attack", extra);
                me->add_temp("apply/damage", 2200);            
             
                msg = WHT "          ����������Ϊ��������\n"NOR;        
                msg += WHT "$N�趯����"+weapon->name()+
     WHT"���Խ�������ʹ��"HIR"��赶��"WHT"�����е������Ѷ��ֿ����ۻ����ң�Ŀ�ɿڴ���\n"NOR;
                //message_combatd(msg, me, target, "");
                 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
            
                msg = HIY "          ����������Ϊ��������\n"NOR;        
   

                msg += HIY "$N�趯����"+weapon->name()+
     HIY"���Խ�������ʹ��"HIR"��ɽ����"HIY"�����е������Ѷ��ֿ����ۻ����ң�Ŀ�ɿڴ���\n"NOR;
                //message_combatd(msg, me, target, "");
                 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);  
             
                msg = HIG "          ����������Ϊ�ȡ�����\n"NOR;        
                msg += HIG "$N�趯����"+weapon->name()+
     HIG"���Խ����ȣ�ʹ��"HIW"��ħ�ȷ�"HIG"�����е������Ѷ��ֿ����ۻ����ң�Ŀ�ɿڴ���\n"NOR;
                //message_combatd(msg, me, target, "");
                 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
                
                
                me->add_temp("apply/attack", -extra);
                me->add_temp("apply/damage", -2200); 
        }
        
        if (me->query_skill("sanqing-jian",1)>=500 || !userp(me))
        {
                msg = HIR "$N�����������"HIY"����ֻأ�������ת�����й�λ�������һ��"HIR"��\n"NOR;
                msg += HIR "$N˫��֮��ͻȻ���������"HIY"��м"HIR"����ֱ����$n��\n"NOR;
                
                me->add("neili",-150);
                if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 ) 
   

                {       
                        msg += HIR "��Щ"HIY"��м"HIR"��$n�������У�$n�������Ŀȫ�ǡ�\n"NOR;
                        message_combatd(msg, me, target, "");
                        size=(int)(me->query_skill("sanqing-jian"));
                        damage=300+random(size)+size;
                        damage=damage+(me->query_str()*10);
                        num=size/5+random(size/5);
                        if (num>5) num=5;
                        for(i=0;i<=num;i++)
                        {
                                target->receive_damage("qi",damage,me);
                                target->receive_wound("qi",damage,me);
                        }
                        COMBAT_D->report_status(target);                
                }
                else
                {
                        msg += HIY "$n���ĺ��˶�������������������У�����ֹ��м�����롣\n"NOR;
                        message_combatd(msg, me, target, "");
                }
        }
me->start_busy(4);                
        me->set_temp("wanxiang_end",time());
        return 1;
   

}
