
#include <ansi.h>
inherit F_SSERVER;

#include "/kungfu/skill/eff_msg.h";

string get_name(string str)
{
        str="神猴狂舞";
        return str;
}

string get_help(string str)                
{
        str="指令：ｐｅｒｆｏｒｍ　ｗｕ\n"
        +"条件：释厄棍法法100级，基本棍法100级，基本内功100级，基本轻功120，最大内力1200"
        +"此perform按照释厄棍法法的级别划分为三个阶段：100级一击，220级两击，280级三击";        
        return str;
}

int def;

int perform(object me, object target)
{       
        object weapon1;
        string msg;
        int damage, p, time;
        object weapon;
        
        if( !target ) target = offensive_target(me);
        
        if( !target 
        || !target->is_character()
        || !me->is_fighting(target) 
        || !living(target) )
                return notify_fail("「神猴狂舞」只能在战斗中使用。\n");

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("这门绝学只能对战斗中的对手使用。\n");
                
    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "club")
        return notify_fail(RED"开什么玩笑，武器不对？\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "zhanzhuang-gong")
                return notify_fail("请使用四平大马站桩功!\n");


        if((int)me->query_skill("yijinjing", 1) < 150)
                return notify_fail("你的易筋经级别还不够，使用这一招会有困难！\n");
                
        if( (int)me->query_skill("club", 1) < 100 ||
           (int)me->query_skill("buddha-club", 1) < 100 )
                return notify_fail("你的棍法还不够娴熟，不会使用「神猴狂舞」。\n");
                
        if((int)me->query_skill("dodge", 1) <120)
                return notify_fail("以你现在的轻功修为如何「神猴狂舞」。\n");
                
        if((int)me->query_skill("force", 1) <100)
                return notify_fail("以你现在的内功修为还使不出「神猴狂舞」。\n");
                
        if( (int)me->query("max_neili") < 1200 )
                return notify_fail("以你现在的内功修为还使不出「神猴狂舞」。\n");
                
        if( (int)me->query("neili") < 600 )
                return notify_fail("你的真气不够！\n");
                
        msg = HIY "\n$N使出方寸山绝技「神猴狂舞」，身法陡然加快！\n" NOR;
        if (random(me->query("combat_exp")) > random(target->query("combat_exp")/3))
        {
                me->start_busy(2);
                target->start_busy(1);
                msg += YEL "\n$N忽然猛一吸气，抡棒回舞，向$n轻轻地劈出。"NOR;
                if ((int)me->query_skill("force", 1)> random((int)me->query_skill("force", 1)/4) || random(3)==0)
                {
                        msg += HIC "\n但见$n大喝一声，愈以内力克制,结果$n只挡住开始两招，就无法再维持澎湃的乱舞。\n" NOR;
                        damage = (int)me->query_skill("buddha-club", 1);
                        damage = damage + random(damage)+300;
                        //def=(int)target->query_temp("apply/armor_vs_force");
                        //damage -=damage*def/3000;
                        target->receive_damage("qi", damage,me);
                        target->receive_wound("qi", damage/2,me);
                        me->add("neili", -(damage/10));
                        p = (int)target->query("qi")*100/(int)target->query("max_qi");
                        msg += damage_msg(damage, "内伤");
                        msg += "( $n"+eff_status_msg(p)+" )\n";
                        message_vision(msg, me, target);
                        target->set_temp("last_damage_from", me);
                        if(me->query_skill("club", 1) > 219)
                        {
                                remove_call_out("perform2");
                                call_out("perform2", 0, me, target);    
                        }
                } 
                else 
                {
                        msg += HIC "\n初时似乎出手不重，但其波浪状的棍影后浪击前浪，一浪高过一浪，连绵不尽！\n"NOR;
                        message_vision(msg, me, target);
                        for (p=1;p<3+random(4);p++)
                        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
                        if(random(me->query_skill("buddha-club", 1))> 219)
                        {
                                remove_call_out("perform2");
                                call_out("perform2", 0, me, target);    
                        }
                }
        } 
        else 
        {       
                me->start_busy(2);
                me->add("neili", -100);                
                msg += HIG"可是$p伏地一滚，躲开了对手的攻击。\n"NOR;
                if(me->query_skill("buddha-club",1)>219)
                {
                        remove_call_out("perform2");
                        call_out("perform2", 0, me, target);    
                }
                message_vision(msg, me, target);
        }
        return 1;
}



