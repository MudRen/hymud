// onlyu.c by greenwc
#include <ansi.h>

inherit F_SSERVER;

int exert(object me)
{
        int ap,dp,damage,success,skill;
object target;
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʹ�÷�⣿\n");

        if((int)me->query("neili") < 500)
                return notify_fail("�������������\n");

        if((int)me->query("jing") < 200 )
                return notify_fail("���޷����о�����\n");


      if( !target ) target = offensive_target(me);
   	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���ž�ѧֻ�ܶ�ս���еĶ���ʹ�á�\n");
		
		        if((int)me->query_skill("buddhism",1) < 100)
                return notify_fail("��������ķ�������������\n");

        if((int)me->query_skill("bitao-shengong",1) < 100)
                return notify_fail("��ı����ķ�������������\n"); 

        me->add("neili", -200);

        if( random(me->query("max_neili")) < 100 ) {
                write("�����ź��˼���������ôҲ�Ҳ��ŵ���\n");
                return 1;
        }
skill=(int)me->query_skill("bitao-shengong",1);
        ap = (int)me->query_skill("bitao-shengong");
        ap = ap * ap * ap /10 ;
        ap += (int)me->query("combat_exp");
        dp = (int)target->query("combat_exp");
            success=0;
           damage=100+((int)me->query_skill("buddhism",1)+random((int)me->query_skill("bitao-shengong",1)/5));
            message_vision(HIY"\n$N��Ȼ����սȦ����$n�����"NOR,me,target);
        message_vision(HIY"\n$N������࣬Խ��Խ�ǳ�Ͱ�����ȫ����������ʥ��Ĺ�ԡ�"NOR,me,target);
            message_vision(HIC"\n��ğo�����������q��ó��T���󡣻������R����o���︣�Կ՟o��ס��"NOR,me,target);
            if (random(ap+dp) > dp )
{            
                   success += 1;
                message_vision(
                 "\n $nͻȻ��ɫ�԰ף��ƺ�������֧����Ż��һ��Ѫ����",
                 me, target );
if (userp(target) && damage > target->query("jing",1)/2) damage=target->query("jing",1)/2;
            target->receive_wound("jing",damage/3,me);
            target->receive_damage("jing",damage*2/3,me);
}
            message_vision(HIG"\n���T�Ʒ����ǻã����T���I���ǻá������ĭ�����L���ó��o���o���ԡ�"NOR,me,target);  
          if (random(ap+dp) > dp )
{            success += 1;

                message_vision(
                 "\n $nͻȻ��ɫ�԰ף��ƺ�������֧����Ż��һ��Ѫ����",
                 me, target );
            damage=damage+100;
            if (userp(target) && damage > target->query("jing",1)) damage=target->query("jing",1)/2;
            target->receive_wound("jing",damage/3,me);
            target->receive_damage("jing",damage*2/3,me);
}
            message_vision(HIR"\n�ٽ��Ĵ��Ԟ����ı��o�����У�ǰ�����o�����o���︣��������硣"NOR,me,target);
                       if (random(ap+dp) > dp )
{           success += 1;
                message_vision(
                 "\n $nͻȻ��ɫ�԰ף��ƺ�������֧����Ż��һ��Ѫ����",
                 me, target );
damage=damage+100;
if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
            target->receive_wound("qi",damage,me);
            target->receive_damage("qi",damage*2,me);
}

if (skill > 200)
{	
            message_vision(HIW"\nҊ��o���Ƿ�����������Ƿ�ã��˵����ı��Կգ�˹���c�����e��"NOR,me,target);
                        if (random(ap+dp) > dp )
{            success += 1;
                message_vision(
                 "\n $nͻȻ��ɫ�԰ף��ƺ�������֧����Ż��һ��Ѫ����",
                 me, target );
damage=damage+100;
if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
            target->receive_wound("qi",damage,me);
            target->receive_damage("qi",damage*2,me);
}
            message_vision(RED"\n��Ҋ��֪�Ƿ�����֪�e�o��������֪���Կգ�̹Ȼ�����������"NOR,me,target);
                        if (random(ap+dp) > dp )
{           success += 1;
                message_vision(
                 "\n $nͻȻ��ɫ�԰ף��ƺ�������֧����Ż��һ��Ѫ����",
                 me, target );
damage=damage+100;
if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
            target->receive_wound("qi",damage,me);
            target->receive_damage("qi",damage*2,me);
}
            message_vision(GRN"\nһ����������Q���ı��o���o�ɜ磬���������ǻ������û�֮�Пo�︣��"NOR,me,target);
                       if (random(ap+dp) > dp )
{            success += 1;
                message_vision(
                 "\n $nͻȻ��ɫ�԰ף��ƺ�������֧����Ż��һ��Ѫ����",
                 me, target );
damage=damage+100;
if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
            target->receive_wound("qi",damage,me);
            target->receive_damage("qi",damage*2,me);
}
}

if (skill > 250)
{	
            message_vision(YEL"\n�������o�����o�����෨���񸶟o���r��������������"NOR,me,target);
                       if (random(ap+dp) > dp )
{           success += 1;
                 message_vision(
                 "\n $nͻȻ��ɫ�԰ף��ƺ�������֧����Ż��һ��Ѫ����",
                 me, target );
damage=damage+100;
 target->add("neili",-damage*3);
 if ((int)target->query("neili")<=0) target->set("neili",0);
 	if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
            target->receive_wound("qi",damage/3,me);
            target->receive_damage("qi",damage*2/3,me);
}

}

if (skill > 300)
{	
            message_vision(HIB"\n�T�Пo���������編��������ѣ��Ŝ�阷��"NOR,me,target);
                        if (random(ap+dp) > dp )
{           success += 1;
                message_vision(
                 "\n $nͻȻ��ɫ�԰ף��ƺ�������֧����Ż��һ��Ѫ����",
                 me, target );
damage=damage+100;
target->add("neili",-damage*3);
 if ((int)target->query("neili")<=0) target->set("neili",0);
 	if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
            target->receive_wound("qi",damage/3,me);
            target->receive_damage("qi",damage*2/3,me);
}
}

if (skill > 350)
{	
       message_vision(WHT"\n�����T�͟룬�����»�k��Ո���������A�S��ɫ��"NOR,me,target);
                        if (random(ap+dp) > dp )
{           success += 1;
                message_vision(
                 "\n $nͻȻ��ɫ�԰ף��ƺ�������֧����Ż��һ��Ѫ����",
                 me, target );
damage=damage+100;
target->add("neili",-damage*3);
 if ((int)target->query("neili")<=0) target->set("neili",0);
 	if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
            target->receive_wound("qi",damage/3,me);
            target->receive_damage("qi",damage*2/3,me);
}
}

if (skill > 400 || !userp(me))
{	
            message_vision(BLU"\n�������������Ե�־�̨������������������޳�����"NOR,me,target);
                        if (random(ap+dp) > dp )
{           success += 1;
                message_vision(
                 "\n $nͻȻ��ɫ�԰ף��ƺ�������֧����Ż��һ��Ѫ����",
                 me, target );
damage=damage+100;
target->start_busy(3);
target->add("neili",-damage*3);
 if ((int)target->query("neili")<=0) target->set("neili",0);
  	if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
            target->receive_wound("qi",damage/3,me);
            target->receive_damage("qi",damage*2/3,me);
}

      }    
            if (success=0) message_vision(HIW"\n$n����һ�������������� ��\n"NOR,me,target);
           else if (success > 5) message_vision(HIB"\n$n������ͷʹ���ѣ�����û����ս��������\n"NOR,me,target);
            else message_vision(HIB"\n$n������ͷ�����������Լ���������\n"NOR,me,target);
            

        me->start_busy(2+random(2));
        return 3+random(5);
}
