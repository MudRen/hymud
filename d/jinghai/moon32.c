// Room: /d/jinghai/moon32.c

inherit ROOM;

void create()
{
	set("short", "死囚牢房");
	set("long", @LONG
这里是一间阴暗潮湿的小石室，只有一盏小油灯高悬在石壁
上方。里面空空如也，只有几张破草席铺在地上。屋里潮湿的四
壁生了青苔。屋子顶端悬挂这一条很粗大的铁链，看来这里是牢
房了。估计，这里关得不是重犯就是疯子。门口上挂一个小木牌
上面写着 [死]。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/qiufan2" : 1,
  __DIR__"npc/qiufan3" : 1,
]));

	setup();
}

void init()
{
	add_action("do_open", "open");
}

int do_open(string arg)
{
	object me, key, nroom;
	me= this_player();

	if( !arg && arg != "死牢" && arg != "silao")
		return notify_fail("要打开什么？\n");

	if( !(key = present("si key", me)) ) 
		return notify_fail("不用钥匙，您老想踹开它？\n");

	if( !(nroom = find_object(__DIR__"moon31")) )
		nroom= load_object(__DIR__"moon31");

	set("exits/out", __DIR__"moon31");
	message("vision", "只听喀嚓一声，死牢门漫漫升起。\n", this_object() );

	me->set_temp("used_key3", 1);
	call_out("close",10,me);
	return 1;
}

int close()
{
	message("vision", "只听喀啦喀啦几声巨响死牢门迅速关上了。\n", this_object() );
	delete("exits/out");
}
