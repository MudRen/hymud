//modify by Wuyou@Sanjie

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
        object weapon, ob;
        string msg, string1;
        int count;
//object weapon;
        if( !target ) target = offensive_target(me);
        
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail(CYN"你要对谁施展"HIW"「云龙九现」"CYN"？\n"NOR);
        
        if( !me->is_fighting(target) )
                return notify_fail(HIW"「云龙九现」"CYN"只能在战斗使用。\n"NOR);
                                  if( me->query_temp("yunlong_yushi"))
                return notify_fail(CYN"九龙未现，不能再次重复施展"HIW"「云龙九现」"CYN"！\n");
if( !target ) target = offensive_target(me);
        
       
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展？\n");

        if( !wizardp(me) && me->query_temp("weapon") )
                return notify_fail("你必须空手才能使用本门绝学!\n");

        if( objectp(me->query_temp("weapon")) )
return notify_fail("你必须空手才能使用本门绝学!\n");
    if( (string)me->query_skill_mapped("force")!= "jinghai-force")
     return notify_fail("必须靖海神功才行。\n");

      if( (int)me->query_skill("jinghai-force", 1) < 60 )
                return notify_fail("你的靖海神功还差些火候。\n");

        if( (int)me->query("neili") < 800 )
                return notify_fail(CYN"你的内力不够！\n");
                
        if( (int)me->query("qi") < 200 || (int)me->query("jing") < 200  )
                return notify_fail(CYN"你身体太虚弱了，无法施展"HIW"「云龙九现」"CYN"！\n"NOR);                
        
        if( (int)me->query_skill("dragonfight", 1) < 200 )
                return notify_fail(CYN"你的龙形搏击不够娴熟，不会使用"HIW"「云龙九现」"CYN"。\n");
                                
                        

        msg = HIW "\n$N突然吞云吐雾，化作一条神龙飞升天际。$N在云中急速穿梭，使出"HIC"龙形搏击"HIW"终极奥义"HIR"云龙九现！\n\n" NOR;
        message_vision(msg, me, target);
        target->start_busy(1);
        ob = me->select_opponent();
        me->delete_temp("yunlong");
        me->set_temp("yunlong",9);
        me->add("neili", -350);
        me->set_temp("yunlong_yushi",1);
        call_out("checking", 1, me, target);
        return 1;
}


void checking(object me, object target)
{
        string msg;
        int damage;
        damage = 10+(int)me->query_skill("dragonfight",1);
        
         if (me && !target) 
                {
                        tell_object(me, CYN"\n你现在没有和人过招，当下收回了云龙九现的攻势。\n\n" NOR);
                        me->delete_temp("yunlong_yushi");
                        me->delete_temp("yunlong");
                        return;
                }
        
        if (!me || !target) return;
        if ( me->query_temp("yunlong")  ) 
        {

                if ( (int)me->query("neili") < 200  ) 
                {
                        tell_object(me, CYN"\n你的内力后继不足，不得不停止云龙九现的攻势！\n\n" NOR);
                        me->delete_temp("yunlong_yushi");
                        me->delete_temp("yunlong");
                        return;
                }
                else if ( me->query_skill_mapped("unarmed") != "dragonfight" ) 
                {
                        tell_object(me, WHT "\n你不在使用龙形搏击，无法再以云龙九现攻敌！\n\n" NOR);
                        me->delete_temp("yunlong_yushi");
                        me->delete_temp("yunlong");
                        return;
                }
                else if (!me->is_fighting() || !target) 
                {
                        tell_object(me, CYN"\n你现在没有和人过招，当下收回了云龙九现的攻势。\n\n" NOR);
                        me->delete_temp("yunlong_yushi");
                        me->delete_temp("yunlong");
                        return;
                }
                else
                {
if (random(2)==0) target->start_busy(2);
me->add_temp("apply/attack", 180);
me->add_temp("apply/damage", 2200);
                        if ( me->query_temp("yunlong") ==9 )
                        {
                                msg = HIY "             〓赑屃驮碑〓\n\n" NOR;
                                msg += MAG "龙子赑屃身负石碑，缓缓而来！\n" NOR;
                             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
                        }
                        if ( me->query_temp("yunlong") ==8 )
                        {
                                msg = HIW "             〓螭吻望月〓\n\n" NOR;
                                msg += HIB "龙子螭吻眼望千里之外，悠然而来！\n" NOR;
                            	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
                        }
                        if ( me->query_temp("yunlong") ==7 )
                        {
                                msg = HIG "             〓饕餮吞天〓\n\n" NOR;
                                msg += HIC "龙子饕餮吃尽天下美食，满意而来！\n" NOR;
                              	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
                        }                       
                        if ( me->query_temp("yunlong") ==6 )
                        {
                                msg = HIR "             〓睚眦怒杀〓\n\n" NOR;
                                msg += WHT "龙子睚眦杀人无数，双手血腥，忿忿而来！\n" NOR;
                               	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
                        }        
                        if ( me->query_temp("yunlong") ==5 )
                        {
                                msg = HIC "             〓狴犴憎恶〓\n\n" NOR;
                                msg += CYN "龙子狴犴视恶如仇，大公无私，威然而来！\n" NOR;
                           	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
                        }  
                        if ( me->query_temp("yunlong") ==4 )
                        {
                                msg = HIR "             〓金猊吐火〓\n\n" NOR;
                                msg += HIM "龙子金猊嗜好烟火，身携真火而来！\n" NOR;
                               	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
                        }  
                        if ( me->query_temp("yunlong") ==3 )
                        {
                                msg = WHT "             〓趴蝮戏水〓\n\n" NOR;
                                msg += HIY "龙子趴蝮翻江倒海，隐于水中，携雨而来！\n" NOR;
                               	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
                        }  
                        if ( me->query_temp("yunlong") ==2 )
                        {
                                msg = MAG "             〓椒图守穴〓\n\n" NOR;
                                msg += HIW "龙子椒图闭门不出，来去匆匆！\n" NOR;
                               	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
                        }  
                        if ( me->query_temp("yunlong") ==1 )
                        {
                                msg = HIB "             〓蒲牢长鸣〓\n\n" NOR;
                                msg += HIG "龙子蒲牢通晓乐理，边走边唱！\n" NOR;
                             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
                        }
me->add_temp("apply/attack", -180);
me->add_temp("apply/damage", -2200); 
                                                                                                                                                                        
                        me->add("neili", -20);
                        if( !target ) target = offensive_target(me);
        
                        if( !target
                        ||      !target->is_character()
                        ||      target->is_corpse()
                        ||      target==me)
                        {
                                me->delete_temp("yunlong_yushi");
                                me->delete_temp("yunlong");
                                return;
                        }
                                
                        if(random(me->query("combat_exp")) > target->query("combat_exp")/5)
                        {       
                                target->receive_damage("qi", damage*2,me);
                                target->receive_wound("qi", damage*2,me);
                                COMBAT_D->report_status(target, 0);     
                                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
                        }
                        me->set_temp("yunlong", me->query_temp("yunlong")-1);
                        call_out("checking", 1, me, target);
                }
        }
        else 
        {
                message_vision(HIW "\n云开雾散，$N化为人形，傲然而立！\n" NOR, me);
                me->delete_temp("yunlong");
                call_out("yunlong_end", 1, me);
        }
}  
void yunlong_end(object me, object target)
{

        
        me->delete_temp("yunlong_yushi");
        if ( me->query_temp("yunlong")  ) 
        {
                tell_object(me, HIR "\n你暗自调息，渐渐平复腾涌的真气。\n\n" NOR);
        }
}

