// zuijiu.c 醉酒

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
                return notify_fail("「八仙醉打」只能在战斗中对对手使用。\n");

      if (!objectp(weapon = me->query_temp("weapon")) 
        || weapon->query("skill_type") != "club"
        || me->query_skill_mapped("club") != "weituo-chu")
                return notify_fail("你现在无法使用「八仙醉打」。\n");
                
            
      if( (int)me->query_skill("weituo-chu",1) < 100 )
                return notify_fail("你的醉棍不够娴熟，不会使用「八仙醉打」！\n");
      
      if( me->query_skill_mapped("force") != "yijinjing" )
                return notify_fail("你现在所使的内功无法使出「八仙醉打」。\n");

      if( (int)me->query_skill("yijinjing",1) < 100 )
                return notify_fail("你的易筋经等级不够，不能使用「八仙醉打」！\n");  
       
      if( (int)me->query_str() < 25 )
                return notify_fail("你的臂力不够强，不能使用「八仙醉打」！\n");
      
      if( (int)me->query("max_neili") < 1300 )
                return notify_fail("你的内力太弱，不能使用「八仙醉打」！\n");
            
      	limit = (me->query("con") + (int)me->query("max_neili") / 50) * 2;
      	lvl = (int)me->query_skill("weituo-chu", 1);

      	lvl /= 30;
      	lvl--;
      	if(lvl > 12) lvl = 12;  
      	if(lvl < 1) return notify_fail("你的等级太低，无法使用出「八仙醉打」！\n");

      	if( (int)me->query("neili") < 100*lvl )
                return notify_fail("你的内力太少了，无法使用出「八仙醉打」！\n");
          
      	message_vision(HIY"\n$N突然一个醉嗝，顿时借着酒劲猛打，醉棍威力大增！\n"NOR,me);
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

	msg = HIR  "$N突然一个醉嗝，不知从何处打出第"+(i+1)+"棍！\n" NOR;     
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
      	}
	me->set_temp("noauto",0);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -2000);
if (extra> 50)
{
	
     message_vision(
    GRN "只见$N喷出一口酒气，一式「八仙醉酒」，围着$n一摇一摆地走动着。\n" NOR, me, target);

        me->start_busy(1);

        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 || random(3)==0) {
          	target->receive_damage("qi",(int)me->query_skill("weituo-chu", 1)*6,me);
          	target->receive_wound("qi",(int)me->query_skill("weituo-chu", 1)*5,me);
                 message_vision(
    HIR " $N脚下却是暗含八卦，步步紧逼，打得$n碍手碍脚难以出招！\n" NOR, me, target);
                target->start_busy(4);
        } 

        else {
          message_vision(
    CYN "可是$n看破了$N的招数，向后纵了开去。\n" NOR, me, target);
          me->start_busy(2);
        }	
	

}
           	me->add("neili", -400);
      		//me->add("jing", 20);

      	me->start_busy(2);
        return 1;
}
