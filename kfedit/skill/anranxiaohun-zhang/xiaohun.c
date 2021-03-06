// xiaohun.c 黯然消魂
// By Kayin @ CuteRabbit Studio 99-4-16 19:18 new
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
        string msg;
	int extra;
	object weapon,ob;
	
        int ap, dp;
        int count;
        int i,skill,damage;
	
	if(me->is_busy())
		return notify_fail("你现在没空！！\n");
	extra = me->query_skill("anranxiaohun-zhang",1);
	skill = me->query_skill("anranxiaohun-zhang",1);
        if( !target ) target = offensive_target(me);
if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("「黯然消魂」只能在战斗中使用。\n");
 
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("「黯然消魂」只能空手使用。\n");		
       
	 if( (int)me->query("neili") < 1000 )
                return notify_fail("你的真气不够！\n");
    if(me->query_skill_mapped("force") != "yunv-xinfa" )
        return notify_fail("你要把玉女心法做为内功才能用。\n");

        if( (int)me->query_skill("anranxiaohun-zhang",1) < 300 )
                return notify_fail("你的黯然消魂掌火候不够，无法使用「黯然消魂」！\n");
	if( (int)me->query_skill("xuantie-sword",1) < 100 )
                return notify_fail("你的玄铁剑法火候不够，无法领悟「黯然消魂」！\n");
        if( (int)me->query_skill("force",1) < 200 )
                return notify_fail("你的内功修为不够，无法使用「黯然消魂」！\n");
	weapon = me->query_temp("weapon");
	if (extra>200) extra=200;
	me->add_temp("apply/attack",100);
	me->add_temp("apply/damage",2000);

        msg = HIM "$N心如止水，心中思念着$N的爱人，无意之中使出了"HIR"“黯然消魂”！\n" NOR;
        msg += HIM   "就似傍晚的遥烟，顿时天地间产生一丝苦涩！\n" NOR;
	         message_vision(msg, me, target);                
	 msg = HIC  "\n   黯 \n" NOR;
	        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "\n      然\n" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "\n        消\n" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "\n          魂\n" NOR;
             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB "\n             掌\n" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/attack",-100);
	 me->add_temp("apply/damage",-2000);

        if( me->query("shen") > 10000
        && target->query("shen") < 10000 )
{
msg = HIG "\n$N怒视$n,大唱一声，打出最后的一掌！就似傍晚的遥烟，顿时天地间产生一丝苦涩！\n"NOR;
 if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
	 {

                msg += RED"\n结果「轰」地一声，$n全身气血倒流，口中鲜血狂喷而出！\n"NOR;
damage=300+((int)me->query_skill("anranxiaohun-zhang")*5);
                if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
                target->receive_damage("qi", damage,me);
                target->receive_wound("qi", damage,me);

// should not busy target if he already in busy (by xbd)
                if (!target->is_busy()) target->start_busy(4);
//             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
		message_combatd(msg, me, target);
                COMBAT_D->report_status(target);
	} else {
		msg += HIY"可是$p急中生智，伏地翻滚而出，避过了这致命一击,躲了开去。\n" NOR;
		message_combatd(msg, me, target);
	}
}
        me->add("neili", -200);
        me->start_busy(2);
