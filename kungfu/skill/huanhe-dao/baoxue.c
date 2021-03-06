#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int damage,extra, mypot, tapot,attp, defp;
        string msg,str; 
               int def,level, ap, dp;

        
        weapon = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招「暴雪天威」？\n");

        if(!me->is_fighting())
                return notify_fail("「暴雪天威」只能在战斗中使用！\n");
        if((int)me->query("max_neili") < 1500 )
                return notify_fail("你的内力不够！\n");
        if((int)me->query("neili") < 1500 )
                return notify_fail("你的内力不足！\n");
        if((int)me->query("jing") < 1500 )
                return notify_fail("你的精神不足，没法子施用外功！\n");
        if((int)me->query_skill("huanhe-dao", 1) < 100)
                return notify_fail("你的煊赫刀级别还不够，使用这一招会有困难！\n");
        if((int)me->query_skill("bawang-qiang",1)+100 < (int)me->query_skill("huanhe-dao",1))
                return notify_fail("此招需要领悟霸王枪法的意境。。。\n"); 
     if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("暴雪天威只能在战斗中使用。\n");

    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
        return notify_fail(RED"开什么玩笑，武器不对？\n"NOR);


        if ( !wizardp(me) && me->query_skill_mapped("force") != "taixuan-gong")
                return notify_fail("请使用太玄功!\n");
        if((int)me->query_skill("taixuan-gong",1) < 100)
                return notify_fail("你的太玄功还不够。。。\n"); 


        if ((int)me->query_skill("literate", 1)> 5 )
                return notify_fail("你觉得煊赫刀深奥之极，一时间难以领会。\n");

        message_combatd(HIW"\n$N运起寒气，身形一转，四周顿时冰冻数尺，空气中寒气逼人，$n只冻的忘记的抵抗！\n"NOR,me,target,"");
        me->set_temp("noauto",1);
        target->start_busy(1);
        damage=100+random(((int)me->query_skill("blade")))+(int)me->query_skill("blade");

        message_combatd(HIW"\n$N嘿嘿一声冷笑，竟然隐入雪花之中。$n大急，四下找寻$N，忽然背后一阵寒气随着\n"NOR,me,target,"");
        message_combatd(HIW"\n刀光狂袭过来！！！\n"NOR,me,target,"");
        
        extra=(int)me->query_skill("huanhe-dao", 1)/5;
        level=(int)me->query_skill("huanhe-dao", 1);
        if (extra> 200) extra=200;
        me->add_temp("apply/attack", extra);
        me->add_temp("apply/damage", 900); 
                
        message_combatd(HIY"飘雪式---$N手中$n"HIY"顺着雪势使出一招！\n"NOR,me,weapon,"");
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"));
        message_combatd(HIC"排雪式---$N手中$n"HIC"犹如扑风追影反撩！\n"NOR,me,weapon,"");
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"));
        message_combatd(HIB"劈雪式---$N手中$n"HIB"夹着翩翩刀光猛劈！\n"NOR,me,weapon,"");
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"));
        
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -900);
                
        if(random(me->query("combat_exp",1))>random(target->query("combat_exp",1))/4)
        {
                message_combatd(HIY"\n打斗中,一只金色大鹏鸟远远飞来！$N和$n都看呆了！\n"NOR,me,target,"");
                message_combatd(HIY"\n突然大鹏鸟用翅膀一扇,顿时狂风大作！\n"NOR,me,target,"");
                if(random(me->query("combat_exp",1))>target->query("combat_exp",1)/4)
                {
                        message_combatd(HIR"\n$N见机不可失,连忙攻出一招！\n"NOR,me,target,"");
                        target->receive_damage("qi",damage*2); 
                        target->receive_damage("jing",damage*2); 
                        message_combatd(HIR"\n狂风夹杂着碎石漫天飞舞,把$n砸得遍体鳞伤！\n"NOR,me,target,"");
                        target->receive_wound("qi",damage);
                        target->receive_wound("jing",damage);
                        COMBAT_D->report_status(target);
                        COMBAT_D->report_sen_status(target);
                 }  
                else 
                if(random(me->query("combat_exp",1))>target->query("combat_exp",1)/2)
                {
                        message_combatd(HIR"\n狂风夹杂着碎石漫天飞舞,把$n砸得遍体鳞伤！\n"NOR,me,target,"");
                        target->receive_wound("qi",damage);
                        COMBAT_D->report_status(target);
                }
                else  
                {
                        message_combatd(HIR"\n狂风夹杂着碎石漫天飞舞,把$N和$n砸得遍体鳞伤！\n"NOR,me,target,""); 
                        target->receive_wound("qi",damage);
                        target->receive_wound("jing",damage);
                        COMBAT_D->report_status(target);
                        me->receive_damage("qi",damage/10);
                        COMBAT_D->report_status(me);
                }        
        }
        me->delete_temp("noauto");
        me->receive_damage("jing", 100);
        me->add("neili", -100);
