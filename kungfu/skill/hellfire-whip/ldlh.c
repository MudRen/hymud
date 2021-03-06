//write by yesi

#include <ansi.h>

inherit F_SSERVER;
void check_fight(object me);
void remove_effect(object me);


int perform(object me, object target)
{
        object weapon;
        int i,j;
                        
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
        {
return notify_fail("你要对谁施展「六道轮回」？\n");}
        
        if(time()-(int)me->query_temp("ldlh_end") < 10) 
                return notify_fail("不能频繁出入「六道轮回」！\n");

        
        if(me->query_temp("ldlh")) 
                return notify_fail("你正在使用「六道轮回」！\n"); 
        
            
        if(!me->is_fighting())
                return notify_fail("「六道轮回」只能在战斗中使用！\n");
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("这门绝学只能对战斗中的对手使用。\n");
    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "whip")
        return notify_fail(RED"开什么玩笑，武器不对？\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "zhanzhuang-gong")
                return notify_fail("请使用四平大马站桩功!\n");
        
        
        if((int)me->query("neili") < 1000 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("qi") < 300 )
                return notify_fail("你的气血不足，没法子施用外功！\n");
        
        
        if((int)me->query_skill("hellfire-whip", 1) < 250)
                return notify_fail("你的六道烈火鞭级别还不够，使用这一招会有困难！\n");

        if((int)me->query_skill("yijinjing", 1) < 150)
                return notify_fail("你的易筋经级别还不够，使用这一招会有困难！\n");

        
        
        
        weapon=me->query_temp("weapon");
        
       
        message_vision(HIW"\n$N口中念念有词：般若波罗密，般若波罗密，苦难众生与我共堕六道，再渡轮回。\n"NOR,me);
        me->set_temp("lunhui",0);
        me->set_temp("ldlh",1);
        me->set_temp("ldlh_time",6+random((me->query_skill("whip"))/6));
        
        call_out("check_fight", 1, me);
        return 1;
}


void check_fight(object me)
{
        object weapon;
        if(!me) return;        
        if( !objectp(weapon=me->query_temp("weapon")) ||
                (weapon->query("apply/skill_type") != "whip" &&
                weapon->query("skill_type") != "whip" ) || 
                me->query_skill_mapped("whip") != "hellfire-whip") 
                remove_effect(me);
        else if(me->query_temp("ldlh_time")<1 || !me->is_fighting())
                remove_effect(me);              
        else {  
                me->add_temp("ldlh_time",-1);
                call_out("check_fight", 1, me);
             }
}



void remove_effect(object me)
{       if(!me) return;
        remove_call_out("check_fight");
        me->delete_temp("ldlh");
        me->delete_temp("lunhui");
        message_vision(HIW"$N从「六道轮回」走了出来。\n"NOR, me);
        me->set_temp("ldlh_end", time() );
}


