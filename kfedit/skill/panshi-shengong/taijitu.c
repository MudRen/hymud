// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */

//taijitu.c

#include <ansi.h>

inherit F_SSERVER;

string get_name(string str)
{
        str="̫��ͼ";
        return str;
}



int check_damage(object me, object target, int time);
int generate_msg(object me);

int exert(object me)
{
        int time;
        string msg;
        object target;
        int damage, ap, dp,qixue,eff_qi,max_qi,qi_pcg,j;

        if( !target ) target = offensive_target(me);


        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ̫��ͼ��\n");

   if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ̫��ͼ��\n");

        if((int)me->query_skill("panshi-shengong",1) < 200)
                return notify_fail("�����ʯ�񹦲��㣡\n");
             
        if((int)me->query_skill("taoism",1) < 200)
                return notify_fail("��Ļ���������������������̫��ͼ��\n");
        if( me->query_temp("cast_taiji"))
                return notify_fail("���Ѿ���ʹ��̫��ͼ��\n");        

        if((int)me->query("neili") < 2500 )
                return notify_fail("��ķ���������\n");
        if((int)me->query("jing") < 500 )
                return notify_fail("���޷����о�����\n");
     
        me->add("neili", -2*(int)me->query_skill("taoism"));
        me->receive_damage("jing", 200);
        if( random(me->query("max_neili")) < 500 ) 
        {
                write("��ʧ���ˣ�\n");
                return 1;
        }
        me->set_temp("cast_taiji",1);
        message_vision(HIR "\n$N�������˾����ģ����һ����߾����������̫�����Ρ�������\n���н��ƶ���Ѹ��������������$N��������ȥ,��Χ��ʱɱ���ķ���\n"
        NOR,me,target);
        //me->set("env/invisibility", 1);
        time=(int)me->query_skill("panshi-shengong",1)/10 ;
if ((int)me->query_skill("panshi-shengong",1)> 600)
{
	
if (random(3)==0 && userp(me))
{
	      me->set("qi",me->query("max_qi"));
	      me->set("eff_qi",me->query("max_qi"));
        me->set("jing",me->query("max_jing"));
        me->set("eff_jing",me->query("max_jing"));
me->add("neili",-300);
}
        

        msg = HIR"\nֻ��һ�����ȣ�$N��������һָ�������������ף����������׵�֮��
���Լ�һ�������߶����׵�ʹ��һ�з��컯�صġ�������

                     ������
                     ���쩧
                     ������
                       ��
                     ������
                     ���ש�
                     ������
                       ��
                     ������
                     ���٩�
                     ������
                       ��
                     ������
                     ����
                     ������
"
                 +"�׵绯��һ���һ𣬰�����$n��\n" NOR;
        ap = me->query_skill("panshi-shengong", 1);
        ap = ap * ap * ap /10;
        ap = ap + (int)me->query("combat_exp");
        dp = target->query_skill("parry",1);
        dp = dp * dp * dp /10;   
        dp = dp + target->query("combat_exp");
        dp = dp*qi_pcg/50;
        if( random(ap + dp) <  dp ) {
              msg += HIB "$nһ�����Ʋ����æ�͵�һ��������ǧ��һ��֮�ʶ������һ����ȴҲ�Ǳ��������ŵû����ɢ��һʱ�䶯�����á�\n"NOR;
              message_vision(msg, me, target);
         } else {
                  j=(int)me->query("max_neili")/20;
                  if (j>1500) j=1500;
                  damage=500+(int)me->query_skill("panshi-shengong",1)*3+j;
                  if (damage > 32000) damage=32000;
                  if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
                  target->receive_wound("qi",damage,me);
                  msg += HIR "$n����$N�����һ�У�Ϊ���������壬��Ȼ���ڵ��أ������мܡ�\n
˵ʱ�٣���ʱ�죬����׹�����$n���ϵ��ش�����\n"NOR;
                   message_vision(msg, me, target);
                   COMBAT_D->report_status(target); 
           }
          me->start_busy(3);

}		
	

        if(time>30) time=30;
        check_damage(me, target, time);
        me->start_busy(3);
        return 10+random(5);

}

