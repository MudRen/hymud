// �߽�����ָ By cigar 2002.04.23
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";
int perform(object me, object target)
{
        object weapon;
        string dodskill,msg;            
             
        int damage, p;  
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С��߽�����ָ����\n");


        if(!me->is_fighting())
                return notify_fail("���߽�����ָ��ֻ����ս����ʹ�ã�\n");

        if((int)me->query("max_neili") < 500 )
                return notify_fail("�������������\n");

        if((int)me->query("neili") < 500 )
                return notify_fail("����������㣡\n");

        if((int)me->query("jing") < 500 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");

if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("ֻ����ս����ʹ�á�\n");

 if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
        return notify_fail(RED"��ʲô��Ц���������ԣ�\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "honghua-shengong")
                return notify_fail("��ʹ�ú컨��!\n");

        if((int)me->query_skill("honghua-shengong",1) < 200)
                return notify_fail("��ĺ컨�񹦻�����������\n"); 


        if((int)me->query_skill("bainiao-jian", 1) < 150)
                return notify_fail("��İ��񽣷����𻹲�����ʹ����һ�л������ѣ�\n");




        message_vision(HIC"\n$Nʹ���߽�����ָ������һת������ʳָ���ŵ�����ֻ������ָ�������ӳ��ֱϮ$n��\n"NOR,me,target);
       me->add_temp("apply/attack", 100);    
        me->add_temp("apply/damage", 1800);
            target->start_busy(1);
        msg=HIC"$N��ȻһЦ������֮��������Ȼ�ӿ죡"NOR;
        me->set_temp("QJB_perform", 1);
            COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg=HIC"$N�鼱��������ָ��$n���۴�ȥ����"NOR;
        me->set_temp("QJB_perform", 2);  
     COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg=HIC"$N˫�ֺ�ʮ��������Ȼ����һ�֣�˫�ƶ�ʱ�������Ʈ�ݣ��鶯�쳣��"NOR;
        me->set_temp("QJB_perform", 3);
             COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        
        msg=HIC"$N��һ��ʹ�ý����ݺᣬ��Ȼ����ɽ�ȡ���������֮�ˣ��޲����죡��"NOR;
        me->set_temp("QJB_perform", 4);
     COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        
        msg=HIC"$N����������������ƻã�����$n��ô�������������Ǳ����˳�ȥ��"NOR;
        me->set_temp("QJB_perform", 5);
             COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        
        msg=HIC"$N��ʱһ���ߺȣ����������Ѫ����������֮�ˣ��޲����죡"NOR;
        me->set_temp("QJB_perform", 6);
     COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        
        msg=HIC"ֻ����ž����һ����$N���е�����������������ѳ�����Ƭ������$n"NOR;
        me->set_temp("QJB_perform", 7);
     COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        me->delete_temp("QJB_perform");
       me->add_temp("apply/attack", -100);    
        me->add_temp("apply/damage", -1800);



        if ((int)me->query_skill("bainiao-jian",1) > 350)
        {
       tell_object(me, HIW"\n\n������ʹ��"BLU"�罣"HIW"������һ���������ʵ�����֮����ֱ��"+target->name()+"�ؿ�����ѨҪѨ��\n\n"NOR); 
//      if(random(me->query_skill("force"))*(me->query_temp("fengdao")+1) >
      if(random(me->query_skill("force"))*3/2 >
         random(target->query_skill("force"))){                
           damage = me->query_skill("force");
           damage = damage + random(damage) + random(damage);
           if(target->query_skill("force")-50 > me->query_skill("force"))
             damage = damage/2 + random(damage);
           if(target->query_skill("force") > me->query_skill("force")*2)
             damage = random(50);
           if(me->query_skill("force") > target->query_skill("force")*2)
             damage = damage+random(damage);
           if(damage > 600){
              tell_object(target, HIB"\n\nͻȻ֮�䣬һ���������ʡ���������������֮��ֱ�������ؿڵġ�����Ѩ���У�
"HIR"����ʱ֮�������Ϣ��ȫ�������ã�\n\n"NOR);
              target->start_busy(3);
              }
           else if(damage <= 50){
              damage = 10;
              tell_object(target, HIY"\nͻȻ֮�䣬һ�����������������֮��ֱ�����ؿڵ�����Ѩ��
�Һ��㻤���񹦱黤ȫ��������絶������ȴҲ���㲻�ã�\n\n"NOR);
              tell_object(me, HIY"�����˷罣���ھ��������Է����Ǻ��������ĵֵ���������\n\n"NOR);
              }
           else{
              tell_object(target, HIB"\nͻȻ֮�䣬һ�������絶���罣����ذ�����䣬ֱ�������ؿڵġ�����Ѩ���У�
"HIR"����ʱ֮�������Ϣ��ȫ�������ã�\n\n"NOR);
              target->start_busy(2);
              }
           target->receive_damage("qi", damage);
           target->receive_wound("qi", damage/3);
           target->add("neili", -damage/2); 
           p = (int)target->query("qi")*100/(int)target->query("max_qi");
           tell_room(environment(target), HIR + target->name()+"ͻȻȫ���͵�һ�������ֽ���������������ݷ�ʲô�����ؿڴ��ͻ���һ���Ƶģ�\n\n" NOR, ({ target })); 
           msg = damage_msg(damage, "����");
           msg += "( $n"+eff_status_msg(p)+" )\n"; 
           message_vision(msg, me, target);          
   
           me->start_busy(2);
           me->add("neili", -100);
           }
         
     else {       
          me->add("neili", -100);

          tell_object(me, HIY"����罣�ھ���û����"+target->name()+"��������Ѿ�ɢ�ˡ�\n\n"NOR);
      
          }
}
        me->receive_damage("jing", 100);
        me->add("neili", -100);

me->start_busy(3);
        return 1;
}