if (level>300)
{
   msg = HIC "\n$N念了几句咒语，右手一挥，周围顿时变的其冷无比！
$N运起凝血神功，一团刺骨的寒气向$n直逼而来！\n" NOR;
        
        
        if( random((int)me->query("max_neili")*4) > (int)target->query("max_neili") || random(3)==0)
        {
                
                msg += HIW"\n$n被$N发出的这团寒气包了个正着！\n\n" NOR;
                
                target->start_busy(2+random(3)); 
                
                msg +=  HIC ">>$N手中"+ weapon->name() + HIC"寒光一闪，身形也随着腾空而起，
随即一式"HIW"「寒光斩」"HIC"幻出无数刀光向$n迎面劈来！\n\n"NOR;
                                
                if (me->query_skill("parry") > random(target->query_skill("parry")))
                {
                        msg += HIC"$n还没想出该怎样拆招，一道血光已经象闪电一般，穿体而过！\n"NOR;
                        damage = (int)me->query_skill("parry", 1);
                        damage = damage + random(damage);
                        def=(int)target->query_temp("apply/armor");
                        //damage -=damage*def/3000;

                        damage -=damage*def/6000;
                        damage = damage + 100;
   						 if (damage > 5000) damage=5000;
                        target->receive_damage("qi", damage);
                        target->receive_wound("qi", damage/2);
                        message_combatd(msg, me, target, "");
                        COMBAT_D->report_status(target);
                }
                else 
                {
                        msg += HIC"$n忙一运功，往后一撤，无形中化解了这招的威力。\n"NOR;
                        message_combatd(msg, me, target, "");
                } 
                
                msg =   HIC">>$N手中"+ weapon->name() +""HIW"--寒光又闪，"HIC"$N也由静转动。
一动便急如风，脚踏奇门，刀走奇招，式式从$n意想不到的方位奇快劈出！\n" NOR;                
                       
                if (random(me->query("combat_exp")) > (target->query("combat_exp"))/4)
                {
                        msg += HIC"$n一阵手忙脚乱，不知该如何去招架这静若水、快如电的刀法！\n"NOR;
                        damage = damage + random(200);
                        if (damage > 5000) damage=5000;
                        if(damage<1)damage = 1;
                        target->receive_damage("qi",damage*3/2);
                        target->receive_wound("qi", damage);
                        message_combatd(msg, me, target, "");
                        COMBAT_D->report_status(target);
                }
                else
                {
                        msg += HIC"$n却心静如水，见招拆招，瓦解了$N这无声的攻势。\n"NOR;
                        message_combatd(msg, me, target, "");
                        
                }

                me->add("neili", -50);
               
        }
        else 
        {
                msg = WHT"\n$n早已经看出$N的企图，身形一闪，已避开了这团寒气。\n" NOR;
                message_combatd(msg, me ,target, "");
                me->start_busy(2);
                me->add("neili", -50);
               
        }       
}               

if (level>600)
{
  damage = (int)me->query_skill("huanhe-dao", 1) + (int)me->query_skill("blade", 1);
        damage = damage/2 + random(damage/2);
  if (damage > 5000) damage=5000;
  msg = MAG "\n\t☆★☆★"HIW"玉雪"HIG"为"HIB"骨"HIW"冰"HIG"为"HIR"魄，"HIY"幻梦"HIW"冰雪"HIM"落"HIC"晴空！"NOR""MAG"★☆★☆\n" NOR;                      
                     
        me->add("jing", -50);
        me->add("qi", -50);
        
        msg += WHT "\n\t～～～六月飞霜～～～\n" NOR;
        msg += WHT "\t\t\t千里冰雪谁人怨？\n" NOR;
        msg += HIC "\n炎炎烈日，晴空万里。$N哀嚎一声，顿时瑞雪纷飞，怨气冲天！\n" NOR;
        
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/5 || random(3)==0 ) 
        {
                msg += HIY "$n不知躲闪，被怨气包围了！\n" NOR;
                target->receive_damage("qi",damage);
                target->receive_wound("qi",damage);
                message_combatd(msg, me, target, "");
                COMBAT_D->report_status(target); 
                me->add("neili", -50);
        }
        else
        {
                msg += HIY "$n运功相抗，将怨气阻止在身体外围。\n" NOR;
                message_combatd(msg, me, target, "");
        }               
        
        msg = MAG "\n\t～～～冰雪碎梦～～～\n" NOR;
        msg += MAG "\t\t\t万物成灰一场空？\n" NOR;
        
        mypot=(int)me->query_skill("huanhe-dao");
        mypot=mypot*mypot*mypot + (int)me->query("combat_exp");

        tapot=(int)target->query_skill("parry");
        tapot=tapot+(int)target->query_skill("dodge")/10;
        tapot=tapot*tapot*tapot/10 + (int)target->query("combat_exp");
        
        msg += HIW "\n天空闪现霞光万道，隐隐约约$n看见天宫中仙子嬉戏，众仙聚宴。
