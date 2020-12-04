// yufeng_poison.c ”Ò∑‰’Î∂æ
// By Kayin @ CuteRabbit Studio 1999/3/23 new

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


        if( duration < 1 ) {
            tell_object(me, MAG"—ÃÀ¯≤–œº"NOR + "∑¢◊˜ÕÍ¡À°£\n");
                } else {
                        tell_object(me, MAG"—ÃÀ¯≤–œº"NOR + "∑¢◊˜¡À£¨ƒ„æıµ√…Ì…œ“ª’ÛΩ©¿‰£¨∆§∑ÙÕ∏≥ˆ“ª≤„◊œ…´°£\n");
                        message("vision", me->name() + "À∆∫ı∫‹≈¬¿‰£¨ªÎ…ÌΩ©”≤£¨≤ªÕ£µÿ¥Ú∂ﬂ‡¬£¨∆§∑Ù…œÕ∏≥ˆ“ª≤„πÓ“Ïµƒ◊œ…´°£\n", 
                                        environment(me), me);
                }
      me->receive_wound("qi",55 + random(100));
      me->receive_wound("jing", 50);
      me->apply_condition("canxia", duration - 1);
      me->start_busy(2);
   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}

