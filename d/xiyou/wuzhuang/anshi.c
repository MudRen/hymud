//Cracked by Roath
//anshi.c
#include <room.h>
inherit ROOM;

int can_enter=1;

void create ()
{
	set ("short", "亭底暗室");
	set ("long", @LONG

这是牡丹亭底下的一间暗室。黑咕窿咚的什么也看不清。你试着
到处摸了摸(mo)。 
LONG);

	set("exits", 
	([ //sizeof() == 4
		//"southwest" : __DIR__"juyuan",
		//"north" : __DIR__"southpool",
		"up" : __DIR__"mudanting",
		//"west" : __DIR__"westway6",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"obj/huangtong-key" : 1,
	]));

	create_door("up", "桌底暗门", "down", DOOR_CLOSED);
	//set("outdoors", "xy9");
set("available",1);
	set("no_clean_up", 1);
	can_enter=1;

	setup();
}


void init()
{
	add_action("do_mo", "mo");
	add_action("do_search", "search");

	if( query("started") != 1 )
	{
		set("started", 1);
call_out("generate_key", 25200+random(50)*360);//15 hours
	}
}

void generate_key()
{
	remove_call_out("generate_key");
	set("available", 1);
}

void reset_enter()
{
    can_enter=1;
}

int do_mo(string arg)
{
	object me, key;
	int sen;

	me = this_player();
	notify_fail("你什么也没摸着。\n");
	
	if(me->is_busy()) return 0;


	sen=me->query("jing");
	if(sen<110) return 0;
	sen-=100;
	me->set("jing",sen);

	sen=(me->query("combat_exp")+me->query("combat_exp"))/2;
//yudian
//         if(sen<10000) return 0;
         if(sen<50000) return 0;

	if( query("available") == 1 )
	{
		set("available", 0);
		key = new(__DIR__"obj/huangtong-key");
		key -> move(this_object());
		message_vision("只听当！地一声，一把黄铜钥匙掉在地上。\n", me);

		remove_call_out("generate_key");
call_out("generate_key", 25200+random(50)*360);//15 hours

		return 1;
	}
	else
	{ 
		message_vision("只听当！地一声，里面什么也没有。\n", me);

		return 1;
	}
}

int clean_up()
{
	return 0;
}

int do_search(string arg)
{
   object me, jin, pan;
   jin=new(__DIR__"obj/jinjizi");
   pan=new(__DIR__"obj/danpan");
   me = this_player();
   
    if( me->query("obstacle/wzg") == "done" ||
      ! me->query("obstacle/village") )
        return notify_fail("你什么也没有找到。\n");
    if( present("jinji zi",me) || present("dan pan",me)||
        me->query_temp("jinpan_got") )
        return notify_fail("你这个人怎么这么贪心。\n");
          
   tell_object(me,"你找到了一个金击子和一个丹盘。\n");
   jin->move(me);
   pan->move(me);
   me->set_temp("jinpan_got",1);
   return 1;
}
