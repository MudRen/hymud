// Code by JHSH
     
#include <ansi.h>
inherit F_DBASE;
inherit F_SSERVER; 
#include <combat.h>       
int perform(object me, object target) 
{ 
        object weapon; 
        int myexp, targexp, damage, skill, merand, targrand, targneili,time,i; 
        string str,*limb,type,msg; 
        mapping myfam; 
        int tmp_jiali,dmg;
        int num,ap,dp;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「怒海惊涛」只能对战斗中的对手使用。\n");



//        if( objectp(me->query_temp("weapon")) )
//                return notify_fail("空手才能施展「怒海惊涛」！\n");

    if(me->query_skill_mapped("force") != "yunv-xinfa" )
        return notify_fail("你要把玉女心法做为内功才能用。\n");


        if ((int)me->query_skill("yunv-jian", 1) < 80)
                return notify_fail("你的玉女剑法火候太浅。\n");
        if ((int)me->query_skill("yunv-shenfa", 1) < 80)
                return notify_fail("你的玉女身法火候太浅。\n");
        if ((int)me->query_skill("tianluo-diwang", 1) < 80)
                return notify_fail("你的天罗地网火候太浅。\n");
        if ((int)me->query_skill("meinv-quan", 1) < 80)
                return notify_fail("你的美女拳火候太浅。\n");
        if ((int)me->query_skill("wuzhan-mei", 1) < 80)
                return notify_fail("你的五展梅火候太浅。\n");
        if ((int)me->query_skill("yinsuo-jinling", 1) < 80)
                return notify_fail("你的银索金铃火候太浅。\n");
        if( me->query_skill("anranxiaohun-zhang",1) < 150 )
                return notify_fail("你黯然销魂掌修为太差，不能运用「怒海惊涛」！\n");
	


        if ( !living(target))    
               return notify_fail("现在不没必要用「怒海惊涛」吧！\n");

        if( me->query("neili") <= 1000 )
                return notify_fail("你的内力不够使用「怒海惊涛」！\n");

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
                            if (! target->is_busy()) 
			target->start_busy(3);
	} else
	{
		message_vision(HIY"$n见状不妙，立刻就地一个打滚，虽然姿势难看以及，不过总算避开了$N这一掌。\n\n"NOR,me,target);
	}

        message_vision(HIW"\n$N在掌风达到顶峰之时，跟着“魂不守舍”、“倒行逆施”、“若有所失”，连出三招。\n\n"NOR,me,target);
	
 if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
	{
		message_vision(HIR"$n惊魂未定，正喘气之际，不提防又一阵猛烈的气浪扑面冲来，复遭$N掌风重创！\n\n",me,target);
                damage=ap;
                if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
                target->receive_damage("qi", damage,me);
                target->receive_wound("qi", damage,me);
                            if (! target->is_busy()) 
			target->start_busy(3);
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
                            if (! target->is_busy()) 
			target->start_busy(3);
	} else
	{
		message_vision(HIY"$n双足点地，拔天而起，从$N的头顶掠过，脚下劲气呼啸而过，真是险之又险！\n\n"NOR,me,target);
	}


if ((int)me->query_skill("anranxiaohun-zhang", 1) > 300)
{
me->add_temp("apply/damage",2000);
me->add_temp("apply/attack",180);
msg = HIB"$N心下万念俱灰，没精打采的挥袖卷出，拍出一掌，只听得噗的一声，这一掌正好击向$n肩头！" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

msg = HIY"紧跟着$N踢出一脚。这一脚发出时恍恍惚惚，隐隐约约，若有若无。砰的一响，向$n胸口袭去！！" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

msg = HIC"$N一招穷途末路闪身到$n身旁，左掌举到胸前平推而出，接着右掌斜斜劈向$n！" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

msg = HIR"$N一招「"MAG"六神不安"HIR"」身如陀螺急转，展开轻功围着$n快速游走，忽然飞身而起，拍向$n" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

msg = HIB"$N一招「"RED"倒行逆施"HIB"」突然纵起丈余，头下脚上，倒过身子，一掌拍向$n" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

msg = HIM"$N一招「"HIY"力不从心"HIM"」含胸收腹，头缓缓低下，脚步沉重，右掌软绵绵的拍向$n" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
me->add_temp("apply/damage",-2000);
me->add_temp("apply/attack",-180);
}


        me->add("neili",-100);
	me->start_busy(2);

        return 1;
}        
