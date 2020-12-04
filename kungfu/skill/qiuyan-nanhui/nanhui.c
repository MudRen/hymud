
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

string *dodge_msg = ({
	"$N一式「雁渡寒潭」，身不倾，脚不移，身体如行云流水般直滑出丈余。\n",
	"$N一式「平沙落雁」，忽然一弯腰，全身贴地而行。\n",
	"$N一式「雁舞风堂」，一转身间，四面八方飘动着无数个$N的身影，令$n手足无措。\n",
	"$N一式「云雁惊厥」，长袖一拂，全身化为一道白影，幽幽地从$n头顶飘落。\n",
	"$N一式「雁影行洲」，身体如陀螺般急转，登时一股气流涌出，令$n难以动弹。\n",
});

int perform(object me, object target)
{
        string msg;

int count;
        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("[秋雁南回]只能在战斗中使用。\n");

  if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("只能在战斗中使用。\n");



        if ( !wizardp(me) && me->query_skill_mapped("force") != "huiyan-xinfa")
                return notify_fail("请使用回雁心法!\n");

        if((int)me->query_skill("huiyan-xinfa",1) < 50)
                return notify_fail("你的回雁心法还不够。。。\n"); 

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
count = (int)me->query_skill("qiuyan-nanhui") / 60 + 2;
  message_combatd(WHT "$N一转身间，四面八方飘动着无数个$N的身影。\n" NOR, me);
if( count > 5 ) count = 5;
   while( count-- )
	 {
  object ob;
  me->clean_up_enemy();
  ob = me->select_opponent();
  if( !ob || (environment(ob) != environment(me))) {

     break;
   }
  else

  message_combatd(HIG "$N长袖一拂，全身化为一道白影。.\n" NOR, me, ob);
  COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
if (!me->query("double_attack"))
  COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
  me->receive_damage("qi", 30);
  me->add("neili", -50);
 }

        return 1;
}
