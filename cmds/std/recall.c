// mazemap.c

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{ 
        object mazeobj;
        string mazedd;
        if (me->is_busy())
                return notify_fail("��������æ��\n");

//if ((int)me->query("combat_exp",1) >6000000 && !me->query("hyvip"))
//return notify_fail("ֻ�л�Ա������Ҳſ���ʹ��������\n");

if(environment(me)->query("magicset")==1
       
       )
			return notify_fail("�˴��޷�ʹ�ã� ����ȫ�ǵ�·����������һ�ҡ�\n");

if (me->is_busy())
return notify_fail("������æ��\n");
if (me->is_fighting())
return notify_fail("�����ڴ�\n");

        if ((time() - me->query_temp("maze/map") < 3))
                return notify_fail("ϵͳ�������̾���������� ....\n");  
        

                
        if (me->query("jing") < 5)
                return notify_fail("�����ھ���״̬���ѣ����ǵȻ��ٲ�ɡ�\n");
        
        //mazeobj = me->query("startroom"); 
mazedd=me->query("startroom");

if (arg) mazedd="/d/city/guangchang";

if (!mazedd)
return notify_fail("�Ҳ������趨����������\n");
if(environment(me)->query("maze")) 
	{
	me->set_temp("nomg",1);
	me->start_busy(10);
}
        me->add("jing", -5);
        me->set_temp("maze/map", time());
        me->move(mazedd);

        return 1;
}