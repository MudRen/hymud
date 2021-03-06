
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

string *dodge_msg = ({
	"$N不进不退，身形只是稍稍一转，宛若一道轻风般从$n身边掠过。\n",
	"$n眼前一花，居然连$N的影子都找不着了。\n忽然从头顶落下一串母鸡下蛋般的笑声，\n原来$N正如一头大鸟般往数丈开外滑翔过去。\n",
	"$N右脚踏了个虚步，双臂一振，顿时乘风而起，居然从$n头顶越了过去。\n",
	"$N左足一点，身形扶摇直上，却在半空中一个转折，轻飘飘地落在了$n身后。\n",
	"$N不慌不忙，身子如行云流水般往后一飘...再一飘，早避到了五尺开外。\n",
	"$N腰身微耸，顺势一掌按在有力无力之处，\n便如沾在$n这招上的一团轻絮，悠闲自得地将其化解。\n",
	"$N突然大喝一声：且慢！便在$n一楞之间，笑得合不拢嘴地退了开来。\n"
});

int perform(object me, object target)
{
        string msg;

int count;
        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("[逍遥仙步]只能在战斗中使用。\n");

  if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("只能在战斗中使用。\n");



        if ( !wizardp(me) && me->query_skill_mapped("force") != "jinghai-force")
                return notify_fail("请使用靖海神功!\n");

        if((int)me->query_skill("jinghai-force",1) < 50)
                return notify_fail("你的靖海神功还不够。。。\n"); 

        if((int)me->query("neili") < 500)
                return notify_fail(HIY "你现在真气不足。\n" HIY);
        if((int)me->query("qi") < 500)
                return notify_fail(HIY "你现在气不足。\n" HIY);

        if( target->is_busy() )
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");

	msg = HIG+dodge_msg[random(sizeof(dodge_msg))]+NOR;
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
count = (int)me->query_skill("xian-steps") / 60 + 2;
if( count > 5 ) count = 5;
   while( count-- )
         {
  object ob;
  me->clean_up_enemy();
  ob = me->select_opponent();
  if( !ob || (environment(ob) != environment(me))) {
  message_combatd(WHT "$N的身法如行云流水，宛若一道轻风。\n" NOR, me);
     break;
   }
  else

  message_combatd(HIG "$N腰身微耸，顺势一掌 ...\n" NOR, me, ob);
 COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
if (!me->query("double_attack"))
COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
  me->receive_damage("qi", 30);
  me->add("neili", -50);
 }
        return 1;
}
