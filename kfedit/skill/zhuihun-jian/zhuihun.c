// Last Modified by winder on Sep. 12 2001
// zhuihun.c 一剑追魂

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
#define PNAME "一剑追魂"
int perform(object me, object target)
{
	object weapon;
	int damage;
	string msg;
	int flag;
	string fskill,sskill,bskill,pfname,pskill;

	sskill = explode(__FILE__,"/")[<2];
	pfname = explode(__FILE__,"/")[<1][0..<3];


	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"只能对战斗中的对手使用。\n");
		
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	fskill = "honghua-shengong";
	bskill = "sword";


	if( (int)me->query_skill(fskill, 1) < 120 )
		return notify_fail("你的"+to_chinese(fskill)+"不够高，不能使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 120 )
		return notify_fail("你的"+to_chinese(sskill)+"不够娴熟，不会使用"+PNAME+"。\n");

	damage = (int)me->query_skill("force", 1);
	damage += (int)me->query_skill(bskill, 1);

	if( (int)me->query("max_neili") < damage + 100)
		return notify_fail("你的内力修为太弱，使不出「一剑追魂」。\n");

	if( (int)me->query("neili") < 500 )
		return notify_fail("你现在内力太弱，不能使用「一剑追魂」。\n");
			
	msg = CYN "$N微微一笑，猛吸一口气，飞身跃起，"+weapon->name()+CYN"如无常索命索，绞向$n。\n"NOR;
         damage += 200;
	if (random(me->query_skill("force")) > target->query_skill("force")/3 )
	{
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/2,me);
		target->start_busy(3);
		me->add("neili", -200);
		msg += HIR "$n只觉剑势如夜幕般铺天盖地般压来，一时间眼前一花，两耳轰鸣，无从招架！！\n"NOR;
		me->start_busy(1);
	} else 
	{
		msg += CYN"可是$p见机极快，飞身跃出了$P的剑网。\n"NOR;
		me->add("neili", -200);
		me->start_busy(1+random(1));
	}
	message_combatd(msg, me, target);


 message_vision(HIC"\n$N使出七剑连环指，剑锋一转，右手食指跟着弹出，只见剑花指风相辉相映，直袭$n！\n"NOR,me,target);
       me->add_temp("apply/attack", 80);    
        me->add_temp("apply/damage", 1500);

        msg=HIC"$N嫣然一笑，诡异之极，身法陡然加快！"NOR;

            COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg=HIC"$N情急智生，提指向$n右眼刺去，！"NOR;

     COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg=HIC"$N双手合十互击，陡然向外一分，双掌顿时变得轻灵飘逸，灵动异常！"NOR;

             COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        
        msg=HIC"$N这一下使得剑气纵横，竟然声震山谷。不明其理之人，无不骇异！！"NOR;

     COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        
        msg=HIC"$N似有无穷弹力，似真似幻，无论$n怎么变招抢攻，总是被弹了出去！"NOR;

             COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        
        msg=HIC"$N这时一声高喝，脸上殷红如血，不明其理之人，无不骇异！"NOR;

     COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        
        msg=HIC"只听“啪”的一声，$N手中的利器被内力冲击，裂成了碎片，飞向$n"NOR;

     COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);


       me->add_temp("apply/attack", -80);    
        me->add_temp("apply/damage", -1500);

	return 1;
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		伤害对方气血

	出手要求：
		红花神功120级
		追魂夺命剑120级
		足够的内力修为
		足够的内力
HELP
	);
	return 1;
}

