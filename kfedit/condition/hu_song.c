#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
     if (!duration) return 0;
  	 if( duration%2==0 
		 //&& 
		 //interactive(me) 
		 &&!environment(me)->query("no_fight")
                 && environment(me)->query("exits")
//		 && strsrch(environment(me)->query("short"),"��")==0
		 && !me->is_fighting()
//&& random(2)==0
		 )
       {
         me->start_busy(3);
          call_out("zuji", 0, me);    
     
	 }
if (!environment(me)->query("no_fight"))
{
        me->apply_condition("hu_song", duration - 1);
}
        return 1;
}


void zuji(object me)
{   
	object obj; 
	int maxpot,maxexp;
	me=this_player();
        if (!me) return;
	maxpot=me->query_skill("force",1);
        maxexp=me->query("combat_exp",1);
if (!maxpot) maxpot=100;

   	if(random(5)==1)
	{obj=new("quest/hyhusong/skiller"+sprintf("%d",random(3)+1));
	 //maxpot=maxpot+10+random(10);
	 obj->set("title",HIR"����һ��"NOR);
	}
	else
	{ obj=new("quest/hyhusong/killer");
	  //maxpot=maxpot-random(10);
	 }
	obj->do_copy(maxpot,maxexp);
	obj->move(environment(me));
	obj->set("id",me->query("id")+" killer");
	obj->set_name("ɱ��", ({ me->query("id")+" killer"}));

	message_vision(HIR"\n$N����$n����һ����Ц������$nȫ�����µĺ�ë�������𣬲���������\n"NOR,obj,me); 
	if(objectp(present("gong zi", environment(this_player()))))
	{
	obj->kill_ob(present("gong zi",environment(this_player())));
 	present("gong zi",environment(this_player()))->kill_ob(obj);
 	present("gong zi",environment(this_player()))->start_busy(6);
        obj->set_leader(present("gong zi",me));
 //       obj->kill_ob(present("gong zi",me));
 	}
	obj->set_leader(me);
	obj->kill_ob(me);
}

string query_type(object me)
{
	return "job";
}
