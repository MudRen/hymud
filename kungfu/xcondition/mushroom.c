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
        tell_object(me, HIW "�����ڸо����õĶ��ˣ�\n" NOR );
        else
        tell_object(me, HIW "��θ��һ���ʹ��ͷ��ð������ĺ��飡\n" NOR ); 
        message("vision", me->name() + "���ְ�סθ������ɫ�Ұף�ͷ��ð������ĺ��Σ�\n",  
                        environment(me), me);
      me->receive_wound("qi",55 + random(100));
      me->receive_wound("jing", 50);
      me->apply_condition("mushroom", duration - 1);
      me->start_busy(2);
   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}