$n不禁看的出神，猛然间一股寒气从后背袭来。\n" NOR;
        
        if( random( mypot+tapot ) > tapot/4 || !living(target) ) 
        {
                msg += HIY "$n早已进入梦幻之中尚未清醒，被刺了一个透心凉。\n" NOR;
                COMBAT_D->do_attack_damage(me, target);
                target->receive_wound("qi", damage);
                message_combatd(msg, me, target, "");
                COMBAT_D->report_status(target);                
                me->add("neili", -50);
        }
        else
        {
                msg += HIY "$n不被幻象所迷惑，避开了这股寒气。\n" NOR;
                message_combatd(msg, me, target, "");
        }
                
        msg = HIR "\n\t～～～踏雪寻梅～～～\n" NOR;
        msg += HIR "\t\t\t曲尽知谁解"HIW"冰心？\n" NOR;        
        msg += HIM "\n冰雪将尽，寒梅盛开。点点梅花，阵阵飘香。万朵梅花齐飘落，如点点寒星袭向$n。\n" NOR;
        
        if (me->query_skill("force") > random(target->query_skill("force")))
        {
                msg += HIY "$n被梅花花瓣打的遍体鳞伤。\n" NOR;
                target->receive_damage("qi",damage);
                target->receive_wound("qi",damage);

                message_combatd(msg, me, target, "");
                COMBAT_D->report_status(target);      
                me->add("neili", -50);
        }
        else
        {
                msg += HIY "$n居然不可思议的躲过了万朵花瓣！\n"NOR;
                message_combatd(msg, me, target, "");
        }
        
}               

if (level > 1000)
{
  msg = HIW
 "\n$N身影慢慢的浮现在你面前，只见$N洒出无数晶莹剔透的"RED"雪玲珑"NOR"\n"HIW"围绕在你周围，刀光剑影的世界霎时间沉寂在这柔和的雪光之中，好一记温柔\n缠绵的"HIG"玲珑雪"NOR"\n"HIM"纵情山水间，挥洒天地情!\n"NOR;

        ap = me->query_skill("huanhe-dao", 1);
        ap = ( ap * ap * ap / (3 * 350) );
        ap = ap*250 + (int)me->query("combat_exp");
        dp = target->query_skill("parry");
        dp = ( dp * dp * dp / (7 * 400) );
        dp = dp*250 + target->query("combat_exp");
        //if( random((ap + dp)/800+1) <  dp/2200 ) 
       if( random((ap + dp)/600+1) <  dp/2500 ) 
        {
                msg += HIY "可$n并没有被这绚丽的雪景所吸引,依然屹立在雪花飞舞的幻景中！\n\n"NOR;
                message_combatd(msg, me, target, "");
        } 
        else 
        {
                damage = 500+(int)me->query_skill("huanhe-dao",1)  +
        (int)me->query("jing") / 200 + random((int)me->query("jing") / 150 ) +
        (int)me->query("qi") / 200 + random((int)me->query("qi") / 150 );
                if (damage > 15000) damage=15000;
                
                msg += HIR "\n$n顿时沉寂在这梦一般的景象之中，如痴如醉中被雪玲珑击中了！\n\n" NOR;
                damage +=random(10);
                target->receive_damage("jing", damage/2);
                target->receive_damage("qi",damage);
                target->receive_wound("qi", damage);
                me->improve_skill("huanhe-dao", 1, 1);
                message_combatd(msg, me, target, "");
                COMBAT_D->report_status(target);
        }
}
        me->start_busy(3);
        
        return 1;
}
