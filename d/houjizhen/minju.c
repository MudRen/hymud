// minju.c
// by dicky

#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "小院");
	set("long", @LONG
这里是一个破旧的民居小院，院子右边是一个磨盘，靠着磨
盘有一口井，几件损坏的农具被随便丢在一边。左边有一棵很大
的槐树，树叶长得非常茂盛，数下有几片衣服碎片，上面布满了
血迹。
LONG
	);

	set("outdoors", "houjizhen");

	set("exits", ([ /* sizeof() == 2 */
 		"south" : __DIR__"shilu3",
	]));

        set("fu_count",2);

	setup();
//	replace_program(ROOM);
}

void init()
{
	if (!this_player()->query_temp("chazhao_times"))
	        this_player()->set_temp("chazhao_times",
			1+random(50));
	add_action("do_chazhao", "chazhao");
}

int do_chazhao()
{
        object me, ob;

        me = this_player();
                
	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢。\n");

        if ( !me->query_temp("taxue/ask_master"))
		return notify_fail("你查找了半天，可是什么也没有找到！\n");

        if ( me->query_temp("chazhao_times") == 0 )
        {
                message_vision(HIB"$N突然感觉一股热血直冲脑门，两眼一黑，晕了过去。\n"NOR, me);
                me->set_temp("chazhao_times",
			1+random(50));
                me->unconcious();
                return 1;
        }

        me->add_temp("chazhao_times", -1);        

        message_vision("$N仔细的在房子里查找，可是什么也没有找到。\n", me);

	if ( random (40) == 10 
        && !present("pozhu fu", me)
        && query("fu_count") >= 1)
        {
        add("fu_count", -1);
	ob=new(__DIR__"obj/futou");
	ob->move(me);
	message_vision(HIC"$N突然找到一把黑黝黝的斧头。\n"NOR, me);
        }
        return 1;
}
