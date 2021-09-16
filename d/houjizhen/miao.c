// miao.c
// by dicky

inherit ROOM;

void create()
{
	set("short", "财神庙");
	set("long", @LONG
你步入财神庙，一眼便看见一尊财神的泥像歪倒在一边，庙四周的
墙角布满了蜘蛛网，上面有几只蜘蛛正等待着猎物自动送上门来。泥像
下面有一张神案，上面到处布满了灰尘，墙壁有几处已经倒塌，几只乌
鸦停留上面，一边发出"呱呱"的叫声。
LONG );
	
	set("exits", ([
		"south"  : __DIR__"hean1",
	]));

	set("objects", ([
		__DIR__"npc/wuya" : 1,
	]));

	setup();
//	replace_program(ROOM);
}

void init()
{
	add_action("do_find","find");
}

int do_find()
{
       	object me;
        me = this_player();

	if (this_player()->query_temp("ganjiang/heshang"))
 	{   
	message_vision("$N找了半天，突然发现神案下面有一条秘道，你侧身钻了进去。\n", me);
     	me->move(__DIR__"midao");
	me->delete_temp("ganjiang/heshang",1);
     	return 1;
 	}
	return notify_fail("你找了半天，也没有找到什么有用的东西！ \n");
}


