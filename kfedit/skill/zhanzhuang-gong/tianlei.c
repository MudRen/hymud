//wuyou@sk_sjsh
//2003-3-13
//���ǵ��������˺��жϱȽ��鷳
//�˺���ֵ�䶯̫��
//�����˷����������жϵ�һ�����
//���˺�ȴʹ����pfm�е��жϷ���
//���ǵ�������������cast��ʵ�ü�ֵҲ�Ͳ���̫����


#include <ansi.h>


#include <combat.h>


inherit F_SSERVER;

int exert(object me)
{
        object target;
        string msg;

        string tar_spells,tar_dodge;

        int ap,dp,dg,damage,chance,skills1,skills2;

        if( !target ) target = offensive_target(me);

   	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���ž�ѧֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( !target
        ||   !target->is_character()
        ||   target->is_corpse()
        ||   target==me)
                return notify_fail("��Ҫ��˭���������ף�\n");
  
//        if( target->is_player() )
//                return notify_fail("��������Ŀǰ����������ʹ�á�\n");

        if( !target 
         || !me->is_fighting(target) 
         || !living(target)
         || environment(target)!=environment(me))
                return notify_fail(WHT"���������ס�ֻ�ܶ�ս���еĶ���ʹ�á�\n"NOR);
        if( (int)me->query_skill("buddhism", 1) < 200 )
                return notify_fail("��������ķ��ȼ�������\n");

        if (!target->is_fighting(me))
               return notify_fail("ֻ����ս���в���ʹ���������ף�\n");

        if((int)me->query("qi") < 500 )
                return notify_fail("���������㣬�ò����������ף�\n");

        if((int)me->query("neili") < 500 )
                return notify_fail("����������������ʹ���������ף�\n");


        if((int)me->query_skill("zhanzhuang-gong", 1) < 300 )
                return notify_fail("��������ڹ����������졣\n");


        msg = HIC"\n$N˫Ŀŭ��$n��������������������ܣ������콫���ҷ�ħ����
$NͻȻ����һ�ӣ�ɲ�Ǽ䣬������ӿ��Ũ���ܲ��������ƶ�վ�������콫��\n\n" NOR;

/*****************************************************************************/
/*��һ��*/
        msg +=HIY "   ������\n";
        msg +=HIY "   ����\n";
        msg +=HIY "   ������\n\n"; 
        msg +=HIY "�����ŵ���������һ����⻯��һ����������$n��\n"NOR;
 
        ap=(int)me->query_skill("buddhism", 1)
              +(int)me->query_skill("zhanzhuang-gong", 1)/2;

        
        damage=me->query_skill("buddhism");
        damage=(me->query_skill("buddhism")+me->query("str")*10+random(damage))*2;
        if (random(me->query_skill("force")) > target->query_skill("force")/3){
          msg += HIC "$n�ۿ��Ž����������û���ƿ����������񽫵Ľ��������ס��$N��æ�ٳ�һ����⣬"
              +"$n�����˸����ţ�\n"NOR;
          message_vision(msg, me, target);
  
  	if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
          target->receive_damage("qi",damage,me);
          target->receive_wound("qi",damage,me);
          if(wizardp(me)) tell_object(me,sprintf("damage: %d \n",damage));
          COMBAT_D->report_status(target); 
}
else
	{
          msg += HIC "$n��æ���˽�$N�Ľ��ƿ���\n"NOR;
          message_vision(msg, me, target);
          }
/***************************************************************************************/
/*�ڶ���*/      
  if( (int)me->query_skill("buddhism", 1) > 150 )
{
        msg = HIG "   ������\n";
        msg +=HIG "   ��ľ��\n";
        msg +=HIG "   ������\n\n"; 
        msg +=HIG "�����������ľ���񽫻������̹����$n��\n"NOR;
        
        damage=me->query_skill("buddhism");
        damage=(me->query_skill("buddhism")+me->query("int")*10+random(damage))*2;
        
        if (random(me->query_skill("unarmed")) > target->query_skill("unarmed")/3){

            //damage = damage * 20 ;
            msg += HIC "���$n������̹�͸�������\n" NOR;
             	if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
            target->receive_wound("qi", damage,me);
            target->receive_damage("qi",damage,me);
            if(wizardp(me)) tell_object(me,sprintf("damage: %d \n",damage));
           
         }
         else
        {
            //damage = damage * 10 ;
            msg += HIC "$n����������������̹���������\n" NOR;
             	if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
            target->receive_wound("qi", damage,me);
            target->receive_damage("qi",damage,me);
            if(wizardp(me)) tell_object(me,sprintf("damage: %d \n",damage));   
         } 
         message_vision(msg, me, target);

         if( damage > 0 ) COMBAT_D->report_status(target);
         else if( damage < 0 ) COMBAT_D->report_status(me);
}
/*******************************************************************************/
/*������*/
  if( (int)me->query_skill("buddhism", 1) > 200 )        
{
        msg = HIW "   ������\n";
        msg +=HIW "   ��ˮ��\n";
        msg +=HIW "   ������\n\n"; 
        msg +=HIW "ˮ���񽫷���Ϊ�ƣ�����Ϊ�꣬�����������ű���Ѹ�Ͷ�����\n"NOR;

        damage=me->query_skill("buddhism");
        damage=(me->query_skill("buddhism")+me->query("con")*10+random(damage))*2;
        
        if (random(me->query_skill("parry")) > target->query_skill("parry")/3){
                msg += HIC"$n�������������������\n"NOR;
                  	if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
                target->receive_damage("qi", damage,me);
                target->receive_wound("qi", damage,me);
                if(wizardp(me)) tell_object(me,sprintf("damage: %d \n",damage));
                message_vision(msg, me, target);
                COMBAT_D->report_status(target,0);
         }
         else{
         msg += HIC"$n��Χ�γ�һ�������ܣ�û���ܵ�˿���˺���"NOR;
         message_vision(msg, me, target);
        }
}
/**************************************************************************************/
/*���Ļ�*/  
  if( (int)me->query_skill("buddhism", 1) > 250 )
{
        msg = HIR "   ������\n";
        msg +=HIR "   ����\n";
        msg +=HIR "   ������\n\n"; 
        msg +=HIR "������˫�Ʋ�����һ�޴�Ļ�������$n��\n"NOR;

        damage=me->query_skill("buddhism");
        damage=(me->query_skill("buddhism")+me->query("dex")*10+random(damage))*2;
        
        if (random(me->query_skill("dodge")) > target->query_skill("dodge")/3){
                msg +=  HIC "������$n������ը���ˣ�\n" NOR;
             	if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
                target->receive_damage("qi", damage,me);
                target->receive_wound("qi", damage,me);
                if(wizardp(me)) tell_object(me,sprintf("damage: %d \n",damage));
                message_vision(msg, me, target);
                if( damage > 0 ) COMBAT_D->report_status(target);

        } else
                {
                msg += HIC"���Ǳ�$n����Ķ㿪�ˣ���\n";
                message_vision(msg, me, target);
                }      
}
/*****************************************************************************************/
/*�����*/
  if( (int)me->query_skill("buddhism", 1) >= 300 )
{
        msg = MAG "   ������\n";
        msg +=MAG "   ������\n";
        msg +=MAG "   ������\n\n"; 
        msg +=MAG "�����񽫽�����֮��ᵽ���У�����$n��\n"NOR;

        damage=me->query_skill("buddhism");
        damage=(me->query_skill("buddhism")+me->query("per")*10+random(damage))*2;
        
        if (random(me->query("combat_exp",1)) > target->query("combat_exp",1)/3){

                if( damage > 0 ) {

                        msg += HIC "���$n���Ҹ����ţ���ʱѪ���ɽ������˲��ᣡ\n" NOR;
                         	if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
                        target->receive_damage("jing", damage/2,me);
                        target->receive_wound("jing", damage/2,me);
                        target->receive_damage("qi", damage,me);
                        target->receive_wound("qi", damage,me);
                        if (!target->is_busy()) target->start_busy(3);
                        if(wizardp(me)) tell_object(me,sprintf("damage: %d \n",damage));
                }

             } 
        else
             {
                         msg += HIC"����$n���Ѵ���֮���ֽ����������ԭ����\n";
              }

        message_vision(msg, me, target);
        if( damage > 0 ) COMBAT_D->report_status(target);
        else if( damage < 0 ) COMBAT_D->report_status(me);
}

         me->add("neili", -500);


         me->start_busy(3);

         return 1;
}

