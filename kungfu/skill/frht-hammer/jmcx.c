// dieying.c 松间蝶影
// Last Modified by sir on 4/25/2001



#include <ansi.h>
#include <combat.h>

#define XIAN "「" HIM "绝命催心" NOR "」"

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;
        object weapon;
        int ap, dp, fp, pp,count;
	int skill, neili_wound, qi_wound;
	int flag;
	string fskill,sskill,bskill,pfname,pskill;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(XIAN "只能在战斗中对对手使用。\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            ((string)weapon->query("skill_type") != "hammer"
            &&  (string)weapon->query("skill_type") != "sword")
            )
                return notify_fail("你使用的武器不对！\n");

	if(me->is_busy())
		return notify_fail("你现在没空！！\n");

        if( !target || !target->is_character()
           || !me->is_fighting(target) || !living(target) )
                return notify_fail("只能对战斗中的对手使用。\n");
                
//	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
//		return notify_fail("这个绝技只能空手使用。\n");		
	if( (int)me->query("neili") < 2000  ) 
		return notify_fail("你的内力不够。\n");

	if( (int)me->query("neili") < me->query("max_neili")/7+200 ) 
		return notify_fail("你的内力不够。\n");

       if( !wizardp(me) &&(int)me->query_skill("frht-hammer", 1) < 500 )
		return notify_fail("你的本门外功不够!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("qingming-xuangong", 1) < 500 )
		return notify_fail("你的本门内功不够高!不能贯通使用！\n");


//	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
//		return notify_fail("你的杂学太多，无法对本门武功贯通使用！\n");

        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("你的江湖经验还不够，无法对本门武功贯通使用！\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("你还没有通过华山论剑! 无法对本门武功贯通使用！\n");

        if ( !wizardp(me) && me->query_skill_mapped("sword") == "love-sword")
                return notify_fail("用这门剑法，如何使用本门绝学!\n");


        if ( !wizardp(me) && me->query_skill_mapped("force") != "qingming-xuangong")
                return notify_fail("不使用本门内功，如何使用本门绝学!\n");


        msg = HBWHT "$N贯通青城派武学，使出了青城派的绝学之精髓！\n" NOR;
message_vision(msg, me, target);               

if (me->query("hyvip")==4) 
	{me->add("neili",-500);}
	else
	{me->add("neili", -me->query("max_neili")/7);}





	msg = HIG "$N"HIG"凝神息气，一式「松间蝶影」，用"+weapon->name()+HIG "如蝶般扑向$n"HIG"。\n";
	message_combatd(msg, me, target);

	skill = me->query_skill("qingming-xuangong",1);
  dp = target->query_skill("force",1);
	if( dp < 1 ) dp = 1;
//	if( random(skill) > dp/2 ) //相同100级就是 random(100) > 150/2  好低...
        if( random(me->query("combat_exp") ) > (int)target->query("combat_exp")/4 || random(3)==0)
	{
	
		msg ="$n顿时觉得眼前蝶影飘飞，双耳嗡嗡内鸣，全身上下一阵刺痛如针扎一般！\n" NOR;
		qi_wound = 3 * skill;
		//qi_wound = qi_wound/2 + random(qi_wound)+300;

		target->receive_damage("qi", qi_wound,me);
		target->receive_wound("qi", qi_wound,me);
	}
	else
	{
		msg = "可是$n宁心静气，身行虚晃，跃出剑影。\n"NOR;
	}
	message_combatd(msg, me, target);
    msg = HIB"$N淡然一笑，本就快捷绝伦的动作骤然变得更加凌厉！就在这一瞬之间，"+
    "$N已劈出数招！夹杂着风，风里含着影！$n只觉得心跳都停止了！\n"NOR;
   me->add_temp("apply/attack",200);
	me->add_temp("apply/damage",2600);
     COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
     msg = HIC"彩蝶穿花！"NOR;
     COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
     msg = HIC"凤凰夺窝！"NOR;
     COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
     msg = HIC"分花拂柳！"NOR;
     COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
     msg = HIC"颠倒阴阳！"NOR;
     COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
     msg = HIC"力划鸿沟！"NOR;
     COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
     msg = HIC"平沙落雁！"NOR;
     COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

me->add_temp("apply/attack",-200);
	me->add_temp("apply/damage",-2600);


	     message_vision(HIY"$N手指$n愤恨道：“对我不仁尔等小命休以”，一语说罢，$N气运丹田，力灌掌心，使出「翻天覆地」。\n"NOR,me,target);
                


       
        if( random(me->query("combat_exp") ) > (int)target->query("combat_exp")/3 || random(3)==0)
{     
        
         message_vision(HIR"只见$n硬生生的接住$N这技绝招，顿感喉头一甜，[噗]的一声吐出一口鲜血。\n"NOR,me, target);  
                damage = me->query_skill("frht-hammer",1);
                target->receive_damage("qi",damage*3,me);
		target->receive_wound("qi",damage*3,me);
}
         else  {message_vision(HIC"$N识破此招，气运丹田，以力抗力硬接此绝招！\n"NOR, target);
                
               }

        if( random(me->query("combat_exp") ) > (int)target->query("combat_exp")/3 || random(3)==0)
        {
                damage = me->query_skill("frht-hammer",1);
                target->receive_damage("qi",damage*3,me);
		target->receive_wound("qi",damage*3,me);
             }
         else  {message_vision(HIC"$N识破此招，气运丹田，以力抗力硬接此绝招！\n"NOR, target);
                
               }
          
msg = HIG "$N"HIG"猛地一个侧身一闪，转到$n"HIG"身后，右掌往$n"HIG"后心印了下去，\n"NOR;

        if( random(me->query("combat_exp") ) > (int)target->query("combat_exp")/3 || random(3)==0)
	{
                damage = me->query_skill("frht-hammer",1);
                target->receive_damage("qi",damage*4,me);
		target->receive_wound("qi",damage*4,me);
msg +=HIR"只见$n硬生生的接住$N这技绝招，[噗]的一声吐出一口鲜血。\n";  
	} else
	{

		msg += HIY"可是$p也随着转身，避开了后心要害。\n"NOR;

	}
	message_combatd(msg, me, target);


          
 msg = RED"$N的左足反踢而起，直撩$n的下阴！不待$n退开站稳，右足连环反踢，将$n踢得一时无法还手！\n"NOR;
         msg += RED"「撩阴脚!!」。$N如影随形的踢出几脚，$n吐出一口鲜血!!。\n"NOR;

        if( random(me->query("combat_exp") ) > (int)target->query("combat_exp")/3 || random(3)==0)
	{
                damage = me->query_skill("frht-hammer",1);
                target->receive_damage("qi",damage*4,me);
		target->receive_wound("qi",damage*4,me);
msg +=HIR"只见$n硬生生的接住$N这技绝招，[噗]的一声吐出一口鲜血。\n";  
	} else
	{

		msg += HIY"可是$p也随着转身，避开了下阴要害。\n"NOR;

	}
	message_combatd(msg, me, target);
     

me->start_busy(3);
	return 1;
}

