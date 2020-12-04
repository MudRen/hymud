// poqizhen.c 破气针
 
#include <ansi.h>
#include <combat.h> 
inherit F_SSERVER;
 
int perform(object me)
{
	string msg;
	object weapon, target;
	int skill, ap, dp, neili_wound, qi_wound,extra;

	me->clean_up_enemy();
	target = me->select_opponent();

	skill = me->query_skill("zimu-zhen",1);

	if( !(me->is_fighting() ))
		return notify_fail("「破气针」只能在战斗中用在对手身上。\n");
 
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "throwing")
		return notify_fail("你使用的武器不对。\n");

	if( (int)me->query_skill("biyun-xinfa", 1) < 100 )
                return notify_fail("你的碧云心法不够高。\n");

        if( (int)me->query("neili", 1) < 300 )
                return notify_fail("你现在内力太弱。\n");


	if( skill < 80)
		return notify_fail("你的子母针法不够纯熟, 不能使用「破气针」！\n");

	if( me->query("neili") < 150 )
		return notify_fail("你的内力不够，无法运用「破气针」！\n");

 extra = me->query_skill("zimu-zhen",1) / 3;
	me->add_temp("apply/attack", 100);	
	me->add_temp("apply/damage", 1800);
msg = RED "$N左手一扬，唐门独门暗器----第一朵令人闻风丧胆的唐花朝$n发了出去。\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	
msg = RED "$N左手一扬，唐门独门暗器----第二朵令人闻风丧胆的唐花朝$n发了出去。\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	
msg = RED "$N左手一扬，唐门独门暗器----第三朵令人闻风丧胆的唐花朝$n发了出去。\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	
	me->add_temp("apply/attack", -100);
	me->add_temp("apply/damage", -1800);
        me->add("neili",-50);

	msg = HIY "$N并指入刀，指缝间夹着三枚暗器,潜运内力，一式「破气针」，直奔$n的上、中、下丹田打去。\n";
	message_vision(msg, me, target);
 
	ap = me->query_skill("throwing") + skill;
	dp = target->query_skill("force") / 2;
	if( dp < 1 )
		dp = 1;
	if( random(ap) > dp )
	{
		if(userp(me))
			me->add("neili",-100);
		msg = "$N「破气针」正中目标, $n顿时觉得丹田上一阵刺痛，\n";
		msg += "全身真气狂泄而出！\n" NOR;
	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
        target->apply_condition("tmqidu_poison", 60);
	} 
		neili_wound = 500 + (skill*3);
		if(neili_wound > target->query("neili"))
			neili_wound = target->query("neili");

		qi_wound = 500 + (skill*3);
		if(qi_wound > target->query("qi"))
			qi_wound = target->query("qi");
if (qi_wound <10) qi_wound=10;
if (qi_wound >100000) qi_wound=100000;
if (neili_wound <10) neili_wound=10;
if (neili_wound >100000) neili_wound=100000;
		target->add("neili", -neili_wound);
target->receive_wound("qi",qi_wound,me);
		target->start_busy(2);
        target->apply_condition("tmpili_poison", 60);

//		me->start_busy(random(2));
	}
	else
	{
		if(userp(me))
			me->add("neili",-80);
		msg = "可是$n瞬间反应过来，腾挪跳跃，躲过了这次重创。\n"NOR;

	}
	message_vision(msg, me, target);
		me->start_busy(2);
	return 1;
}
