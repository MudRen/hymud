int valid_leave(object me, string dir)
{
object fang;



	if ( objectp(present("qi wushi", environment(me))) )
		return notify_fail("����ʿ��ס�����ȥ·��\n");




        if ((int)me->query_temp("marks/steps") == -10 && (int)me->query_temp("marks/step") == 16)
         {
            me->move(__DIR__"fangjian1");
            me->delete_temp("marks/steps");
            me->delete_temp("marks/step");
            me->set_temp("qijuok",1);
             return notify_fail("�����ھ���ʱ,�������ţ��������������֡�\n");
         }  

        if ((int)me->query_temp("marks/steps") == -11 && (int)me->query_temp("marks/step") == 17)
         {
            me->move(__DIR__"fangjian1");
            me->delete_temp("marks/steps");
            me->delete_temp("marks/step");
            me->set_temp("qijuok",1);
             return notify_fail("�����ھ���ʱ,�������ţ��������������֡�\n");
         }  

        if ((int)me->query_temp("marks/steps") == 10 && (int)me->query_temp("marks/step") == -16)
         {
            me->move(__DIR__"fangjian1");
            me->delete_temp("marks/steps");
            me->delete_temp("marks/step");
            me->set_temp("qijuok",1);
             return notify_fail("�����ھ���ʱ,�������ţ��������������֡�\n");
         }  

        if ((int)me->query_temp("marks/steps") == 11 && (int)me->query_temp("marks/step") == -17)
         {
            me->move(__DIR__"fangjian1");
            me->delete_temp("marks/steps");
            me->delete_temp("marks/step");
            me->set_temp("qijuok",1);
             return notify_fail("�����ھ���ʱ,�������ţ��������������֡�\n");
         }  


        if ((int)me->query_temp("marks/steps") >= 99 && (int)me->query_temp("marks/step") <= -99)
         {
            me->move(__DIR__"fangjian1");
            me->delete_temp("marks/steps");
            me->delete_temp("marks/step");
            me->set_temp("qijuok",1);
             return notify_fail("�����ھ���ʱ,�������ţ��������������֡�\n");
         } 
         
         


        if ((int)me->query_temp("marks/steps") >= 99 && (int)me->query_temp("marks/step") >= 99)
         {
            me->move(__DIR__"fangjian1");
            me->delete_temp("marks/steps");
            me->delete_temp("marks/step");
            me->set_temp("qijuok",1);
             return notify_fail("�����ھ���ʱ,�������ţ��������������֡�\n");
         }          


        if ((int)me->query_temp("marks/steps") <= -99 && (int)me->query_temp("marks/step") >= 99)
         {
            me->move(__DIR__"fangjian1");
            me->delete_temp("marks/steps");
            me->delete_temp("marks/step");
            me->set_temp("qijuok",1);
             return notify_fail("�����ھ���ʱ,�������ţ��������������֡�\n");
         }   

if (userp(me) && random(5)==0)
{
     	fang = load_object(__DIR__"npc/qiwushi");
	fang->move(environment(me));	
	fang->kill_ob(me);
		return notify_fail("ͻȻ����һ������ʿ��ס�����ȥ·��\n");	
	
}
 if ( (int)me->query_temp("marks/steps")> 11 )
 tell_object(me, "�����������ߵĳ�����Χ�ˡ�\n");
 
 if ( (int)me->query_temp("marks/steps")< -11 )
 tell_object(me, "���������ߵĳ�����Χ�ˡ�\n");
                  
 if ((int)me->query_temp("marks/step")>17 )
 tell_object(me, "���������ߵĳ�����Χ�ˡ�\n");

 if ((int)me->query_temp("marks/step")<-17 )
 tell_object(me, "�����������ߵĳ�����Χ�ˡ�\n");

 if ( (int)me->query_temp("marks/steps")> 0 && (int)me->query_temp("marks/step")>0 )
 tell_object(me, "����������̫���ˡ�\n");

if ( (int)me->query_temp("marks/steps")< 0 && (int)me->query_temp("marks/step")<0 )
 tell_object(me, "������������̫���ˡ�\n");

 if ( (int)me->query_temp("marks/steps")> 0 && (int)me->query_temp("marks/step")>0 )
 tell_object(me, "������������̫���ˡ�\n");

if ( (int)me->query_temp("marks/steps")< 0 && (int)me->query_temp("marks/step")<0 )
 tell_object(me, "����������̫���ˡ�\n"); 



 
 //tell_object(me, "w" + me->query_temp("marks/step") + "��\n");
 //tell_object(me, "s" + me->query_temp("marks/steps") + "��\n");

                   if (dir == "west")
         me->add_temp("marks/step",1);

        if (dir == "south")
          me->add_temp("marks/steps",1);
        if (dir == "east")
          me->add_temp("marks/step",-1); 
        if (dir == "north")
          me->add_temp("marks/steps",-1);
        return ::valid_leave(me, dir);
}

