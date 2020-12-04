// /d/heifeng/gate.c

inherit ROOM;

void close_cross();

void create()
{
	set("short", "ɽկ����");
	set("long", @LONG
һ�������Ӵ�ɵ�կ�ų�����������ǰ�������ֵ���
��Ŀ¶�����׹⣬��ͣ�����ſ�Ѳ���š����Ϻ���һ����
(sign)���㲻����ԥ���Ƿ�Ҫ����ǰȥ��
LONG
);

	set("item_desc", ([
		"sign": "�ڷ�կ\n",
	]) );
        set("NONPC",1);

	
	set("exits", ([
		"north"   : __DIR__"corr",
		"south"   : __DIR__"cross",
	]) );

	set("objects", ([
		__DIR__"npc/bandit_guard" : 2,
]) );

	set("outdoors", "heifeng");
	setup();
}

void init()
{
	object ob;

	if( living(ob = previous_object()) && userp(ob) && ob->query_temp("can_enter_heifeng"))
		ob->delete_temp("can_enter_heifeng");
}

/*
void greeting(object ob)
{
	if( !ob )
		return;

	if(environment(ob) == find_object(__DIR__"cross"))
	{
		call_out("close_cross",1);
		return;
	}

	if(ob->query_temp("heifeng/come_in"))
	{
		close_cross();
		ob->delete_temp("heifeng/come_in");
		return;
	}
}

void close_cross()
{
	object ob = find_object(__DIR__"lu10");

	if(!ob)
		ob = load_object(__DIR__"lu10");

	if(ob->query("exits/north"))
	{
		tell_room(ob,"ֻ��һ��֨֨�¸µ����죬���������ı��������������\n");
		ob->delete("exits/north");
	}

	if(query("exits/south"))
	{
		tell_room(__FILE__,"ֻ��һ��֨֨�¸µ����죬�����ֱ�����������\n");
		delete("exits/south");
	}
}
*/
