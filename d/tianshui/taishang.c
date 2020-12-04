// Room: /d/tianshui/taishang.c
// by ���ֺ�(find)

inherit ROOM;

int max_skill = 45;

mapping skill = ([
"zhuge" : "literate",
"zhangfei" : "fork",
"guanyu" : "blade",
]),

act = ([
"zhangfei" : "����ǹˣ��һͨ",
"zhuge" : "���Ŷ�ë�ȱȻ��˼���",
"guanyu" : "���ŵ�ˣ��һͨ",
])
;

protected void time_counter()
{
	object *players;
	int time;

	call_out("time_counter", 5);

	if(!sizeof(players = filter_array(all_inventory(), (: userp :))))
		return;

	time = time();

	foreach(object ob in players)
	{
		int n;

		if(!ob)
			continue;

		if(!n = ob->query_temp("tianshui_time_counter"))
		{
			ob->set_temp("tianshui_time_counter", time);
			continue;
		}

		if(time - n > 12)
		{
			object room;
			message_vision("����һ��󺰡���ô������������˵�Ű�$N����̨����\n",ob);
			room = find_object(__DIR__"houtai");
			if(!room)
				room = load_object(__DIR__"houtai");

			if(room)
				room->do_xie(ob);

			ob->delete_temp("tianshui_time_counter");
			ob->move(__DIR__"xitai");
	                tell_room(__DIR__"xitai",sprintf("%s��̨�ϵ���������ˤ�˸���������\n",ob->name()),ob);
		}
	}
}

void create()
{
	set("short", "̨��");
	set("long", @LONG
����һ����ª��Ϸ̨��Ϸ��������������ѽѽ�س��š�
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
  "westdown" : __DIR__"houtai",
  "eastdown" : __DIR__"xitai",
]));
	
	setup();
	call_out("time_counter", 5);
}

void init()
{
	add_action("do_chang","chang");
	add_action("do_quit","quit");
}

int do_chang(string arg)
{
	object me = this_player(),room;
	int plevel,pper,pint;
	string play;

	if( !stringp(play = me->query_temp("tianshui_playing")) )
		return notify_fail("������ߺ�ߴߴ��Ҳ��֪���ڳ�Щʲô��\n");

	pper = me->query("per");
	pint = me->query("int");

	if(me->is_busy())
		return notify_fail("������æ��");

	me->start_busy(2);

	if(me->query("kee") < 20)
	{
		message_vision("$N�۵���ͷ�󺹣�����ǻ�������ˣ�����һ��ߺ�ȣ���$N����̨����\n",me);
		room = find_object(__DIR__"houtai");
		if(!room)
			room = load_object(__DIR__"houtai");

		if(room)
			room->do_xie(me);

		me->delete_temp("tianshui_time_counter");
		me->move(__DIR__"xitai");
                tell_room(__DIR__"xitai",sprintf("%s��̨�ϵ���������ˤ�˸���������\n",me->name()),me);
		return 1;
	}
		
	me->receive_damage("qi", 20);

	if(me->query_skill(skill[play],1) > max_skill)
		return notify_fail(sprintf("���Ѿ�����ͨ����Ϸ����%s�ˡ�\n",to_chinese(skill[play])));

	if( !me->query_skill(skill[play], 1) )
		me->set_skill(skill[play], 0);
	plevel = me->query_skill(skill[play], 1);
	me->improve_skill(skill[play],(pper+pint)/5+plevel);

	message_vision(sprintf("$N����ѽѽ�س���һ�Σ���%s��̨��һƬ�кã�\n",act[play]),me);
	me->set_temp("tianshui_time_counter", time());

	return 1;
}

int valid_leave(object me,string dir)
{
	if( (dir == "eastdown") && me->query_temp("tianshui_playing"))
		return notify_fail("�㻹ûжױ����ô�����أ�\n");
	me->delete_temp("tianshui_time_counter");
	return ::valid_leave(me,dir);
}

int do_quit(string arg)
{
	object me = this_player(),room;

	room = find_object(__DIR__"houtai");
	if(!room)
		room = load_object(__DIR__"houtai");

	if(room)
		room->do_xie(me);
	return 0;
}
