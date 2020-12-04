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
	if( !arg ) return notify_fail("��Ҫ��˭��ͷ��\n");

	if( me->is_busy() )
		return notify_fail("����һ��������û����ɣ�\n");

    if( me->is_fighting() )
        return notify_fail("�������������!��\n");

        if (!objectp(weapon = me->query_temp("weapon")) ||
		((string)weapon->query("skill_type") != "sword" &&
		 (string)weapon->query("skill_type") != "blade"))
		return notify_fail("�㲻�õ������￳�ö���\n");

	if(!objectp(obj = present(arg, environment(me))))
		return notify_fail("��ֻ�ܿ�ʬ���ͷ��\n");

	if(userp(obj) || living(obj) )
		return notify_fail("�ǻ��ǻ�ģ���ɱ�˲��ܿ�ͷ��\n");

	if( me->is_fighting() )	return notify_fail("�㻹��ս���У����뿳�˼ҵ�ͷ��\n");

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
		message_vision( "$N�Ǹ���ͷʬ��\n", obj );
		return 1;
	}
	newname = obj->query("name");
	if(strsrch(newname, "���õ�ʬ��") >= 0)
	{
		message_vision( "��ʬ������ɶ��ѽ��\n", obj );
		return 1;
	}
	if(strsrch(newname, "ʬ��") >= 0)
		newname = replace_string(newname, "ʬ��", "ͷ­");
	else
	{
		message_vision(obj->query("name")+"��ʲôͷ�ɿ��ġ�\n", obj );
		return 1;
	}
	newob = new("/clone/misc/head");
	newob ->set("name", HIR+newname+NOR);
	newob ->move(me);
        if(obj->query("userp")){
	newob ->set("userp", 1);
	}

	if( me->is_fighting() ) me->start_busy(1);
	message_vision( "$N����"+weapon->query("name")+"��$n���Դ�����������\n", me, obj );
	obj->set("kantou", 1);
	newname = obj->query("name");


	if (obj->query("family_name"))
{
  if (obj->query("family_name")==me->query_temp("nmp2tg"))
{
message_vision( "$N�����"+me->query_temp("nmp2tg")+"�Ĵ�ɱ����\n", me, obj );
	exp= random(18)+500;
addnl(me,"exp",exp);
me->delete_temp("nmp2tg");

	if(strsrch(newname, "ʬ��") >= 0)
		newname = replace_string(newname, "ʬ��", "��ͷʬ��");
	obj->set("name", newname);
return 1;
}


}	


//if (wizardp(me)) message_vision( "�Է�����:"+obj->query("family_name")+"�����ɣ�"+me->query("quest/quest")+"��"+me->query_temp("questmp")+"��\n", me, obj );

//message_vision( "�Է�����:"+obj->query("family_name")+"�����ɣ�"+me->query("quest/quest")+"��"+me->query_temp("questmp")+"��\n", me, obj );
	
	if (obj->query("family_name"))
{
  if (obj->query("family_name")==me->query("jobtgn"))
{
	me->add_temp("mpjobn5",1);
	//exp = 10+random(8);
//addnl(me,"exp",exp);
message_vision( "$N�����"+me->query_temp("mpjobn5",1)+"��ʦ������������\n", me, obj );
}
}	
	
	
	

	
	
	
	
if (obj->query("family_name"))
{
  if ((obj->query("family_name")==me->query("quest/quest")
|| obj->query("family_name")==me->query_temp("questmp"))
&& me->query_condition("mjb2_busy"))
{
iso=0;

if ((int)me->query_temp("questsl") >1 && me->query("mjb2job")!="����")
{
	exp= random(188)+188;
	pot= exp*0.7;
addnl(me,"exp",exp);
me->add_temp("questsl",-1);
tell_object(me,"�㻹��Ҫ����"+(int)me->query_temp("questsl")+"�����ˡ�\n" NOR);
iso=1;
}	

if ((int)me->query("quest/questsl") >1 && me->query("mjb2job")=="����")
{
	exp= random(188)+188;
	pot= exp*0.7;
addnl(me,"exp",exp);
	me->add("quest/questsl",-1);
	tell_object(me,"�㻹��Ҫ����"+(int)me->query("quest/questsl")+"�����ˡ�\n" NOR);
iso=1;
}


if ((int)me->query_temp("questsl") ==1 && me->query("mjb2job")!="����" && iso==0)
{
me->delete_temp("questsl");
me->delete_temp("questmp");
     exp=random(888)+888;
		     pot=exp*2/3+random(200);

 		       tell_object(me,HIW"���������������\n"NOR);
me->clear_condition("mjb2_busy");		
me->clear_condition("mp2_kill");
me->delete("quest");
me->delete("task_time");
me->delete("mjb2job");
me->delete_temp("team_count");	
addnl(me,"exp",exp);
if (random(3)==0) addnl(me,"mpgx",1);
}

if ((int)me->query("quest/questsl") ==1 && me->query("mjb2job")=="����"  && iso==0)
{
     exp=random(888)+888;
		     pot=exp*2/3+random(200);

 		       tell_object(me,HIW"���������������\n"NOR);
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

	if(strsrch(newname, "ʬ��") >= 0)
		newname = replace_string(newname, "ʬ��", "��ͷʬ��");
	obj->set("name", newname);
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : kantou <ʬ������>
 
���ָ��������㿳�µ������ߵ�ͷ­.
 
HELP
    );
    return 1;
}
 
