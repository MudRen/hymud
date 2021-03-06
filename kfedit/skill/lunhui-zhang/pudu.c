// writted by jie
// 2/2001

#include <ansi.h>
#include <combat.h>


inherit F_SSERVER;

int perform(object me, object target)
{       
        string msg="";
        int damage,wound;
        object weapon=me->query_temp("weapon");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展「慈光普渡」？\n");

        if(!me->is_fighting())
                return notify_fail("「慈光普渡」只能在战斗中使用！\n");
        
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("这门绝学只能对战斗中的对手使用。\n");

    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "staff")
        return notify_fail(RED"开什么玩笑，武器不对？\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "zhanzhuang-gong")
                return notify_fail("请使用四平大马站桩功!\n");
                        if((int)me->query_skill("yijinjing", 1) < 150)
                return notify_fail("你的易筋经级别还不够，使用这一招会有困难！\n");
        if( (int)me->query("bellicosity") > 300 )
        return notify_fail("你的杀气太重，无法施展佛门绝技。\n");
                

                
        if((int)me->query("max_neili") < 500 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("neili") < 300 )
                return notify_fail("你的内力不足！\n");
        
        if((int)me->query("jing") < 300 )
                return notify_fail("你的精神不足，没法子施用外功！\n");
        
        
        if((int)me->query_skill("lunhui-zhang", 1) < 80)
                return notify_fail("你的轮回杖修为还不够，使用这一招会有困难！\n");
        
        message_vision(HIY"$N气沉丹田，犹如金刚浑身发金光，招转佛门正宗绝招「慈光普渡」，向$n连续发动进攻！\n"NOR,me,target);
                        me->add_temp("apply/attack",200);
                me->add_temp("apply/damage",1200);  
        me->set("ciguangpudu", 6);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
        me->set("ciguangpudu", 7);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
        me->set("ciguangpudu", 8);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
        me->set("ciguangpudu", 9);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
                        me->add_temp("apply/attack",-200);
                me->add_temp("apply/damage",-1200);  
        me->delete("ciguangpudu");
        me->start_busy(2);
        message_vision(HIW"$N低吟“阿弥陀佛！”「慈光普渡」用功完毕，身上淡淡的金光慢慢隐去.\n"NOR,me,target);

        me->add("neili", -50);
        return 1;
}

