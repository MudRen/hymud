#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
        int i,dam_kee,dam_gin,dam_sen;
        

        if( duration < 1 )
        tell_object(me, HIW "你身上不知中的什么毒终于发作光了！\n" NOR );
        else
        tell_object(me, HIW "你身上的毒素发作了！\n" NOR );
      me->receive_wound("qi",55 + random(100));
      me->receive_wound("jing", 50);
      me->apply_condition("unknown", duration - 1);
      me->start_busy(2);
   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}

