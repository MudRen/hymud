// huanyin_poison.c
#include <ansi.h>

int update_condition(object me, int duration)
{
   int damage,damage2;
damage=me->query("qi")/20;
damage2=me->query("jing")/20;
if (damage > 25000) damage=25000;   
if (damage2 > 25000) damage2=25000;   	
	
if ((int)me->query("jing") < 300000)
{
    me->receive_damage("jing", damage2);
    me->receive_wound("jing", damage2);
 }  else    me->receive_wound("jing", damage2);
      me->start_busy(random(3)+1);
if ((int)me->query("qi") < 300000)
{
    me->receive_damage("qi", damage);
    me->receive_wound("qi", damage);
}  else    me->receive_wound("qi", damage);
	
me->start_busy(2);
        me->apply_condition("huanyin_poison", duration - 1);
if (me)
{
        message_vision(HIG "$N" HIG "��ʹ���������һ����������"
              "����һ�ɵ�����������\n" NOR, me);
        tell_object(me, HIR "���Ȼ�е�һ�����Ե���Ķ�������͸����"
               "֫���࣬͸�������⡣��\n" NOR );
}
        if( duration < 1 ) return 0;
        return 1;
}



