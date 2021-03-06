// Room: /d/jinghai/moon35.c

inherit ROOM;

void create()
{
	set("short", "天字号牢房");
	set("long", @LONG
这里是一间阴暗潮湿的小石室，只有一盏小油灯高悬在石壁
上方。里面空空如也，只有几张破草席铺在地上。屋里潮湿的四
壁生了青苔。屋子顶端悬挂这一条很粗大的铁链，看来这里是牢
房了。估计，这里关得不是重犯就是疯子。门口上挂一个小木牌
上面写着 [天]。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/master7" : 1,
]));

	setup();
}
void init()
{
      add_action("do_open", "open");
}

int do_open(string arg)
{
	object me,room;

	me= this_player();
	if( !arg && arg != "铁闸" && arg != "zha")
		return notify_fail("要打开什么？\n");

	if( !objectp(present("tian key", me)) ) 
		return notify_fail("铁闸锁着呢，不用钥匙恐怕打不开。\n");

	if(!room = find_object(__DIR__"moon36"))
		room = load_object(__DIR__"moon36");
	if(!room)
		return notify_fail("铁闸无法打开。\n");

	if(!room->query("exits/enter"))
	{
		room->set("exits/enter",__FILE__);
		tell_room(room,"只听喀嚓一声，铁闸慢慢升起。\n");
	}
	set("exits/out", __DIR__"moon36");

	tell_room(__FILE__,"只听喀嚓一声，铁闸慢慢升起。\n");
	call_out("close",5);
	return 1;
}

void close()
{
	object room = find_object(__DIR__"moon36");

	if(query("exits/out"))
	{
		tell_room(__FILE__,"只听喀啦喀啦几声巨响铁闸自动关闭了。\n");
		delete("exits/out");
	}

	if(!room)
		room = load_object(__DIR__"moon35");

	if(room && room->query("exits/enter"))
	{
		room->delete("exits/enter");
		tell_room(room,"只听喀啦喀啦几声巨响铁闸缓缓地关闭了。\n");
	}

}
