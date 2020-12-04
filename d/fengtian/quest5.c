// Room: /d/fengtian/quest5.c

inherit ROOM;

void create()
{
	set("short", "��ɽ��");
	set("long", @LONG
����һ���������С�����������ϲ���һֻ��ѡ�ӭ�����
ǽ��Ƕ��һ��ʯ�塣���Ϸ���һ�������ε�ʯϻ�ӡ�
LONG
	);

	setup();
}

void init()
{
	add_action("do_push","push");
	add_action("do_open","open");
}

int do_push(string arg)
{
	object me = this_player(),ob;

	if(arg != "ʯ��")
		return notify_fail("��Ҫ��ʲô��\n");

	ob = find_object(__DIR__"quest4");
	if(!ob)
		ob = load_object(__DIR__"quest4");

	if(!ob || (me->query("force") < 200))
		return notify_fail("����������һ�£�����ʯ����˿û����\n");

	message_vision("$N�ƿ�ʯ�壬����¶����һ�����ڡ�\n",me);

	tell_room(ob,"�����ƿ�ʯ�壬¶����һ�����ڡ�\n");

	set("exits/south",__DIR__"quest4");
	ob->set("exits/north",__DIR__"quest5");

	call_out("do_close",8);
	return 1;
}

private void do_close()
{
	object ob;

	tell_room(__FILE__,"ʯ���������ƻ���ԭλ��\n");
	delete("exits/south");

	ob = find_object(__DIR__"quest4");
	if(!ob)
		ob = load_object(__DIR__"quest4");

	if(ob)
	{
		tell_room(ob,"ʯ���������ƻ���ԭλ��\n");
		ob->delete("exits/north");
	}
}

int do_open(string arg)
{
	object me = this_player(),ob,obs;

	if(arg != "ʯϻ��" && arg != "ʯϻ")
	{
		write("��Ҫ��ʲô��\n");
		return 1;
	}

	obs = filter_array(children(__DIR__"obj/feiyusword"),(: clonep :));

	if(sizeof(obs))
	{
		write("���ʯϻ�ӣ���������ʲôҲû�С�\n");
		return 1;
	}

	ob = new(__DIR__"obj/feiyusword");
	ob->set("master",me->query("id"));
	ob->move(this_object());
	me->set_temp("feiyu_upgrade_quest/had",1);
	message_vision("$N�͵�һ�´�ʯϻ�ӣ�һ�Ѷ̽���������˳�����\n",me);
	return 1;
}
