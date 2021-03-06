#include <ansi.h>
#include <combat.h>

#define GUI "「" HIR "鬼魅身法" NOR "」"
#define HUI "「" HIW "毁天" HIR "灭地" NOR "」"
#define QIONG "「" HIR "无穷无尽" NOR "」"

inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;
        object weapon;
        int ap, dp;
        int skill;
        int count;
        int lvl;
        int i,j;
        int ap1, dp1, damage;



        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! me->is_fighting(target))
                return notify_fail(GUI "只能对战斗中的对手使用。\n");

	if (target->is_busy())
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧。\n");

        skill = me->query_skill("kuihua-dafa", 1);
        lvl = me->query_skill("kuihua-dafa", 1);
        if (skill < 100)
                return notify_fail("你的辟邪剑法不够娴熟，难以施展" GUI "。\n");

        if (me->query("neili") < 100)
                return notify_fail("你现在的真气不足，难以施展" GUI "。\n");

       if ((int)me->query_skill("kuihua-xinfa", 1) < 50)
               return notify_fail("你的葵花心法太低了。\n");


        if (me->query_skill_mapped("sword") != "kuihua-dafa")
                return notify_fail("你没有准备使用葵花神功，难以施展" GUI "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIR "$N" HIR "身子忽进忽退，宛若鬼魅，身形诡秘异常，在$n"
              HIR "身边飘忽不定。\n" NOR;

        ap = me->query_skill("kuihua-dafa", 1) * 2;
        dp = target->query_skill("parry");

	if (ap / 2 + random(ap) > dp || random(3)==0)
        {
		msg += HIR "$p" HIR "霎时只觉眼花缭乱，只能紧守门户，不"
                       "敢妄自出击！\n" NOR;
		target->start_busy(ap / 55 + 3);
	} else
        {
		msg += CYN "可是$p" CYN "看破了$P" CYN "的身法，并没有受"
                       "到任何影响。\n" NOR;
		me->start_busy(2);
	}
        me->add("neili", -50);
	message_vision(msg, me, target);

if (skill>200 && me && target)
{
  msg = HIR "\n$N" HIR "尖啸一声，猛然进步欺前，一招竟直袭$n" HIR "要害，速度之快，令"
              "人见所未见，闻所未闻。\n" NOR;

        ap = me->query_skill("unarmed");
        dp = target->query_skill("force");

        if (ap / 2 + random(ap) > dp || random(3)==0)
        {
                ap = me->query_skill("kuihua-dafa", 1);
                me->start_busy(1 + random(2));


                damage=me->query_skill("kuihua-dafa", 1)*2;	
                damage = damage  + random(damage);
           target->receive_damage("qi",damage*2,me);
           target->receive_wound("qi",damage,me);
                msg +=HIR "这一招速度之快完全超出了$n" HIR "的想象，$n" HIR
                                                "慌忙回缩招架，但是此招之快，已无从躲闪，$n" HIR "尖叫"
                                                "一声，已然中招。\n" NOR;

 

   

        } else
                msg += HIM "$n" HIM "大吃一惊，连忙退后，居然"
                                "侥幸躲开着这一招！\n" NOR;
                       message_vision(msg, me, target);
        me->start_busy(2);

	
}	

if (skill>300 && me && target)
{
   msg = HIR "\n$N" HIR "默运葵花魔功，身形变得奇快无比，接连向$n"
              HIR "攻出数招！\n" NOR;
        i = 4;
        if (lvl / 2 + random(lvl) > (int)target->query_skill("dodge") || random(3)==0)
        {
                msg += HIR "$n" HIR "只觉得眼前一花，发现四周都是$N"
                       HIR "的身影，不由暗生惧意，接连后退。\n" NOR;
                count = me->query_skill("kuihua-dafa", 1);
                i += random(6);
        } else
        {
                msg += CYN "$n" CYN "见$N" CYN "身法好快，哪里"
                       "敢怠慢，连忙打起精神小心应对。\n" NOR;
                count = 0;
        }

        message_vision(msg, me, target);
me->set_temp("action_flag", 1);
        me->add_temp("apply/attack", 200);
        me->add_temp("apply/damage", 1800);
j=1;
        while (i--)
        {
                if (! me->is_fighting(target))
                        break;
                if (i > 5 && ! target->is_busy())
                        target->start_busy(1);
	j=j+1;
	msg = HIY "$N身形奇快无比，接连向$n攻出第"+chinese_number(j+1)+"招！！\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        }
me->delete_temp("action_flag");
        me->add_temp("apply/attack", -200);
        me->add_temp("apply/damage", -1800);
	me->start_busy(2);
}	

	return 1;
}
