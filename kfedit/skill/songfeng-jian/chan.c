// chan.c 松风剑法「缠」字诀
// Last Modified by winder on Aug. 13 2000

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
#define PNAME "「缠」字诀"
int perform(object me, object target)
{
	object weapon;
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

	if( target->is_busy() )
		return notify_fail(target->name()+"目前正自顾不暇，放胆攻击吧！\n");

	fskill = "qingming-xuangong";
	bskill = "sword";


	if( (int)me->query_skill(fskill, 1) < 50 )
		return notify_fail("你的"+to_chinese(fskill)+"火候不够，使不出"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 40 )
		return notify_fail("你的"+to_chinese(sskill)+"不娴熟，使不出"+PNAME+"。\n");

	if( (int)me->query("neili") < 300 )
		return notify_fail("你的内力不够，不会使用「缠」字诀。\n");

	msg = HIG"$N"HIG"使出松风剑法「缠」字诀，将手中剑搭在$n"HIG"兵刃上，剑随意转，连绵不绝，使$n"HIG"一时无法变招。\n";
	
	if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/4) 
	{
		msg += HIR "结果$p被$P闹个手忙脚乱，惊慌失措，呆在当场，不知如何应对！\n" NOR;
		target->start_busy((int)me->query_skill("sword", 1)/50+2);
	        me->add("neili", -150);  // -200
	} else {
		msg +=HIY"可是$p看破了$P的企图，镇定逾恒，一振振开了$P的剑，全神应对自如。\n" NOR;
		me->start_busy(1);
		me->add("neili", -50);  // -100
	}
	message_combatd(msg, me, target);

    msg = HIB"$N淡然一笑，本就快捷绝伦的剑法骤然变得更加凌厉！就在这一瞬之间，"+
    "$N已劈出数剑！剑夹杂着风，风里含着剑影！$n只觉得心跳都停止了！\n"NOR;
   me->add_temp("apply/attack",100);
	me->add_temp("apply/damage",1600);
     COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
     msg = HIC"颠倒阴阳！\n"NOR;
     COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
     msg = HIC"力划鸿沟！\n"NOR;
     COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
     msg = HIC"平沙落雁！\n"NOR;
     COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);


me->add_temp("apply/attack",-100);
	me->add_temp("apply/damage",-1600);
	return 1;
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		迟滞对方出手

	出手要求：
		青冥玄功50级
		松风剑法40级
		内力300
HELP
	);
	return 1;
}

