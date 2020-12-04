#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{       
        string msg="";
        int damage,wound,myexp,yourexp,busy,extra;

        object weapon=me->query_temp("weapon");

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ����������\n");

        if(!me->is_fighting())
                return notify_fail("��������ֻ����ս����ʹ�ã�\n");
        
    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "staff")
        return notify_fail(RED"��ʲô��Ц���������ԣ�\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "zhanzhuang-gong")
                return notify_fail("��ʹ����ƽ����վ׮��!\n");

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("���ž�ѧֻ�ܶ�ս���еĶ���ʹ�á�\n");

                
        if((int)me->query("max_neili") < 500 )
                return notify_fail("�������������\n");

        if((int)me->query("neili") < 500 )
                return notify_fail("����������㣡\n");

        if((int)me->query("jing") < 300 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");

        if((int)me->query_skill("buddhism", 1) < 120)
                return notify_fail("��������ķ���Ϊ��������ʹ����һ�л������ѣ�\n");
        if((int)me->query_skill("lunhui-zhang", 1) < 120)
                return notify_fail("����ֻ�����Ϊ��������ʹ����һ�л������ѣ�\n");
     
        if( time()-(int)me->query_temp("cibei_end") < 4 )  
                return notify_fail("�������˵���˱��˾ͷ��ˡ�\n");

        myexp = (int) me->query("combat_exp"); 
        yourexp = (int) target->query("combat_exp");
        busy = 2+random(4); 
        extra = me->query_skill("lunhui-zhang",1);  

        message_vision(HIY"$N�����������Ĵ�Կգ�����˷𷨷��ӵ���������ʱ������գ�$N���Լ��򵽵�"HIR"��������"HIY"�籡������\n"NOR,me,target);
    
        if(random(myexp)>random(yourexp/6)) 
        {
        
                me->add_temp("apply/attack",200);
                me->add_temp("apply/damage",1200);  
                if(!target->is_busy()) 
                        target->start_busy(busy);
              target->receive_wound("qi",extra + random(extra));

                 message_vision(HIG"\n�} �} �} ��������������������̨��ʱʱ�ڷ��ã���ʹ�ǳ������} �} �} \n"NOR,me,target);
       
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
                message_vision(HIW"\n�} �} �} ���᱾�������������̨��������һ��δ��ǳ������} �} �} \n"NOR,me,target);
   
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
                message_vision(HIR"\n�} �} �} ���������棬ʾ��ʮ����������δ�ˣ���ħ���ް����} �} �} \n"NOR,me,target);
     
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
                message_vision(HIC"\n�} �} �} Ҫ���Ļ�������������ʾ������������ʶ�Ǻγ��룡�} �} �} \n"NOR,me,target);
       
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
           
                me->add_temp("apply/attack",-200);  
                me->add_temp("apply/damage",-1200);  
            
                message_vision(HIY"$N�߿ԡ������ӷ𣬷���ȱ��������ŷ��ƮȻ���ˡ�\n"NOR,me,target);

       
        }
        else
 	    {
                message_vision(HIY"$n�ٺ�һЦ����ȵ���������㣬�����ҷ����� $N��������δ˵�����ƿ������ˡ�\n"NOR,me,target);
        }

        me->add("neili", -200);
        me->start_busy(2);
        me->set_temp("cibei_end",time());
        return 1;
}