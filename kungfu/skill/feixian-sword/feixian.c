 // tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        int i;
        object weapon;
        if( !target ) target = offensive_target(me); 
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("天外飞仙只能对战斗中的对手使用。\n");
        weapon = me->query_temp("weapon");
        if (!weapon) return notify_fail("天外飞仙只能和飞仙剑法配和！\n");
        if( (string)weapon->query("skill_type") != "sword" )
        return notify_fail("天外飞仙只能和剑配和！\n");
        if ( (string) me->query_skill_mapped("sword") != "feixian-sword")
        return notify_fail("天外飞仙只能和飞仙剑法配和！\n");

         if ((int)me->query_skill("feixian-sword",1) <10)
        return notify_fail("飞仙剑法需要十极以上！\n");

	if( (int)me->query("neili",1) < 5  ) 
		return notify_fail("你的内力不够。\n");
        
        me->add("neili",-5);
        if (me->query("neili",1) > 200) me->add("neili",-80);
        extra = me->query_skill("feixian-sword",1) / 30;
        extra += me->query_skill("feixian-sword",1) /30;
        if (extra> 60) extra=60;
        if (extra< 10) extra=10;

        me->add_temp("apply/attack", extra);    
        me->add_temp("apply/damage", 200);
        if (!target->is_busy() && random(3)==0) target->start_busy(2);
        msg = HIR  "$N倒踏［飞仙步法］，以迅雷不及掩耳之势使出［飞仙剑法］中的精髓－－天外飞仙！\n手中的"+ weapon->name() + HIR"划出一道长虹，闪电般的击向$n！" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg =  HIW "剑光一闪，消失．．．．\n" NOR;
        message_vision(msg, me, target);
        for(i=0;i<extra/5;i++)
        {
        msg = HIY "$N"+HIY"身形突转，御剑回飞！\n" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        }
        me->set_temp("usefx",1);
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -200);
        me->start_busy(2);
        return 1;
}      
