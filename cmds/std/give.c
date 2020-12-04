// give.c
// ����2000/6/14����bug

#include <ansi.h>

inherit F_CLEAN_UP;
#include "/quest/givehdgift.c"
int do_give(object me, object obj, object who);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string target, item;
string wiz_status;
	object obj, who, *inv, obj2;
	int i, amount;

        if (userp(me) && !query_heart_beat(me))
        {
         "/cmds/usr/quithy"->main(me);
         write("������û�������������µ�½!!\n");
        }

	if(!arg) return notify_fail("��Ҫ��˭ʲô������\n");

	if( sscanf(arg, "%s to %s", item, target)==2
	|| sscanf(arg, "%s %s", target, item)==2 );
	else return notify_fail("��Ҫ��˭ʲô������\n");

	if(!objectp(who = present(target, environment(me))) || !living(who))
		return notify_fail("����û������ˡ�\n");

	if( me->is_busy() )
		return notify_fail("����һ��������û����ɣ�\n");

	if( who->query("env/no_accept")&&!wizardp(me) )
		return notify_fail("�˼����ڲ���Ҫʲô������\n");
	if(sscanf(item, "%d %s", amount, item)==2) {
		if( !objectp(obj = present(item, me)) )	
			return notify_fail("������û������������\n");
	if( obj->query_temp("is_rided_by") == me->query("id"))
		return notify_fail( obj->name() + "���������ţ����ܸ��ˡ�\n");
if (userp(me) && !userp(who) && obj->is_character())
	return notify_fail("����ѻ�������??\n");

if (who->query("id")!="zhou botong" &&
who->query("id")!="shangguanjiannan")
{
	if( obj->query("no_give")&& obj->query("no_get")&&!wizardp(me))
			return notify_fail("�����������������ˡ�\n");

	if( obj->query("no_drop")&&!wizardp(me) )
			return notify_fail("�����������������ˡ�\n");
	if( obj->query("no_drop")&& obj->query("no_get")&&!wizardp(me) )
			return notify_fail("�����������������ˡ�\n");
	if( obj->query("no_get")&&!wizardp(me) )
			return notify_fail("�����������������ˡ�\n");

}
                if( obj->query("weapon_prop") && me->is_exert() &&
                        obj == me->query_temp("weapon"))
                               return notify_fail("������ʹ��"+me->query_exert()+"���޷�����"+obj->name()+"��\n");
                if( obj->query("weapon_prop") && me->is_perform() &&
                        obj == me->query_temp("weapon"))
                               return notify_fail("������ʹ��"+me->query_perform()+"���޷�����"+obj->name()+"��\n");
	if( obj->query("ownmake") && !wizardp(me) )
		return notify_fail("�����������������ˡ�\n");
	if( obj->query("jobfeng") )
		return notify_fail("�����������������ˡ�\n");

        if(obj->query("dynamic_quest") && !userp(me))
		return notify_fail("�����������������ˡ�\n");
		if( !obj->query_amount() )	
			return notify_fail( obj->name() + "���ܱ��ֿ����ˡ�\n");
		if( amount < 1 )
			return notify_fail("����������������һ����\n");
		if( amount > obj->query_amount() ) 
			return notify_fail("��û����ô���" + obj->name() + "��\n");

                // add by hello 1996.12.05
                // �����������ǲ�������̫����
                inv = all_inventory(who);
	wiz_status = SECURITY_D->get_status(me);
	if( wiz_status != "(admin)" 
	&& userp(me) && wizardp(me))
message("channel:chat", HIC"����Ҽල��"+me->name() + "��" + 
                  who->query("name") + "��"+obj->query("name")+HIC"!"NOR"��\n", users());

                if (inv && sizeof(inv)>49 && userp(who))
                {
                        write(who->name()+"���϶���ô�ණ���ˣ��㻹���������\n");
                        return 1;
                }
		else if( amount == (int)obj->query_amount() )
			return do_give(me, obj, who);
		else {
			obj->set_amount( (int)obj->query_amount() - amount );
			obj2 = new(base_name(obj));
			obj2->set_amount(amount);
			if (do_give(me, obj2, who))
				return 1;
			else {
				obj->set_amount((int)obj->query_amount() + amount);
				return 0;
			}
		}
	}

	if(arg=="all") {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++) {
			do_give(me, inv[i], who);
		}
		write("Ok.\n");
		return 1;
	}

	if(!objectp(obj = present(item, me)))
		return notify_fail("������û������������\n");
	return do_give(me, obj, who);
}

