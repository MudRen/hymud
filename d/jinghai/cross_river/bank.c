// Cross_river: bank.c
// by Find.

inherit ROOM;

protected string bfile;
protected int max_passenger = 6;
protected object boat;
protected string yell_msg = "$N����ɤ�Ӻ����������ң�����Ҫ���ӣ�����\n";

// �ӿں���
protected void set_boat_file(string file)
{
	if(!stringp(file) || !strlen(file))
		return;

	bfile = file;
}

protected void set_max_passenger(int n)
{
	if(n > 0)
		max_passenger = n;
}

protected void set_yell_msg(string msg)
{
	if(!stringp(msg) || !strlen(msg))
		return;

	yell_msg = msg;
}
// ����

protected int check_boat()
{
	if(!objectp(boat = find_object(bfile)) && !objectp(boat = load_object(bfile)) )
		return notify_fail("�޷������ƶ��壬���ҹ���Ա����\n");
	return 1;
}

void init()
{
	add_action("do_yell", "yell");
}

int do_yell(string arg)
{
	object me = this_player();

	// �������
	if(arg != "����" && arg != "boat")
	{
		message_vision("$N���Ų��Ӻ���һɤ�ӣ�Ҳ��֪��������ʲô��\n",me);
		return 1;
	}

	if(me->query_temp("yell_boat"))
		return notify_fail("���Ѿ��������ˣ����ĵ�һ����ɡ�\n");

	if(!boat && !check_boat())
		return 0;

	me->set_temp("yell_boat", 1);

	if(find_call_out("yell_boat") == -1)
		call_out("yell_boat", 2);

	message_vision(yell_msg, me);
	return 1;
}

protected void yell_boat()
{
	boat->reply_yell(this_object());
}

// �ɱ��������ı�ڶɵ�����
protected int valid_passenger(object who)
{
	if(!who)
		return 0;

	if( !who->query_temp("payed_duchuan") )
		return notify_fail("\n���Ƚ�Ǯ���ϴ���\n");

	return 1;
}

int valid_leave(object me,string dir)
{
	if(!userp(me))
		return 1;

	me->delete_temp("yell_boat", 1);

	if(!boat && !check_boat())
		return notify_fail("�˵ضɴ����ִ������ҹ���Ա����\n");

	if(dir == "enter")
	{
		if(!boat && !check_boat())
			return notify_fail("�˵ضɴ����ִ������ҹ���Ա����\n");

		if( sizeof(filter_array(all_inventory(boat),(: userp :) )) >= max_passenger )
			return notify_fail("�����Ѿ���Ҳ�������ˣ�����һ�˰ɡ�\n");

		if(!valid_passenger(me))
			return 0;
	}

	return 1;
}
