// ss_poison.c
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
   int damage,damage2;
   if( duration < 1 ) return 0;
   if( !living(me) ) {
      message("vision", me->name() + HIG"��ҵغ���һ����\n", environment(me), me);
   }
   else {
      tell_object(me, HIB "��Ȼһ�ɺ�������һ������ӿ�����������е������������ˣ�\n" NOR );
      message("vision", me->name() + "ͻȻ���ڵ��ϣ�˫��������һ����ץ��\n",
            me);
   }

damage=me->query("qi")/10;
damage2=me->query("jing")/10;
if (damage > 8000) damage=8000;
if (damage2 > 8000) damage2=8000;
if (damage <10 ) damage=10;
if (damage2 <10 ) damage2=10;

me->receive_wound("qi", damage);
me->receive_wound("jing",damage2);

   me->start_busy(4);
   me->apply_condition("ss_poison", duration - 1);

   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}
