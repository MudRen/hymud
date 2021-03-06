// Room: /d/jinghai/moon11.c

inherit ROOM;

void create()
{
	set("short", "西栈道");
	set("long", @LONG
这是一条用碎石拼铺成的道路，道路两旁整齐的排列着圆木
围墙。道路向南北两个方向笔直的伸延开去。时不时有一队队红
巾水勇鱼贯而过。东边不远可以看见一大块空地。南北两侧分别
是水寨的兵器库和弟子休息室的所在。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"moon14",
  "east" : __DIR__"moon7",
  "south" : __DIR__"moon15",
]));
        set("outdoors","jinghai");
        set("objects",([
        __DIR__"npc/kanshou1" : 1,
]));

	

	setup();
}

int valid_leave(object who,string dir)
{
	object npc;

	npc=present("kan shou",this_object());

	if(dir=="east" || dir == "e")
	{
		who->delete_temp("can_enter_wuqi");
		return ::valid_leave(who,dir);
	}

	if( (dir == "north")
	&& !wizardp(who)
	&& (who->query("class") != "jinghai")
	)
		return notify_fail("非本派弟子不得进入休息室！\n");
	if(npc
	&& (dir == "south" || dir == "s")
	&& !who->query_temp("can_enter_wuqi") )
		return notify_fail("看守说道：没有令牌休想进入兵器库。\n");

	return ::valid_leave(who,dir);
}
