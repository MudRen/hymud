//wuyou@sk_sjsh
//2003-3-13
//考虑到法术的伤害判断比较麻烦
//伤害数值变动太大
//我用了法术里命中判断的一般规则
//而伤害却使用了pfm中的判断方法
//考虑到如果反弹，这个cast的实用价值也就不是太大了


#include <ansi.h>


#include <combat.h>


inherit F_SSERVER;

int exert(object me)
{
        object target;
        string msg;

        string tar_spells,tar_dodge;

        int ap,dp,dg,damage,chance,skills1,skills2;

        if( !target ) target = offensive_target(me);

   	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("这门绝学只能对战斗中的对手使用。\n");

        if( !target
        ||   !target->is_character()
        ||   target->is_corpse()
        ||   target==me)
                return notify_fail("你要对谁用五行天雷？\n");
  
//        if( target->is_player() )
//                return notify_fail("五行天雷目前不允许对玩家使用。\n");

        if( !target 
         || !me->is_fighting(target) 
         || !living(target)
         || environment(target)!=environment(me))
                return notify_fail(WHT"「五行天雷」只能对战斗中的对手使用。\n"NOR);
        if( (int)me->query_skill("buddhism", 1) < 200 )
                return notify_fail("你的禅宗心法等级不够。\n");

        if (!target->is_fighting(me))
               return notify_fail("只有在战斗中才能使用五行天雷！\n");

        if((int)me->query("qi") < 500 )
                return notify_fail("你体力不足，用不了五行天雷！\n");

        if((int)me->query("neili") < 500 )
                return notify_fail("你须运足内力才能使用五行天雷！\n");


        if((int)me->query_skill("zhanzhuang-gong", 1) < 300 )
                return notify_fail("你的这门内功还不够纯熟。\n");


        msg = HIC"\n$N双目怒视$n，口中念道“般若波罗密，五雷天将助我伏魔！”
$N突然伸手一挥，刹那间，风起云涌，浓云密布，隐隐云端站着五雷天将。\n\n" NOR;

/*****************************************************************************/
/*第一击*/
        msg +=HIY "   ┏━┓\n";
        msg +=HIY "   ┃金┃\n";
        msg +=HIY "   ┗━┛\n\n"; 
        msg +=HIY "伴随着电闪雷鸣，一道金光化作一把利剑射向$n。\n"NOR;
 
        ap=(int)me->query_skill("buddhism", 1)
              +(int)me->query_skill("zhanzhuang-gong", 1)/2;

        
        damage=me->query_skill("buddhism");
        damage=(me->query_skill("buddhism")+me->query("str")*10+random(damage))*2;
        if (random(me->query_skill("force")) > target->query_skill("force")/3){
          msg += HIC "$n眼看着金光罩来，竟没法逼开，被金雷神将的金光牢牢罩住，$N连忙再出一道金光，"
              +"$n被劈了个正着！\n"NOR;
          message_vision(msg, me, target);
  
  	if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
          target->receive_damage("qi",damage,me);
          target->receive_wound("qi",damage,me);
          if(wizardp(me)) tell_object(me,sprintf("damage: %d \n",damage));
          COMBAT_D->report_status(target); 
}
else
	{
          msg += HIC "$n连忙后退将$N的金光逼开。\n"NOR;
          message_vision(msg, me, target);
          }
/***************************************************************************************/
/*第二击*/      
  if( (int)me->query_skill("buddhism", 1) > 150 )
{
        msg = HIG "   ┏━┓\n";
        msg +=HIG "   ┃木┃\n";
        msg +=HIG "   ┗━┛\n\n"; 
        msg +=HIG "天空雷声阵阵，木雷神将化身点点绿光冲向$n。\n"NOR;
        
        damage=me->query_skill("buddhism");
        damage=(me->query_skill("buddhism")+me->query("int")*10+random(damage))*2;
        
        if (random(me->query_skill("unarmed")) > target->query_skill("unarmed")/3){

            //damage = damage * 20 ;
            msg += HIC "结果$n被点点绿光透身而过！\n" NOR;
             	if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
            target->receive_wound("qi", damage,me);
            target->receive_damage("qi",damage,me);
            if(wizardp(me)) tell_object(me,sprintf("damage: %d \n",damage));
           
         }
         else
        {
            //damage = damage * 10 ;
            msg += HIC "$n左躲右闪，但还别绿光擦身而过！\n" NOR;
             	if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
            target->receive_wound("qi", damage,me);
            target->receive_damage("qi",damage,me);
            if(wizardp(me)) tell_object(me,sprintf("damage: %d \n",damage));   
         } 
         message_vision(msg, me, target);

         if( damage > 0 ) COMBAT_D->report_status(target);
         else if( damage < 0 ) COMBAT_D->report_status(me);
}
/*******************************************************************************/
/*第三击*/
  if( (int)me->query_skill("buddhism", 1) > 200 )        
{
        msg = HIW "   ┏━┓\n";
        msg +=HIW "   ┃水┃\n";
        msg +=HIW "   ┗━┛\n\n"; 
        msg +=HIW "水雷神将翻手为云，覆手为雨，倾盆大雨夹杂着冰刀迅猛而至。\n"NOR;

        damage=me->query_skill("buddhism");
        damage=(me->query_skill("buddhism")+me->query("con")*10+random(damage))*2;
        
        if (random(me->query_skill("parry")) > target->query_skill("parry")/3){
                msg += HIC"$n被冰刀戳的体无完肤！\n"NOR;
                  	if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
                target->receive_damage("qi", damage,me);
                target->receive_wound("qi", damage,me);
                if(wizardp(me)) tell_object(me,sprintf("damage: %d \n",damage));
                message_vision(msg, me, target);
                COMBAT_D->report_status(target,0);
         }
         else{
         msg += HIC"$n周围形成一个法力盾，没有受到丝毫伤害。"NOR;
         message_vision(msg, me, target);
        }
}
/**************************************************************************************/
/*第四击*/  
  if( (int)me->query_skill("buddhism", 1) > 250 )
{
        msg = HIR "   ┏━┓\n";
        msg +=HIR "   ┃火┃\n";
        msg +=HIR "   ┗━┛\n\n"; 
        msg +=HIR "火雷神将双掌并力将一巨大的火球推向$n！\n"NOR;

        damage=me->query_skill("buddhism");
        damage=(me->query_skill("buddhism")+me->query("dex")*10+random(damage))*2;
        
        if (random(me->query_skill("dodge")) > target->query_skill("dodge")/3){
                msg +=  HIC "火球在$n的身上炸开了！\n" NOR;
             	if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
                target->receive_damage("qi", damage,me);
                target->receive_wound("qi", damage,me);
                if(wizardp(me)) tell_object(me,sprintf("damage: %d \n",damage));
                message_vision(msg, me, target);
                if( damage > 0 ) COMBAT_D->report_status(target);

        } else
                {
                msg += HIC"但是被$n巧妙的躲开了！！\n";
                message_vision(msg, me, target);
                }      
}
/*****************************************************************************************/
/*第五击*/
  if( (int)me->query_skill("buddhism", 1) >= 300 )
{
        msg = MAG "   ┏━┓\n";
        msg +=MAG "   ┃土┃\n";
        msg +=MAG "   ┗━┛\n\n"; 
        msg +=MAG "土雷神将将五岳之峰搬到空中，砸向$n！\n"NOR;

        damage=me->query_skill("buddhism");
        damage=(me->query_skill("buddhism")+me->query("per")*10+random(damage))*2;
        
        if (random(me->query("combat_exp",1)) > target->query("combat_exp",1)/3){

                if( damage > 0 ) {

                        msg += HIC "结果$n被砸个正着，顿时血花飞溅，受伤不轻！\n" NOR;
                         	if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
                        target->receive_damage("jing", damage/2,me);
                        target->receive_wound("jing", damage/2,me);
                        target->receive_damage("qi", damage,me);
                        target->receive_wound("qi", damage,me);
                        if (!target->is_busy()) target->start_busy(3);
                        if(wizardp(me)) tell_object(me,sprintf("damage: %d \n",damage));
                }

             } 
        else
             {
                         msg += HIC"但是$n不费吹灰之力又将五岳搬回了原处。\n";
              }

        message_vision(msg, me, target);
        if( damage > 0 ) COMBAT_D->report_status(target);
        else if( damage < 0 ) COMBAT_D->report_status(me);
}

         me->add("neili", -500);


         me->start_busy(3);

         return 1;
}

