// yufeng_poison.c ����붾
// By Kayin @ CuteRabbit Studio 1999/3/23 new

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
        int dam_kee,dam_gin,dam_sen;
        string msg;
        dam_kee = (int) me->query("max_qi")/10;
        dam_gin = (int) me->query("max_jing")/10;
        dam_sen = (int) me->query("max_jing")/10;
    if( duration < 1 )
        {
                tell_object(me, HIR "�������ܲ���" HIY "�����Ϻ�ɢ" HIR "�Ĵ������ã�ȫ���Ѷ�����\n" NOR );
                message("vision", me->name() + "ȫ�������ѡ�\n", environment(me), me); 
if (userp(me))
{
                me->unconcious();
if (random(8)==0)
{
me->die();
}
	
}


        }
   if( !living(me) ) {
      message("vision", me->name() + "ʹ��غ���һ����\n", environment(me), me);
   }
   else {
 tell_object( me, HIR "���е�" HIY "�����Ϻ�ɢ" HIR  "�����ˣ������ȫ�����Ȳ��ѣ�\n" NOR );
                msg = me->query("gender") == "����" ? 
                        "ͷ����췢�ȣ�����һ˫�۾����������������۹���Ҫ����ǹ⡣\n" 
                        : "����΢΢�����Ϸ���һ���һ��㵭���ĺ�ɫ�������ѽ��������Ĳ��������ƺ�Ҫ�γ�ˮ����\n" ;
                message("vision", "ֻ��" + me->name() + msg, environment(me), me);
   }
        me->receive_wound("qi", dam_kee);
    me->receive_wound("jing", dam_gin);
    me->receive_wound("jing", dam_sen);
        me->apply_condition("hehe", duration - 1);

      me->start_busy(2);
   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}
