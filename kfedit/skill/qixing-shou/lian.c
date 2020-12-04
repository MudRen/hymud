#include <ansi.h>
#include <combat.h>

#define LIAN "「" HIR "重阳连环掌" NOR "」"

inherit F_SSERVER;
 
int perform(object me, object target)
{
	object weapon;
        string msg;
        mapping p;
        int i, af;


        if (! target)
        {
	        me->clean_up_enemy();
	        target = me->select_opponent();
        }

	if (! target || ! me->is_fighting(target))
		return notify_fail(LIAN "只能对战斗中的对手使用。\n");
 
	if (objectp(me->query_temp("weapon")))
                return notify_fail(LIAN "只能空手施展。\n");


        if ((int)me->query_skill("qixing-shou", 1) < 150)
                return notify_fail("你七星分天手不够娴熟，难以施展" LIAN "。\n");


	if ((int)me->query_skill("force") < 120)
		return notify_fail("你的内功火候不够，难以施展" LIAN "。\n");

	if ((int)me->query("neili") < 100)
		return notify_fail("你目前的真气不足，难以施展" LIAN "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIY "$N" HIY "大喝一声，施出「" HIR "重阳连环掌" HIY "」，顿"
              "时双掌纷飞，向$n" HIY "猛攻而去。\n" NOR;
	message_combatd(msg, me, target);
	me->add("neili", -80);

//        af = member_array("strike", keys(p));

        for (i = 0; i < 5; i++)
        {
                if (! me->is_fighting(target))
                        break;

                me->set_temp("action_flag", af);
        	COMBAT_D->do_attack(me, target, 0, 0);
        }

	me->start_busy(2);
	return 1;
}
