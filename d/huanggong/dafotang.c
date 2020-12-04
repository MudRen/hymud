// Room: /d/huanggong/dafotang.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
���Ǵ�������Ĵ���á����﹩��һ���������񣬷���ǰ��һ�Ź�
�������ϵ���յ�͵ơ�����������һ�����š�
LONG );
	set("exits", ([
  		"south" : __DIR__"cininggong",
	]));
	set("objects", ([
  		__DIR__"npc/maodongzhu": 1,
  		__DIR__"npc/liuyan": 1,
	]));
	set("coor/x", -220);
	set("coor/y", 5272);
	set("coor/z", 0);
	setup();
	//replace_program(ROOM);
}

void init()
{
	add_action("do_open", "open");
	add_action("do_open", "unlock");
}

void close_gate()
{
	object room;

	if(!( room = find_object(__DIR__"neishi")) )
		room = load_object(__DIR__"neishi");
	if(objectp(room))
	{
		delete("exits/north");
		message("vision","ֻ��ƹ��һ���������Զ�����������\n", this_object());

	}
}

int do_open(string arg)
{
	object room,ob;

	if (query("exits/north"))
		return notify_fail("�����Ѿ��ǿ����ˡ�\n");

	if (!arg || (arg != "door" && arg != "south"))
		return notify_fail("��Ҫ��ʲô��\n");

	if (!(ob = present("hg key", this_player())))
		return notify_fail("�㲻��������\n");

	if(!( room = find_object(__DIR__"neishi")) )
		room = load_object(__DIR__"neishi");
       if(ob) destruct(ob);
	if(objectp(room))
	{
		set("exits/north", __DIR__"neishi");
		message_vision("$Nʹ���Ѱ��Ŵ��˿�����\n",this_player());
		message("vision","�������˰Ѱ��Ŵ��ˡ�\n",room);
		remove_call_out("close_gate");
		call_out("close_gate", 10);
	}
	return 1;
}
int valid_leave(object me, string dir)
{
	if ( objectp(present("mao dongzhu", environment(me))) && 
		dir == "north")
		return notify_fail("ë������ס�����ȥ·��\n");

	if ( objectp(present("liu yan", environment(me))) && 
		dir == "north")
		return notify_fail("������ס�����ȥ·��\n");
	return ::valid_leave(me, dir);
}