int check_damage(object me, object target, int time)
{
        int ap,dp,damage,success,j;

        if( !target
        || !me 
        || environment(me) != environment(target)) 
        {
                remove_call_out("check_damage");
                if (me) me->delete_temp("cast_taiji");
                //me->set("env/invisibility", 0);
                return 1;
        }

        if( !target
        || !me 
        || environment(me) != environment(target)) 
        {
                remove_call_out("check_damage");
                me->delete_temp("cast_taiji");
                //me->set("env/invisibility", 0);
                return 1;
        }

        ap= (int)me->query_skill("taoism",1);
        ap= ap*ap*ap/10;
        ap= ap+(int)me->query("combat_exp",1);

        dp= (int)target->query_skill("parry",1);
        dp= dp*dp*dp/10;
        dp= dp+(int)target->query("combat_exp",1);
        j=(int)me->query("max_neili",1)/20;
        if (j>1500) j=1500;
        damage=(int)me->query_skill("panshi-shengong",1)+j;
        success=1;
        if( damage < 0 ) success = 0;
        if( random(ap+dp) < dp ) success = 0;
        if( (int)me->query("neili") < 30 ) success = 0;
        if( (int)me->query("qi")  < 30 ) success = 0;
        if( environment(me)->query("no_fight")
        || environment(me)->query("no_magic") ) success = 0;

        if( success )
        {
                if(random(2))
                {
                        message_vision(HIC"\n�Ʋ���������������ֵĹ�����ɽ�������󴸳�$n������\n"NOR,me,target);
                        message_vision(HIR"\n$n���ɽ��Ĵ��ҵ����ΰ��أ����ˤ���ڵأ�\n"NOR, me, target);
                        if (damage > 28000) damage=28000;
                        if (!target->is_busy()) target->start_busy(1);
                        if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
                        target->receive_damage("qi", damage,me);
                        target->receive_wound("qi", damage/2,me);
                        COMBAT_D->report_status(target);
                        me->receive_damage("jing", 25);
                        me->add("neili", -25);
                        //if(!me->is_busy()) me->start_busy(2); 
                } 
                else 
                {
                        message_vision(HIC"\n�׹���ĸ˫˫��������ʱ���ɳ��ʯ��\n"NOR, me, target);
                        message_vision(HIR"\n$n���������ò��վ�����ȣ����ǲ����ˣ�\n"NOR, me, target);
                       if (damage > 25000) damage=25000;
                       if (damage > target->query("eff_jing")/2) damage=target->query("eff_jing")/2;
                        if (!target->is_busy()) target->start_busy(1);
                        target->receive_damage("jing", damage,me);
                        target->receive_wound("jing", damage/2,me);
                        COMBAT_D->report_sen_status(target);
                        me->receive_damage("jing", 25);
                        me->add("neili", -25);
                        //if(!me->is_busy()) me->start_busy(2);      
                }
        }
        time--;
        if( time ) 
        {
                call_out("generate_msg", 4, me);
                call_out("check_damage", 8, me, target, time);
        }
        else 
        {
                me->delete_temp("cast_taiji");
                //me->set("env/invisibility", 0);
                return 1;
        }
      
        return 1;
}

int generate_msg(object me)
{
        string *msgs=({
                HIR"\n������Ӱ���أ������ɽ�����������\n"NOR,
                HIY"\n�����Ʈ���Ŵ��죬������ա���\n"NOR,
                HIB"\n��ػ����У����������Ĵ�������\n"NOR,
                MAG"\n��Χ������Ӱ���Ѿ�����������򡭡�\n"NOR,
        });
        if( !me ) return 1;
        tell_room( environment(me), msgs[random(sizeof(msgs))]);
        return 1;
}

