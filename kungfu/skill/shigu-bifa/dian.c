// dian.c 石鼓打穴笔法「点」字诀
// Last Modified by sir 11.1.2001

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
#define PNAME "「点」字诀"
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
		(string)weapon->query("skill_type") != "dagger")
		return notify_fail("你使用的武器不对。\n");

	if( target->is_busy() )
		return notify_fail(target->name()+"目前正自顾不暇，放胆攻击吧！\n");

	fskill = "wuzheng-xinfa";
	bskill = "shigu-bifa";


	if( (int)me->query_skill(fskill, 1) < 50 )
		return notify_fail("你的"+to_chinese(fskill)+"火候不够，使不出"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 40 )
		return notify_fail("你的"+to_chinese(sskill)+"不娴熟，使不出"+PNAME+"。\n");

	if( (int)me->query("neili") < 300 )
		return notify_fail("你的内力不够，不会使用「点」字诀。\n");

	msg = HIC"$N使出石鼓打穴笔法「点」字诀，卷起漫天笔影，向$n电射而去，带着呼呼风声点向$n的全身要穴。$n不及攻敌，拼力躲避，顿时动作大乱。\n";

	if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/3)
	{
		if (target->query_temp("hmg_dzjm"))
		{
			msg += HIY "$P手中兵器点中$p的大穴，$p只觉微微一麻，迅即行动如常。\n"NOR;
					me->start_busy(2);
			me->add("neili", -50);
		} else {
			msg +=  HIG "结果$p被$P点中几处穴道，惊慌失措，呆在当场，不知如何应对！ \n" NOR;
			target->start_busy( random((int)me->query_skill(bskill,1) / 50) + 3);
			me->add("neili", -50);
		}
	} else {
		msg +=HIY"可是$p看破了$P的企图，镇定逾恒，一振振开了$P的兵器，全神应对自如。\n" NOR;
		me->start_busy(2);
		me->add("neili", -50);
	}
	message_combatd(msg, me, target);

if (me && target)
	{
me->add_temp("apply/attack", 100);	
	me->add_temp("apply/damage", 900);

	msg = HIY "$N一招"HIG"「指点江山」"NOR"，疾点向$n的期门穴!" NOR;
	
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 msg =  YEL  "$N向前跨上一步，混身充满战意，使出"CYN"「银瓶乍破」"NOR"，疾点$n的地仓穴! " NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 msg =  YEL  "$N自左而右地一晃，使出"BLU"「铁骑突出」"NOR"带着呼呼风声横打$n的章门穴! " NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 msg =  YEL  "$N飞身跃起，一式"MAG"「龙耀九霄」"NOR"，卷起漫天笔影，向$n电射而去 " NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg =  YEL  "N使出一招"HIW"「遥拜玉虚」"NOR"挺笔中宫直进，笔尖颤动，中途忽然转而向上变幻无方。 " NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -100);
	me->add_temp("apply/damage", -900);
		me->start_busy(2);
}

	return 1;
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效： /
		迟滞对方出手

	出手要求：
		无争心法50级
		石鼓打穴笔法40级
		内力300
HELP
	);
	return 1;
}

