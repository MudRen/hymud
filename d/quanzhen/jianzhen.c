inherit ROOM;

#include <ansi.h>
void create()
{
  set("short",HIG"��������"NOR);
  set("long",@LONG
�����ϼ��������˶������Ź��ű������������ȴ������������������ۼ�ʶ������ 
��������ʱ,�����׵�����߲��ó����м�,ȴ�����Ե��²������,����һ��������˹���,
��ȷ�����ɵ����������������,���ǽ������д�һ��,�����Ȼ�޷��ӳ�.����������
���ƶ�,������βӦ,��β����Ӧ,��������β��Ӧ,���ν������������С�
LONG);

     set("outdoors", "xiaoyao");
     set("exits",([
           "east" : __DIR__"jianzhen",
           "west" : __DIR__"jianzhen",
           "north" : __DIR__"jianzhen",
           "south" : __DIR__"jianzhen",
     ]));
 	set("objects", ([
		__DIR__"npc/qiwushi" : 3,
	]));
     setup();
}
int valid_leave(object me, string dir)
{
object fang;



	if ( objectp(present("qz dizi", environment(me))) )
		return notify_fail("ȫ�������ס�����ȥ·��\n");




        if ((int)me->query_temp("marks/steps") == -12 && (int)me->query_temp("marks/step") == 18)
         {
            me->move(__DIR__"damen");
     	fang = load_object("/kungfu/class/xueshan/huodu");
	fang->move(environment(me));	
        fang->kill_ob(me);    
            me->delete_temp("marks/steps");
            me->delete_temp("marks/step");
            me->set_temp("qijuok",1);
             return notify_fail("�����ھ���ʱ,�������ţ����������������\n");
         }  

        if ((int)me->query_temp("marks/steps") == -13 && (int)me->query_temp("marks/step") == 19)
         {
            me->move(__DIR__"damen");
     	fang = load_object("/kungfu/class/xueshan/huodu");
	fang->move(environment(me));	
        fang->kill_ob(me);    
            me->delete_temp("marks/steps");
            me->delete_temp("marks/step");
            me->set_temp("qijuok",1);
             return notify_fail("�����ھ���ʱ,�������ţ����������������\n");
         }  
         

        if ((int)me->query_temp("marks/steps") == 13 && (int)me->query_temp("marks/step") == -19)
         {
            me->move(__DIR__"damen");
     	fang = load_object("/kungfu/class/xueshan/huodu");
	fang->move(environment(me));	
        fang->kill_ob(me);    
            me->delete_temp("marks/steps");
            me->delete_temp("marks/step");
            me->set_temp("qijuok",1);
             return notify_fail("�����ھ���ʱ,�������ţ����������������\n");
         }  
         
        if ((int)me->query_temp("marks/steps") == 12 && (int)me->query_temp("marks/step") == -18)
         {
            me->move(__DIR__"damen");
     	fang = load_object("/kungfu/class/xueshan/huodu");
	fang->move(environment(me));	
        fang->kill_ob(me);    
            me->delete_temp("marks/steps");
            me->delete_temp("marks/step");
            me->set_temp("qijuok",1);
             return notify_fail("�����ھ���ʱ,�������ţ����������������\n");
         }  


        if ((int)me->query_temp("marks/steps") >= 99 && (int)me->query_temp("marks/step") <= -99)
         {
            me->move(__DIR__"damen");
     	fang = load_object("/kungfu/class/xueshan/huodu");
	fang->move(environment(me));	
        fang->kill_ob(me);    
            me->delete_temp("marks/steps");
            me->delete_temp("marks/step");
            me->set_temp("qijuok",1);
             return notify_fail("�����ھ���ʱ,�������ţ����������������\n");
         }  

        if ((int)me->query_temp("marks/steps") >= 99 && (int)me->query_temp("marks/step") >= 99)
         {
            me->move(__DIR__"damen");
     	fang = load_object("/kungfu/class/xueshan/huodu");
	fang->move(environment(me));	
        fang->kill_ob(me);    
            me->delete_temp("marks/steps");
            me->delete_temp("marks/step");
            me->set_temp("qijuok",1);
             return notify_fail("�����ھ���ʱ,�������ţ����������������\n");
         }  


        if ((int)me->query_temp("marks/steps") <= -99 && (int)me->query_temp("marks/step") >= 99)
         {
            me->move(__DIR__"damen");
     	fang = load_object("/kungfu/class/xueshan/huodu");
	fang->move(environment(me));	
        fang->kill_ob(me);    
            me->delete_temp("marks/steps");
            me->delete_temp("marks/step");
            me->set_temp("qijuok",1);
             return notify_fail("�����ھ���ʱ,�������ţ����������������\n");
         }  


 if ( (int)me->query_temp("marks/steps")> 13 )
 tell_object(me, "�����������ߵĳ�����Χ�ˡ�\n");
 
 if ( (int)me->query_temp("marks/steps")< -13 )
 tell_object(me, "���������ߵĳ�����Χ�ˡ�\n");
                  
 if ((int)me->query_temp("marks/step")>19 )
 tell_object(me, "���������ߵĳ�����Χ�ˡ�\n");

 if ((int)me->query_temp("marks/step")<-19 )
 tell_object(me, "�����������ߵĳ�����Χ�ˡ�\n");

 



 if ( (int)me->query_temp("marks/steps")> 0 && (int)me->query_temp("marks/step")>0 )
 tell_object(me, "����������̫���ˡ�\n");

if ( (int)me->query_temp("marks/steps")< 0 && (int)me->query_temp("marks/step")<0 )
 tell_object(me, "������������̫���ˡ�\n");

 if ( (int)me->query_temp("marks/steps")> 0 && (int)me->query_temp("marks/step")>0 )
 tell_object(me, "������������̫���ˡ�\n");

if ( (int)me->query_temp("marks/steps")< 0 && (int)me->query_temp("marks/step")<0 )
 tell_object(me, "����������̫���ˡ�\n");


         
if (userp(me) && random(5)==0)
{
     	fang = load_object(__DIR__"npc/qiwushi");
	fang->move(environment(me));	
	fang->kill_ob(me);
		return notify_fail("ͻȻ�����������˱仯������һ��ȫ�������ס�����ȥ·��\n");	
	
}
if (wizardp(me))
{
 tell_object(me, "marks/steps" + me->query_temp("marks/step") + "��\n");
 tell_object(me, "marks/step" + me->query_temp("marks/steps") + "��\n");
}
                   if (dir == "east")
         me->add_temp("marks/step",1);

        if (dir == "west")
          me->add_temp("marks/step",-1); 


        if (dir == "south")
          me->add_temp("marks/steps",1);
        if (dir == "north")
          me->add_temp("marks/steps",-1);
        return ::valid_leave(me, dir);
}

