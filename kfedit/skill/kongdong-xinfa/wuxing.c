#include <ansi.h>

inherit F_SSERVER;
void doblow(object);
int random_go(object victim,string* dirs);

int exert(object me)
{
        string msg,start;
        int busy_time, ap, dp ,msgnum ,damage;
object target;

        if( !target ) target = offensive_target(me);
        if ( !me->is_fighting() && !target) target=me;

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse() )
                return notify_fail("��Ҫ��˭ʩչ���������\n");

if ( target != me ) {
        if ( !me->is_fighting() )
                return notify_fail("�������ֻ����ս����ʹ�ã�\n");
   

}



        if((int)me->query_skill("taiyi",1) < 100)
                return notify_fail("���̫�ҵ���������������\n");

        if((int)me->query_skill("kongdong-xinfa",1) < 100)
                return notify_fail("�������ķ�������������\n"); 




        if ( target == me ) {

                if((int)me->query("neili") < 100 )
                        return notify_fail("�������������\n");
                if((int)me->query("jing") < 100 )
                        return notify_fail("��ľ���û�а취��Ч���У�\n");


 if (me->is_busy())
                return notify_fail("��������æ��\n");
   

        if( me->is_fighting() )
                return notify_fail("ս�����޷�ʹ������ת����\n");
        if( me->is_ghost())
                return notify_fail("����޷�ʹ������ת����\n");

        if(environment(me)->query("no_fly")||environment(me)->query("no_death_penalty")
                || environment(me)->query("no_fly"))
                return notify_fail("�˵ز���ʹ������ת����\n");  

if( !environment(me)->query("no_fight"))
return notify_fail("ֻ�а�ȫ�ص����ʹ������ת����\n");  

if(environment(me)->query("short")==BLU"ɽ��"NOR
       ||environment(me)->query("short")==WHT"����ʯ��"NOR
       ||environment(me)->query("short")==YEL"�Ҷ�"NOR
       ||environment(me)->query("short")==RED"���Ҷ�"NOR
       ||environment(me)->query("short")==CYN"ʯ��"NOR
       ||environment(me)->query("magicroom")
       ||environment(me)->query("maze")      
       )
return notify_fail("ֻ�а�ȫ�ص����ʹ������ת����\n");   

                me->add("neili", -100);
   

                me->receive_damage("jing", 10);

                if( random(me->query_skill("taiyi")) < 20 ) {
                        
                        write("��ʧ���ˡ�\n");
                        return 1;
                }
        msgnum = random(5);
        switch ( msgnum ) {
        case 0:
            msg = WHT "$N�����૵��������ģ���Ȼ���һ����������\n"  +
            "ֻ��$N����һ����������Ӱ���ٵ���ʧ�ˣ�\n\n"NOR ;
            break ;
        case 1:
            msg = HIY "$N�����૵��������ģ���Ȼ���һ����������\n"  +
            "ֻ��$N����һ����⣬ವ�һ�������ˣ�\n\n"NOR ;
            break ;
        case 2:
            msg = HIR "$N�����૵��������ģ���Ȼ���һ����������\n"  +
            "ֻ��$N����һ�Ż��棬Ȼ����ʧ����Ӱ���٣�\n\n"NOR ;
            break ;
        case 3:
            msg = HIG "$N�����૵��������ģ���Ȼ���һ����������\n"  +
   

            "ֻ��$N����һ�ο�ľ�������Ѳ�֪ȥ��\n\n"NOR ;
            break ;
        case 4:
            msg = BLU "$N�����૵��������ģ���Ȼ���һ����������\n"  +
            "ֻ��$N����һ�Ŵ�����֪Ʈ������ȥ�ˣ�\n\n"NOR ;
            break ;
        }

        message_vision(msg, me);


        switch ( msgnum ) {
        case 0:
            start="/d/death/mengpo";
            message("vision", WHT+me->name()+"����Ӱ��һ�ź�����������Ρ�\n"NOR,
              environment(me), me);
            tell_object(me, WHT"�����ӰͻȻ������һ�ź����С�\n"NOR);
            break ;
        case 1:
            start="/d/city/wumiao";
            message("vision", HIY+me->name()+"ͻȻ��һ����������˳�����\n"NOR,
              environment(me), me);
            tell_object(me, HIY"�����ӰͻȻ������һ������С�\n"NOR);
   




            break ;
        case 2:
            start="/d/xibei/kongdong/xuanyuan_gong";
            message("vision", HIR+"ͻȻ���һ��,"+me->name()+"����ð�˳�����\n"NOR,
              environment(me), me);
            tell_object(me, HIR"�����ӰͻȻ������һ�Ż����С�\n"NOR);
            break ;
        case 3:
            start="/d/wudang/sanqingdian";
            message("vision", HIG+"ֻ��һ�ο�ľ�ѿ�,"+me->name()+"�������˳�����\n"NOR,
              environment(me), me);
            tell_object(me, HIG"�����ӰͻȻ������һ�ο�ľ�С�\n"NOR);
            break ;
        case 4:
            start="/d/kunlun/jingshenfeng";
            message("vision", BLU+"һ��Ũ��Ʈ���������"+me->name()+"�����Ρ�\n"NOR,
              environment(me), me);
            tell_object(me, BLU"�����ӰͻȻ������һ��Ũ���С�\n"NOR);
            break ;
        }
        me->move(start);
me->start_busy(5);
        return 2+random(3);
   
        }

        if((int)me->query_skill("taiyi") < 100)
                return notify_fail("���̫�ҵ���������������\n");

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("���ž�ѧֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if((int)me->query_skill("kongdong-xinfa",1) < 100)
                return notify_fail("�������ķ�������������\n"); 

        if((int)me->query("neili") < 200 )
                return notify_fail("�������������\n");
    
        if((int)me->query("jing") < 200 )
                return notify_fail("��ľ���û�а취��Ч���У�\n");

        me->add("neili", -200);
        me->receive_damage("jing", 20);
   
        if( random(me->query_skill("taiyi")) < 40 ) {
                write("��ʧ���ˡ�\n");
                return 1;
        }

        if  (target->is_busy() ) 
        { 
                msgnum = random(4);}
                else  msgnum = random(5) ;
                switch ( msgnum ) {
                case 4:    
                        msg = WHT "$N�����૵��������ģ���Ȼ���һ����������\n"  +
                        "ֻ��һ�ź�������$n���ϣ�\n\n"NOR ;
                        ap = me->query_skill("taiyi");
                        ap = ( ap * ap * ap / (4 * 400) ) * (int)me->query("jing");
                        ap += (int)me->query("combat_exp");
                        dp = target->query_skill("taiyi");
                        dp = dp * dp * dp ;
                        dp += (int)target->query("combat_exp");
                        break ;
                case 1:
                        msg = HIY "$N�����૵��������ģ���Ȼ���һ����������\n"  +
                           "ֻ��һ���������$n��\n\n"NOR ;
                        ap = me->query_skill("taiyi");
                        ap = ( ap * ap * ap / 800 ) * (int)me->query("qi");
                        ap += (int)me->query("combat_exp");
                        dp = target->query_skill("taiyi");
                        dp = dp * dp * dp ;
                        dp += (int)target->query("combat_exp");
                        break;
                case 2:
                        msg = HIR "$N�����૵��������ģ���Ȼ���һ����������\n"  +
                        "ֻ��һ�Ż���ֱ��$n��\n\n"NOR ;
                        ap = me->query_skill("taiyi");
                        ap = ( ap * ap * ap / 1600 ) * (int)me->query("jing");
                        ap += (int)me->query("combat_exp"); 
                        dp = target->query_skill("taiyi");
                        dp = dp * dp * dp ;
                        dp += (int)target->query("combat_exp");

                        break;
                case 3:
                        msg = HIG "$N�����૵��������ģ���Ȼ���һ����������\n"  +
                        "ֻ����������������ľ����$n��ͷ���£�\n\n"NOR ;
                        ap = me->query_skill("taiyi");
   


                        ap = ( ap * ap * ap / 1200 ) * (int)me->query("max_neili");
                        ap += (int)me->query("combat_exp"); 
                        dp = target->query_skill("taiyi");
                        dp = dp * dp * dp ;
                        dp += (int)target->query("combat_exp");
                        break;
                case 0:
                        msg = BLU "$N�����૵��������ģ���Ȼ���һ����������\n"  +
                        "ֻ��һ����Х��һ�ɾ�������$n������\n\n"NOR ;
                        ap = me->query_skill("taiyi");
                        ap = ( ap * ap * ap / 2400 ) * (int)me->query("neili");
                        ap += (int)me->query("combat_exp"); 
                        dp = target->query_skill("taiyi");
                        dp = dp * dp * dp ;
                        dp += (int)target->query("combat_exp");
                        break;
                }
                if( random(ap + dp) > dp )  {

                        switch (msgnum) {

                        case 4:

                                busy_time  += (int)me->query("force_factor")/50;
                                   if ( busy_time < 0 ) busy_time = 0 ;
                                if (busy_time > 7) busy_time =8;            
                                target->start_busy(busy_time+2);
                                msg +=  WHT "\n$n���������֣�ֻ�������ܻ����ɵ�һƬ��ʲôҲ���������\n" NOR;
                                break;
                        case 1:
                                damage = 200+(int)me->query("max_neili") / 10
                                + random((int)me->query("eff_qi") / 3);
                                damage -= (int)target->query("max_neili") / 15
                                + random((int)target->query("eff_qi") / 4);
                                damage += (int)me->query("force_factor")
                                - (int)target->query("force_factor");
                                if (damage > 0) msg +=  HIY "\n������͡���һ��������$n����͸�������
                 \n�ϳ�һ��������Ѫ����ֱ�䵽��������ĵ��£�\n" NOR;
                                if (damage <= 0 ) 
                                {
                                        msg += HIY "\n����$n����Ӳ������һ�£����޴� ��\n" NOR;
                                        damage =10;
                                }
                                if (damage > 0) damage +=random((damage*(int)me->query_skill("taiyi"))/100);
                                if (damage >25000) damage=25000;
                                	
                                
                                               	if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
                       
                                if (damage > 0) target->receive_damage("qi", damage,me);
                                if (damage > 0) target->receive_wound("qi", damage/4,me);
                                break;
                           case 2:
                                damage = 100+(int)me->query("max_neili") / 10 +
                                random((int)me->query("eff_jing") / 5);
                                damage -= (int)target->query("max_neili") / 15 +
                                random((int)target->query("eff_jing") / 8);
                                damage+=(int)me->query("force_factor")-(int)target->query("force_factor");
                                if( damage > 0 ) msg +=  HIR "\n$n�����һ�ƣ�ֻ�����ۻ����ң����񲻶�������ε��ڵأ�\n" NOR;
                                if ( damage <=0 ) 
                                {
                                        msg += HIR "\n$nǿ�����񣬾�Ȼû��̫���Ӱ�졣\n" NOR; 
                                        damage = 20;
                                 }
                                damage +=random((damage*(int)me->query_skill("taiyi"))/100);
                                 if (damage >25000) damage=25000;
                                	
                                               	if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;

 
                                target->receive_damage("jing", damage,me);
                                target->receive_wound("jing", damage/3,me);
                
                                break;
                        case 3:
                                damage = (int)me->query("max_neili") / 20 +
                                random((int)me->query("max_neili") / 10);
                                damage -= (int)target->query("max_neili") / 30 +
                                random((int)target->query("eff_neili") / 15);   
                                damage +=(int)me->query("force_factor")-(int)target->query("force_factor");
   






                                if( damage > 0 ) msg +=  HIG "\n$n����ľ�Ҹ����ţ��ƺ�����Щ���ˣ�\n" NOR;
                                if ( damage <=0 ) 
                                { 
                                        msg += HIG "\n$n���Ʋ������������ƺ�ֻ���˵���ˡ�\n" NOR; 
                                        damage =5;
                                }
                                damage +=random((damage*(int)me->query_skill("taiyi"))/100);
  
  if (damage >25000) damage=25000;
                                if (( damage > 0 ) && (damage >=(int)target->query("neili"))) target->set("neili", 0); 
                                if ((damage >0) && (damage < (int)target->query("neili"))) target->add("neili", -damage);
        
                                break;  
                        case 0:
                                damage = (int)me->query("max_neili") / 10 +
                                random((int)me->query("max_neili") / 10);
                                damage -= (int)target->query("max_neili") / 15 +
                                random((int)target->query("max_neili") / 15);
                                damage+=(int)me->query("force_factor")-(int)target->query("force_factor");
                                if( damage > 0 ) msg +=  BLU "\n$n�������ܵ���������������Ҳ��ʧ�˲��٣�\n" NOR;
                                if ( damage <=0 ) 
                                { 
                                        msg += BLU "\n$n�����е�յ����ģ��ƺ��������˵�Ӱ�졣\n" NOR; 
                                        damage = 10 ;
                                }
                                
                                 
                                	

                                   if( damage > 0 ) damage +=random((damage*(int)me->query_skill("taiyi"))/100);
                                   	if (damage >25000) damage=25000;
                                if (( damage > 0 ) && (damage >=(int)target->query("neili"))) target-> set("neili", 0);
                                if (( damage > 0 ) && (damage < (int)target->query("neili"))) target-> add("neili", -damage);
                                target->start_busy(5);
                                break;
                        }
                } else {
                msg += "����$n����һԾ���㿪����һ����\n";
        
        }
        message_vision(msg, me, target);
        if( ( damage > 0 ) && ( msgnum == 1 ))COMBAT_D->report_status(target);
        if( ( damage > 0 ) && ( msgnum == 2 ))COMBAT_D->report_sen_status(target);
me->start_busy(3);
        return 3+random(3);
}