// yufeng_poison.c ����붾
// By Kayin @ CuteRabbit Studio 1999/3/23 new

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	int damage;
   if( duration < 1 ) return 0;
   if( !living(me) ) {
      message("vision", me->name() + "ʹ��غ���һ����\n", environment(me), me);
   }
   else {
      tell_object(me, HIR "��Ȼһ�󳹹ǵ����������е�����뷢���ˣ�\n" NOR );
      message("vision", me->name() + "ͻȻ�����ڵ������������ϵ�����ץ��\n",
            environment(me), me);
   }
   damage=me->query("jing",1)/10+10;
if (damage>10000) damage=10000;
      me->receive_wound("jing", damage);
      me->apply_condition("yf_poison", duration - 1);
      if (!me->is_busy()) me->start_busy(3);
   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}
