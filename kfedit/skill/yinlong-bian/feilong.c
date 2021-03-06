#include <ansi.h>
#include <combat.h> 
#include "/kungfu/skill/eff_msg.h";

inherit F_SSERVER;

void attack_1();
void attack_2();
void attack_3();
void finish();
void attack(int n);

int perform(object me, object target)
{
        string msg;
        int ap, dp;
        int damage;
        int count;
        int i, attack_time;
        object weapon = me->query_temp("weapon");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［飞龙］只能对战斗中的对手使用。\n");

        if( (me->query_skill("yinlong-bian",1) < 150 )
        ||      (me->query_skill("jiuyin-zhengong",1) < 150 ) ) 
                return  notify_fail("你的功夫还不够娴熟，不会使用飞龙。\n");

        if( !weapon 
        ||      weapon->query("skill_type") != "whip"
        ||      me->query_skill_mapped("whip") != "yinlong-bian" ) 
                return  notify_fail("你现在无法使用飞龙。\n");

        if( me->query("neili") < 1500 )
                return notify_fail("你的内力不够。\n");


        msg = HIB "突然之间，" HIB "$N" HIB "身形一闪一晃，疾退数丈,"+ weapon->name() +
              HIB "从右肩急甩向后，陡地"
              HIB "鞭头击向\n" HIB "$n" HIB "面门。" HIB "$N" HIB "本来与"
              HIB "$n" HIB "相隔十丈有余,但"+ weapon->name() +
              HIB "说到便到，正如天"
              HIB "外\n游龙，矢矫而至。！\n" NOR;

        ap = me->query_skill("whip");
        dp = target->query_skill("parry");
        attack_time = 6;
        if (ap / 2 + random(ap * 2) > dp || random(3)==0)
        {
                msg += HIR "结果$p" HIR "被$P" HIR
                       "攻了个措手不及，目接不暇，疲于奔命！\n" NOR;
                count = ap / 10;
                if (!target->is_busy()) target->start_busy(3);
                attack_time += random(ap / 50);
        } else
        {
                msg += HIC "$n" HIC "见$N" HIC "鞭势狠辣，心下凛然，凝神应付。\n" NOR;
                count = 0;
        }
        message_combatd(msg, me, target);
        if (attack_time > 9)
                attack_time = 9;

        me->add_temp("apply/attack",200);
        me->add_temp("apply/damage",3000);
        for (i = 0; i < attack_time; i++)
        {
                if (! me->is_fighting(target))
                        break;
                COMBAT_D->do_attack(me, target, weapon, 0);
        }
        me->add_temp("apply/attack",-200);
        me->add_temp("apply/damage",-3000);
        //me->start_perform(8,"飞龙");
        msg = HIG "$N使出九阴银龙鞭的「飞龙」，将一条鞭子使的滴水不漏。\n"NOR;

        me->add_temp("apply/dodge",200);
// busy 在各个 callout 连续增加
        me->start_busy(2);
        message_vision(msg, me, target);
        call_out("attack_1",3);
        me->add("neili", -100);
        return 1;
}

void attack_1()
{
      object me = this_player();
      object target = offensive_target(me);
      if (me->is_fighting()) {
      attack(3);
      me->start_busy(2);
      call_out("attack_2",3); } else
      call_out("finish",1);
}

void attack_2()
{
      object me = this_player();
      object target = offensive_target(me);
      if (me->is_fighting()) {
      attack(4);
      me->start_busy(2);
      call_out("attack_3",3);} else
      call_out("finish",1);
}

void attack_3()
{
      object me = this_player();
      object target = offensive_target(me);
      if (me->is_fighting()) {
      attack(5);
      me->start_busy(1);
      call_out("finish",1);} else
      call_out("finish",1);
}

void finish()
{
      object me = this_player();
      message_vision(HIY"\n$N力气不济，鞭法缓了下来。\n"NOR, me);
      me->add_temp("apply/dodge",-200);
}

void attack(int n)
{
	object me = this_player();
	object target = offensive_target(me);
	int damage = me->query_skill("yinlong-bian", 1), p;
        object weapon = me->query_temp("weapon");
	string msg, dodge_skill;
        if( !weapon 
        ||      weapon->query("skill_type") != "whip"
        ||      me->query_skill_mapped("whip") != "yinlong-bian" )
		return;
	message_vision(HIY"\n$N突然抽空挥鞭向$n攻去！\n"NOR, me, target);
        damage=damage+100;
	if (	random(me->query("combat_exp")) > target->query("combat_exp")/3	)
	 {
		message_vision(HIR"但见飞舞的"+weapon->name()+"从天而下和$n缠在一起，一股排山倒海的内劲无声息的向$n胸口撞去！\n"NOR, me, target);
		damage = damage * n + random(damage);
		target->receive_damage("qi", damage);
		target->receive_wound("qi", random(damage));
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg = damage_msg(damage, "拉伤");
                msg += "( $n"+eff_status_msg(p)+" )\n";
		message_vision(msg, me, target);
	} else {
		dodge_skill = target->query_skill_mapped("dodge");
		if( !dodge_skill ) dodge_skill = "dodge";
		msg = SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
		message_vision(msg, me, target);
	}

}
