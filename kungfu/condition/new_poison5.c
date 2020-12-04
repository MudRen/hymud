// corpse_poison.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;


string name() { return "new_poison5"; }

string chinese_name() { return "自然伤害"; }

int update_condition(object me, int duration)
{
int damage;
        if( duration < 1 ) return 0;

 message("vision", me->name() + HIG"身上绿光一闪,自然之毒的伤害发作了。\n"NOR, environment(me), me);
damage=me->query("qi")/30;
tell_object(me, HIG "身上绿光一闪,自然之毒的伤害发作了。\n" NOR );
if (damage> 10000) damage=10000;
me->receive_wound("qi", damage);
me->receive_damage("qi", damage);
tell_object(me, HIG "你吐出的几口绿色的血液,全身无力。\n" NOR );

damage=me->query("jing")/30;
if (damage> 10000) damage=10000;
me->receive_wound("jing", damage);
me->receive_damage("jing", damage);
tell_object(me, HIG "你全身痛苦,神智有一些不清了！\n" NOR );


        
     if (!me->is_busy()) me->start_busy(2);


        me->apply_condition(name(), duration - 1);

        if( duration < 1 ) return 0;
        return CND_CONTINUE;
}
