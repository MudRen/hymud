// invocation.c

#include <ansi.h>
inherit F_SSERVER;

string get_name(string str)
{
        str="�������";
        return str;
}


int exert(object me)
{
        int invocation_time;
        object soldier;
object target;
int skill;    


        if( !me->is_fighting() )
                return notify_fail("ֻ��ս���в����ٻ��콫��\n");
        
        invocation_time=60+(200-(int)me->query_skill("taoism"));
        if(invocation_time<30) invocation_time=30;
        	
        	
        if((time()-me->query_temp("last_invocation"))<invocation_time)
            return notify_fail("��սй��콫�����Ƕ�����з��ˣ�\n");

        if((int)me->query_skill("taoism",1) < 100)
                return notify_fail("��Ļ��������������������ã�\n");

        if( (int)me->query("neili") < 550 )
                return notify_fail("��ķ��������ˣ�\n");

        if( (int)me->query("jing") < 280 )
                return notify_fail("��ľ����޷����У�\n");

if (!userp(me) && me->query_temp("nozh"))
	return notify_fail("�����޷��ٷ���\n");
if (!userp(me) &&  me->query_temp("zhrs",1)>30)
return notify_fail("����һ��ս�����ޡ�\n");
        message_vision(HIY"$N����һ�ѽ�,�૵����˼����������콫����������!! \n"NOR, me);

        me->add("neili", -150);
        me->receive_damage("neili", 80);
   

        skill=(int)me->query_skill("panshi-shengong",1);
        skill=skill*0.7;
        soldier = new("/d/biwu/hs");
        soldier->move(environment(me));
        soldier->set_temp("invoker",me);
        soldier->set("possessed", me);
	      soldier->set_name(HIY+this_player()->query("name")+"�Ļ����콫"NOR,({"tianjiang"}));
        soldier->invocation(me);
        soldier->initlvl(skill,18);
        soldier->set_temp("nozh",1);
if (!userp(me)) me->add_temp("zhrs",1);

 message_vision(HIY"$N "+HIY"�ȵ�����ּ ն����ħ��! \n"NOR, soldier,me);

        me->set_temp("last_invocation",time());
        me->start_busy(2+random(2));

        return 3+random(5);
}


