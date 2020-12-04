#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
//inherit F_CLEAN_UP;

string get_name(string str)
{
        str="不悔";
        return str;
}

string get_help(string str)                
{
        str="指令：ｐｅｒｆｏｒｍ　ｂｕｈｕｉ\n"
        +"条件：基本枪法100级，平天大法100级"
        +"命中率极高的绝招，威力不小！";
        return str;
}

int perform(object me, object target)
{
        object weapon;
        int i,j,k,damage,lmt;
        string msg;
        weapon = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要攻击谁？\n");

        if(!me->is_fighting())
                return notify_fail("你们没有在打架！\n");
                
     
        if((int)me->query("max_neili") < 1000 )
                return notify_fail("你的内功太差。\n");

        if((int)me->query("neili") < 500 )
                return notify_fail("你的内力不足！\n");

        if((int)me->query("jing") < 100 )
                return notify_fail("你的精神不足，没法子施用外功！\n");

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

                
        i=(int)me->query("combat_exp");
        j=(int)target->query("combat_exp");
        k=(int)me->query_skill("club");
        
        if(k<100)        
                return notify_fail("你的枪法级别还不够，使用这一招会有困难！\n");

        me->delete("env/brief_message");
        target->delete("env/brief_message");
        message_vision(HIM"\n$N一挺手中"+weapon->name()+NOR+HIB"直刺$n！\n"NOR,me,target);
//所以狠狠的加强了不悔。
//Wuyou@Sanjie
        //if (random(i)>random(j)) 
        if (i > random(j)) 
        {
                damage=300+k+(int)me->query("str");
                target->receive_damage("qi",damage,me);
                target->receive_wound("qi",damage/2,me);
                COMBAT_D->report_status(target);
        }
        //if (random(i)*7/8> random(j)) 
        if (i > random(j)) 
        {
                message_vision(HIM"\n$N一枪刺空，又是一肘，仍击向"+HIB"$n"+HIM"！\n"NOR,me,target);
                damage=400+k+random(k)+(int)me->query("str");
                target->receive_damage("qi",damage,me);
                target->receive_wound("qi",damage/2,me);
                COMBAT_D->report_status(target);
        }
        //if (random(i)*5/6> random(j)) 
        if (i > random(j)) 
        {
                message_vision(HIR"\n$N一枪刺空，又是一肘，气势未减，仍击向"+HIB"$n"+HIR"！\n"NOR,me,target);
                message_vision(HIM"\n$N一肘又空，但仍不收招，双眼一瞪，一头撞向"+HIB"$n"+HIM"！\n"NOR,me,target);
                damage=500+k+random(k)*2+(int)me->query("str");
                target->receive_damage("qi",damage,me);
                target->receive_wound("qi",damage/2,me);
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

        //me->receive_damage("jing", 30);
        me->add("neili", -100);
        me->receive_damage("qi", 30); 

        me->start_busy(3);
        return 1;
}


