// Cross_river: boat.c
// by Find.

#define BOAT_IDLE	0
#define GOTO_BANK1	1
#define AT_BANK1	2
#define GOTO_BANK2	3
#define AT_BANK2	4

inherit ROOM;

protected int stat;
protected string cross_msg = "����", b1_desc = "����", b2_desc = "����";
protected object master, bank1, bank2;

protected string mfile;
protected string bfile1;
protected string bfile2;

// �ӿں���
protected void set_boat_master(string file)
{
	if(!stringp(file) || !strlen(file))
		return;

	mfile = file;
}

protected void set_boat_bank1(string file)
{
	if(!stringp(file) || !strlen(file))
		return;

	bfile1 = file;
}

protected void set_boat_bank2(string file)
{
	if(!stringp(file) || !strlen(file))
		return;

	bfile2 = file;
}

protected void set_cross_msg(string msg)
{
	if(!stringp(msg) || !strlen(msg))
		return;

	cross_msg = msg;
}

protected void set_bank1_desc(string msg)
{
	if(!stringp(msg) || !strlen(msg))
		return;

	b1_desc = msg;
}

protected void set_bank2_desc(string msg)
{
	if(!stringp(msg) || !strlen(msg))
		return;

	b2_desc = msg;
}
// ����

protected void load_master()
{
	if(!mfile)
		error("δ�趨 master �ļ�����\n");
	if( !objectp(master = new(mfile)) )
		error("�޷����붯�������\n");
	else if(!master->move(this_object()))
	{
		destruct(master);
		error("�޷����붯�������\n");
	}

	master->set_boat(this_object());

}

protected void find_bank()
{
	if(!bfile1)
		error("δ�趨 bfile1 �ļ�����\n");

	if(!bfile2)
		error("δ�趨 bfile2 �ļ�����\n");

	if(!objectp(bank1 = find_object(bfile1))
	&& !objectp(bank1 = load_object(bfile1)))
		error("�޷����� 1 �������\n");

	if(!objectp(bank2 = find_object(bfile2))
	&& !objectp(bank2 = load_object(bfile2)))
		error("�޷����� 2 �������\n");
}

protected void start_up()
{
	load_master();
	find_bank();
}

protected int check_all_obj()
{
	if(!bank1 || !bank2)
	{
		find_bank();
		if(!bank1 || !bank2)
			return 0;
	}

	if(!master)
	{
		load_master();
		if(!master)
			return 0;
	}

	return 1;
}

protected void setup()
{
	start_up();

	
	set("no_clean_up",1);
	return ::setup();
}

void reply_yell(object bank)
{
	int flag;

	if(!bank)
		return;

	// ������
	if(!check_all_obj())
		return;
	if(bank != bank1)
	{
		if(bank != bank2)
			return;
		else
			flag = 1;	// bank2 ����
	}

	// �������״̬
	switch (stat)
	{
		case BOAT_IDLE:
			tell_room(bank, sprintf("ԶԶ�Ĵ���%s����������ඣ���͹�ȥඣ�\n", master->name()));
			stat = flag?GOTO_BANK2:GOTO_BANK1;
			if(find_call_out("reach_bank") != -1)
				remove_call_out("reach_bank");
			call_out("reach_bank", 2);
			return;
		case GOTO_BANK1:
			if(!flag)
			{
				tell_room(bank, sprintf("ԶԶ�Ĵ���%s������������ʲô�����Ͼ͵�����\n", master->name()));
				return;
			}
			tell_room(bank, sprintf("ԶԶ�Ĵ���%s����������æ�������أ���һ�����\n", master->name()));
			return;
		case AT_BANK1:
			if(!flag)
				return;
			tell_room(bank, sprintf("ԶԶ�Ĵ���%s����������æ�������أ���һ�����\n", master->name()));
			return;
		case GOTO_BANK2:
			if(flag)
			{
				tell_room(bank, sprintf("ԶԶ�Ĵ���%s������������ʲô�����Ͼ͵�����\n", master->name()));
				return;
			}
			tell_room(bank, sprintf("ԶԶ�Ĵ���%s����������æ�������أ���һ�����\n", master->name()));
			return;
		case AT_BANK2:
			if(flag)
				return;
			tell_room(bank, sprintf("ԶԶ�Ĵ���%s����������æ�������أ���һ�����\n", master->name()));
	}
}

protected void reach_bank()
{
	object *inv;
	if(!check_all_obj())
		return;

	switch (stat)
	{
		case GOTO_BANK1:
			stat++;

			if(sizeof(inv = filter_array(all_inventory(), (: userp :))))
				foreach(object tmp in inv)
					tmp->delete_temp("payed_duchuan");

			tell_room(this_object(),sprintf("%s����һɤ�ӣ�������������˵�Ŵ���̤�����´���\n", master->name()));

			bank1->set("exits/enter",base_name(this_object()));
			set("exits/out",base_name(bank1));
			master->move(bank1);
			tell_room(bank1,sprintf("�ɴ������ˣ�%s����̤��Ӷɴ�������������
%s˵������Ҫ%s�ĸϽ��ϴ�������\n", master->name(), master->name(), cross_msg ));
			master->shou_qian(0);
			return;
		case GOTO_BANK2:
			stat++;

			if(sizeof(inv = filter_array(all_inventory(), (: userp :))))
				foreach(object tmp in inv)
					tmp->delete_temp("payed_duchuan");

			tell_room(this_object(),sprintf("%s����һɤ�ӣ�������������˵�Ŵ���̤�����´���\n", master->name()));

			bank2->set("exits/enter",base_name(this_object()));
			set("exits/out",base_name(bank2));
			master->move(bank2);
			tell_room(bank2,sprintf("�ɴ������ˣ�%s����̤��Ӷɴ�������������
%s˵������Ҫ%s�ĸϽ��ϴ�������\n", master->name(), master->name(), cross_msg ));
			master->shou_qian(0);
			return;
		default:
			return;
	}
}

void leave_bank()
{
	if(!check_all_obj())
		return;

	switch (stat)
	{
		case AT_BANK1:
			if(sizeof(filter_array(all_inventory(), (: userp :))))
			{
				stat = GOTO_BANK2;
				call_out("goto_opposite", 2);
			}
			else
				stat = BOAT_IDLE;
			return;
		case AT_BANK2:
			if(sizeof(filter_array(all_inventory(), (: userp :))))
			{
				stat = GOTO_BANK1;
				call_out("goto_opposite", 2);
			}
			else
				stat = BOAT_IDLE;
			return;
	//	default:
	//		return;
	}
}

protected void goto_opposite()
{
	string msg;

	if(!check_all_obj())
		return;

	switch (stat)
	{
		case GOTO_BANK2:
			msg = sprintf("%s��%sʻȥ��\n", query("short"), b2_desc);
			break;
		case GOTO_BANK1:
			msg = sprintf("%s��%sʻȥ��\n", query("short"), b1_desc);
			break;
		default:
			return;
	}

	tell_room(this_object(), msg);

	call_out("close_opposite", 10);
}

protected void close_opposite()
{
	if(!check_all_obj())
		return;

	tell_room( this_object(),sprintf("%s��%s������ȥ��\n", query("short"),
		(stat==GOTO_BANK2)?b2_desc:b1_desc) );

	call_out("reach_bank", 3);
}
