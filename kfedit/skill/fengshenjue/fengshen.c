
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

string *dodge_msg = ({
     "$N一招"HIW"「轻衣胜雪踏凌波」，$n只觉一个影子晃过，却不见了$N的身影。\n",
     "$N一招"CYN"「弹剑击筑且作歌」，身体微微前倾，$n眼睛一花。\n",
     "$N脚下快步不停，一招"HIR"「三千红尘青丝断」，$n眼睛一花，站在原地不知道如何是好。\n",
     "$N一个"HIM"「长安道上对月酌」，长袖翻飞。\n",
     "$N息气上升，意存玉枕，一招"HIB"「永夜拋人何处去」，身子飘然而起。\n",
     "$N微微一笑，一招"HIY"「苦求乐土坠尘穹」，身如幻影，快如旋风，瞬间已站在了$n身后。\n",
     "$N一招"MAG"「犹带昭阳日影来」，凌空一个跟头翻身落在$n身后。\n",});


int perform(object me, object target)
{
        string msg;

int count;
        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("[风神步只能在战斗中使用。\n");

  if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("只能在战斗中使用。\n");



        if ( !wizardp(me) && me->query_skill_mapped("force") != "panshi-shengong")
                return notify_fail("请使用磐石神功!\n");

        if((int)me->query_skill("panshi-shengong",1) < 50)
                return notify_fail("你的磐石神功还不够。。。\n"); 

        if((int)me->query("neili") < 500)
                return notify_fail(HIY "你现在真气不足。\n" HIY);
        if((int)me->query("qi") < 500)
                return notify_fail(HIY "你现在气不足。\n" HIY);

        if( target->is_busy() )
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");

	msg = HIW+dodge_msg[random(sizeof(dodge_msg))]+NOR;
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 ) {
                msg += HIR "结果$p被$P绕得不知所措！\n" NOR;
                target->start_busy(5);
                me->add("neili", -100);
                       } else {
                msg +=  GRN"结果$P自己绕了个头晕眼花。\n"NOR;
                me->add("neili", -100);
                me->start_busy(2);
        }
        message_combatd(msg, me, target);
count = (int)me->query_skill("panshi-shengong") / 50 + 2;
  message_combatd(HIY "$N息气上升，意存玉枕，身子飘然而起。\n" NOR, me);
if( count > 4 ) count = 4;
   while( count-- )
	 {
  object ob;
  me->clean_up_enemy();
  ob = me->select_opponent();
  if( !ob || (environment(ob) != environment(me))) {

     break;
   }
  else

  message_combatd(HIR "$N身如幻影，快如旋风，长袖翻飞。.\n" NOR, me, ob);
  COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
if (!me->query("double_attack"))
  COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
  me->receive_damage("qi", 30);
  me->add("neili", -50);
 }

        return 1;
}
