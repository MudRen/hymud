
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{

        int damage, p;
        string msg;
      
        damage = me->query_condition("qiankunyibang")/5 +2;
if (userp(me))
	{
	 damage *= me->query_con();
}
else
	{
 damage *= random(30)+1;		
}		
      
        tell_object(me, "ͻȻ��о��ؿ���ʹ�쳣��������������ͷ��ɢ���Ƶģ���Ѫ���˿ڿ���ӿ�˳�����\n");
message("vision", me->name() + "ͻȻһ�Բ�����˫�����أ��ŵ��㵹���������������۵�һ���³�����Ѫ����\n",
            environment(me), me);
//        tell_room(environment(me), HIR + me->name()+"ͻȻһ�Բ�����˫�����أ��ŵ��㵹���������������۵�һ���³�����Ѫ����\n" NOR,({ me }));
        me->receive_damage("qi", damage/2);
        me->receive_wound("qi", damage/2);
        me->start_busy(random(2));
        me->apply_condition("qiankunyibang", duration - 1);
        if( duration < 1 ) return 0;
        return CND_CONTINUE;
}