int do_give(object me, object obj, object who)
{
int exp,pot;
string wiz_status;
 object maxpot,badguy,fang,killern;
 int i,j,maxskill,fskill,rw;

if (who->query("id")!="zhou botong")
{
	if( obj->query("no_give")&& obj->query("no_get")&&!wizardp(me))
			return notify_fail("�����������������ˡ�\n");

	if( obj->query("no_drop")&&!wizardp(me) )
			return notify_fail("�����������������ˡ�\n");
	if( obj->query("no_get")&& obj->query("no_drop") && !wizardp(me) )
			return notify_fail("�����������������ˡ�\n");
}
	if( obj->query("jobfeng") )
		return notify_fail("�����������������ˡ�\n");
        if (userp(who) &&
            sizeof(filter_array(all_inventory(who), (: ! $1->query("equipped") :))) >= 40 &&
            ! obj->can_combine_to(who))
        {
		tell_object(me, "�˼����ϵĶ���ʵ����̫���ˣ�û�����ö����ˡ�\n");
                return 0;
        }

	switch ((string)obj->query("equipped"))
	{
	case "worn":
		tell_object(me, obj->name() + "�������������ܸ����ˡ�\n");
                return 0;

	case "wielded":
                tell_object(me, obj->name() + "������װ�����ܸ����ˡ�\n");
                return 0;
	}

// Add by Java 
	if( userp(obj) )
		return notify_fail("��ֻ������ҡ�\n");
// on June 3.1998

	if( obj->query_temp("is_rided_by") == me->query("id"))
		return notify_fail( obj->name() + "�������������š�\n");

	if( me->is_busy() )
		return notify_fail("����һ��������û����ɣ�\n");
		// check for dynamic_quests
        if(obj->query("dynamic_quest"))
        if(TASK_D->quest_reward(me,who,obj))
        return 1;





if(me->query_temp("nhdjob2lb")=="�����ͻ�" && !userp(who)
 && obj->query("nhwtg")==who->query("name")
 && !userp(obj))
{
exp=1300+random(188);
if ((int)me->query_temp("nhdjobsl",1)>=1) exp=exp+((int)me->query_temp("nhdjobsl",1)*30);
if (me->query("hyvip",1)==4) 
exp=exp/2+300;
else
exp=exp/2;
tell_object(me,HIR"��ɹ��������һ�����������!\n"+
NOR);
destruct(obj);
me->delete_temp("nhdjob2lb");
me->delete_temp("nhdjob2tg");
me->delete_temp("nhdjob2sc");
me->delete_temp("nhdjob2en");
me->clear_condition("taskjob_busy");
addnl(me,"exp",exp);
me->add_temp("nhdjobsl",1);
me->add("max_neili",1);
if (me->query("shen")>=0) me->add("shen",200);
if (me->query("shen")<0) me->add("shen",-200);
tell_object(me,"��������һ���������޺Ͷ��ٵ���!\n");
if (random(9)==0)
	 {
tell_object(me,"������ɹ���������!\n");
	 me->add("mpgx",1);
}
if ((int)me->query_temp("tjoblx",1)<7)
{
if (random(2)==0)
"/adm/daemons/taskd"->give_gift3(5,who,me);
else
"/adm/daemons/taskd"->give_gift3(7,who,me);
if (me->query_temp("nhdjob2sc"))
message_vision("$n˵��,���и�����ȥ�� ��õ�������Ϣ����:\n" + me->query_temp("nhdjob2sc") + "��\n", me, who);
}

me->set_temp("tjobstart",0);
me->set_temp("tjobk",0);
me->delete_temp("tjobstart");
me->delete_temp("tjobk");
return 1;
}

if(me->query_temp("nhdjob2lb")=="Ѱ����Ʒ" && !userp(who)
 && obj->query("name")==who->query_temp("nhdjobxh")
 && !userp(obj))
{
exp=1300+random(188);
if ((int)me->query_temp("nhdjobsl",1)>=1) exp=exp+((int)me->query_temp("nhdjobsl",1)*30);
if (me->query("hyvip",1)==4) 
exp=exp/2+300;
else
exp=exp/2;
tell_object(me,HIR"��ɹ��������һ�����������!\n"+
NOR);
destruct(obj);
who->delete_temp("nhdjobxh");
me->delete_temp("nhdjob2lb");
me->delete_temp("nhdjob2tg");
me->delete_temp("nhdjob2sc");
me->delete_temp("nhdjob2en");
me->clear_condition("taskjob_busy");
me->add_temp("nhdjobsl",1);
addnl(me,"exp",exp);
me->add("max_neili",1);
if (me->query("shen")>=0) me->add("shen",200);
if (me->query("shen")<0) me->add("shen",-200);
tell_object(me,"��������һ���������޺Ͷ��ٵ���!\n");
if (random(9)==0)
	 {
tell_object(me,"������ɹ���������!\n");
	 me->add("mpgx",1);
}
if ((int)me->query_temp("tjoblx",1)<7)
{
if (random(2)==0)
"/adm/daemons/taskd"->give_gift3(4,who,me);
else
"/adm/daemons/taskd"->give_gift3(8,who,me);
if (me->query_temp("nhdjob2sc"))
message_vision("$n˵��,���и�����ȥ�� ��õ�������Ϣ����:\n" + me->query_temp("nhdjob2sc") + "��\n", me, who);
}

me->set_temp("tjobstart",0);
me->set_temp("tjobk",0);
me->delete_temp("tjobstart");
me->delete_temp("tjobk");
return 1;
}
//tell_object(me,obj->query("killbyn")+":"+me->query_temp("nhdjob2lb"));
if(me->query_temp("nhdjob2lb")=="��������" && !userp(who)
 && obj->query("killbyn")==who->query("id")
 && !userp(obj))
{
exp=1350+random(188);
if ((int)me->query_temp("nhdjobsl",1)>=1) exp=exp+((int)me->query_temp("nhdjobsl",1)*30);
if (me->query("hyvip",1)==4) 
exp=exp/2+300;
else
exp=exp/2;
tell_object(me,HIR"��ɹ��������һ�����������!\n"+
NOR);
destruct(obj);
//who->delete_temp("nhdjobxh");
me->delete_temp("nhdjob2lb");
me->delete_temp("nhdjob2tg");
me->delete_temp("nhdjob2sc");
me->delete_temp("nhdjob2en");
me->clear_condition("taskjob_busy");
addnl(me,"exp",exp);
me->add("max_neili",1);
me->add_temp("nhdjobsl",1);
if (me->query("shen")>=0) me->add("shen",200);
if (me->query("shen")<0) me->add("shen",-200);
tell_object(me,"��������һ���������޺Ͷ��ٵ���!\n");
if (random(9)==0)
	 {
tell_object(me,"������ɹ���������!\n");
	 me->add("mpgx",1);
}
if ((int)me->query_temp("tjoblx",1)<7)
{
if (random(2)==0)
"/adm/daemons/taskd"->give_gift3(4,who,me);
else
"/adm/daemons/taskd"->give_gift3(6,who,me);
if (me->query_temp("nhdjob2sc"))
message_vision("$n˵��,���и�����ȥ�� ��õ�������Ϣ����:\n" + me->query_temp("nhdjob2sc") + "��\n", me, who);
}

me->set_temp("tjobstart",0);
me->set_temp("tjobk",0);
me->delete_temp("tjobstart");
me->delete_temp("tjobk");

return 1;
}


if(me->query_temp("hdjob2lb")=="�ͻ�" && !userp(who)
 && obj->query("hwtg")==who->query("name")
 && !userp(obj))
{
exp=1300+random(188);
if ((int)me->query_temp("hdjobsl",1)>=1) exp=exp+((int)me->query_temp("hdjobsl",1)*30);
if (me->query("hyvip",1)==4) 
exp=exp/2+300;
else
exp=exp/2;
tell_object(me,HIR"��ɹ��������һ����һ�������!\n"+
NOR);
destruct(obj);
me->delete_temp("hdjob2lb");
me->delete_temp("hdjob2tg");
me->delete_temp("hdjob2sc");
me->clear_condition("taskjob_busy");
addnl(me,"exp",exp);
me->add_temp("hdjobsl",1);
me->add("max_neili",2);
if (me->query("shen")>=0) me->add("shen",500);
if (me->query("shen")<0) me->add("shen",-500);
tell_object(me,"�������˶����������޺���ٵ���!\n");
if (random(5)==0)
	 {
tell_object(me,"������ɹ���������!\n");
	 me->add("mpgx",1);
}
me->set_temp("tjobstart",0);
me->delete_temp("tjobstart");

//return notify_fail(HIR"��ɹ��������һ������!��\n"NOR);
return 1;
}

if(me->query_temp("hdjob2lb")=="����" && userp(who)
 && obj->query("hwtg")==who->query("id")
 && !userp(obj))
{
exp=1300+random(188);
if ((int)me->query_temp("hdjobsl",1)>=1) exp=exp+((int)me->query_temp("hdjobsl",1)*30);
if (me->query("hyvip",1)==4) 
exp=exp/2+300;
else
exp=exp/2;
tell_object(me,HIR"��ɹ��������һ����һ�������!\n"+
NOR);
destruct(obj);
me->delete_temp("hdjob2lb");
me->delete_temp("hdjob2tg");
me->delete_temp("hdjob2sc");
me->clear_condition("taskjob_busy");
addnl(me,"exp",exp);
addnl(who,"exp",exp);
me->add("max_neili",2);
me->add_temp("hdjobsl",1);
who->add("max_neili",2);
if (me->query("shen")>=0) me->add("shen",500);
if (me->query("shen")<0) me->add("shen",-500);
if (who->query("shen")>=0) who->add("shen",500);
if (who->query("shen")<0) who->add("shen",-500);
tell_object(who,"�������˶����������޺���ٵ���!\n");
tell_object(me,"�������˶����������޺���ٵ���!\n");
if (random(5)==0)
	 {
tell_object(me,"������ɹ���������!\n");
	 me->add("mpgx",1);
}
me->set_temp("tjobstart",0);
me->delete_temp("tjobstart");
//return notify_fail(HIR"��ɹ��������һ������!��\n"NOR);
return 1;
}

if(me->query_temp("hdjob2lb")=="Ѱ��" && userp(who)
 && obj->query("name")==who->query_temp("hdjobxh")
 && !userp(obj))
{
exp=1300+random(188);
if ((int)me->query_temp("hdjobsl",1)>=1) exp=exp+((int)me->query_temp("hdjobsl",1)*30);
if (me->query("hyvip",1)==4) 
exp=exp/2+300;
else
exp=exp/2;

tell_object(me,HIR"��ɹ��������һ����һ�������!\n"+
NOR);
destruct(obj);
who->delete_temp("hdjobxh");
me->delete_temp("hdjob2lb");
me->delete_temp("hdjob2tg");
me->delete_temp("hdjob2sc");
me->clear_condition("taskjob_busy");
me->add_temp("hdjobsl",1);
addnl(me,"exp",exp);
me->add("max_neili",2);
if (me->query("shen")>=0) me->add("shen",500);
if (me->query("shen")<0) me->add("shen",-500);
tell_object(me,"�������˶����������޺���ٵ���!\n");
if (random(5)==0)
	 {
tell_object(me,"������ɹ���������!\n");
	 me->add("mpgx",1);
}
me->set_temp("tjobstart",0);
me->delete_temp("tjobstart");
//return notify_fail(HIR"��ɹ��������һ������!��\n"NOR);
return 1;
}


        if(!userp(who)
 && obj->query("name")==me->query_temp("jobitem")
 && who->query("name")==me->query_temp("jobnpc")
 && !userp(obj))
{
exp=random(320)+390;
pot=exp*2/3+random(280);
exp=exp/2;
  if (exp < 90) exp=88+random(22);
if (!me->query("zhuanshen") && me->query("combat_exp",1)<=8000000 ) exp=exp*5;
addnl(me,"exp",exp);

fskill=me->query_skill("force",1);
if (fskill >=100)
{
	me->start_busy(2);
rw=random(199);
fskill=fskill/2+1;
killern=new("/quest/menpai/man");
killern->move(environment(me));
killern->initlvl(fskill);
killern->setn(rw);
//killern->kill_ob(me);

tell_object(me, me->query("name")+"���ָ����и�" + killern->query("name") + "�ܿ��ɡ�\n" NOR);

}
tell_object(me,HIR"��ɹ��������һ������!\n"+
NOR);
		if ((int)me->query_temp("menpaikill")==1)
		{
me->add_temp("menpaijob",1);
		me->delete_temp("menpaikill");	
		}
destruct(obj);
me->apply_condition("nonamejob",0);
me->delete_condition("nonamejob");
me->set("quest", 0);
me->delete_temp("jobnpc");
me->delete_temp("jobitem");
//return notify_fail(HIR"��ɹ��������һ������!��\n"NOR);
return 1;
}

	if( !interactive(who) && !who->accept_object(me, obj) )
//		return notify_fail("������������˼һ�����Ҫ�������������\n");
		return notify_fail("�Է�����������������\n");
/* 
       //��������¼��/log/cmds/give   ����(lywin)

	log_file("cmds/give",
	sprintf("%s(%s) ��%s��һ��(%s) ����%s��%s��on %s\n",
	me->name(),  //��¼ʹ�����������
	geteuid(me), //��¼ʹ�������ID
	(string)environment(me)->query("short"), //��¼������Ʒ���ڵķ���
	obj->name(1), //��¼������Ʒ������
	who->name(),  //��¼ʹ�ö��������
	geteuid(who), //��¼ʹ�ö����ID
	ctime(time()) ) ); //��¼ʹ�������ʱ��
*/

	wiz_status = SECURITY_D->get_status(me);
	if( wiz_status != "(admin)" && wiz_status != "(arch)" 
	&& userp(me) && wizardp(me))
message("channel:chat", HIC"����Ҽල��"+me->name() + "��" + 
                  who->query("name") + "��"+obj->query("name")+HIC"!"NOR"��\n", users());

	if( !userp(who) && obj->value() ) {
		message_vision("$N�ó�" + obj->short() + "��$n��\n", me, who);
if (!obj->query("money_id") || !who->query("pubmaster") || !who->query_temp("no_kill")  || obj->query("base_value") < 100 )
{
		destruct(obj);
}
else
{
//if (!userp(who) && (int)who->query("combat_exp")==50000000)
//{
//		destruct(obj);
//}

	obj->move(who);

}

//if (!userp(who) && (int)who->query("combat_exp")==50000000)
//{
//		destruct(obj);
//}

        me->save();
        if (userp(who)) who->save();
		return 1;
	} else if( obj->move(who) ) {
		printf("���%sһ%s%s��\n", who->name(), obj->query("unit"),
			obj->name());
		message("vision", sprintf("%s����һ%s%s��\n", me->name(),
			obj->query("unit"), obj->name()), who );
		message("vision", sprintf("%s��%sһ%s%s��\n", me->name(), who->name(),
			obj->query("unit"), obj->name()), environment(me), ({me, who}) );
		me->save();
	if( !userp(who) && !obj->is_character()
	&& !userp(obj)) 
{
obj->set("no_beg",1);	
obj->set("no_steal",1);
}


		if (userp(who)) who->save();
		if (userp(obj)) obj->save();
if (userp(me) &&me->query_temp("xmud")) 
{
	seteuid(getuid());
	me->force_me("xnventory");
}

if (userp(who) && who->query_temp("xmud")) 
{
	seteuid(getuid());
	who->force_me("xnventory");
}
if (userp(obj) && obj->query_temp("xmud")) 
{
	seteuid(getuid());
	obj->force_me("xnventory");
}

		return 1;
	}
	else return 0;
}
int help(object me)
{
write(@HELP
ָ���ʽ : give <��Ʒ����> to <ĳ��>
      �� : give <ĳ��> <��Ʒ����>
 
���ָ��������㽫ĳ����Ʒ�����ˣ���Ȼ��������Ҫӵ��������Ʒ��
 
HELP
    );
    return 1;
}
