//剑心移
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

#include "/kungfu/skill/eff_msg.h";
inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
                int damage, p;
        object weapon;
        extra = (int)me->query_skill("murong-jianfa",1);
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("只能对战斗中的对手使用。\n");
        weapon = me->query_temp("weapon");
	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if(me->is_busy())
		return notify_fail("你现在没空！！\n");

	if( (int)me->query("neili") < 2000  ) 
		return notify_fail("你的内力不够。\n");

	if( (int)me->query("neili") < me->query("max_neili")/7+200 ) 
		return notify_fail("你的内力不够。\n");

       if( !wizardp(me) &&(int)me->query_skill("douzhuan-xingyi", 1) < 500 )
		return notify_fail("你的本门外功不够!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("murong-jianfa", 1) < 500 )
		return notify_fail("你的本门外功不够高!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("shenyuan-gong", 1) < 500 )
		return notify_fail("你的本门内功不够高!不能贯通使用！\n");

	//if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
	//	return notify_fail("你的杂学太多，无法对本门武功贯通使用！\n");

        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("你的江湖经验还不够，无法对本门武功贯通使用！\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("你还没有通过华山论剑! 无法对本门武功贯通使用！\n");

        if ( !wizardp(me) && me->query_skill_mapped("force") != "shenyuan-gong")
                return notify_fail("不使用本门内功，如何使用本门绝学!\n");


        msg = HBWHT "$N贯通慕容世家武学，使出了慕容世家的绝学之精髓！\n" NOR;
	if (me->query("hyvip")==4) 
	{me->add("neili",-500);}
	else
	{me->add("neili", -me->query("max_neili")/7);}
        message_vision(msg, me, target);    

	me->add_temp("apply/attack", 200);	
	me->add_temp("apply/damage", 2800);
        msg = WHT "$n所发的招式,突然招招打向自己！\n" NOR;
        message_vision(msg, me, target);    
if (random(3)==0) target->start_busy(3);
	msg =  HIR"斗" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("shenyuan-gong",1)),me);
        msg =  HIR"转" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("shenyuan-gong",1)),me);
        msg =  HIR"星" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("shenyuan-gong",1)),me);
        msg =  HIR"移" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("shenyuan-gong",1)),me);
        message_vision(HIM"紧跟着$N使出慕容剑法中的绝招［快剑］闪电般向$n攻出第一剑！\n\n" NOR,me,target);        
	 msg =  RED"慕容剑法" NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("shenyuan-gong",1)),me);
	 msg =  HIY"武当太极剑" NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("shenyuan-gong",1)),me);
	 msg =  HIB"少林无影剑" NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("shenyuan-gong",1)),me);
	 msg =  HIW"华山独孤九剑" NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);





	me->add_temp("apply/attack", -200);	
	me->add_temp("apply/damage", -2800);
        
        
        message_vision(WHT"$N连出六剑，结果$n被攻了个手忙脚乱！\n" NOR,me,target);
        

        msg = HIY "\n忽然天昏地暗，$N使出$n的绝招，袍袖中两股内家真气向$n扑去！\n"NOR;
        if(me->query("neili") < random(target->query("neili"))){
          // me->add("neili", -100);
           target->add("jing", -50);
           target->add("neili", -200);
           msg += HIY"结果$p和$P两人内力一拼，双方都没占到丝毫好处！\n"NOR;
           message_vision(msg, me, target);
           return 1;
           }
        if( weapon = target->query_temp("weapon") ){
 if (random(me->query("combat_exp")) >target->query("combat_exp")/3 || random(3)==0)
        {                
     damage = (int)me->query_skill("shenyuan-gong", 1);
         //damage = random(damage)+1000;                
                target->receive_damage("qi", damage*7,me);
                target->receive_wound("qi", damage*7,me);   

            msg += HIR"\n$p只觉得全身受到内力震荡，钻心般巨痛，一口鲜血喷出。\n"NOR;
            message_vision(msg, me, target);
                //(target->query_temp("weapon"))->move(environment(target));
            } 
          else {
            //me->add("neili", -60);
            msg += "$p怎么也想不到$N能够使出自己的成名绝技，危及之中双脚跋地而起，艰难的躲过这一招，脸色变的苍白。\n";
            message_vision(msg, me, target);
            }        
         }
        else
        {
 if (random(me->query("combat_exp")) >target->query("combat_exp")/3 || random(3)==0)
        {                
                     damage = (int)me->query_skill("shenyuan-gong", 1);
         //damage = random(damage)+1000;                
                target->receive_damage("qi", damage*8,me);
                target->receive_wound("qi", damage*8,me);   

                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg += damage_msg(damage, "内伤");
                msg += "( $n"+eff_status_msg(p)+" )\n";                       
        } else 
           {
             //me->add("neili", -180);
             msg += CYN"\n$p怎么也想不到$N能够使出自己的成名绝技，危及之中双脚跋地而起，艰难的躲过这一招，脸色变的苍白。\n" NOR;
          }
        message_vision(msg, me, target);

        }

 msg = HIW "只见$N" HIW "身形一展，身法陡然变得诡异无比，聚力于指悄然点"
              "出，数股剑气直袭$n" HIW "要穴而去。\n" NOR;  

        message_combatd(msg, me, target);
        me->add("apply/attack", 80);
        me->add("apply/damage", 1800);
        msg = MAG "$N一指点向$n的幽门穴" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = YEL "$N二指点向$n的章门穴" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = WHT "$N三指点向$n的大横穴"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg =RED "$N四指点向$n的紫宫穴" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = HIR "$N五指点向$n的冷渊穴" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = HIC "$N六指点向$n的天井穴" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = HIB "$N七指点向$n的极泉穴" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = GRN "$N八指点向$n的清灵穴" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);        
        me->add("apply/damage", -1800);
        me->add("apply/attack", -80);
me->start_busy(4);
        return 1;
}
