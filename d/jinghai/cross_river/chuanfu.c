// Cross_river: chuanfu.c
// by Find.

inherit NPC;

protected object boat;
protected int max_passenger = 6;
protected string cross_msg = "����";

// �ӿں���
protected void set_max_passenger(int n)
{
	if(n > 0)
		max_passenger = n;
}

protected void set_cross_msg(string msg)
{
	if(!stringp(msg) || !strlen(msg))
		return;

	cross_msg = msg;
}
// ����

void set_boat(object ob)
{
	if(!ob)
		return;

	boat = ob;
}

protected varargs int have_person(object where)
{
	object env;

	if(!where)
	{
		if(!env = environment())
		{
			call_out("do_leave",1);
			return 0;
		}
	}
	else
		env = where;

	return sizeof(filter_array(all_inventory(env), (: userp :)));
}

void shou_qian(int count)
{
	int n;

	remove_call_out("shou_qian");

	if(!boat)
	{
		call_out("do_leave",1);
		return;
	}

	if(count >= 4)
	{
		call_out("kai_chuan",1);
		return;
	}

	if( !have_person() && (count > 2) )
	{
		call_out("kai_chuan",1);
		return;
	}

	n = sizeof(filter_array(all_inventory(boat),(: userp :) ));
	if(n >= max_passenger)
	{
		call_out("kai_chuan",1);
		return;
	}

	if(count)
		say(sprintf("%s˵������Ҫ%s����Ͻ��ϴ�����\n", name(), cross_msg));
	call_out("shou_qian",6,++count);
}

void kai_chuan()
{
	object *inv, env = environment();
	int n;

	if(!env)
	{
		call_out("do_leave",1);
		return;
	}

	if(!boat)
	{
		call_out("do_leave",1);
		return;
	}

	if( n = sizeof(inv = all_inventory(boat)) )
	{
		for(int i=0;i<n;i++)
		{
			object ride;
	
			if(inv[i] && userp(inv[i]) && !inv[i]->query_temp("payed_duchuan"))
			{
				message_vision(name()+"��������$N˵�������Ѿ������������´��ɡ���˵�Ű�$N������ȥ��\n",inv[i]);
				if(ride = inv[i]->query_temp("on_rided"))
					ride->move(env);
				inv[i]->move(env);
				tell_room(env,sprintf("��%s�Ӵ�������������\n",name(), inv[i]->name()),({inv[i]}));
			}
		}
	}

	tell_room(env,sprintf("%s���ϴ�����̤�塣\n",name()));

	this_object()->move(boat);
	env->delete("exits/enter");
	boat->delete("exits/out");

	message_vision("$N����������̤�塣\n$N������������ඣ�������ã���\n", this_object());

	boat->leave_bank();
}

// �˺����ɱ�����������趨��������
int accept_object(object me,object obj)
{
	if(!boat)
	{
		call_out("do_leave",1);
		return 0;
	}

	if(me->query_temp("payed_duchuan"))
		return notify_fail(sprintf("%s˵���������Ѿ����˴�Ǯ�ˣ��������Ʒѡ�\n", name()));

	if(!obj->query("money_id"))
		return 0;

	if(obj->value() < 100)
		return notify_fail(sprintf("%s˵������ÿλһ�����ӣ�С�����⣬�Ų���Ƿ����\n", name()));

	if(sizeof(filter_array(all_inventory(boat),(: userp :) )) >= max_passenger)
		return notify_fail(sprintf("%s˵����%s�����Ѿ����������ϵ���һ�˰ɡ�\n",
			name(), boat->query("short")));

	me->set_temp("payed_duchuan",1);

	tell_object(me, sprintf("%s˵����л�ͣ����Ͽ���ȥ�ɣ���Ҫ��������\n", name()));

	return 1;
}

// ���⺯��
void unconcious()
{
	call_out("do_die",2);
	return ::unconcious();
}

void do_die()
{
	::die();
}

void do_leave()
{
	destruct(this_object());
}
// END ���⺯��
