//By exp
//changed by wuyou@sk_xyj 2002-12-6

#include <condition.h>
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        string str;
        string msg;
        int extra;
        object weapon;
        object ob;              // 对手的武器
        int i,attack_time,skill,damage;        

        extra = me->query_skill("sanqing-jian",1);
        if ( extra < 60) 
                return notify_fail("你的三清剑法还不够纯熟！\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［幻剑］只能对战斗中的对手使用。\n");

    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
        return notify_fail(RED"开什么玩笑，武器不对？\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "kongdong-xinfa")
                return notify_fail("请使用崆峒心法!\n");

        if((int)me->query_skill("kongdong-xinfa",1) < 100)
                return notify_fail("你的崆峒心法还不够。。。\n"); 
                
        if( (int)me->query_skill("sword", 1) < 60 )
            return notify_fail("你的基本剑法太低！\n");
        if( (int)me->query_skill("force", 1) < 60 )
            return notify_fail("你的内功不够娴熟，使不出［幻剑］！\n");
        if( (int)me->query("max_neili") < 800 )
            return notify_fail("你现在内力修为不足，使不出［幻剑］！\n");    
        if( (int)me->query("neili") < 100 )
            return notify_fail("你现在内力不足，使不出［幻剑］！\n");         


        weapon = me->query_temp("weapon");
        if (extra > 200) extra=200;
        me->add_temp("apply/damage",1800);
        me->add_temp("apply/attack",extra*2);
        message_vision(HIW"$N手中的"+ weapon->name()+  "一出鞘，就化做一道光华击向$n，
一道弧形的光华：灿烂、辉煌、美丽。\n" + HIG"光华在闪动、变幻、高高在上，轻云飘忽，$n
只觉得这道光华彷佛就在自己眉睫间，却又不能确定它在那里？
它的变化，几乎已超越了人类能力的极限，几乎已令人无法置信。"NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIY"可是它确实在那里，而且无处不在。
可是就在$n已确定它存在时，它忽然又不见了。"NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(WHT"又奇迹般忽然出现，又奇迹般忽然消失。"NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR"所有的动作和变化，都已在一刹那间完成，终止。
就像是流星，却又像是闪电，却又比流星和闪电更接近奇迹。
因为催动这变化的力量，是由$N发出来的。"NOR,me,target);
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       me->add_temp("apply/damage",-1800);
       me->add_temp("apply/attack",-extra*2);
       me->add("neili", -100);
       me->start_busy(2);

if (me->query_skill("sanqing-jian",1) > 300 || !userp(me))
{
       msg = HIM "$N轻声长叹,使出了「那一剑的风情」,剑招中带着三分惊艳,三分潇洒,三分可爱和一分不可一世。\n";

 if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
        {
 skill=me->query_skill("sanqing-jian",1);
                if (! objectp(ob = target->query_temp("weapon")))
                {
                        msg += "\n"HIM "那剑犹如一道电光闪过,却比彩虹更加绚丽!"NOR"\n\n"HIR"结果$n已为$N的剑意所伤,哇,的一声吐出一口鲜血。\n\n" NOR;
                        
                        //me->start_busy(1);
                        
                        damage = 700 + skill;
                target->receive_damage("qi", damage,me); 
                target->receive_wound("qi", damage,me);
                        //target->start_busy(random(3));
                      
        message_vision(msg, me, target);
                } else
                {
                          msg += "\n"HIM"那剑犹如一道电光闪过,却比彩虹更加绚丽!"NOR"\n\n"HIR"结果$n已为$N的剑意所伤,哇,的一声吐出一口鲜血。\n" NOR;
                         // msg += "\n"YEL"那一剑,击掉了$n手里的"+ob->query("name")+"。\n\n"NOR;

                        ob->unequip();
                        damage = 700 + skill;
                target->receive_damage("qi", damage,me); 
                target->receive_wound("qi", damage,me);
                        //me->start_busy(1);
                        
        message_vision(msg, me, target);

                } 
            
        }
else
        {
                msg += HIM"那剑犹如一道电光闪过,却比彩虹更加绚丽!\n"NOR"\n"HIY"结果$n让自身真气灌注四周空间,消解了$N的剑意。\n" NOR;
                //me->start_busy(3);
                message_vision(msg, me, target);

        } 

 me->add("neili", -300);
me->start_busy(2);
}

       return 1;
}

