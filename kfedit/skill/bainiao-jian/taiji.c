// modify by shao 2001.12.27
// 连续三招：太极分两仪，两仪生四象，四象化八卦，最后再合太极。
// 主要根据exp和skills来计算

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
string get_name(string str)
{
        str="太极";
        return str;
}



int perform(object me, object target)
{
        string msg;
        object weapon;
        int exp1, exp2,sword,parry,damage, wound;

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("你不在战斗中用什么用？\n");

if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("只能在战斗中使用。\n");

 if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
        return notify_fail(RED"开什么玩笑，武器不对？\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "honghua-shengong")
                return notify_fail("请使用红花神功!\n");

        if((int)me->query_skill("honghua-shengong",1) < 200)
                return notify_fail("你的红花神功还不够。。。\n"); 

        exp1 = (int)me->query("combat_exp",1);
        exp2 = (int)target->query("combat_exp");
        sword = (int)me->query_skill("bainiao-jian",1);
        sword = sword * sword * sword / 10;
        parry = (int)target->query_skill("parry",1);
        parry = parry * parry * parry / 10;

        if(me->query_skill("sword",1) < 100 )   
                return notify_fail("你的基本剑法太差了！\n");
        
        if(me->query_skill("bainiao-jian",1) < 100 )   
                return notify_fail("你的百鸟剑法太差了！\n");





        if(me->query("max_neili") < 800)
                return notify_fail("你的内力不够发挥太极的威力！\n");

        if(me->query("neili") < 800)
                return notify_fail("你的内力不够了！\n");

        weapon = me->query_temp("weapon");

        if ((int)me->query_skill("bainiao-jian",1) > 100)
        {
                msg = HIW "$N陡然出招变慢，手中的"+ weapon->query("name")+ HIW"竟画出一个太极，由中分成阴阳两极！           
         $N默默念道：“太极分两仪！\n"NOR;

                message_vision(msg, me, target);
        
                if( random( exp1 + sword )> ( exp2 + parry) / 4)
                {
                        msg = HIR "$n只觉得阴阳两极之势直逼过来，不知道如何躲闪，顿时被$N的"+ weapon->query("name")+ HIR"击了个正着！\n\n"NOR;
                        message_vision(msg, me, target);
                        me->add("neili",-30);
                        damage = (100 + me->query_str() + random(me->query_skill("bainiao-jian",1)/2 + me->query("force_factor")) / 2 );
                        wound=random(damage-(int)target->query_temp("apply/armor"));
                        if(wound>0) target->receive_wound("qi", wound);
                        target->receive_damage("qi", damage);
                        COMBAT_D->report_status(target, 0);
 
                }
                else
                {
                        msg = HIG "只见$n成竹在胸，轻松将其化解！\n\n"NOR;
                        message_vision(msg, me, target);
                        me->add("neili",-30);
                        me->start_busy(1);
                }
        }


        if ((int)me->query_skill("bainiao-jian",1) > 150)
        {
                msg = HIW "阴阳两极又随手中的"+ weapon->query("name")+ HIW"生出四象，从四个方向攻来！           
         $N默默念道：“两仪生四象！\n"NOR;

                message_vision(msg, me, target);

                if( random( exp1 + sword )> ( exp2 + parry) / 4)
                {
                        msg = HIR "$n一不留神，被$N打的无还手之力！\n\n"NOR;
                        message_vision(msg, me, target);
                        me->add("neili",-30);
                        damage = (150 + me->query_str() + random(me->query_skill("bainiao-jian",1)/2 + me->query("force_factor")) );
                        wound=random(damage-(int)target->query_temp("apply/armor"));
                        if(wound>0) target->receive_wound("qi", wound);
                        target->receive_damage("qi", damage);
                        COMBAT_D->report_status(target, 0);
 
                }
                else
                {
                        msg = HIG "$n镇定自若，将$N的攻势一一化解！\n\n"NOR;
                        message_vision(msg, me, target);
                        me->add("neili",-30);
                        me->start_busy(2);
                }
        }



        if ((int)me->query_skill("bainiao-jian",1) > 200)
        {
                msg = HIW "四象随即又生变化化为八卦！           
         $N默默念道：“四象化八卦！\n"NOR;
       
                message_vision(msg, me, target);
        
                if( random( exp1 + sword )> ( exp2 + parry) / 3)
                {
                        msg = HIR "只见剑影从乾、坤、震、坎、艮、离、巽、兑八方而至，$n立刻手忙脚乱，八个方位不能兼顾！\n\n"NOR;
                        message_vision(msg, me, target);
                        me->add("neili",-50);
                        damage = (250 + me->query_str() + random(me->query_skill("bainiao-jian",1) + me->query("force_factor")) / 2 );
                        wound=random(damage-(int)target->query_temp("apply/armor"));
                        if(wound>0) target->receive_wound("qi", wound);
                        target->receive_damage("qi", damage);
                        COMBAT_D->report_status(target, 0);
 
                }
                else
                {
                        msg = HIG "$n左挡右闪，毫不容易将其化解！\n\n"NOR;
                        message_vision(msg, me, target);
                        me->add("neili",-30);
                        me->start_busy(2);
                }
        }


        if ((int)me->query_skill("bainiao-jian",1) > 300)
        {
                msg = HIW "八卦又渐渐合而为一，形成一个太极！           
         $N默默念道：“八卦合太极！\n"NOR;
       
                message_vision(msg, me, target);
        
                if( random( exp1 + sword )> ( exp2 + parry) / 2)
                {
                        msg = HIR "一个巨大的太极向$n罩了过来，$n刚喘口气，又立刻被罩了个正着！\n\n"NOR;
                        message_vision(msg, me, target);
                        me->add("neili",-30);
                        damage=(me->query_kar() / 10+          random(me->query_skill("sword",1)) / 20 );
                        if ( damage > 6)
                        damage = 6;
                        target->start_busy(damage);
 
                }
                else
                {
                        msg = HIG "$n一招正中太极中心将其化解！\n\n"NOR;
                        message_vision(msg, me, target);
                        me->add("neili",-30);
                        me->start_busy(2);
                }
        }


        me->start_busy(2);

        return 1;
}


