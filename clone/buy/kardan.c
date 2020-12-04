// shenliwan.c 福缘丹

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIG "福貌丹" NOR, ({ "kar wan", "wan"}) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "一颗七彩的福貌丹，据说吃了可以加福貌。\n");
                set("value", 10000);
		set("no_put",1);
		set("unit", "颗");
	}
}

void init()
{
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	object me;
int i;

        if (! id(arg))
                return notify_fail("你要吃什么？\n");




        me = this_player();
        message_vision("$N一仰脖，吞下了一颗" + this_object()->name() +
                       "。\n", me);
i=30;
if ( me->query("zhuanshen"))
{
i=50;
}
        if (me->query("kar") > i)
        {

                tell_object(me, "你觉得这药没啥味道，对你的福缘没有作用\n");
        } else
{
                tell_object(me, HIR "你觉得似乎自己的福缘发生了变化。\n" NOR);
                me->add("kar", 1);
}


        if (me->query("per") > i)
        {
                tell_object(me, "你觉得这药没啥味道，对你的相貌没有作用。\n");
        } else
{
                tell_object(me, HIR "你觉得似乎自己的相貌发生了变化。\n" NOR);
                me->add("per", 1);
}


        destruct(this_object());
	return 1;
}
