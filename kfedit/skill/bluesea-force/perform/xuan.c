// yong.c 玄黄连环掌

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
 
int perform(object me, object target)
{
        string msg;
        int count;
        int lvl;
        int i,j;
 object weapon;
        if (! target)
        {
	        me->clean_up_enemy();
	        target = me->select_opponent();
        }

	if (! target || ! me->is_fighting(target))
		return notify_fail("玄黄连环掌只能对战斗中的对手使用。\n");
 
	if (me->query("neili") < 200)
		return notify_fail("你的真气不够，无法施展玄黄连环掌！\n");

	if ((lvl = me->query_skill("bluesea-force", 1)) < 150)
		return notify_fail("你的南海玄功火候不够，无法施展玄黄连环掌！\n");

        if (me->query_skill_mapped("strike") != "bluesea-force")
                return notify_fail("你没有激发南海玄功为掌法，无法施展玄黄连环掌！\n");

        if (me->query_skill_prepared("strike") != "bluesea-force")
                return notify_fail("你没有准备好使用南海玄功，无法施展玄黄连环掌！\n");

        if (me->query_skill_mapped("force") != "bluesea-force")
                return notify_fail("你使用的内功不对。\n");

        if ( objectp(weapon = me->query_temp("weapon"))              )
                return notify_fail("必须空手才能用。\n");


       if (! living(target))
              return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIC "$N" HIC "轻轻划了个圈子，身形忽然变快，合数招为一击攻向$n"
              HIC "！\n" NOR;
        i = 5;
        if (lvl + random(lvl) > (int)target->query_skill("force") * 2 / 3)
        {
                msg += HIY "内力激荡之下，$n" HIY "登时觉得呼吸"
                       "不畅，浑身有如重压，万分难受，只见$N"
                       HIY "一掌接一掌的攻到，有如海浪。\n" NOR;
                count = me->query_skill("bluesea-force", 1) / 5;

                i += random(5);
        } else
        {
                msg += CYN "$n" CYN "见来掌奇快，只好振作精神勉力抵挡。\n" NOR;
                count = 0;
        }

	message_combatd(msg, me, target);
	me->add("neili", -i * 20);
j=1;

                                me->add_temp("apply/attack", 100);
                me->add_temp("apply/damage", 1200);
        while (i--)
        {
                if (! me->is_fighting(target))
                        break;
                if (i > 4 && ! target->is_busy())
                        target->start_busy(1);
	msg = HIR "玄黄连环第"+ chinese_number(j) +" 招！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
j=j+1;
        }

                        me->add_temp("apply/attack", -100);
                me->add_temp("apply/damage", -1200);
	me->start_busy(2);
	return 1;
}