int perform2(object me, object target)
{
        int damage, p,skill;
        object weapon1;
        string msg,weapon,force_skill,force_skill_name;
        if(!target||!living(target)) return notify_fail("对手已经不能再战斗了。\n");
        weapon = me->query_temp("weapon");  
        if( !(weapon1 = me->query_temp("weapon"))
        ||      (string)weapon1->query("skill_type") != "club" )
                return notify_fail("你以为你是谁？没棒也发神猴狂舞！\n");


        if( !target 
        || !target->is_character()
        || !me->is_fighting(target) 
        || !living(target) )
                return notify_fail("「神猴狂舞」现在没对手了呀。\n");
        if( (int)me->query("neili", 1) < 300 )
                return notify_fail("你待要再出第二击，却发现自己的内力不够了！\n");     
        if (random(5)>2)
                msg = HIC"\n但见$N倒拖兵器,突然一个仰身,大喝一声,募的绕身回劈,$n眼前一黑!!\n"NOR;
        else
                msg = HIG"\n但见$N倒拖兵器,突然狂啸一声,抡棍横扫,声势刚烈,$n早已吓慌了手脚!!\n"NOR;
        message_vision(msg, me, target); 
        if (random(me->query("combat_exp")) > target->query("combat_exp")/4  || random(3)==0)
        {
                //msg = CYN "$n惊骇之下，"NOR+HIR+force_skill_name+NOR+CYN"顿时破绽百出，$n根本无从招架！\n" NOR;
                msg = CYN "$n惊骇之下，顿时破绽百出，$n根本无从招架！\n" NOR;
                 //message_vision(msg, me, target); 
                me->start_busy(2);
                target->start_busy(2);
                damage = (int)me->query_skill("buddha-club", 1);
                damage = damage+(int)me->query_skill("force", 1);
                damage = damage +400;
                //def=(int)target->query_temp("apply/armor_vs_force");
                //damage -=damage*def/3000;
                target->receive_damage("qi", damage,me);
                target->receive_wound("qi", damage/2,me);
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg += damage_msg(damage, "内伤");
                msg += "( $n"+eff_status_msg(p)+" )\n";
                message_vision(msg, me, target);
                target->set_temp("last_damage_from", me);
                if(me->query_skill("buddha-club", 1) > 279)
                {
                        remove_call_out("perform3");
                        call_out("perform3", 0, me, target);    
                }
        } 
        else 
        {       
                me->start_busy(2);
//                me->add("neili", -200);                
                msg = WHT"可是$p料敌之先,抢攻几招，反逼$N连连后退。\n"NOR;
                if(me->query_skill("buddha-club", 1) > 279
                && me->query_skill("club", 1) > 279)
                {
                        remove_call_out("perform3");
                        call_out("perform3", 0, me, target);    
                }
        }
        message_vision(msg, me, target);
        return 1;
}


int perform3(object me, object target)
{
        int damage, p,skill;
        object weapon1;
        string msg,weapon,force_skill,force_skill_name,*limbs;
        if(!target||!living(target)) return notify_fail("对手已经不能再战斗了。\n");
        weapon = me->query_temp("weapon");  
        if( !(weapon1 = me->query_temp("weapon"))
             ||      (string)weapon1->query("skill_type") != "club" )
                return notify_fail("你以为你是谁？没棒也发神猴狂舞！\n"); 
        if(!living(target)) 
                return notify_fail("对手已经不能再战斗了。\n");
        if( !target 
        || !target->is_character()
        || !me->is_fighting(target) 
        || !living(target) )
                return notify_fail("神猴狂舞现在没对手了呀。\n");

        if( (int)me->query("neili", 1) < 800 )
                return notify_fail("你待要再出第四击，却发现自己的内力不够了！\n");     
        if (random(5)>2)
        {
                msg = HIC"\n$N一声咆哮，兵器竟然脱手飞出，如游龙般翱翔青宇，破空射向$n的左肩！\n"NOR;
                msg += HIC "$n大吃一惊，但见$N空手猱身而上，双手擒拿点拍，攻势凌厉之极!\n" NOR;
        }
        else 
                msg = HIG"\n$N长啸一声，一式「天地鹤翔」，腾空飞起，全身迸出无数道棍影，弥漫天际！\n"NOR;
        message_vision(msg, me, target); 
        if (random(me->query("combat_exp")) > random(target->query("combat_exp")/8)  || random(3)==0)
        {
                //msg = CYN "$n慌乱中已经来不及运起"NOR+HIR+force_skill_name+NOR+CYN",$N抡起就是一棒\n" NOR;
                msg = CYN "$n慌乱中已经来不及招架,$N抡起就是一棒\n" NOR;
                me->start_busy(2);
                target->start_busy(1);
                damage = (int)me->query_skill("unarmed", 1);
                damage = damage+(int)me->query_skill("force", 1)+500;
                
                //damage = damage*(1+random(3))/2+random(damage);
                def=(int)target->query_temp("apply/armor_vs_force");
 //               damage -=damage*def/3000;
                target->receive_damage("qi", damage,me);
                target->receive_wound("qi", damage,me);
                me->add("neili", -100);
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg += damage_msg(damage, "砸伤");
                msg += "( $n"+eff_status_msg(p)+" )\n";
                limbs = target->query("limbs");
                msg = replace_string(msg, "$l", limbs[random(sizeof(limbs))]);
                msg = replace_string(msg, "$w", weapon->name());    
                message_vision(msg, me, target);
                target->set_temp("last_damage_from", me);
                me->start_busy(2);

                        msg += HIC "\n初时似乎出手不重，但其波浪状的棍影后浪击前浪，一浪高过一浪，连绵不尽！\n"NOR;
                        message_vision(msg, me, target);
                                        me->add_temp("apply/attack",100);
                me->add_temp("apply/damage",1200);  
                        for (p=1;p<3+random(4);p++)
                        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
                                        me->add_temp("apply/attack",-100);
                me->add_temp("apply/damage",-1200);  

        } 
        else 
        {       
                        msg += HIC "\n初时似乎出手不重，但其波浪状的棍影后浪击前浪，一浪高过一浪，连绵不尽！\n"NOR;
                        message_vision(msg, me, target);
                                                              me->add_temp("apply/attack",100);
                me->add_temp("apply/damage",1200);  
                        for (p=1;p<3+random(4);p++)
                        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
                                        me->add_temp("apply/attack",-100);
                me->add_temp("apply/damage",-1200);  
                me->start_busy(2);

                msg = HIC"可是$p一个反身,轻轻躲过$N凌厉的进攻。\n"NOR;
                message_vision(msg, me, target);
        }

        return 1;
}


