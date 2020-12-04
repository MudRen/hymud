// qishang 七伤
#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg,str;
        object weapon;
        int i, j, damage;
            int skill, ap, dp, neili_wound, qi_wound;
       if( !target ) target = me->select_opponent();

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("此招只能对战斗中的对手使用。\n");
        if( objectp(me->query_temp("weapon")) )
                return notify_fail("你必须空手才能使用此招！\n");


        if( (int)me->query_skill("qishang-cuff", 1) < 250 )
                return notify_fail("你的七伤拳还不够娴熟，还没有办法拳出七伤。\n");

        if( (int)me->query("neili", 1) < 800 )
                return notify_fail("以你的目前的内力没有办法发出这一招。\n");

        i=random((int)(me->query_skill("qishang-cuff",1)/50));
        if(i<1) i=1;
        if(i>7) i=7;
if (i < 3 && !userp(me))
{
i=2+random(6);        	
}
if (i >= 1 && me->query("neili")>=800)
{
        msg = HIY "$N凝神定气，使出七伤拳总诀中的「" HIR "藏离诀" HIY "」，双拳势如雷霆，向$n击去。\n"NOR;
        message_vision(msg, me, target);	
skill = me->query_skill("qishang-cuff",1) + me->query_skill("force",1);
	        ap = me->query("combat_exp") + skill * 500;
        dp = target->query("combat_exp") / 2;
if( random(ap) > dp || !living(target))
        {
                        me->add("neili",-100);

                msg = HIG "$n被$N拳风扫中，只觉全身真气失却驾驭，往外急泻！\n"NOR;
                neili_wound = skill + random(skill * 2);
                neili_wound += me->query("jiali");
                if(neili_wound > target->query("neili"))
                        neili_wound = target->query("neili");
                if(target->query("neili")<0)
                        neili_wound = 0;
if (neili_wound <10) neili_wound=10;
if (neili_wound >100000) neili_wound=100000;
                target->add("neili", -neili_wound);
                target->receive_wound("qi", neili_wound);
                target->start_busy(2);
                me->start_busy(2 + random(2));
		str = COMBAT_D->status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));
		msg += "($n"+str+")\n";
        }
        else
        {
                msg = HIG "只见$n不慌不忙，轻轻一闪，躲过了$N的必杀一击！\n"NOR;
                if(userp(me))
                        me->add("neili",-100);
                me->start_busy(3);
        }
        message_vision(msg, me, target);
}	


if (i >= 2 && me->query("neili")>=800)
{
        msg = HIY "$N凝神定气，使出七伤拳总诀中的「" HIR "摧肝肠诀" HIY "」，双拳势如雷霆，向$n击去。\n"NOR;
        message_vision(msg, me, target);
      ap = me->query("combat_exp") + skill * 500;
        dp = target->query("combat_exp") / 2;
        if( dp < 1 )
                dp = 1;
        if( random(ap) > dp || !living(target))
        {
                if(userp(me))
                        me->add("neili",-100);

                msg = HIG "$n前胸中了$N全力一击，只觉一阵剧痛，“哇”的一声喷出一口鲜血！\n"NOR;
                qi_wound = skill + random(skill);
                qi_wound += me->query("jiali");
                if(qi_wound > target->query("qi"))
                        qi_wound = target->query("qi");
if (qi_wound <10) qi_wound=10;
if (qi_wound >100000) qi_wound=100000;

                target->receive_wound("qi", qi_wound);
                target->start_busy(2);
                me->start_busy(2 + random(2));
		str = COMBAT_D->status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));
		msg += "($n"+str+")\n";
        }
        else
        {
                msg = HIG "只见$n不慌不忙，轻轻一闪，躲过了$N的必杀一击！\n"NOR;
                if(userp(me))
                        me->add("neili",-100);
                me->start_busy(3);
        }
        message_vision(msg, me, target);
}

if (i >= 3 && me->query("neili")>=800)
{
        msg = HIY "$N" HIY "怒喝一声，双拳连环，施出绝招「" HIR "伤字诀" HIY "」，双拳迅猛无比"
              "的袭向$n" HIY "。\n" NOR;
      //message_vision(msg, me, target);
      ap = me->query("combat_exp") + skill * 500;
        dp = target->query("combat_exp") / 2;
             
        if( random(ap) > dp || !living(target))
        {
                damage =skill + random(skill);

                me->add("neili", -160);
                msg += HIG "只见$P" HIG "这一拳把$p" HIG"飞了出去，重重的摔在地上，吐血不止！\n" NOR;
		str = COMBAT_D->status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));
		msg += "($n"+str+")\n";

                me->start_busy(2);
        } else 
        {
                msg += HIC "可是$p" HIC "奋力招架，硬生生的挡开了$P"
                       HIC "这一招。\n"NOR;
                me->add("neili", -120);
                me->start_busy(3);
        }
        message_combatd(msg, me, target);
}

