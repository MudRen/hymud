//by dewbaby@sk_sjsh
//�����¡�

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;


int perform(object me, object target)
{
        object weapon,ob;
        string msg;
         int myexp,yourexp,youexp;
        int busy;    
        int hyjf, ap, dp, attp, defp;
        int damage;    
 
 

               string str; 


        
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ�����¾�ʽ����\n");
         
         
         
     if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�����¾�ʽ��ֻ����ս����ʹ�á�\n");

    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
        return notify_fail(RED"��ʲô��Ц���������ԣ�\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "taixuan-gong")
                return notify_fail("��ʹ��̫����!\n");

        if((int)me->query_skill("taixuan-gong",1) < 100)
                return notify_fail("���̫����������������\n"); 

        if((int)me->query_skill("bawang-qiang",1)+100 < (int)me->query_skill("sumi-jian",1))
                return notify_fail("������Ҫ�������ǹ�����⾳������\n"); 


        if ((int)me->query_skill("literate", 1)> 5 )
                return notify_fail("�����̫�������֮����һʱ��������ᡣ\n");
         
         if( environment(me)->query("no_fight") )
                return notify_fail("�����ﲻ�ܹ������ˡ�\n");

         if( (int)me->query_skill("sumi-jian", 1) < 120) 
                return notify_fail("������޽����������޷�ʹ�ô���!\n");

         hyjf = (int)me->query_skill("sumi-jian",1);

         if( (int)me->query_skill("sword",1) < hyjf)
                return notify_fail("��Ļ��������ȼ��������޷�ʹ�������¡� ��\n");

         if (me->query("neili") < 1300)
                return notify_fail("�������������޷�ʹ����һ�С�\n");

         me->clean_up_enemy();
         ob = me->select_opponent();
         myexp = (int) me->query("combat_exp");
         yourexp = (int) target->query("combat_exp");
         busy = (int)me->query_skill("parry",1)/54;
message_vision(HIY"\n$N�ڿ�Ծ������ָ�����죬�ڿ��л��˸�Բ�����ֽ������ƣ����಻��������"HIW"���͵�"HIY"ǧ�ž���"BLINK""HIR"����\n"NOR,me,target);        
    
message_vision(HIR"\n\n            ���µ�����˭������ÿ��ѽڸ���Բ��\n"NOR,me,target);
message_vision(HIR"\n\n            ��ĺ�����۾����𣬱�ˮ������������\n"NOR,me,target);
message_vision(HIR"\n\n            ����Ҷ���㼸���ᣬɽ���Ѿ�׼���ߡ�\n"NOR,me,target);
message_vision(HIR"\n\n            ������Ѿ�Ӧͣ�����ֿ��µ����꺮��\n"NOR,me,target);

         damage=100+(int)me->query_skill("parry")+random((int)me->query_skill("sword"));
         if(random(myexp)>yourexp/8)
         {
                
          msg = HIY "��������˭���ģ�ǧɽ���¿���ϧ����ҹ��������£�������������Ϧ.....��\n" NOR;
          message_vision(msg, me, target);
          target->start_busy(3);
          target->receive_damage("qi",damage,me);
          target->receive_wound("qi",damage/3,me);
          target->receive_damage("jing",damage,me);
          target->receive_wound("jing",damage/3+20,me);
          COMBAT_D->report_status(target);
      }
      else {
            message_vision(HIW"$n�������ģ�һ����Ц��������˾�����ϧ���Թ������³��¡���\n"NOR,me, target);
          me->start_busy(2);
          me->add("neili", -100);
  

  }
         
 if (hyjf> 300 && me && target)
 	{
  myexp = (int) me->query("combat_exp");
              youexp = (int) target->query("combat_exp");
                      
              msg = HIW "$Nʹ�����͵�"HIB"��������"WHT+"���б��������ֳ�˿˿"HIB+"����"WHT+"֮��\n\n" NOR; 
              message_vision(msg, me); 
       	me->add_temp("apply/attack", 90);
me->add_temp("apply/damage", 1000);
              //me->clean_up_enemy(); 
              ob = target; 
    if (random(2)==0) target->start_busy(3);
              message_vision(HIY"$N����Ѹ�����磬ȦȦ�������ϵ�ӿ��$n��\n"NOR, me, ob); 
              
              
              	msg = HIB "$N������ɽ�����Ϫˮ�ǣ���ҡ���������ʡ� ��\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
       
              message_vision(HIY"$Nһ��֮��ڶ����漴����$n"HIY+"��������æ���ҡ�\n"NOR, me, ob); 
  
                	msg = HIB "$N��Ȼ����������Ӧ˯Ϊ������ ��\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
  
                  	msg = HIB "$N��Ȼ��:���������ڹ�˭�͡� ��\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);

       
              message_vision(HIY"$N�Ų����������н���ȴ����ͣ�١�$n"HIY+"ֻ�ܰ��Խпࡣ\n"NOR, me, ob); 
                	msg = HIB "$N�����������������ÿҹԲ�� ��\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
  
                  	msg = HIB "$N�����:�����Ĳ��Ǽ������� ��\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
 
              message_vision(HIY"$Nת���ƹ�$n��"HIY+"��������һ��������������ꡣ\n"NOR, me, ob); 
                	msg = HIB "$Nӽ����������ֻ˵�������� ��\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
  
                  	msg = HIB "$Nӽ��:������ƫ���롣 ��\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
       
              message_vision(HIW"$N�����������֣���������Ӱ��$n�������Ƶ��޷�������\n"NOR, me, ob); 
              COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0); 
	me->add_temp("apply/attack", -90);
me->add_temp("apply/damage", -1000);
 	}	
if (hyjf > 600  && me && target)
{
         message_combatd( HIR "$N�����ڽ���Ĭ��������ֻ�������һ������Ȼ��������ҫ��$N����"+ weapon->name() + HIR"���ϻ�����\n"
         + "�أ���������ư���$n���������\n"NOR, me, target, "");

        attp = me->query_skill("taixuan-gong",1) + me->query_skill("sumi-jian",1);
        defp = target->query_skill("dodge");

//      if( random( attp ) > random( defp ) )
        if(  attp  > random( defp ) || random(3)==0)
        {
                damage = 800+me->query_skill("sumi-jian",1) + me->query_skill("sword",1)+ (int)me->query_skill("taixuan-gong", 1)*2;
                damage = damage - random( target->query_skill("dodge")/10 );

                target->receive_wound("jing", random( damage ),me);
                target->receive_damage("qi", 20 + random(damage)+damage,me);
                target->receive_wound("qi", 20 + damage, me);
                me->start_busy(3);
                target->start_busy(3 + random(4));
        }
        else 
        {
                message_combatd( HIY "����$p�ζ����Σ�Ѹ�ٵ�������������м��\n" NOR, me, target, "" );
                me->start_busy(2);
        }
	
me->add("neili", -50);
}		
	 	        
           me->start_busy(3);
if (msg && me && target)          message_vision(msg, me, target); 
     return 1;  
}


