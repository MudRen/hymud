//Cracked by Roath
//bugong.c 霸王枪法之不攻
//writted by libai

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        object weapon;
        int mkee;

        int damage, ap, dp;

        int myskill,times, extra,i;
        string number;

        
        int b_time = (int)me->query_skill("bawang-qiang") / 50 + 2;
        if (b_time < 4) b_time = 4;
        if (b_time > 8) b_time = 10; 
        myskill = (int)me->query_skill("bawang-qiang", 1);  
        extra = (int)me->query_skill("bawang-qiang", 1);  


        if( !target ) target = offensive_target(me);

        
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "club")
                return notify_fail("你没用枪，怎么使出不攻！\n");
        
        if (me->query("neili") < 500) return notify_fail("你的内力太少。\n");
         if (me->query("jing") < 100) return notify_fail("你的精太少。\n");
       
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("不攻只能对战斗中的对手使用。\n");

        if( target->is_busy() )
                return notify_fail(target->name() + "还在犹豫不决，放胆攻击吧。\n");
    
        if(environment(me)!=environment(target))
                return notify_fail("你要攻击的人不在这里。\n");
     if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("不攻只能在战斗中使用。\n");

    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "club")
        return notify_fail(RED"开什么玩笑，武器不对？\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "taixuan-gong")
                return notify_fail("请使用太玄功!\n");

        if((int)me->query_skill("taixuan-gong",1) < 100)
                return notify_fail("你的太玄功还不够。。。\n"); 
        
        if( (int)me->query_skill("bawang-qiang", 1) < 80 )
                return notify_fail("你的霸王枪法不够娴熟，不能采用不攻。\n");

        msg = CYN "$N手中"RED"长枪"CYN"猛抖，脚踏奇步，登时涌起凛冽杀气，遥罩$n，似攻非攻，似守非守!
"HIR"不攻"CYN"一出，$n立时感到若不主动进攻，将陷於被动挨打的劣势。\n";
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 ) {
                msg += "$n连忙上前猛攻,但是却无从着手，不由陷入了两难的境地。\n" NOR;
                target->start_busy(5);
        } else {
                me->start_busy(3);
                msg += "可是$n也并不着急,反而收起兵刃急退数步。\n" NOR;
        }

        message_vision(msg, me, target);

      if(myskill <170){
                times = 3;        
                number = "三";}
            else
                if (myskill <190){
                    times = 4;
                    number = "四";}
                else
                    if(myskill <210 ){
                           times = 5;
                           number = "五";}
                     else{ 
                           times = 6;
                           number = "六";}


        damage = 300+me->query_str() + random(me->query_skill("club"));

message_vision(HIC"\n$N一声长啸，"+ weapon->query("name")+ HIC"光一转，闪电般连续向$n攻出了"+number+"枪，枪枪要命！\n"NOR,me,target);

                if (!target->is_busy()) target->start_busy(1);
        if (extra> 200) extra=200;
        for(i=1;i<=times;i++)
{
        me->add_temp("apply/attack", extra*2);
        me->add_temp("apply/damage", 2200);
                        msg = HIY "第"+chinese_number(i)+"枪-------> ”\n" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        
        me->add_temp("apply/attack", -extra*2);
        me->add_temp("apply/damage", -2200);
        me->receive_damage("jing", 20);
        me->add("neili", -(times*10));
me->start_busy(3);
}      
        me->add("neili",-100);
        return 1;
}