// yao_tian.c

inherit ROOM;

protected string m_name, m_id;
protected object yao_miao;
protected int last_time;

void do_refresh()
{
	m_name = 0; m_id = 0;
	if(objectp(yao_miao) && (environment(yao_miao) == this_object()))
		destruct(yao_miao);
	yao_miao = 0;
}

protected void check_valid()
{
	if( m_name || m_id || yao_miao )
	{
		if( (yao_miao && (environment(yao_miao) != this_object()))
		|| (m_id && !objectp(find_player(m_id)))
		|| (time() - last_time > 300) )
			do_refresh();
	}
}

void init()
{
	add_action("do_zai","zai");
	add_action("do_pour", "pour");
	add_action("do_shi", "shi");
	add_action("do_wa", "wa");
}

int do_zai(string arg)
{
	object me = this_player(), *inv, miao;

	if(m_name)
	{
		if(m_id == me->query("id"))
			return notify_fail("���Ѿ�����������һ��ҩ�磬�������Ժ���˵�ɡ�\n");
		return notify_fail(sprintf("%s������������ҩ�磬�㻻���ط��ɡ�\n",m_name));
	}

	if(!arg || (arg == ""))
		return notify_fail("��Ҫ����������ʲô��\n");

	inv = filter_array(all_inventory(me), (: $1->id($(arg)) && $1->is_yao_miao() && !$1->is_success() :));

	if(!sizeof(inv))
		return notify_fail("��Ҫ����������ʲô��\n");

	miao = inv[0];
	miao->do_zai();
	miao->move(this_object());

	message_vision("$NС������Ľ����ϵ�ҩ�����������\n", me);

	m_name = me->name();
	m_id = me->query("id");
	yao_miao = miao;
	last_time = time();

	return 1;
}

int do_pour()
{
	object me = this_player(), *inv;

	if(!objectp(yao_miao) || (environment(yao_miao) != this_object()))
		do_refresh();

	if(!m_id)
		return notify_fail("����û��ʲô��Ҫ��ˮ�Ķ�����\n");

	if(m_id != me->query("id"))
		return notify_fail(sprintf("%s������������ҩ�磬�㻻���ط��ɡ�\n",m_name));

	inv = filter_array(all_inventory(me), (: $1->is_shui_piao() && $1->is_full() :));

	if(!inv || !sizeof(inv))
		return notify_fail("��û��ʢ��ˮ��ˮư��ô��ҩ�罽ˮ��\n");

	inv[0]->do_pour();

	message_vision("$N����ˮư��С������ĸ�ҩ�罽��һ��ˮ��\n", me);

	yao_miao->accept_pour();
	return 1;
}

int do_shi()
{
	object me = this_player(), fei;

	if(!objectp(yao_miao) || (environment(yao_miao) != this_object()))
		do_refresh();

	if(!m_id)
		return notify_fail("����û��ʲô��Ҫʩ�ʵĶ�����\n");

	if(m_id != me->query("id"))
		return notify_fail(sprintf("%s������������ҩ�磬�㻻���ط��ɡ�\n",m_name));

	if(!objectp(fei = present("hua fei",me)))
		return notify_fail("������û�л��ʡ�\n");

	if(!yao_miao->time_to_fei())
		return notify_fail("ҩ���ˮ��û�н��㣬���»�����ʩ�ʵ�ʱ��\n");

	message_vision("$NС������Ľ�һ�黨��ʩ���˵��\n",me);
	destruct(fei);

	yao_miao->do_fei();
	return 1;
}

int do_wa(string arg)
{
	object me = this_player();

	if(!objectp(yao_miao) || (environment(yao_miao) != this_object()))
		do_refresh();

	if(!m_id)
		return notify_fail("����û��ʲô���ڵĶ�����\n");

	if(m_id != me->query("id"))
		return notify_fail(sprintf("%s������������ҩ�磬�㻻���ط��ɡ�\n",m_name));

	if(!arg || !yao_miao->id(arg) )
		return notify_fail("��Ҫ��ʲô������\n");

	if(!yao_miao->can_wa())
		return notify_fail("ҩ�绹û���Ժá�\n");

	message_vision("$NС������Ľ�ҩ�����˳�����\n", me);

	yao_miao->do_wa();

	yao_miao->move(me);

        do_refresh();
	return 1;
}

void reset()
{
	::reset();

	check_valid();
}
