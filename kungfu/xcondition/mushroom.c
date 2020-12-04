#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
        int i,dam_kee,dam_gin,dam_sen;
        
        i = 30/(duration+1);
    dam_kee = (int) me->query("max_qi")/i;
    dam_gin = (int) me->query("max_jing")/i;
    dam_sen = (int) me->query("max_jing")/i;

        if( duration < 1 )
        tell_object(me, HIW "你终于感觉到好的多了！\n" NOR );
        else
        tell_object(me, HIW "你胃里一阵绞痛，头上冒出豆大的汗珠！\n" NOR ); 
        message("vision", me->name() + "右手按住胃部，面色惨白，头上冒出豆大的汗滴！\n",  
                        environment(me), me);
      me->receive_wound("qi",55 + random(100));
      me->receive_wound("jing", 50);
      me->apply_condition("mushroom", duration - 1);
      me->start_busy(2);
   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}


