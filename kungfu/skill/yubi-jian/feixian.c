 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        int i;
        int a;
        object weapon;
        if( !target ) target = offensive_target(me); 
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("天外飞仙只能对战斗中的对手使用。\n");
        weapon = me->query_temp("weapon");
        if (!weapon) return notify_fail("天外飞仙只能和玉壁月华明剑法配和！\n");
        if( (string)weapon->query("skill_type") != "sword" )
        return notify_fail("你使用的武器不对！\n");


	if( (int)me->query("neili") < 500  ) 
		return notify_fail("你的内力不够。\n");
        me->add("neili",-100);

        extra = me->query_skill("yubi-jian",1) / 20;
        extra += me->query_skill("yubi-jian",1) /20;
        if (extra> 80) extra=80;

        me->add_temp("apply/attack", extra);    
        me->add_temp("apply/damage", 500);
        msg = HIR  "$N倒踏［飞仙步法］，以迅雷不及掩耳之势使出［玉壁月华明剑法］中的精髓－－天外飞仙！\n手中的"+ weapon->name() + HIR"划出一道长虹，闪电般的击向$n！" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg =  HIW "剑光一闪，消失．．．．\n" NOR;
        message_vision(msg, me, target);
        a=extra/5;
        if (a<5) a=5;
        if (a>12) a=12;
        for(i=0;i<a;i++)
        {
        msg = HIY "$N"+HIY"身形突转，御剑回飞！\n" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        }
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -500);
        me->start_busy(2);
        return 1;
}      
