//轩辕古墓 幽明神通 幽明玄雷
#include <ansi.h>

inherit F_SSERVER;

int random_go(object victim,string* dirs);

int exert(object me)
{
        int success_adj, damage_adj,damage;
        string msg;
        int success, ap, dp, ap2, ap3, ap4, dp2, dp3, dp4,howlong;
object target;
success_adj = 130;
damage_adj = 130;



        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse() )
                return notify_fail("你要对谁施展这个法术？\n");





        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("只能在战斗中使用。\n");

        if (!target) target=me;


        if( random(me->query("max_neili")) < 850 ) {
                write("你的没有那么多内力\n");

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要用雷劈谁？\n");

        if((int)me->query("neili") < 700 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("jing") < 50 )
                return notify_fail("你无法集中精力瞄准！\n");

        me->add("neili", -250);
                me->receive_damage("jing", 10);

                return 1;
        }

       msg =  HIW "$N大喝一声：“雷神助我”，天空中顿时乌云密布，雷声滚滚\n
突然一个接一个黑色的闪电夹杂在滚滚的雷声中蒙的劈向$n\n" NOR;
        message_combatd(msg, me,target);		
if (random(me->query("combat_exp",1)) > target->query("combat_exp",1)/3 && living(target)){
            damage = (int)me->query_skill("hanbing-zhenqi");  //以基本内功和九阳神功的高低，取决杀伤力的大小！
            damage = 100+damage + random(damage);
            damage +=(int)(me->query_skill("taoism", 1)*8);
if (damage < target->query("qi") || userp(target))
{
            target->receive_damage("qi", damage);
            target->receive_wound("qi", damage);
}
		msg=HIC "结果一道闪电从$n身上透体而过，$n顿时被劈的焦黑！\n" NOR;
}
else
{
		msg="只见$n施展轻功连连跳跃，每一道闪电都从身边擦过！\n" NOR; 
}
message_combatd(msg, me,target);		

if ((int)me->query_skill("hanbing-zhenqi",1)> 380)
	{
      msg = HIW
"$N一声大喝“风神何在！”半空中一声闷雷\n
几阵旋风夹杂在雷声中扑面而来，$n被风刮的政不开眼睛\n
$N双手一推，旋风将$n紧紧的包裹起来......\n" 
NOR;

        success = 1;
        ap = me->query_skill("taoism");
        ap = ap * ap * ap /12 ;
        ap += (int)me->query("combat_exp");
        dp = (int)target->query("combat_exp");

        ap2 = (int)me->query_per();
        dp2 = (int)target->query_per();


        ap3 = (int)me->query("neili");
        dp3 = (int)target->query("neili");
        if( random(ap + dp + 2500*(ap2+dp2)+200*(ap3+dp3)) < (dp+2500*dp2+200*dp3) ) success = 0;


        if(success == 1 ){
                msg +=  HIR "$n周身被如刀刃般狂风刮的生疼，却始终无法移动半步！\n" NOR;
                target->start_busy(7);
                }           
        else {
                msg +=  HIR "$n嘴角路出一丝冷笑道：“雕虫小技，何足挂齿”双手一挥风平浪静！\n" NOR;   
                me->start_busy(1+random(2));        
              
        } 
me->add("neili", -150);
        message_vision(msg, me, target);
		
}		

if ((int)me->query_skill("hanbing-zhenqi",1)> 600)
	{
            if(random((int)me->query("max_neili")) >(int)target->query("max_neili")/2) {
                        message_vision(HIB"$N随有一挥，平地起来一团黑雾，瞬间包围着$n......\n"NOR, me,target);

 msg =  MAG "$N口中念念有词，突然从$N的身后出现无数的美女\n
$n正在差异中，只见美女渐渐靠近，霎时间变成无数黑色妖狐扑了过来\n" NOR;
        message_combatd(msg, me,target);		
            damage = (int)me->query_skill("hanbing-zhenqi");  
            damage = damage + random(damage);
            damage +=(int)(me->query_skill("taoism", 1)*8);
if (damage < target->query("qi") || userp(target))
{
            target->receive_damage("qi", damage);
            target->receive_wound("qi", damage);
}
		msg=HIC "大惊失措，不只如何应对，被妖狐咬的遍体鳞伤！\n" NOR;
                } else {
                        msg="$n不慌不忙，左手一挥，妖狐惨嚎一声，顿时灰飞烟灭！\n" NOR; 
                        me->start_busy(2);
                }
                me->add("neili", -150);
message_combatd(msg, me,target);	

}


        me->start_busy(3);
        return 3+random(5);
}