if (i >= 4 && me->query("neili")>=800)
{
     msg = HIY "$N凝神定气，使出七伤拳总诀中的「" HIR "伤肺诀" HIY "」，双拳势如雷霆，向$n击去。\n"NOR;
        message_vision(msg, me, target);

        ap = me->query("combat_exp") + skill * 500;
        dp = target->query("combat_exp") / 2;
        if( dp < 1 )
                dp = 1;
        if( random(ap) > dp || !living(target))
        {
                if(userp(me))
                        me->add("neili",-100);

                msg = HIG "$N的拳风隐含风雷，“澎”的一声打在$n身上！\n$n只觉得呼吸不顺，顿时脚步慢了许多！\n"NOR;
                //dodge_decrease = (int)target->query("apply/dodge") / 10;
		str = COMBAT_D->status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));
		msg += "($n"+str+")\n";

                target->add_temp("apply/dodge", -(i*10));
                target->start_busy(2);
                me->start_busy(2 );
        }
        else
        {
                msg = HIG "只见$n不慌不忙，轻轻一闪，躲过了$N的必杀一击！\n"NOR;
                if(userp(me))
                        me->add("neili",-100);
                me->start_busy(3);
        }
message_vision(msg, me, target);
}

if (i >= 5 && me->query("neili")>=800)
{
       msg = HIY "$N凝神定气，使出七伤拳总诀中的「" HIR "损心诀" HIY "」，双拳势如雷霆，向$n击去。\n"NOR;
        message_vision(msg, me, target);

        ap = me->query("combat_exp") + skill * 500;
        dp = target->query("combat_exp") / 2;
        if( dp < 1 )
                dp = 1;
        if( random(ap) > dp || !living(target))
        {
                if(userp(me))
                        me->add("neili",-100);
                msg = HIG "$N连环拳势如风雷，$n中了$N开山裂石的一拳，顿时心神大震，不能随意出招！\n"NOR;
		str = COMBAT_D->status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));
		msg += "($n"+str+")\n";
               
                target->add_temp("apply/attack", -(i*10));
                target->start_busy(2);
                me->start_busy(2);
                
        }
        else
        {
                msg = HIG "只见$n不慌不忙，轻轻一闪，躲过了$N的必杀一击！\n"NOR;
                if(userp(me))
                        me->add("neili",-100);
                me->start_busy(3);
        }
message_vision(msg, me, target);
}

if (i >= 6 && me->query("neili")>=800)
{
       msg = HIY "$N凝神定气，使出七伤拳总诀中的「" HIR "意恍惚诀" HIY "」，双拳势如雷霆，向$n击去。\n"NOR;
        message_vision(msg, me, target);

        ap = me->query("combat_exp") + skill * 500;
        dp = target->query("combat_exp") / 2;
        if( dp < 1 )
                dp = 1;
        if( random(ap) > dp || !living(target))
        {
                if(userp(me))
                        me->add("neili",-100);

                msg = HIC "结果$N双拳击中时，却是若有若无。\n$n正在奇怪间，已被$N的真气制住，神情恍恍忽忽的！\n"NOR;
                target->start_busy((int)skill/30);
                me->start_busy(2);
		str = COMBAT_D->status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));
		msg += "($n"+str+")\n";
        }
        else
        {
                msg = HIG "只见$n不慌不忙，轻轻一闪，躲过了$N的必杀一击！\n"NOR;
                if(userp(me))
                        me->add("neili",-100);
                me->start_busy(4);
        }
        message_vision(msg, me, target);
}


if (i >= 7 && me->query("neili")>=800)
{
        msg = HIY "$N凝神运功，使出“七伤拳”最后的绝招，"+chinese_number(i)+"股无比强劲的热气呼啸的扑向$n身上各大要穴。\n"+HIC "$n急提丹田之气与体内来回撞击的"+chinese_number(i)+"股劲气相扩。\n"NOR;
        if (!(me->query("neili")<0)) me->add("neili",-i*30);
        if ((random(me->query_skill("force")) > target->query_skill("force")/2) || !living(target))
        {
                me->start_busy(1);
                target->start_busy(i);
                
                damage = (int)me->query_skill("cuff")*2;
                damage += me->query("jiali");
                damage += random(damage);
                damage /= 2;
                
                target->receive_damage("qi", (int)((i*(2*damage))/2));
                target->receive_wound("qi", (int)((i*damage)/2));
                if (!(target->query("neili")<0)) target->add("neili",-i*20);
     
                msg += HIY"结果$n抵受不住$N的"+chinese_number(i)+"种劲气在体内来回的撞击。"+GRN"\n($n"+HIR"所受的内伤着实不轻。"+GRN")\n"NOR;
		str = COMBAT_D->status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));
		msg += "($n"+str+")\n";
        } else 
        {
                me->start_busy(4);
                if (!target->is_busy()) target->start_busy(1);
                msg += CYN"可是$p忙运内力与$P的"+chinese_number(i)+"种劲气相扩，把之在体内化之无形。\n"NOR;
                if (!(target->query("neili")<0)) target->add("neili",-i*50);
        }
        message_vision(msg, me, target);
}
        return 1;
}


