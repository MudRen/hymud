// kantou.c

#include <ansi.h>
inherit F_CLEAN_UP;
#include "/quest/menpai/givegift.c"
int do_kan(object me, object ob, object weapon);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object obj, *inv, weapon;
int iso;
	if( !arg ) return notify_fail("你要砍谁的头？\n");

	if( me->is_busy() )
		return notify_fail("你上一个动作还没有完成！\n");

    if( me->is_fighting() )
        return notify_fail("你正打得热闹呢!。\n");

        if (!objectp(weapon = me->query_temp("weapon")) ||
		((string)weapon->query("skill_type") != "sword" &&
		 (string)weapon->query("skill_type") != "blade"))
		return notify_fail("你不用刀剑哪里砍得动！\n");

	if(!objectp(obj = present(arg, environment(me))))
		return notify_fail("你只能砍尸体的头。\n");

	if(userp(obj) || living(obj) )
		return notify_fail("那还是活的！先杀了才能砍头！\n");

	if( me->is_fighting() )	return notify_fail("你还在战斗中！还想砍人家的头？\n");

	return do_kan(me, obj, weapon);
}
	
int do_kan(object me, object obj, object weapon)
{
	object newob;
	string newname;
int exp,pot,iso;
	if( !obj ) return 0;
	if (obj->query("kantou") == 1)
	{
		message_vision( "$N是个无头尸。\n", obj );
		return 1;
	}
	newname = obj->query("name");
	if(strsrch(newname, "腐烂的尸体") >= 0)
	{
		message_vision( "腐尸还砍个啥劲呀。\n", obj );
		return 1;
	}
	if(strsrch(newname, "尸体") >= 0)
		newname = replace_string(newname, "尸体", "头颅");
	else
	{
		message_vision(obj->query("name")+"有什么头可砍的。\n", obj );
		return 1;
	}
	newob = new("/clone/misc/head");
	newob ->set("name", HIR+newname+NOR);
	newob ->move(me);
        if(obj->query("userp")){
	newob ->set("userp", 1);
	}

	if( me->is_fighting() ) me->start_busy(1);
	message_vision( "$N挥起"+weapon->query("name")+"将$n的脑袋砍了下来。\n", me, obj );
	obj->set("kantou", 1);
	newname = obj->query("name");


	if (obj->query("family_name"))
{
  if (obj->query("family_name")==me->query_temp("nmp2tg"))
{
message_vision( "$N完成了"+me->query_temp("nmp2tg")+"的刺杀任务。\n", me, obj );
	exp= random(18)+500;
addnl(me,"exp",exp);
me->delete_temp("nmp2tg");

	if(strsrch(newname, "尸体") >= 0)
		newname = replace_string(newname, "尸体", "无头尸体");
	obj->set("name", newname);
return 1;
}


}	


//if (wizardp(me)) message_vision( "对方门派:"+obj->query("family_name")+"你门派："+me->query("quest/quest")+"的"+me->query_temp("questmp")+"。\n", me, obj );

//message_vision( "对方门派:"+obj->query("family_name")+"你门派："+me->query("quest/quest")+"的"+me->query_temp("questmp")+"。\n", me, obj );
	
	if (obj->query("family_name"))
{
  if (obj->query("family_name")==me->query("jobtgn"))
{
	me->add_temp("mpjobn5",1);
	//exp = 10+random(8);
//addnl(me,"exp",exp);
message_vision( "$N完成了"+me->query_temp("mpjobn5",1)+"次师傅交待的任务。\n", me, obj );
}
}	
	
	
	

	
	
	
	
if (obj->query("family_name"))
{
  if ((obj->query("family_name")==me->query("quest/quest")
|| obj->query("family_name")==me->query_temp("questmp"))
&& me->query_condition("mjb2_busy"))
{
iso=0;

if ((int)me->query_temp("questsl") >1 && me->query("mjb2job")!="扬威")
{
	exp= random(188)+188;
	pot= exp*0.7;
addnl(me,"exp",exp);
me->add_temp("questsl",-1);
tell_object(me,"你还需要消灭"+(int)me->query_temp("questsl")+"个敌人。\n" NOR);
iso=1;
}	

if ((int)me->query("quest/questsl") >1 && me->query("mjb2job")=="扬威")
{
	exp= random(188)+188;
	pot= exp*0.7;
addnl(me,"exp",exp);
	me->add("quest/questsl",-1);
	tell_object(me,"你还需要消灭"+(int)me->query("quest/questsl")+"个敌人。\n" NOR);
iso=1;
}


if ((int)me->query_temp("questsl") ==1 && me->query("mjb2job")!="扬威" && iso==0)
{
me->delete_temp("questsl");
me->delete_temp("questmp");
     exp=random(888)+888;
		     pot=exp*2/3+random(200);

 		       tell_object(me,HIW"你完成了扬威任务\n"NOR);
me->clear_condition("mjb2_busy");		
me->clear_condition("mp2_kill");
me->delete("quest");
me->delete("task_time");
me->delete("mjb2job");
me->delete_temp("team_count");	
addnl(me,"exp",exp);
if (random(3)==0) addnl(me,"mpgx",1);
}

if ((int)me->query("quest/questsl") ==1 && me->query("mjb2job")=="扬威"  && iso==0)
{
     exp=random(888)+888;
		     pot=exp*2/3+random(200);

 		       tell_object(me,HIW"你完成了扬威任务\n"NOR);
me->clear_condition("mjb2_busy");		
me->clear_condition("mp2_kill");
me->delete("quest");
me->delete("task_time");
me->delete("mjb2job");
me->delete_temp("team_count");	
addnl(me,"exp",exp);


}



}
}

	if(strsrch(newname, "尸体") >= 0)
		newname = replace_string(newname, "尸体", "无头尸体");
	obj->set("name", newname);
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : kantou <尸体名称>
 
这个指令可以让你砍下地上死者的头颅.
 
HELP
    );
    return 1;
}
 
