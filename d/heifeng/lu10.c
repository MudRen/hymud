// Room: /d/heifeng/lu10.c

inherit ROOM;

int being_yell = 0;

void create()
{
	set("short", "��������");
	set("long", @LONG
����ɽ����ߴ���ǰ��������͵��������£�������ɽ��
�����Ĵ�����ߴ�������Զ����ȥ��ŨŨ�İ�����������һ��
Сʯ�壬��д�š��ڷ��������ĸ��֡�ʯ������ɽ���ϳ�����
������
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "southdown" : __DIR__"lu9",
]));

	set("outdoors","heifeng");

	setup();
}

void init()
{
	add_action("do_yell","yell");
	add_action("do_push","push");
}

int do_yell(string arg)
{
	object me = this_player();
	string passwd;

	if(!arg || arg == "" )
	{
		message_vision("$N����ɤ�Ӻ��˼�����Ҳ��֪��������ʲô��\n",me);
		return 1;
	}

	if(arg != "�ڷ�����")
	{
		if(strlen(arg) <= 12)
			message_vision(sprintf("$N����ɤ�Ӻ�����%s������Զ������������� %s %s...\n",
				arg,arg,arg),me);
		else
			message_vision(sprintf("$N����ɤ�Ӻ�����%s����\n",arg),me);
		return 1;
	}

	message_vision(sprintf("$N��������������%s��;����կ�����źڷ����������ǰ���ݼ�����\n",
		me->name()),me);

	if(being_yell || query("exits/north"))
		return 1;

	being_yell = 1;

	write("ֻ������һ����˵�������Ե�Ƭ�̣���ȥ�����������\n");
	call_out("do_tongzhi",4,me);
	return 1;
}

void do_tongzhi(object me)
{
	if(!me || environment(me) != this_object())
	{
		being_yell = 0;
		return;
	}

	tell_room(__FILE__,sprintf("ֻ���Ķ���һ���ߺ����������л�����%s%s��կһ�𣡡�\n\n���������\n",
		me->name(),RANK_D->query_respect(me)));

	tell_room(__FILE__,"ֻ���ö���һ��֨֨�¸µ����졣\n");

	me->delete_temp("enter_heifeng");
	me->set_temp("can_enter_heifeng",1);

	call_out("open_cross",2,me);
	return;
}

int valid_leave(object who,string dir)
{
	if(dir == "north" && !who->query_temp("can_enter_heifeng"))
		return 0;
	else
		return ::valid_leave(who,dir);
}

void open_cross(object me)
{
	object ob;

	tell_room(__FILE__,"һ��ľ���ŴӶ�����˹�����\n");
	set("exits/north",__DIR__"cross");

	ob = find_object(__DIR__"gate");
	if(!ob)
		ob = load_object(__DIR__"gate");

	if(!ob->query("exits/south"))
	{
		tell_room(ob,"ֻ���ö���һ��֨֨�¸µ����죬���ű�����������\n");
		ob->set("exits/south",__DIR__"cross");
	}

	being_yell = 0;
	call_out("close_cross",20);
	return;
}

void close_cross()
{
/*
	object ob = find_object(__DIR__"gate");

	if(!ob)
		ob = load_object(__DIR__"gate");

	if(ob->query("exits/south"))
	{
		tell_room(ob,"ֻ��һ��֨֨�¸µ����죬�����ֱ�����������\n");
		ob->delete("exits/south");
	}
*/
	if(query("exits/north"))
	{
		tell_room(__FILE__,"ֻ��һ��֨֨�¸µ����죬���������ı��������������\n");
		delete("exits/north");
	}
}

int do_push(string arg)
{
	object me = this_player();

	if(!me || arg != "����")
		return 0;

	write("�㳶������������һ��С·��\n");


	me->move(__DIR__"ling7");
	tell_room(__FILE__,sprintf("%s�����������˽�ȥ��\n",me->name()));
	return 1;
}
