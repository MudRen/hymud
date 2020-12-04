// po.c 破字诀

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        object weapon, weapon2;
        int n;
        int skill, skill2, ap, dp, damage;
        string type;

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        skill = me->query_skill("never-defeated", 1);

        skill2 = me->query_skill("never-defeated", 1);

        if (! me->is_fighting(target))
                return notify_fail("破字诀只能对战斗中的对手使用。\n");

        if (! objectp(weapon = me->query_temp("weapon")))
                return notify_fail("你必须手持兵刃才能施展破字诀！\n");

//       if( !me->query("zhuanbest",1))
//        return notify_fail("你没有资格使用这项技能！\n");

       if( !me->query("4zhuan") && !me->query("5zhuan"))
        return notify_fail("你没有资格使用这项技能！\n");

        type = weapon->query("skill_type");
        if (me->query_skill(type, 1) < 150)
                return notify_fail("你的" + to_chinese(type) + "水平有限，无法施展破字诀！\n");

        if (me->query_skill_mapped(type) != "never-defeated")
                return notify_fail("你没有激发不败神功，无法施展破字诀！\n");

        if (skill < 100)
                return notify_fail("你的不败神功等级不够，无法施展破字诀！\n");

        if (me->query("neili") < 150)
                return notify_fail("你现在真气不够！\n");

       if (! living(target))
              return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        me->add("neili", -100);

        ap = skill * 3 / 2 + skill2 * 3 / 2;
        dp = target->query_skill("parry") +
             target->query_skill("unarmed", 1);

        msg = HIC "$N" HIC "手中" + weapon->name() +
              HIC "一抖，犹如夜雨流星，铺天盖地的攻向$n"
              HIC "，没有半点规矩可循。\n" NOR;
        if (ap / 2 + random(ap * 2) > dp)
        {
                n = 4 + random(4);
                if (ap / 2 + random(ap) > dp)
                {
                        msg += HIY "$n" HIY "见来招即巧又拙，不同于人间"
                               "任何招式，不禁大为慌乱，一时破绽迭出，$N"
                               HIY "见状连出" + chinese_number(n) + "招！\n" NOR;
                        message_vision(msg, me, target);
                        me->start_busy(1 + random(n));
                        while (n-- && me->is_fighting(target))
                        {
                                if (random(2) && ! target->is_busy())
					target->start_busy(1);
                                COMBAT_D->do_attack(me, target, weapon, 0);
                        }

                        weapon2 = target->query_temp("weapon");
                        if (weapon2 && random(ap) / 2 > dp && weapon2->query("type") != "pin")
                        {
if (!weapon2->query("systemmake") && !weapon2->query("ownmake"))
{
                                msg = HIW "$n" HIW "觉得眼前眼花缭乱，手中的" + weapon2->name() +
                                      HIW "一时竟然拿捏不住，脱手而出！\n" NOR;
                                weapon2->move(environment(me));
                        }
                        } else
                        {
                                msg = HIY "$n竭力抵挡，一时间再也无力反击。\n" NOR;
                        }



if (me->query("zhuanfinal/1") ==1 && random(2)==0)
{
	if (userp(target))
	target->receive_wound("qi", target->query("qi")/8);
        if (!userp(target))
         target->receive_wound("qi", 500);
	msg +=RED"$N使用了斩仙决!!$n突然胸口一痛鲜血狂奔!\n"NOR;
}
else
if (me->query("zhuanfinal/2") ==1 && random(2)==0)
{
	if (userp(target))
	target->add("neili", -target->query("neili")/8);
        if (!userp(target))
         target->add("neili", -500);
	msg +=HIY"$N使用了破仙决!!$n突然内力消失!\n"NOR;
}
else
if (me->query("zhuanfinal/3") ==1 && random(2)==0)
{
	if (!target->is_busy())
	target->start_busy(4);
	msg +=HIY"$N使用了乱仙决!!$n突然手忙脚乱!\n"NOR;
}

if (me->query("5zhuan") )
{
                if (me->query("qi") < me->query("max_qi") )
                me->add("qi", me->query("max_qi") / 8);
                if (me->query("eff_qi",1) < me->query("max_qi",1) )
                me->add("eff_qi",me->query("max_qi")/8);

                if (me->query("jing",1) < me->query("max_jing",1) )
                me->add("jing",me->query("max_jing")/8);
                
                if (me->query("neili",1) < me->query("max_neili",1) )
                me->add("neili",me->query("max_neili")/8);

                if (me->query("qi") < me->query("max_qi") )
	msg += HIY"$N使用了无上妙仙决!!$N全身的伤好了很多!\n"NOR;
}

                        if (! me->is_fighting(target))
                                // Don't show the message
                                return 1;
                } else
                {
                        msg += HIY "$n" HIY "只办了个勉力遮挡，全然无法反击。\n" NOR;
                        target->start_busy(2 + random(skill / 50));
                }
        } else
        {
                msg += HIC "不过$n" HIC "一丝不苟，严守门户，没有露出半点破绽。\n" NOR;
                me->start_busy(2);
        }

        message_vision(msg, me, target);
        return 1;
}

