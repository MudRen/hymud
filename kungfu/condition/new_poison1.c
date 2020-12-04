// corpse_poison.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;


string name() { return "new_poison1"; }

string chinese_name() { return "神圣伤害"; }

int update_condition(object me, int duration)
{
int damage;
        if( duration < 1 ) return 0;

 message("vision", me->name() + CYN"身上圣光一闪,神圣伤害发作了。\n"NOR, environment(me), me);
damage=me->query("qi")/20;
if (damage> 10000) damage=10000;
if (me->query("shen",1) < 0)
{
damage=damage*3;
me->receive_wound("qi", damage);
me->receive_damage("qi", damage);
tell_object(me, CYN "你身上圣光一闪,神圣伤害发作了。\n" NOR );
tell_object(me, CYN "你忽觉自己所做的坏事受到了审判，心中痛苦万分！\n" NOR );
}
        
        if (!me->is_busy()) me->start_busy(2);


        me->apply_condition(name(), duration - 1);

        if( duration < 1 ) return 0;
        return CND_CONTINUE;
}
