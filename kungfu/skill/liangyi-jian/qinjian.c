// tianlei.c 

#include <ansi.h>

#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	int damage;
        string msg;
        object weapon;
int extra;
	if( !target ) target = offensive_target(me);

    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
		return notify_fail("手中无剑,你怎么使得出！\n");

	if(me->is_busy())
		return notify_fail("你现在没空！！\n");
	extra = me->query_skill("liangyi-jian",1);
        if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("只能在战斗中使用。\n");
 

	if(me->is_busy())
		return notify_fail("你现在没空！！\n");

	if( (int)me->query("neili") < 2000  ) 
		return notify_fail("你的内力不够。\n");

	if( (int)me->query("neili") < me->query("max_neili")/7+200 ) 
		return notify_fail("你的内力不够。\n");

       if( !wizardp(me) &&(int)me->query_skill("kunlun-zhang", 1) < 500 )
		return notify_fail("你的本门外功不够!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("liangyi-jian", 1) < 500 )
		return notify_fail("你的本门外功不够高!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("xuantian-wuji", 1) < 500 )
		return notify_fail("你的本门内功不够高!不能贯通使用！\n");

	//if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
		//return notify_fail("你的杂学太多，无法对本门武功贯通使用！\n");

        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("你的江湖经验还不够，无法对本门武功贯通使用！\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("你还没有通过华山论剑! 无法对本门武功贯通使用！\n");

        if ( !wizardp(me) && me->query_skill_mapped("force") != "xuantian-wuji")
                return notify_fail("不使用本门内功，如何使用本门绝学!\n");


        msg = HBWHT "$N贯通昆仑武学，使出了昆仑的绝学之精髓！\n" NOR;
	if (me->query("hyvip")==4) 
	{me->add("neili",-500);}
	else
	{me->add("neili", -me->query("max_neili")/7);}
        message_vision(msg, me, target);              
	me->add_temp("apply/attack",200);
	me->add_temp("apply/damage",3000);
 if (random(2)==0) target->start_busy(3);
 msg=HIY "$N衣衫无风自动，使出昆仑派两仪剑法中的震山绝技。\n"
HIG "刹那间天昏地暗，飞沙走石，无数剑影向$n的全身要害或刺，或砍，或劈而去。\n" NOR;
        message_vision(msg, me, target);              
    msg = HIC"$n看到剑光偏左，疾侧身右转，但只这一刹，剑光刹时袭向右首！"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("liangyi-jian",1)));
    msg = HIG"$n看到剑光偏右，疾侧身左转，但只这一刹，剑光刹时袭向左首！"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("liangyi-jian",1)));
    msg = HIY"$n看到剑光偏上，疾侧身下转，但只这一刹，剑光刹时袭向下身！"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("liangyi-jian",1)));
    msg = HIR"$n看到剑光偏下，疾侧身上转，但只这一刹，剑光刹时袭向上身！"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("liangyi-jian",1)));
    msg = CYN"$n看到剑光偏前，疾侧身前转，但只这一刹，剑光刹时袭向前身！"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("liangyi-jian",1)));
    msg = WHT"$n看到剑光偏后，疾侧身后转，但只这一刹，剑光刹时袭向后身！"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("jing",random((int)me->query_skill("liangyi-jian",1)));
	me->add_temp("apply/attack",-200);
	me->add_temp("apply/damage",-3000);
	

        msg = HIW "$N催动内力,一曲[十面埋伏]缓缓奏出,企图瓦解$n的攻势。\n";
     if (random(me->query("combat_exp")) > target->query("combat_exp") / 3 
     || random(3)==0
     )               
{

                msg += GRN " 结果$p被$P琴音所惑,只觉进也不是,退也不是,处处埋伏,吐出一口鲜血，顿时方寸大乱\n" NOR;
		damage = (int)me->query_skill("liangyi-jian", 1);
		
		damage = damage*8 + random(600);
		
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage,me);


        } else {
                msg += HIR"可是$p内力深厚,不为$P的琴声所动,全神应对自如。\n" NOR;
        }
        message_combatd(msg, me, target);


    msg = HIY "\n$N忽然仰天大喝一声“琴 剑 双 绝”，手上的剑如风车般连环击出，一阵热浪随剑势狂飙而出，势不可挡！\n"NOR;



        if (random(me->query_skill("force")) > target->query_skill("force")/3 ||
          random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 
          || random(3)==0)
	{
		target->start_busy(random(3)+1);
		
		damage = (int)me->query_skill("xuantian-wuji", 1);
		
		damage = damage*8 + random(600);
		
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage,me);
		
		if( damage < 300 ) msg += HIY"\n结果$n脸色一下变得惨白，昏昏沉沉接连退了好几步！\n"NOR;
        	else if( damage < 400 ) msg += HIY"\n结果重重地击中，$n「哇」地一声吐出一口鲜血！\n"NOR;
        	else if( damage < 500 ) msg += RED"\n结果「轰」地一声，$n全身气血倒流，口中鲜血狂喷而出！\n"NOR;
        	else msg += HIR"\n结果只听见几声喀喀轻响，$n一声惨叫，像滩软泥般塌了下去！！\n"NOR;
		
	} else 
	{
    msg += HIY"\n$p危急中突然伏地翻滚而出，避过了这致命一击，已吓得脸色苍白！\n" NOR;
	}
	message_vision(msg, me, target);


me->start_busy(4);
	return 1;
}
