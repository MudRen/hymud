#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;


string name() { return "tiezhang_yin"; }

string chinese_name() { return "����������"; }


int update_condition(object me, int duration)
{
int damage;
        if( duration < 1 ) return 0;
damage=me->query("qi",1)/7;
 if (damage>18000) damage=18000;
 message("vision", me->name() + HIB"��ɫ�Ұף���Ƥ���ϣ��䲻������һ����ս��\n"NOR, environment(me), me);
                tell_object(me, HIB "��е��ؿڴ����������ʹ��ȫ��ѪҺ����Ҫ����סһ��\n" NOR );
me->add("qi",-damage);
        if (!me->is_busy())
        me->start_busy(3);


        me->apply_condition(name(), duration - 1);

        if( duration < 1 ) return 0;
        return CND_CONTINUE;
}


