// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// jiutian.c 九天式

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#define HUAN "「" HIR "寰阳式" NOR "」"

int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg,pmsg;
        int ap, dp;

                
        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }
        if (! target || ! me->is_fighting(target))
                return notify_fail("「九天式」只能对战斗中的对手使用。\n");

        if ((int)me->query_skill("liuyang-zhang", 1) < 120)
                return notify_fail("你的六阳掌法不够娴熟，不会使用「九天式」。\n");
                                
        if ((int)me->query_skill("force") < 300)
                return notify_fail("你的内功修为不够高，难以运用「九天式」。\n");
                        
        if ((int)me->query("neili") < 300)
                return notify_fail("你现在真气不够，不能使用「九天式」。\n");
                        
        msg = HIC "$N" HIC "双掌一振，化出满天掌影，团团笼罩住$n" HIC "！\n" NOR;

        ap = me->query_skill("strike"); 
        dp = target->query_skill("parry"); 
             
        if (ap / 2 + random(ap) > dp)
        {
                damage = me->query_skill("strike");
   target->add("qi",-damage*2);
		target->add("eff_qi",-damage*2);
                msg += HIR "$p" HIR "无奈，只能硬挡一招，结果被$P"
                                           HIR "震得连退数步，吐血不止！\n" NOR;

                me->start_busy(2);
        } else
        {
                msg += HIC "可是$p" HIC "强运内力，硬生生的挡住$P"
                       HIC "这一掌，没有受到任何伤害！\n"NOR;
                me->add("neili", -50);
                me->start_busy(3);
        }
        message_combatd(msg, me, target);

if( (int)me->query_skill("liuyang-zhang", 1) > 200 )
{
  msg = HIR "$N" HIR "双掌一振，施出天山六阳掌「寰阳式」，幻出"
              "满天掌影，团团罩住$n" HIR "。\n" NOR;

        me->add("neili", -50);
        
        ap = me->query_skill("strike"); 
        dp = target->query_skill("force"); 
             
        if (ap / 2 + random(ap) > dp)
        {
                damage = me->query_skill("strike");
   target->add("qi",-damage*2);
		target->add("eff_qi",-damage*2);
                msg += HIR "$n" HIR "见躲闪不得，只能硬挡下一"
                                           "招，顿时被$P" HIR "震得连退数步，吐血"
                                           "不止！\n" NOR;
                me->start_busy(3);
        } else
        {
                msg += HIC "可是$p" HIC "强运内力，硬生生的挡住$P"
                       HIC "这一掌，没有受到任何伤害。\n"NOR;
                me->start_busy(3);
        }
        message_combatd(msg, me, target);
}	


if( (int)me->query_skill("liuyang-zhang", 1) > 300 )
{

        msg = HIR "$N" HIR "将八荒六合唯我独尊功提运至极限，全身真气迸发，呼的一掌"
              "向$n" HIR "头顶猛然贯落。\n" NOR;

        me->add("neili", -500);
        ap = me->query_skill("strike") + me->query_skill("force"); 
        dp = target->query_skill("parry") + target->query_skill("force"); 
        
        //if (target->is_good()) ap += ap / 10;

        if (ap / 2 + random(ap) > dp)
        {
                damage = 0;
                if (me->query("max_neili") > target->query("max_neili") * 2)
                {
                        msg += HIR "顿时只听“噗”的一声，$N" HIR "一掌将$n"
                               HIR "头骨拍得粉碎，脑浆四溅，当即瘫了下去。\n"
                               NOR "( $n" RED "受伤过重，已经有如风中残烛，"
                               "随时都可能断气。" NOR ")\n";
                        damage = -1;
                } else
                {
                        damage = me->query_skill("strike");
   target->add("qi",-damage*2);
		target->add("eff_qi",-damage*2);
                msg += HIR "$n" HIR "慌忙抵挡，可已然不及，$N"
                                                   HIR "掌劲如洪水般涌入体内，接连震断数根"
                                                   "肋骨。\n" NOR;

                       
                }
                me->start_busy(3);
        } else
        {
                msg += CYN "$p" CYN "见$P" CYN "掌劲澎湃，决计抵挡不"
                       "住，当即身子向后横丈许，躲闪开来。\n" NOR;
                me->start_busy(4);
        }
        message_combatd(msg, me, target);
}	

if( (int)me->query_skill("liuyang-zhang", 1) > 380 )
{
 msg = WHT" \n只见$N" WHT "忽然掌缘隐隐泛出殷红之色，丝丝白气缭绕其间，转瞬间已将$P的手掌包了起来。\n" +
             "待得此时，$n" WHT "已觉不妙，哪知正待闪躲，$N" WHT "这招「" HIY "一掌震天" WHT "」已然推至胸前，来势虽\n" +
             "缓，但$p只觉身周的空气仿佛已经凝结，这一掌之力已将上下左右前后包了起来，实是难\n"+
             "以摆脱。瞬间的空气流动直如一个真空大洞，使得身周的人均觉得一阵气滞！\n\n"NOR;

        ap = me->query_skill("strike") + me->query("con") * 20; 
        dp =  target->query_skill("force") + target->query("con") * 20; 
             
        if (ap / 2 + random(ap) > dp)
        {
 damage = me->query_skill("strike");
   target->add("qi",-damage*2);
		target->add("eff_qi",-damage*2);
                pmsg = HIR "$n" HIR "眼见$N" HIR "一招已至，掌劲如洪，内力澎湃，然而苦于身陷旋涡之中，避无可避，只是\n" +
                       "稍微挪动脚步也已困难之极，结果被$N" HIR "一掌印在胸前，登感一阵痛入骨髓，却是肋骨被\n" +
                       "这一掌之力震断，气血翻涌已然失控，一口鲜血如箭般从口鼻中喷了出来！\n\n" NOR;
 damage = me->query_skill("strike");
   target->add("qi",-damage*2);
		target->add("eff_qi",-damage*2);
                msg += HIR "$n" HIR "眼见$N" HIR "一招已至，掌劲如洪，内力澎湃，然而苦于身陷旋涡之中，避无可避，只是\n" +
                       "稍微挪动脚步也已困难之极，结果被$N" HIR "一掌印在胸前，登感一阵痛入骨髓，却是肋骨被\n" +
                       "这一掌之力震断，气血翻涌已然失控，一口鲜血如箭般从口鼻中喷了出来！\n\n" NOR;
                //msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 65, pmsg);
                
                me->start_busy(3);      
        } else
        {
                msg += HIG "岂料$n" HIG "机敏异常，一眼道破$N" HIG "这招的破绽之处乃是旋涡的中心，其间极为薄弱，于是\n"+
                       "单手成指，竟刺破$N" HIG "的旋涡屏障，接连两指点在$P手心的" HIR "少府"
                       HIG "、" HIR "劳宫" HIG "二穴！结果$N" HIG "穴道被\n" +
                      "封，这内力无处宣泄，竟反蚀其身，震得$P脸如金纸，口唇紫青，查点受了内伤！\n\n" NOR;

                me->start_busy(3);
        }
        message_combatd(msg, me, target);
}	

        return 1;
}
