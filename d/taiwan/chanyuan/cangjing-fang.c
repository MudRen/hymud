
#include <ansi.h>
inherit ROOM;

int do_sao(string arg);
void create ()
{
  set ("short","藏经房");
  set ("long", @LONG
这里是净念禅院的藏经房，这里有很多经书。平时是不让外人进来
的。这里的经书很多，放了整整七、八柜子。有个小僧人正在那里打扫
着柜子上的尘土。由于近年禅院有很多僧人到外地讲经传法，所以近日
来这里的僧人逐渐多了起来。
LONG);

  set("exits", ([ 
	 
	  "out":__DIR__"changlang3",
         ]));

  
  set("valid_startroom", 1);
  setup();
 
}

void init()
{
	add_action("do_sao","sao");
}

int do_sao(string arg)
{
	object me;
	me=this_player();
	if(!arg||arg!="经房") return notify_fail("你想扫什么?\n");
	if(!me->query_temp("budian_job/1"))
		return notify_fail("你在这里忙什么呢?\n");
	if(me->is_busy()) return notify_fail("你正忙着呢!\n");
	if((int)me->query("sen",1)<=5) return notify_fail("你太累了,已经不能再干活了!\n");
	if(me->query_temp("budian_job/ok"))
		return notify_fail("好了,你可以回去交工了!\n");
	if(me->query_temp("budian_job/count"))
		me->add_temp("budian_job/count",1+random(1));
	else me->set_temp("budian_job/count",1);
	if((int)me->query_temp("budian_job/count",1)>=10+random(5))
		me->set_temp("budian_job/ok",1);
	me->receive_damage("sen",10+random(2));
	call_out("return_job",2,me);me->start_busy(1);
	message_vision("$N仔细地打扫起经房来.\n",me);
	return 1;
}

void return_job(object me)
{
	message_vision("$N擦擦头上的汗,觉得自己又为佛家圣地做了件好事.\n",me);

	return;
}
