//xiangxi.c  
//created by DHXY-EVIL 2000.7.7
//Modified by vikee for xlqy-zq station 2000-12-5 9:05 .The CopyRight was keeped by DHXY-evil.

#include <ansi.h>
#include <combat.h>
#include <condition.h>
inherit F_SSERVER;

int perform(object me, object target)
{       
        string msg="";
        int damage,wound;
        int i,j;
        int success, ap, dp;        
        object weapon=me->query_temp("weapon");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ����˼��������\n");

        if(!me->is_fighting())
                return notify_fail("����˼������ֻ����ս����ʹ�ã�\n");
        
   if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("ֻ����ս����ʹ�á�\n");

 if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
        return notify_fail(RED"��ʲô��Ц���������ԣ�\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "huiyan-xinfa")
                return notify_fail("��ʹ�û����ķ�!\n");

        if((int)me->query_skill("huiyan-xinfa",1) < 200)
                return notify_fail("��Ļ����ķ�������������\n"); 
        
        if(environment(me)!=environment(target))
                return notify_fail("��Ҫ�������˲������\n");
                
        if((int)me->query("max_neili") < 1800 )
                return notify_fail("�������������\n");

        if((int)me->query("neili") < 500 )
                return notify_fail("����������㣡\n");
        if((int)me->query("jing") < 300 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");

        if((int)me->query_skill("jiutian-sword", 1) < 80)
                return notify_fail("��ľ����Ȫ����Ϊ��������ʹ����һ�л������ѣ�\n");

        message_vision(HIM"$N��˼�����͵�ʩ�����Ľ��ľ��С���˼����������$n"+HIM"��������������\n"NOR,me,target);
        me->set("xiangsi", 8);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        switch (random(4))
        {
         case 0:
              {
               message_vision(HIC"$n�������е���˼֮���Ⱦ�������鶾��\n"NOR,me,target);
               target->apply_condition("ill_shanghan",20);
               target->apply_condition("ill_zhongshu",20);
               target->apply_condition("ill_dongshang",20);
               target->apply_condition("ill_fashao",20);
               target->apply_condition("ill_keshou",20);
               break;
               }
         case 1:
              {

               message_vision(HIB"һ�ɾ�������$n��$n�ƺ����˵���⣡\n"NOR,me,target);
               target->apply_condition("drunk",20);
               break;
              } 
         case 2:
              {
               message_vision(HIB"��������Ϊ���\n"NOR,me,target);
               message_vision(HIM"���޺ۣ�����ţ��������³������\n"NOR,me,target);  
               target->apply_condition("flower_poison",20);
               break;
              }
         case 3:
              {
               break;
              }
        }
        me->set("xiangsi", 9);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        switch (random(4))
        {
         case 0:
              {
               message_vision(HIR"$n�������е���˼֮���Ⱦ�������鶾��\n"NOR,me,target);
               target->apply_condition("flower_poison",20);
               break;
              }
         case 1:
              {
               message_vision(HIC"һ�ɾ�������$n��$n�ƺ����˵���⣡\n"NOR,me,target);
               target->apply_condition("drunk",20);
               break;
              }
         case 2:
              {
               message_vision(HIW"��������Ϊ���\n"NOR,me,target);
               message_vision(HIB"���޺ۣ�����ţ��������³������\n"NOR,me,target);
                target->apply_condition("ill_dongshang",20);
               target->apply_condition("ill_fashao",20);
               target->apply_condition("ill_keshou",20);
               target->apply_condition("ill_shanghan",20);
               target->apply_condition("ill_zhongshu",20);               
               break;
              }
         case 3:
              {
         break;
              }
        }
        me->set("xiangsi", 10);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        switch (random(4))
        {
         case 0:
              {
               message_vision(HIR"$n�������е���˼֮���Ⱦ�������鶾��\n"NOR,me,target);
                             target->apply_condition("flower_poison",20);
               break;
              }
         case 1:
              {
               message_vision(HIG"һ�ɾ�������$n��$n�ƺ����˵���⣡\n"NOR,me,target);
               target->apply_condition("drunk",20);
               break;
              }
         case 2:
              {
               message_vision(HIW"��������Ϊ���\n"NOR,me,target);
               message_vision(HIM"���޺ۣ�����ţ��������³������\n"NOR,me,target);  
                target->apply_condition("ill_dongshang",20);
               target->apply_condition("ill_fashao",20);
               target->apply_condition("ill_shanghan",20);
               target->apply_condition("ill_zhongshu",20);               
               target->apply_condition("ill_keshou",20);
               break;
              }
         case 3:
              {
               break;
               }
        }
        me->delete("xiangsi");



if ((int)me->query_skill("jiutian-sword",1)> 360)
{
	if (!target->is_busy()) target->start_busy(2);
       message_vision(HIW"
�㽣��Խ��Խ�죬�������䣬������ˣ�ͻȻһ����Х��������
�������ΰ���������������л���һ�������Ļ��ߣ�˼������
�ữ���ޱߵĽ���
"NOR, me);
       me->add("neili", -50);
        me->add_temp("apply/attack",200	);
        me->add_temp("apply/damage",3800);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
msg=HIW""NOR; 
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);      
msg=HIW"������"NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
msg=HIW"�����"NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
msg=HIW"�����"NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
msg=HIW""NOR; 
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	
        me->add_temp("apply/attack",-200);
        me->add_temp("apply/damage",-3800);

}	

if ((int)me->query_skill("jiutian-sword",1)> 880)
{
 msg = HIW"$N����Խ��Խ��������ȥ���Լ����˵Ĺ�ȥ���֣����ɾ�����ʹ����
"+HIM"�����������������Ը���������ǰԵô����
"+HIW"$N����Ͱ��˻�ǰ���²���糲�ʱ�Ļ�����ɵó��ˡ�������

"+HIR"$N���뵽�����������ȥʱ����������飬�����к��ޱ���˫�۵��龰����
"+HIR"ͻȻ��$N����ȫ���ѪҺ�ڷ��ڡ���
"+HIW"$N���������������û���㣬�һ��Ż���ʲô���壿��
�������ʱ��$N�·𿴵����������ڶ��Լ�΢Ц����
"HIW"$N���쳤Х�����ζ�ת������$n���˹��������г�����ת���ۡ���һ�������Լ������ţ�\n" NOR;
	
        success = 1;
        ap = me->query_skill("jiutian-sword");
        ap = ap * ap * ap /10 ;
        ap += (int)me->query("combat_exp");
        ap = 4*ap; //this is for ƴ�� so easier.
        dp = target->query("combat_exp");
        if( random(ap + dp) < dp ) success = 0;

        ap = (int)me->query("max_neili");
        dp = (int)target->query("max_neili");
        if( ap < random(dp) ) success = 0;

        if(success == 1 ){//now both die.
                msg +=  HIR "$n��$N�ľٶ��Ŵ��ˣ�һ��ûע�ⱻ$N͸������Ľ�������ؿڣ���ʱ����һ���ҽУ�\n��$NҲ����һ̱�����ڵ��ϡ�\n" NOR;
                message_vision(msg, me, target);

       me->add("neili", -50);
       me->add("max_neili", -2);
damage=target->query("max_jing")/2;
if (damage > 39999) damage=39999;
     target->receive_damage("jing",damage);
                target->receive_wound("jing", damage);

damage=target->query("max_qi")/2;
if (damage > 39999) damage=39999;
target->start_busy(3);
     target->receive_damage("qi",damage);
                target->receive_wound("qi", damage);
                COMBAT_D->report_status(target);

                COMBAT_D->report_status(me);
  
                //attacker die here.

        }
            
        else {
                msg +=  HIR "$n�����龰���˲���ʲô����ˣ��͵�һ���㿪����������һ����\n$N��̾һ��������һ̱�����ڵ��ϡ���Ǵ���һ˿΢Ц����\n" NOR;
                message_vision(msg, me, target);

                                
       me->add("neili", -50);
       me->add("max_neili", -2);

              
                COMBAT_D->report_status(me);

                //attacker die here.
        } 
	
}	
        message_vision(HIY"$N�ġ���˼�������ù���ϣ����ص���,�����չ�.\n"NOR,me,target);

        me->start_busy(3);
        //me->add("qi", -100);
        me->add("neili", -50);
        //me->add("jing",-100);
        
        return 1;
}


