// corpse_poison.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;


string name() { return "new_poison6"; }

string chinese_name() { return "奥术伤害"; }

int update_condition(object me, int duration)
{
int damage;
        if( duration < 1 ) return 0;

 message("vision", me->name() + WHT"身上白光一闪,奥术的伤害发作了。\n"NOR, environment(me), me);

damage=(int)me->query("neili")/20;
if (damage> 10000) damage=10000;
if (damage< 1000) damage=1000;	
if ((int)me->query("neili")> damage)
{
//tell_object(me, WHT "伤害值:"+damage+"。\n" NOR );
me->add("neili", -damage);
tell_object(me, WHT "你身上白光一闪,奥术的伤害发作了。\n" NOR );
tell_object(me, WHT "你全身的力气消散在了空气中。\n" NOR );
}
       
     if (!me->is_busy()) me->start_busy(2);


        me->apply_condition(name(), duration - 1);

        if( duration < 1 ) return 0;
        return CND_CONTINUE;
}
