// bighammer.c
#include <ansi.h>


#include <combat.h>


inherit F_SSERVER;


int exert(object me)
{
	object target;
	int success_adj, damage_adj;
        object weapon;
        int damage,p;
        string msg,dodge_skill;
//	success_adj = 150;
//	damage_adj = 140;
        success_adj = 170;
        damage_adj = 170;// xintai 1/29/2001 个人意见，不过bighammer也太NB了一点:)
 

        if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("这门绝学只能对战斗中的对手使用。\n");

        if( !target 
         || !me->is_fighting(target) 
         || !living(target)
         || environment(target)!=environment(me))
                return notify_fail(WHT"「大力降魔杵」只能对战斗中的对手使用。\n"NOR);
        if( (int)me->query_skill("buddhism", 1) < 50 )
                return notify_fail("你的禅宗心法等级不够。\n");

	if((int)me->query("neili") < 500 )
		return notify_fail("你的内力不够！\n");

	if((int)me->query("jing") < 120 )
		return notify_fail("你无法集中精力，别砸中自己了！\n");
	if( me->is_busy() )
		return notify_fail("你现在正忙着呢，哪有空运功？\n");
	me->add("neili", -250);
	me->receive_damage("jing", 50);




        msg = HIC "$N口中念了几句咒文，半空中现出阿傩，迦叶二尊者，各人手执\n一根巨大无比的降魔杵，呼！地一声向$n当头砸下！\n" NOR;
        message_combatd(msg, me,target);		
if (random(me->query("combat_exp")) > target->query("combat_exp")/3 && living(target)){
            damage = (int)me->query_skill("zhanzhuang-gong");  //以基本内功和九阳神功的高低，取决杀伤力的大小！
            damage = damage + random(damage);
            damage +=(int)(me->query_skill("buddhism", 1)*8);
if (damage < target->query("qi") || userp(target))
{
	if ( userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
            target->receive_damage("qi", damage,me);
            target->receive_wound("qi", damage,me);
}
		msg=HIC "结果砸个正着，差点没把$n砸扁！\n" NOR;
}
else
{
		msg="但是$n在千钧一发之际躲了开来。\n" NOR; 
}
message_combatd(msg, me,target);		
			//backfire hit message. note here $N and $n!!!

	me->start_busy(3);
	return 3+random(5);
}

