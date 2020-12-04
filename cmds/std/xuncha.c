// hubo.c
#include <ansi.h>
inherit F_CLEAN_UP;
#include "/quest/menpai/givegift.c"
int main(object me)
{
	string msg;
 object ob;
int exp,pot,base_exp,a;
	int i,maxskill;
	object fang,who,where;
        int count,add_exp;
        object *team,boss;
object maxpot,obj;
ob = this_object();
me = this_player();
	who=me;
	where = environment(who);
 
    if( me->is_busy() )
	return notify_fail("你的动作还没有完成。\n");
    if( me->is_fighting() )
        return notify_fail("你正打得热闹呢!。\n");

    if( (int)me->query("jing") < 70 ) return notify_fail("你的精不够！\n");
    if( (int)me->query("qi") < 70 ) return notify_fail("你的精不够！\n");

    if( me->query("mjb2job")!="巡查" ) return notify_fail("你现在没有巡查任务！\n");

        fang = present("sha shou",where);
	if(fang)
	{
		who->start_busy(3);
         return notify_fail("你先解决现有的强敌吧！\n");
	}

        fang = present("boss killer",where);
	if(fang)
	{
		who->start_busy(3);
 return notify_fail("你先解决现有的强敌吧！\n");
	}

    //if( !me->query_condition("roomjob") ) return notify_fail("你这个任务已经过期了！\n");
if (me->query("quest/location1ok")!="done")
{
    if (environment(me)->query("short") !=me->query("quest/location1n"))
     {
         tell_object(me,HIR"第一个目标是叫你到"+me->query("quest/location1n")+"去巡查的吧！\n"NOR);
          return 1;
     }
}


if (me->query("quest/location2ok")!="done" && me->query("quest/location1ok")=="done")
{
    if (environment(me)->query("short") !=me->query("quest/location2n"))
     {
         tell_object(me,HIR"第二个目标是叫你到"+me->query("quest/location2n")+"去巡查的吧！\n"NOR);
          return 1;
     }
}


if (me->query("quest/location3ok")!="done" && me->query("quest/location2ok")=="done")
{
    if (environment(me)->query("short") !=me->query("quest/location3n"))
     {
         tell_object(me,HIR"第三个目标是叫你到"+me->query("quest/location3n")+"去巡查的吧！\n"NOR);
          return 1;
     }
}


    msg = HIG "$N与附近的江湖人物，混在一起，说了一会把"+environment(me)->query("short")+GRN"这里发生的事的情况大致了解了！\n" NOR;
message_vision(msg, me);
if( !environment(me)->query("no_fight"))
{
if (random(3)==1 && me->query("combat_exp") > 1000000)
{
call_out("zuji", 0, me);    
me->start_busy(2);
tell_object(me,HIR"附近突然杀出一个杀手来！\n"NOR);
return 1;
}
}

if (me->query("quest/location1ok")!="done")
{
me->set("quest/location1ok","done");
tell_object(me,HIR"巡查第一个目的地完成！\n"NOR);
return 1;
}
if (me->query("quest/location2ok")!="done")
{
me->set("quest/location2ok","done");
tell_object(me,HIR"巡查第二个目的地完成！\n"NOR);
return 1;
}

if (me->query("quest/location3ok")!="done")
{
      if(!where->query("iskillok") && (random(20)==0 || wizardp(me)))
      {
      message_vision("突然突然杀进一个武林高手 对$N说道： 把你的小命交出来吧!\n",who);	
      	fang = new("/quest/menpai/boss");
	fang->move(environment(who));	
	maxskill=(int)who->query_skill("force",1)+20;
	if (!who->query("zhuanshen") && who->query("combat_exp",1) <=6000000) maxskill=maxskill*2/3;
	fang->initlvl(maxskill);
        fang->set("combat_exp",me->query("combat_exp",1));
        fang->set("str", me->query("str"));
        fang->set("dex", me->query("dex"));
        fang->set("per", me->query("per"));
        i=me->query_temp("team_count");
        if (!i) i=sizeof(me->query_team());
        if (!i) i=1;
        fang->set("qi",fang->query("max_qi")*i);
        fang->set("eff_qi",fang->query("max_qi")*i);
        fang->set("max_qi",fang->query("max_qi")*i);

        fang->set("jing",fang->query("max_jing")*i);
        fang->set("eff_jing",fang->query("max_jing")*i);
        fang->set("max_jing",fang->query("max_jing")*i);

        fang->set("neili",fang->query("max_neili")*i);
        fang->set("max_neili",fang->query("max_neili")*i);

        
	fang->kill_ob(who);
     this_object()->set("iskillok",1);
     where->set("iskillok",1);
      return 1;  
      }	
}

if (me->query("quest/location3ok")!="done")
{
me->set("quest/location3ok","done");
tell_object(me,HIR"巡查任务全部完成！\n"NOR);

}

if  (me->query("quest/location3ok")=="done")
{
a=FAMILY_D->query_family_fame(me->query("family/family_name"));
if (a==0) a=random(3000)+100;
if (a> 10 && random(10)==0) 
{	
exp=(int)a/10+10;
pot=(int)exp*2/3+10;
        tell_object(me, me->query("family/family_name")+"在江湖上的威望是" + chinese_number(a) + "。\n" NOR);
addnl(me,"exp",exp);

}

 count=me->query_temp("team_count");
		if (count<2) count=2;	
               
		team=me->query_team();
		count=sizeof(team);
		//write("\n"+sprintf("%d",count));
if (!count)
{
		     exp=random(888)+888;
		     pot=exp*2/3+random(200);

addnl(me,"exp",exp);
if (random(3)==0) addnl(me,"mpgx",1);
me->clear_condition("mjb2_busy");		
me->clear_condition("mp2_kill");
me->delete("quest");
me->delete("task_time");
me->delete("mjb2job");
me->delete_temp("team_count");	
}	

		for(i=0;i<count;i++)
		{ if(team[i]!=0)
		{
			if (team[i]->query_condition("mjb2_busy"))
			{ 
			 add_exp=100;
		     exp=random(888)+888;
		     pot=exp*2/3+random(200);
		     team[i]->delete_temp("team_count");
             if (environment(me)==environment(team[i])) addnl(team[i],"exp",exp);
team[i]->clear_condition("mjb2_busy");		
team[i]->clear_condition("mp2_kill");
team[i]->delete("quest");
team[i]->delete("task_time");
team[i]->delete("mjb2job");
team[i]->delete_temp("team_count");
			}
			} 
		}

}

    me->start_busy(3);
    me->receive_damage("jing", 50);
    me->receive_damage("qi", 50);
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

	obj->move(environment(me));
	if (!me->query("zhuanshen") && me->query("combat_exp",1) <=6000000) maxskill=maxskill*2/3;
	obj->initlvl(maxskill);
         obj->set("combat_exp",maxexp);
        obj->set("str", me->query("str"));
        obj->set("dex", me->query("dex"));
        obj->set("per", me->query("per"));
        obj->set("qi", me->query("max_qi")*i);
        obj->set("eff_qi", me->query("max_qi")*i);
        obj->set("max_qi", me->query("max_qi")*i);
        obj->set("eff_jing", me->query("max_jing")*i);
        obj->set("max_jing", me->query("max_jing")*i);
        obj->set("jing", me->query("max_jing")*i);
        obj->set("neili", me->query("max_neili")*i);
        obj->set("max_neili", me->query("max_neili")*i);
	
	message_vision(HIG"\n$N对着$n大叫一声，你们全去死吧，杀啊!。\n"NOR,obj,me); 
	obj->kill_ob(me);
	obj->set_leader(me);
}

int help(object me)
{
        write(@HELP
指令格式 : hubo
 
这个指令可以让你在任务中，来巡查情报的。
 
HELP
    );
    return 1;
}

