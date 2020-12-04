
// shisan 落雁十三剑
// 2000.5.30  by ybl

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
object weapon;
int i,j;
string msg;
int damage;
if( !target ) target = offensive_target(me);

if( !target || !target->is_character()|| !me->is_fighting(target) )

 return notify_fail("「落雁十三剑」只能对战斗中的对手使用。\n");

if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
        return notify_fail("你所使用的武器不对\n");

if ( (int)me->query_int() < 30 )
 return notify_fail("你的先天不足，不能领悟「落雁十三剑」！n");


if( (int)me->query_skill("luoyan-jianfa", 1) < 199 )
 return notify_fail("你的落雁剑法不够娴熟，不会使用「落雁十三剑」。\n");

if( (int)me->query("neili")<800)
 return notify_fail("你现在内力太弱，不能使用「落雁十三剑」。\n");

        if( me->query_skill("nei-bagua",1) <=50)
                 return notify_fail("内八卦等级不够。\n");




/* */ if(random(2)==1) {
/* */ i=13;
  message_vision(YEL+"\n$N"+RED+"纵声长笑数声，落雁剑法接连出招。\n"NOR,me);
}
else {
/* */ i=12;
 message_vision(YEL+"\n$N"+RED+"纵声长笑数声，落雁剑法接连出招。\n"NOR,me);
}

me->add_temp("apply/attack",50);
/* */ weapon=me->query_temp("weapon");
/* */ for(j=1;j<=i;j++) {
        msg = HIY "$N"+HIY"纵声长笑，刺出第"+(i+1)+"剑！\n" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
}
me->add_temp("apply/attack",-50);
if (me && target)
{
if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/4 )
{
	msg = HIR  "$N手中"+ weapon->name() +"的剑芒散发出若有若无的浅笑．．．" NOR;
	msg +=  HIW "剑光一闪，消失．．．．\n" NOR;
                me->start_busy(3);
                //if (!target->is_busy())
                //target->start_busy(random(2));
                damage = (int)me->query_skill("luoyan-jianfa", 1)+500;
                damage = damage + random(damage);
                target->receive_damage("qi", damage,me);
                target->receive_wound("qi", damage,me);
                target->receive_damage("jing", damage/6,me);
                target->receive_wound("jing", damage/6,me);
            	  //target->add("neli",-100);
                me->add("neili", -100);
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);
}
}
me->start_busy(2);
me->add("neili",-250);

return 1;
}
int help(object me)
{
	
	write(@HELP

	使用功效：
		对敌人连续出手十三招

	出手要求：
		落雁剑法199级
		内力修为800
		内力800
HELP
	);
	return 1;
}