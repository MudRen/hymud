#include <ansi.h>

#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        string str;
        int snowsword,f,bufa,ini_damage_apply,times,damage;
        string desc_msg="";
        int sword_level;
        string msg;
        int ap, dp,qixue,eff_qi,max_qi,qi_pcg,dmg;
object victim;
                        
        snowsword = (int)me->query_skill("snowsword", 1);
        victim=target;
        f = (int)me->query_skill("bitao-shengong", 1);
        bufa = (int)me->query_skill("qiongya-bufa", 1);
       
               if (! target) target = offensive_target(me);
  if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԣ�\n");

	if(me->is_busy())
		return notify_fail("������û�գ���\n");



        if (! target || ! me->is_fighting(target))
                return notify_fail("ֻ����ս���жԶ���ʹ�á�\n");
                
//	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
//		return notify_fail("�������ֻ�ܿ���ʹ�á�\n");		
	if( (int)me->query("neili") < 2000  ) 
		return notify_fail("�������������\n");

	if( (int)me->query("neili") < me->query("max_neili")/7+200 ) 
		return notify_fail("�������������\n");

       if( !wizardp(me) &&(int)me->query_skill("snowsword", 1) < 500 )
		return notify_fail("��ı����⹦����!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("bitao-shengong", 1) < 500 )
		return notify_fail("��ı����ڹ�������!���ܹ�ͨʹ�ã�\n");


//	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
//		return notify_fail("�����ѧ̫�࣬�޷��Ա����书��ͨʹ�ã�\n");

        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("��Ľ������黹�������޷��Ա����书��ͨʹ�ã�\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("�㻹û��ͨ����ɽ�۽�! �޷��Ա����书��ͨʹ�ã�\n");

        //if ( !wizardp(me) && me->query_skill_mapped("sword") == "snowsword")
          //      return notify_fail("�����Ž��������ʹ�ñ��ž�ѧ!\n");


        if ( !wizardp(me) && me->query_skill_mapped("force") != "bitao-shengong")
                return notify_fail("��ʹ�ñ����ڹ������ʹ�ñ��ž�ѧ!\n");

//        if( !wizardp(me) && me->query_temp("weapon") )
//              return notify_fail("�������ֲ���ʹ�ñ��ž�ѧ!\n");

        msg = HBWHT "$N��ͨ��������ѧ��ʹ���˺����ɵľ�ѧ֮���裡\n" NOR;
message_vision(msg, me, target);               
victim=target;
if (me->query("hyvip")==4) 
	{me->add("neili",-500);}
	else
	{me->add("neili", -me->query("max_neili")/7);}
   

               
                
        sword_level=(int)(snowsword/50);




        
  //      if( time()-(int)me->query_temp("wuxue_end") < 3 )
  //              return notify_fail("�����ö�Ͳ����ˣ�\n");
                
        if ( sword_level <= 1 ) desc_msg = "" ; 
        else desc_msg = chinese_number(sword_level);
        if ( sword_level > 9 ) desc_msg = "��";
   



        ini_damage_apply = me->query_temp("apply/damage");
        me->add_temp("apply/attack", 200);	
        me->add_temp("apply/damage", 2800);
        message_vision(HIW"\n$N��߳һ�����ż�һ�㣬���弱���������ڰ����һ��������
ͬʱ�����ᶶ�������������������ѩ����$n��\n"NOR,me,target);
        target->start_busy(2);
        damage=1;
        //ǰ����
        message_vision(HIC"\n$Nͬʱʹ�����ѩ�轣��ǰ���У��ڰ����ѹ��$n��\n"NOR,me,target);
        

        target->receive_damage("qi", (random(me->query_skill("bitao-shengong",1))+10),me);

        me->set_temp("WX_perform", 6);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        //������
//        if( snowsword > 99 && f > 99 && bufa > 99 )
//           {
                message_vision(HIC"\n$N����бб����Ʈ����Ҳ����ͷ�����־ʹ̳������С�\n"NOR,me);

             

                me->set_temp("WX_perform", 8);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
target->receive_damage("qi", (random(me->query_skill("bitao-shengong",1))+10),me);
//        }
      
        //�������
//        if( snowsword > 149 && f > 149 && bufa > 149 )
//        {
                message_vision(HIC"\n$Nббһ�ٸ�������������ǧ��֧����������һ�ɺ�������$n��\n"NOR,me,target);
                    

                me->set_temp("WX_perform", 9);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
   
target->receive_damage("qi", (random(me->query_skill("bitao-shengong",1))+10),me);
                    
//        }
        me->add_temp("apply/attack", -200);	               
        me->delete_temp("WX_perform");
        me->add_temp("apply/damage",-2800);


damage=me->query_skill("snowsword", 1)+random(100);   
         //message_vision(HIY"\n$N��Ȼ����սȦ����$n�����"NOR,me,target);
        message_vision(HIY"$N������࣬Խ��Խ�ǳ�Ͱ�����ȫ����������ʥ��Ĺ�ԡ�"NOR,me,target);
            message_vision(HIC"\n��ğo�����������q��ó��T���󡣻������R����o���︣�Կ՟o��ס��"NOR,me,target);
 if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
{            
                   
                message_vision(
                 "\n $nͻȻ��ɫ�԰ף��ƺ�������֧����Ż��һ��Ѫ����",
                 me, target );

            target->receive_wound("qi",damage,me);
            target->receive_damage("qi",damage,me);
}
            message_vision(HIG"\n���T�Ʒ����ǻã����T���I���ǻá������ĭ�����L���ó��o���o���ԡ�"NOR,me,target);  
 if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
{            

                message_vision(
                 "\n $nͻȻ��ɫ�԰ף��ƺ�������֧����Ż��һ��Ѫ����",
                 me, target );
            damage=damage+100;
            target->receive_wound("qi",damage,me);
            target->receive_damage("qi",damage,me);
}
            message_vision(HIR"\n�ٽ��Ĵ��Ԟ����ı��o�����У�ǰ�����o�����o���︣��������硣"NOR,me,target);
 if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
{         
                message_vision(
                 "\n $nͻȻ��ɫ�԰ף��ƺ�������֧����Ż��һ��Ѫ����",
                 me, target );
damage=damage+100;
if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
            target->receive_wound("qi",damage,me);
            target->receive_damage("qi",damage,me);
}


            message_vision(HIW"\nҊ��o���Ƿ�����������Ƿ�ã��˵����ı��Կգ�˹���c�����e��"NOR,me,target);
                         if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
{           
                message_vision(
                 "\n $nͻȻ��ɫ�԰ף��ƺ�������֧����Ż��һ��Ѫ����",
                 me, target );
damage=damage+100;
if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
            target->receive_wound("qi",damage,me);
            target->receive_damage("qi",damage,me);
}
            message_vision(RED"\n��Ҋ��֪�Ƿ�����֪�e�o��������֪���Կգ�̹Ȼ�����������"NOR,me,target);

                        if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
{          
                message_vision(
                 "\n $nͻȻ��ɫ�԰ף��ƺ�������֧����Ż��һ��Ѫ����",
                 me, target );
damage=damage+100;
if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
            target->receive_wound("qi",damage,me);
            target->receive_damage("qi",damage,me);
}
            message_vision(GRN"\nһ����������Q���ı��o���o�ɜ磬���������ǻ������û�֮�Пo�︣��"NOR,me,target);
                      
if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
{           
                message_vision(
                 "\n $nͻȻ��ɫ�԰ף��ƺ�������֧����Ż��һ��Ѫ����",
                 me, target );
damage=damage+100;
if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
            target->receive_wound("qi",damage,me);
            target->receive_damage("qi",damage,me);
}



            message_vision(YEL"\n�������o�����o�����෨���񸶟o���r��������������"NOR,me,target);
 if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
{          
                 message_vision(
                 "\n $nͻȻ��ɫ�԰ף��ƺ�������֧����Ż��һ��Ѫ����",
                 me, target );
damage=damage+100;

 	if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
            target->receive_wound("qi",damage,me);
            target->receive_damage("qi",damage,me);
}




            message_vision(HIB"\n�T�Пo���������編��������ѣ��Ŝ�阷��"NOR,me,target);
 if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
{          
                message_vision(
                 "\n $nͻȻ��ɫ�԰ף��ƺ�������֧����Ż��һ��Ѫ����",
                 me, target );
damage=damage+100;

 	if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
            target->receive_wound("qi",damage,me);
            target->receive_damage("qi",damage,me);
}



       message_vision(WHT"\n�����T�͟룬�����»�k��Ո���������A�S��ɫ��"NOR,me,target);
 if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
{          
                message_vision(
                 "\n $nͻȻ��ɫ�԰ף��ƺ�������֧����Ż��һ��Ѫ����",
                 me, target );
damage=damage+100;

 	if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
            target->receive_wound("qi",damage,me);
            target->receive_damage("qi",damage,me);
}



            message_vision(BLU"\n�������������Ե�־�̨������������������޳�����"NOR,me,target);
                        if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
{          
                message_vision(
                 "\n $nͻȻ��ɫ�԰ף��ƺ�������֧����Ż��һ��Ѫ����",
                 me, target );
damage=damage+100;


  	if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
            target->receive_wound("qi",damage,me);
            target->receive_damage("qi",damage,me);
}

 

         message_vision(HIY"\n$N˫�ֺ�ʮ��������ʣ�\n" NOR,me,target);
message_vision(HIC"��һ�ж����ᣬ�޳��ѵþá�\n"NOR,me,target);
message_vision(HIC"  ������η�壬��Σ�ڳ�¶��\n"NOR,me,target);
message_vision(HIC"  �ɰ������ǣ��ɰ���������\n"NOR,me,target);
message_vision(HIC"  �����ڰ��ߣ��������޲�����\n"NOR,me,target);
message_vision(HIB" $N̾��:��Ү?��Ү?��������......
��Ȼ��ʽһ������һƬ����,�Ʋʵ����ɰ�����$n\n"NOR,me,target);
   

                 
        ap = me->query_skill("snowsword", 1);
        ap = ap * ap * ap /10;
        ap = ap + (int)me->query("combat_exp");
        dp = target->query_skill("parry");
        dp = dp * dp * dp /20;   
        dp = dp + target->query("combat_exp");
        dp = dp*qi_pcg/50;  
 if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
  {
target->receive_damage("qi", (me->query_skill("snowsword",1)*4),me);
target->receive_wound("qi", (me->query_skill("snowsword",1)*4),me);   

                   message_vision(HIM "$n��������,�����е���һֻ�ʵ����������\n"NOR, me, target);
                   COMBAT_D->report_status(target); 

         } else {
                            message_vision(HIW"$nһ�����Ʋ��һ����Ծ,����Ȧ�⡣\n"NOR, me, target);

           }
        
      
        


            msg = HIW"$N����һҧ��ͻȻ�߸���������ȫ�������˽���һ��"
                 +"����һ���׹⣬���������$n��\n" NOR;
        ap = me->query_skill("snowsword", 1);
        ap = ap * ap * ap /10;
        ap = ap + (int)me->query("combat_exp");
        dp = target->query_skill("parry");
        dp = dp * dp * dp /10;   
        dp = dp + target->query("combat_exp");
        dp = dp*qi_pcg/50;  //more badly you're hurt, more chance you will succeed
 if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
  {
target->receive_damage("qi", (me->query_skill("bitao-shengong",1)*4),me);
target->receive_wound("qi", (me->query_skill("bitao-shengong",1)*4),me);   
                msg += HIW "$n����$N��˾�����Ϊ���������壬��Ȼ���ڵ��أ������мܡ�
˵ʱ�٣���ʱ�죬����׹�����$n���ϵ��ش�����\n"NOR;
                message_vision(msg, me, target);



                COMBAT_D->report_status(target); 
         } 
         else {

                msg += HIW "$nһ�����Ʋ����æ�͵�һ��������ǧ��һ��֮�ʶ������һ����ȴҲ�Ǳ��������ŵû����ɢ��һʱ�䶯�����á�\n"NOR;
                message_vision(msg, me, target);

         }
    
    



me->start_busy(4);
        //me->set_temp("wuxue_end",time());
        return 1;
}
