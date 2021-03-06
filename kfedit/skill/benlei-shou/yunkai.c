// yunkai.c 云开雾阖
// Last Modified by winder on Sep. 12 2001

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
#define PNAME "「云开雾阖」"
int perform(object me,object target)
{
	string msg;
	object weapon;
	int skill, ap, dp, neili_wound, qi_wound,i,a;

	int flag;
	string fskill,sskill,bskill,pfname;

	sskill = explode(__FILE__,"/")[<2];
	pfname = explode(__FILE__,"/")[<1][0..<3];
 

	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"只能对战斗中的对手使用。\n");
		
	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必须空手才能使用"PNAME"！\n");
		
	fskill = "honghua-shengong";
	bskill = "hand";
	


	if( (int)me->query_skill(fskill, 1) < 60 )
		return notify_fail("你的"+to_chinese(fskill)+"等级不够，不能使用"+PNAME+"。\n");
	if( (int)me->query_skill(sskill, 1) < 60 )
		return notify_fail("你的"+to_chinese(sskill)+"等级不够，不能使用"+PNAME+"。\n");
	if( me->query("max_neili") < 200 )
		return notify_fail("你的内力修为不够，无法使"PNAME"！\n");
	if( me->query("neili") < 150 )
		return notify_fail("你的内力不够，无法运用"PNAME"！\n");
 
	msg = HIC "$N"HIC"潜运「云开雾阖」，双掌挟着阵阵的风雷之声向$n"HIC"击去。\n"NOR;
	message_combatd(msg, me, target);
	skill = me->query_skill(bskill, 1);
 
	ap = me->query("combat_exp") + skill * 400;
	dp = target->query("combat_exp") / 2;
	if( dp < 1 ) dp = 1;
	if( random(ap) > dp )
	{
		msg=HIR"$n"HIR"只觉得胸前一阵剧痛，“哇”的一声喷出一口鲜血！\n"NOR;
		neili_wound = 600 + random(skill);
		qi_wound = neili_wound * 3;
		if(qi_wound > target->query("qi"))
			qi_wound = target->query("qi");
		if(neili_wound > target->query("neili"))
			neili_wound = target->query("neili");
if (qi_wound <10) qi_wound=10;
if (qi_wound >100000) qi_wound=100000;
if (neili_wound <10) neili_wound=10;
if (neili_wound >100000) neili_wound=100000;

		if(userp(me)) me->add("neili",-(100+neili_wound/2));
		
		target->add("neili", -neili_wound);
		target->receive_damage("qi", qi_wound,me);
		target->start_busy(2);
		me->start_busy(random(2));
	}
	else
	{
		msg = HIG"只见$n不慌不忙，轻轻一闪，躲过了$N的必杀一击！\n"NOR;
		if(userp(me)) me->add("neili",-100);
		me->start_busy(4);
	}
	message_combatd(msg, me, target);

       me->add_temp("apply/attack", 100);    
        me->add_temp("apply/damage", 900);
	msg = HIR  "$N双掌挟着阵阵的风雷之声，如潮水般的击向$n！" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg =  HIY "第一道风雷掌力，．．．．\n" NOR;
        message_vision(msg, me, target);
        for(i=0;i<7;i++)
	{
	msg = HIR "$N身形突转，一道风雷手又打了过来！\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	}

        me->add_temp("apply/attack", -100);
        me->add_temp("apply/damage", -900);


	return 1;
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		伤害对方气血和内力

	出手要求：
		红花神功60级
		奔雷手60级
		内力修为200
		内力150
HELP
	);
	return 1;
}

