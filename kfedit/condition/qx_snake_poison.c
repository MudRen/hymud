#include <ansi.h>

int update_condition(object me, int duration)
{
   int damage,damage2;
damage=me->query("qi")/8;
damage2=me->query("jing")/8;
if (damage > 17000) damage=17000;   
if (damage2 > 17000) damage2=17000;   	
	

    me->receive_damage("jing", damage2);
    me->receive_wound("jing", damage2);

      me->start_busy(random(3)+1);

    me->receive_damage("qi", damage);
    me->receive_wound("qi", damage);
	
me->start_busy(4);
        me->apply_condition("qx_snake_poison", duration - 1);
if (me)
{
        message_vision(BLU"$N的身体发出诡异色的蓝光，混身经脉疼痛欲裂,扭结成怪异的肉筋.\n"NOR, me);
        tell_object(me, HIR "你中的七修蛇毒发作了！\n" NOR );
}
        if( duration < 1 ) return 0;
        return 1;
}


