// hezhong.c
// by dicky

inherit ROOM;
#include <ansi.h>
void create()
{
    set("short", "河底石壁");
    set("long", @LONG
你屏气凝神，通过水底中的一条斜向上的通道。来到河底的一块石
壁旁边，石壁上有一个洞，洞口长满了水草，突然你感觉到洞口有一股
莫名的力量推来，你不自觉被水流反推回去，你一咬牙，忙运内功抵抗
，身体才停止后退。
LONG
        );

	set("outdoors", "houjizhen");

	set("exits", ([
		"enter" :  __DIR__"hedong",
	]));

	set("outdoors", "houjizhen");
	setup();
}

void init()
{
	object me;
	me=this_player();
	add_action("do_qian","qian");
	if ((int)me->query("qi", 1) < 0||(int)me->query("jing", 1) < 0){
 	me->set_temp("last_damage_from","在水潭中被淹");
       	me->unconcious();
       	me->die();
       	return ;
       }       
}

int do_qian(string arg)
{
	object me;
       	me=this_player();
       	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着哪！\n");
       	if ( !arg || arg != "up" )
       		return notify_fail("你要往哪里潜？\n");
       	if (arg =="up")
 	{
     	if ((int)me->query_encumbrance() * 100 / (int)me->query_max_encumbrance() >= 40) 
	  return notify_fail("你身子沉重，用尽全力也无法潜回上面!\n");
         message_vision(YEL"$N手脚齐划，顺着水势向上面浮去。\n"NOR, me);
         me->move(__DIR__"hezhong1");
         tell_room(environment(me), me->name() + "从下面波的一声潜了上来。\n", ({ me }));
         message_vision (HIC"$N只觉得身体的压力减少了不少，$N松了一口气。\n"NOR,me);
         return 1;
	 } 
	return 1;
}
