//qianghun.c
//五岳枪魂
//Created by wuyou@sk_sjsh
//2003-8-12
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

void npc_attack( object invoker, object target, string npc, object where );



int perform(object me, object target)
{
        string msg;
        object weapon, where; 
        int damage, ap, dp, i,lmt;
        int j,k;
        weapon = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail(CYN"你要对谁施展「五岳枪魂」？\n"NOR);

        if(!me->is_fighting()) 
                return notify_fail(CYN"「五岳枪魂」只能在战斗中使用！\n"NOR); 
        
       if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("只能在战斗中使用。\n");

 if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "club")
        return notify_fail(RED"开什么玩笑，武器不对？\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "hanbing-zhenqi")
                return notify_fail("请使用寒冰真气!\n");

        if((int)me->query_skill("hanbing-zhenqi",1) < 200)
                return notify_fail("你的寒冰真气还不够。。。\n"); 

        if( (int)me->query("neili") < 1000 )
                return notify_fail(CYN"你的内力不足，召唤不出「五岳枪魂」。\n"NOR);

        if( me->query("max_neili") < 3000 )
                return notify_fail("你的内力修为甚浅，不足以用「五岳枪魂」。\n"NOR);
                

        if( (int)me->query("qi") < 200 || (int)me->query("jing") < 200  )
                return notify_fail(CYN"你身体太虚弱了，无法施展「五岳枪魂」！\n"NOR);

        if( (int)me->query_skill("wuyue-spear", 1) <400 )
                return notify_fail(CYN"你的五岳神枪不够纯熟，无法使出这招「五岳枪魂」！\n"NOR);
                
        if( (int)me->query_skill("club", 1) <400 )
                return notify_fail(CYN"你的基本枪法不够纯熟，无法使出这招「五岳枪魂」！\n"NOR);           

                
        msg = HIY "\n$N手举"+ weapon->query("name")+ HIY"直指苍天，仰天长啸："HIW"“五岳山神，助我除魔。”\n"NOR;            
        msg += HIY "\n啸声刚罢，天上一道闪电直落枪尖，幻化出一道绚烂的光芒！\n\n" NOR;
        msg += HIR "          ┏━┓                          ┏━┓\n"NOR;
        msg += HIR "          ┃"HIW"縱"HIR"┃ ┏━┓┏━┓┏━┓┏━┓ ┃"HIW"神"HIR"┃\n"NOR;
        msg += HIR "          ┃"HIW"橫"HIR"┃ ┃"HIW"五"HIR"┃┃"HIW"嶽"HIR"┃┃"HIW"槍"HIR"┃┃"HIW"魂"HIR"┃ ┃"HIW"槍"HIR"┃\n"NOR;
        msg += HIR "          ┃"HIW"五"HIR"┃ ┗━┛┗━┛┗━┛┗━┛ ┃"HIW"無"HIR"┃\n"NOR;   
        msg += HIR "          ┃"HIW"嶽"HIR"┃                          ┃"HIW"敵"HIR"┃\n"NOR;
        msg += HIR "          ┗━┛                          ┗━┛ \n"NOR;
        
        ap = me->query_skill("wuyue-spear", 1);
        ap = ( ap * ap * ap / (4 * 400) );
        ap = ap*250 + (int)me->query("combat_exp");
        dp = target->query_skill("parry");
        dp = ( dp * dp * dp / (4 * 300) );
        dp = dp*250 + target->query("combat_exp");      
        
        if( random((ap + dp)/200) >  dp/1000 )
        {
                msg += HIY "\n天上一道五彩神光将$n笼罩，$n立即不能动弹。\n"NOR;
                msg += HIY "$N手中的"+ weapon->query("name")+ HIY"化作一道闪电，洞穿$n的身体！\n"NOR;
                
                damage = 300+(int)me->query_skill("club",1) / 2 + (int)me->query_skill("wuyue-spear",1) 
                + random((int)me->query_skill("hanbing-zhenqi",1) / 2) + random((int)me->query_skill("force",1) / 2)
                + (int)me->query("str") + me->query("jaili");
                
                //if(!target->is_busy())
                //        target->start_busy(2);
                        
                target->receive_damage("qi", damage,me);
                target->receive_wound("qi", damage,me);   
                target->receive_damage("jing", damage/2,me);
                target->receive_wound("jing", damage/3,me); 
                message_vision(msg, me, target);
                COMBAT_D->report_status(target);                                
                
                me->add("neili", -100);
                me->receive_damage("qi", 100);                
        }
       msg = HIY  "$N枪意绵绵，仿佛如椽巨笔饱墨临纸，手中的\n"+ weapon->name()+  "如狂风暴雨般地向$n卷来！\n\n" NOR;
        message_vision(msg,me,target);
        lmt = random(4)+3;
        		       me->add_temp("apply/attack", 150);    
        me->add_temp("apply/damage", 1500);
        for(i=1;i<=lmt;i++)
        {
        msg =  HIC "$N大喝一声：接第"+chinese_number(i)+"枪！\n" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        }
		       me->add_temp("apply/attack", -150);    
        me->add_temp("apply/damage", -1500);
 
 
                if (random(2)==1 && (int)me->query_skill("wuyue-spear", 1)>= 380)
                {
                        msg += HIY "\n瞬间，五派掌门屹立在$n的面前，对$n发动攻击！\n"NOR;
                        message_vision(msg, me, target); 
                        where=environment(target);

                  call_out("npc_attack", 1, me, target, "/kungfu/class/songshan/zuo", where);
                  call_out("npc_attack", 1, me, target, "/kungfu/class/henshan/moda", where);
                  call_out("npc_attack", 1, me, target, "/kungfu/class/hengshan/xian", where);
                  call_out("npc_attack", 1, me, target, "/kungfu/class/taishan/tianmen", where);
                  call_out("npc_attack", 1, me, target, "/kungfu/class/huashan/yue-buqun", where);                                                                        
                        me->add("neili", -100);
                        //me->receive_damage("jing", 100);  
                }
                else
                {
                        msg += HIY "\n$n尚未等你召唤出"HIR"「五岳枪魂」"HIY",便向$N发动反击，$N不得不举枪相迎。\n"NOR;
                        message_vision(msg, me, target); 
                        me->receive_damage("qi", 20);  
                        me->receive_damage("jing", 20); 
                        me->add("neili", -20);
                }
     
     if ((int)me->query_skill("wuyue-spear", 1)>= 680)
     	{
                  
        i=(int)me->query("combat_exp");
        j=(int)target->query("combat_exp");
        k=(int)me->query_skill("wuyue-spear");
        me->add("neili",-100);

        me->delete("env/brief_message");
        target->delete("env/brief_message");
        message_vision(HIM"\n$N一挺手中"+weapon->name()+NOR+HIB"直刺$n！\n"NOR,me,target);

        if (i > random(j)) 
        {
                damage=100+k+(int)me->query("str");
                target->receive_damage("qi",damage);
                target->receive_wound("qi",damage/2);
                COMBAT_D->report_status(target);
        }
        //if (random(i)*7/8> random(j)) 
        if (i > random(j)) 
        {
                message_vision(HIM"\n$N一枪刺空，又是一肘，仍击向"+HIB"$n"+HIM"！\n"NOR,me,target);
                damage=200+k+random(k)+(int)me->query("str");
                target->receive_damage("qi",damage);
                target->receive_wound("qi",damage/2);
                COMBAT_D->report_status(target);
        }
        //if (random(i)*5/6> random(j)) 
        if (i > random(j)) 
        {
                message_vision(HIR"\n$N一枪刺空，又是一肘，气势未减，仍击向"+HIB"$n"+HIR"！\n"NOR,me,target);
                message_vision(HIM"\n$N一肘又空，但仍不收招，双眼一瞪，一头撞向"+HIB"$n"+HIM"！\n"NOR,me,target);
                damage=300+k+random(k)*2+(int)me->query("str");
                target->receive_damage("qi",damage);
                target->receive_wound("qi",damage/2);
                COMBAT_D->report_status(target);
        }
        else 
                if (random(2)) 
                {
                        message_vision(HIR"\n$N一枪刺空，又是一肘，仍击向$n！\n"NOR,me,target);
                        message_vision(HIR"\n$N一肘又空，但仍不收着，一头撞向$n！\n"NOR,me,target);
                        message_vision(HIR"\n$N一头虽然撞空，但$n也被这拼命的举动吓了一跳！\n"NOR,me,target);
                        target->start_busy(5);
                }
                else 
                {
                        message_vision(HIM"\n$N一枪刺空，又是一肘，仍击向$n！\n"NOR,me,target);
                        message_vision(HIM"\n$N一肘又空，但仍不收着，一头撞向$n！\n"NOR,me,target);
                        message_vision(HIW"\n$n哈哈大笑，只逞匹夫只勇又有何用，轻松避开\n"NOR,me,target);
                }
	
     
    }
        me->start_busy(3);

        return 1;
       
}
                        
void npc_attack(object invoker, object target, string npc, object where)
{
        object attacker;
        int rd;
        string tid;

        if(!invoker || !target) return;

        if( environment(invoker) != environment(target) ) return;
        if( environment(target) != where) return;

        seteuid(getuid());
        attacker = new(npc);
        attacker->move(environment(invoker));
if (!target->is_busy()) target->start_busy(1);
        COMBAT_D->do_attack(attacker, target, attacker->query_temp("weapon"));

        // give the killing credit to the invoker.
        // so this would be counted as PK if the invoker is user.

        if(target->query_temp("last_damage_from")==attacker)
                target->set_temp("last_damage_from", invoker);
        
        if(target->query_temp("last_fainted_from")==attacker)
                target->set_temp("last_fainted_from", invoker->query("id"));
        
        destruct(attacker);
}
                             
