// zuijiu.c ���

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{                                  
      int drunk, limit, i, lvl;
      	string msg;
        int extra;
      object weapon;
      
      if( !target ) target = offensive_target(me);
     
      if( !target || !me->is_fighting(target) || !living(target))
                return notify_fail("���������ֻ����ս���жԶ���ʹ�á�\n");

      if (!objectp(weapon = me->query_temp("weapon")) 
        || weapon->query("skill_type") != "club"
        || me->query_skill_mapped("club") != "weituo-chu")
                return notify_fail("�������޷�ʹ�á�������򡹡�\n");
                
            
      if( (int)me->query_skill("weituo-chu",1) < 100 )
                return notify_fail("������������죬����ʹ�á�������򡹣�\n");
      
      if( me->query_skill_mapped("force") != "yijinjing" )
                return notify_fail("��������ʹ���ڹ��޷�ʹ����������򡹡�\n");

      if( (int)me->query_skill("yijinjing",1) < 100 )
                return notify_fail("����׽�ȼ�����������ʹ�á�������򡹣�\n");  
       
      if( (int)me->query_str() < 25 )
                return notify_fail("��ı�������ǿ������ʹ�á�������򡹣�\n");
      
      if( (int)me->query("max_neili") < 1300 )
                return notify_fail("�������̫��������ʹ�á�������򡹣�\n");
            
      	limit = (me->query("con") + (int)me->query("max_neili") / 50) * 2;
      	lvl = (int)me->query_skill("weituo-chu", 1);

      	lvl /= 30;
      	lvl--;
      	if(lvl > 12) lvl = 12;  
      	if(lvl < 1) return notify_fail("��ĵȼ�̫�ͣ��޷�ʹ�ó���������򡹣�\n");

      	if( (int)me->query("neili") < 100*lvl )
                return notify_fail("�������̫���ˣ��޷�ʹ�ó���������򡹣�\n");
          
      	message_vision(HIY"\n$NͻȻһ�����ã���ʱ���žƾ��ʹ��������������\n"NOR,me);
extra=(int)me->query_skill("weituo-chu", 1)/4;
if (extra<10) extra=10;
if (extra>200) extra=200;

if (random(2)==0) target->start_busy(2);
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", 2000);
me->set_temp("noauto",1);
      	for(i=0; i < lvl; i++){
      	   	if(!me->is_killing(target) 
      	   	&& !target->is_killing(me)
      	   	&& !target->is_fighting(me))
      	   	break;

	msg = HIR  "$NͻȻһ�����ã���֪�Ӻδ������"+(i+1)+"����\n" NOR;     
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
      	}
	me->set_temp("noauto",0);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -2000);
if (extra> 50)
{
	
     message_vision(
    GRN "ֻ��$N���һ�ھ�����һʽ��������ơ���Χ��$nһҡһ�ڵ��߶��š�\n" NOR, me, target);

        me->start_busy(1);

        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 || random(3)==0) {
          	target->receive_damage("qi",(int)me->query_skill("weituo-chu", 1)*6,me);
          	target->receive_wound("qi",(int)me->query_skill("weituo-chu", 1)*5,me);
                 message_vision(
    HIR " $N����ȴ�ǰ������ԣ��������ƣ����$n���ְ������Գ��У�\n" NOR, me, target);
                target->start_busy(4);
        } 

        else {
          message_vision(
    CYN "����$n������$N��������������˿�ȥ��\n" NOR, me, target);
          me->start_busy(2);
        }	
	

}
           	me->add("neili", -400);
      		//me->add("jing", 20);

      	me->start_busy(2);
        return 1;
}
