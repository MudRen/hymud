// zhu.c 诛仙决
 
#include <ansi.h>
#include <combat.h>
 
inherit F_SSERVER;
 
int perform(object me, object target)
{
	string msg;
	int ap, dp;
        int damage;

        if (! target)
        {
        	me->clean_up_enemy();
        	target = me->select_opponent();
        }

	if (! target || ! me->is_fighting(target))
		return notify_fail("诛仙决只能对战斗中的对手使用。\n");
 
	if (me->query_skill("yinyang-shiertian", 1) < 120)
		return notify_fail("你的阴阳十二重天还不够娴熟，不能使用诛仙决！\n");

        if (me->query("neili") < 200)
                return notify_fail("你的内力不够，不能使用诛仙决！\n");
 
       if (! living(target))
              return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

    if( objectp(me->query_temp("weapon")) )
   return notify_fail("你必须空手使用！\n");

//       if( !me->query("zhuanbest",1))
//        return notify_fail("你没有资格使用这项技能！\n");

       if( !me->query("4zhuan") && !me->query("5zhuan"))
        return notify_fail("你没有资格使用这项技能！\n");


	msg = HIC "$N" HIC "随手拍出一掌，疾若奔马，如箭一般飞向$n"
              HIC "速度快的不可思议！\n" NOR;
 
	ap = me->query_skill("yinyang-shiertian", 1) * 3 / 2 + me->query("con") * 20 +
             me->query_skill("unarmed", 1);
	dp = target->query_skill("parry") + target->query("int") * 20 +
             target->query_skill("unarmed", 1);

        me->start_busy(4);
        me->add("neili", -50);
        if (ap / 2 + random(ap) < dp)
        {
		msg += HIG "然而$n" HIG "看破了$N" HIG
                       "的掌势，不慌不忙的躲过了这一击！\n" NOR;
        } else
	{
		me->add("neili",-75);
                damage = ap  + random(ap / 2);
                if (damage>58000) damage=58000;
if (me->query("zhuanfinal/1") ==1 && random(2)==0)
{
	if (userp(target))
	target->receive_wound("qi", target->query("qi")/8);
        if (!userp(target))
         target->receive_wound("qi", 900,me);
	msg +=RED"$N使用了斩仙决!!$n突然胸口一痛鲜血狂奔!\n"NOR;
}
else
if (me->query("zhuanfinal/2") ==1 && random(2)==0)
{
	if (userp(target))
	target->add("neili", -target->query("neili")/8);
        if (!userp(target))
         target->add("neili", -800);
	msg +=HIY"$N使用了破仙决!!$n突然内力消失!\n"NOR;
}
else
if (me->query("zhuanfinal/3") ==1 && random(2)==0)
{
	if (!target->is_busy())
	target->start_busy(4);
	msg +=HIY"$N使用了乱仙决!!$n突然手忙脚乱!\n"NOR;
}
                target->add("qi",-damage);
		target->add("eff_qi",-damage);
                msg +=HIR "$n" HIR "正在思虑这一掌的后势，掌力已至"
                                           "胸前，只听“噗”的一声，$n吐血三尺！\n" NOR;
me->start_busy(4);
	}

	message_vision(msg, me, target);
	return 1;
}
