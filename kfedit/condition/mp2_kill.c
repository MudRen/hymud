#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
     if (!duration) return 0;
  	 if( duration%2==0 
		 //&& 
		 //interactive(me) 
		 && environment(me)->query("short")!="�ɴ�"
		 &&!environment(me)->query("no_fight")
		 && !me->is_fighting())
       {  me->start_busy(2);
          call_out("zuji", 0, me);    
     
	 }
if (!environment(me)->query("no_fight"))
{
        me->apply_condition("mp2_kill", duration - 1);
}
        return 1;
}


void zuji(object me)
{   
	object obj; 
	int maxpot;
	int maxexp;
	int maxskill;
	int i;
        if (!me) return;
	maxskill=me->query_skill("force",1);
	maxpot=me->query_temp("maxpot");
	maxexp=me->query("combat_exp",1);
        if (maxskill<150)
        maxskill=150;
        i=me->query_temp("team_count");
        if (!i) i=sizeof(me->query_team());
        if (i==0) i=1;
        if (!i) i=1;
        obj=new("/quest/menpai/kill");
         maxskill=maxskill*2/3;
if (!me->query("zhuanshen") && me->query("combat_exp",1) <=6000000) maxskill=maxskill/2+1;
	obj->move(environment(me));
	obj->initlvl(maxskill);
         obj->set("combat_exp",maxexp);
        obj->set("str", me->query("str"));
        obj->set("dex", me->query("dex"));
        obj->set("per", me->query("per"));
        obj->set("qi", me->query("max_qi")/2*i);
        obj->set("eff_qi", me->query("max_qi")/2*i);
        obj->set("max_qi", me->query("max_qi")/2*i);
        obj->set("eff_jing", me->query("max_jing")/2*i);
        obj->set("max_jing", me->query("max_jing")/2*i);
        obj->set("jing", me->query("max_jing")/2*i);
        obj->set("neili", me->query("max_neili")/2*i);
        obj->set("max_neili", me->query("max_neili")/2*i);
	
	message_vision(HIG"\n$N����$n���һ��������ȫȥ���ɣ�ɱ��!��\n"NOR,obj,me); 
	obj->kill_ob(me);
	obj->set_leader(me);
}

string query_type(object me)
{
	return "job";
}
