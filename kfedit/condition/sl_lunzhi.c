// sl_lunzhi.c

#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
	object ob;

        seteuid(getuid());
        if (duration < 1)
	{
		tell_object(me,HIY"����ֵ��ʱ���ѵ������ȥ����(lunzhi ok)�ɣ�\n" NOR);
                return 0;
        }
	if (!duration) return 0;
		
		
		tell_object(me,HIY"��������ֵ������Ŀ�����Χ�������е㶯����\n" NOR);
  	 if( duration%2==0 
                 && environment(me)->query("short")!="�ɴ�"
		 &&!environment(me)->query("no_fight")
		 && !me->is_fighting())
       {  me->start_busy(2);
       			tell_object(me,HIY"��������ֵ������Ŀ�����Χ�������е㶯����\n" NOR);
          call_out("zuji", 0, me);    
     
	 }		
		
	me->apply_condition("sl_lunzhi", duration - 1);
        return 1;
}

string query_type(object me)
{
	return "job";
}
void zuji(object me)
{   
	object obj; 
	int maxpot;
	int maxexp;
	int maxskill;
        if (!me) return;
	maxskill=me->query_skill("force");
	maxpot=me->query_temp("maxpot");
	maxexp=me->query("combat_exp");
        if (maxskill<5)
        maxskill=5;
   	if(random(10)>6)
	{obj=new("/quest/menpaijob/lingxiao/wudang2"); 
obj->do_copy(me,maxpot,2);
obj->set("title",HIY"�䵱�ɵ���"NOR);     
obj->set("usename",me->query("name"));
obj->move(environment(me));
message_vision(HIY"$N��Ц����������Ҫ��ʶ��ʶ������������ʲô����?\n"NOR, obj);
me->kill_ob(obj);
obj->kill_ob(me);
	}
	else
		{
obj=new("/quest/menpaijob/lingxiao/emei2"); 
obj->do_copy(me,maxpot,2);
obj->set("title",HIG"�����ɵ���"NOR);
obj->set("usename",me->query("name"));
obj->move(environment(me));
message_vision(HIY"$N��Ц����������Ҫ��ʶ��ʶ������������ʲô����?\n"NOR, obj);
me->kill_ob(obj);
obj->kill_ob(me);
	obj->kill_ob(me);

}
}

