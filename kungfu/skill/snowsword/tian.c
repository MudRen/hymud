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

                        
        snowsword = (int)me->query_skill("snowsword", 1);
        f = (int)me->query_skill("bitao-shengong", 1);
        bufa = (int)me->query_skill("qiongya-bufa", 1);
       
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ�������ѩ����\n");

        if(!me->is_fighting())
                return notify_fail("�������ѩ��ֻ����ս����ʹ�ã�\n");


     if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("ֻ����ս����ʹ�á�\n");
        
    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
        return notify_fail(RED"��ʲô��Ц���������ԣ�\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "bitao-shengong")
                return notify_fail("��ʹ�ñ����ķ�!\n");

   

        if((int)me->query_skill("bitao-shengong",1) < 100)
                return notify_fail("��ı����ķ�������������\n"); 
                
                
        sword_level=(int)(snowsword/50);
        if( snowsword < 50)
                return notify_fail("��ķ��ѩ�轣�����𻹲�����ʹ����һ�л������ѣ�\n");


        if((int)me->query("neili") < 500 )
                return notify_fail("����������㣡\n");


        
        if( bufa < 50)
                return notify_fail("��ı��Ų������𻹲�����ʹ����һ�л������ѣ�\n");
                

        
  //      if( time()-(int)me->query_temp("wuxue_end") < 3 )
  //              return notify_fail("�����ö�Ͳ����ˣ�\n");
                
        if ( sword_level <= 1 ) desc_msg = "" ; 
        else desc_msg = chinese_number(sword_level);
        if ( sword_level > 9 ) desc_msg = "��";
   



        ini_damage_apply = me->query_temp("apply/damage");
        me->add_temp("apply/attack", 200);	
        me->add_temp("apply/damage", 2200);
        message_vision(HIW"\n$N��߳һ�����ż�һ�㣬���弱���������ڰ����һ��������
ͬʱ�����ᶶ�������������������ѩ����$n��\n"NOR,me,target);
        target->start_busy(2);
        damage=1;
        //ǰ����
        message_vision(HIC"\n$Nͬʱʹ�����ѩ�轣��ǰ���У��ڰ����ѹ��$n��\n"NOR,me,target);
        
        me->set_temp("WX_perform", 5);
        damage=COMBAT_D->do_attack(me, target, me->query_temp("weapon"));


        damage=COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        

        me->set_temp("WX_perform", 6);
        damage=COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        //������
        if( snowsword > 99 && f > 99 && bufa > 99 )
           {
                message_vision(HIC"\n$N����бб����Ʈ����Ҳ����ͷ�����־ʹ̳������С�\n"NOR,me);
                
                
                
                me->set_temp("WX_perform", 7);
                damage=COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
             

                me->set_temp("WX_perform", 8);
                damage=COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        }
      
        //�������
        if( snowsword > 149 && f > 149 && bufa > 149 )
        {
                message_vision(HIC"\n$Nббһ�ٸ�������������ǧ��֧����������һ�ɺ�������$n��\n"NOR,me,target);
                    

                me->set_temp("WX_perform", 9);
                damage=COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
   

                me->set_temp("WX_perform", 10);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
            
                    
        }
        me->add_temp("apply/attack", -200);	               
        me->delete_temp("WX_perform");
        me->add_temp("apply/damage",-2200);


if (snowsword> 600)
{
         message_vision(HIY"\n$N˫�ֺ�ʮ��������ʣ�\n" NOR,me,target);
message_vision(HIC"\n��һ�ж����ᣬ�޳��ѵþá�\n"NOR,me,target);
message_vision(HIC"\n  ������η�壬��Σ�ڳ�¶��\n"NOR,me,target);
message_vision(HIC"\n  �ɰ������ǣ��ɰ���������\n"NOR,me,target);
message_vision(HIC"\n  �����ڰ��ߣ��������޲�����\n"NOR,me,target);
message_vision(HIB"\n $N̾��:��Ү?��Ү?��������......
��Ȼ��ʽһ������һƬ����,�Ʋʵ����ɰ�����$n\n\n"NOR,me,target);
   

                 
        ap = me->query_skill("snowsword", 1);
        ap = ap * ap * ap /10;
        ap = ap + (int)me->query("combat_exp");
        dp = target->query_skill("parry");
        dp = dp * dp * dp /20;   
        dp = dp + target->query("combat_exp");
        dp = dp*qi_pcg/50;  
        if( random(ap + dp) <  dp ) {
                            message_vision(HIW"$nһ�����Ʋ��һ����Ծ,����Ȧ�⡣\n"NOR, me, target);
         } else {
dmg=target->query("qi")/2;
if (dmg > 20000) dmg=20000;
                  target->receive_damage("qi",dmg,me);

                   message_vision(HIM "$n��������,�����е���һֻ�ʵ����������\n"NOR, me, target);
                   COMBAT_D->report_status(target); 
           }
        
}       
        

if (snowsword> 800)
   

{
            msg = HIW"\n$N����һҧ��ͻȻ�߸���������ȫ�������˽���һ��"
                 +"����һ���׹⣬���������$n��\n" NOR;
        ap = me->query_skill("snowsword", 1);
        ap = ap * ap * ap /10;
        ap = ap + (int)me->query("combat_exp");
        dp = target->query_skill("parry");
        dp = dp * dp * dp /10;   
        dp = dp + target->query("combat_exp");
        dp = dp*qi_pcg/50;  //more badly you're hurt, more chance you will succeed
        if( random(ap + dp) <  dp ) {
                msg += HIW "$nһ�����Ʋ����æ�͵�һ��������ǧ��һ��֮�ʶ������һ����ȴҲ�Ǳ��������ŵû����ɢ��һʱ�䶯�����á�\n"NOR;
                message_vision(msg, me, target);
         } 
         else {
dmg=target->query("qi")/2;
if (dmg > 20000) dmg=20000;
                target->receive_wound("qi",dmg);
                msg += HIW "$n����$N��˾�����Ϊ���������壬��Ȼ���ڵ��أ������мܡ�\n
˵ʱ�٣���ʱ�죬����׹�����$n���ϵ��ش�����\n"NOR;
                message_vision(msg, me, target);



                COMBAT_D->report_status(target); 
         }
    
}       


me->add("neili", -100);
me->start_busy(2);
        //me->set_temp("wuxue_end",time());
        return 1;
}