if (skill>300 && target && me)
{
 msg = "\n"+ HIM "$N" HIM "一声长叹，心如止水，黯然神伤，于不经意中随"
              "手使出了" HIR "『黯然销魂』" HIM "！\n" NOR;

        ap = 100+me->query_skill("unarmed") +
             me->query_skill("force");

        dp = target->query_skill("parry") +
             target->query_skill("force");
             
 if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
        {
damage=ap;
                if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
                target->receive_damage("qi", damage*3,me);
                target->receive_wound("qi", damage*2,me);
                        msg +=HIR "只听$n" HIR "一声闷哼，“噗”的一"
                                           "声，这一掌正好击在$p" HIR "肩头。 \n"
                                           NOR;
                msg += HIY "$n" HIY "见$P" HIY "这一招变化莫测，奇幻无"
                       "方，不由大吃一惊，慌乱中破绽迭出。\n" NOR;
        } else
        {
                msg += HIC "$n" HIC "不敢小觑$P" HIC
                       "的来招，腾挪躲闪，小心招架。\n" NOR;
        }

        message_combatd(msg, me, target);
	
	
}	        
if (skill>400 && target && me)
{
                msg = "\n"+ HIR "$N" HIR "心下万念俱灰，凄然向妻子"
                      HIR "望了一眼，暗道：“别了！你自己保重。”\n"
                      "当下失魂落魄，随手一招，恰好使出了黯然销魂掌中"
                      "的「拖泥带水」。\n" NOR;

        ap = 300+me->query_skill("unarmed") +
             me->query_skill("force");

        dp = target->query_skill("parry") +
             target->query_skill("force");
             
 if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
        {
damage=ap;
                if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
                target->receive_damage("qi", damage*3,me);
                target->receive_wound("qi", damage*3,me);

                        msg +=HIR "只听$n" HIR "一声闷哼，“噗”的一"
                                           "声，这一掌正好击在$p" HIR "肩头。 \n"
                                           NOR;

        } else
        {
                msg += HIC "可是$p" HIC "小心应付、奋力招架，挡开了这一招。\n"
                       NOR;
        }

        message_combatd(msg, me, target);
	
	
}	
        
if (skill>500 && target && me)
{
 ap = me->query_skill("force") + me->query_skill("unarmed") + me->query_skill("anranxiaohun-zhang");
	dp = target->query_skill("force") + target->query_skill("parry");
	
        skill=me->query_skill("anranxiaohun-zhang",1);

        message_vision(HIW"\n$N的掌风隐隐带着潮涌之声，掌风鼓荡，竟似有狂潮涌来，这正是神雕大侠当年在海边练出的绝技。 \n\n"NOR,me,target);
	
 if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
	{
		message_vision(HIR"$n哪里躲避得开，大惊下已经给$N的掌风印上胸口，一口鲜血狂喷而出！\n\n",me,target);
damage=ap;
                if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
                target->receive_damage("qi", damage,me);
                target->receive_wound("qi", damage,me);
	} else
	{
		message_vision(HIY"$n见状不妙，立刻就地一个打滚，虽然姿势难看以及，不过总算避开了$N这一掌。\n\n"NOR,me,target);
	}

        message_vision(HIW"\n$N在掌风达到顶峰之时，跟着“魂不守舍”、“倒行逆施”、“若有所失”，连出三招。\n\n"NOR,me,target);
	
	if (ap/2 + random(ap/2) > dp || random(3)==0)
	{
		message_vision(HIR"$n惊魂未定，正喘气之际，不提防又一阵猛烈的气浪扑面冲来，复遭$N掌风重创！\n\n",me,target);
damage=ap;
                if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
                target->receive_damage("qi", damage,me);
                target->receive_wound("qi", damage,me);

	} else
	{
		message_vision(HIY"$n顾不得反击，急身后退三丈，脸颊给$N的掌风扫到，微微发红，不过总算避开了$N这三掌。\n\n"NOR,me,target);
	}
	
        message_vision(HIW"跟着$N腾身而起，一招“行尸走肉”，闪电般踢出一脚。\n\n"NOR,me);
 if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
	{
		message_vision(HIR"$n眼看着这霸气冲天的一脚，已然放弃了抵抗，整个脸部给$N重重踹上，牙齿皆碎，面目血色狰狞！\n\n",me,target);
damage=ap;
                if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
                target->receive_damage("qi", damage*2,me);
                target->receive_wound("qi", damage*2,me);

	} else
	{
		message_vision(HIY"$n双足点地，拔天而起，从$N的头顶掠过，脚下劲气呼啸而过，真是险之又险！\n\n"NOR,me,target);
	}
	
}	

        return 1;
}

