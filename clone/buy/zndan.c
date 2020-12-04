// shenliwan.c 福缘丹

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIG "壮年丹" NOR, ({ "zn wan", "wan"}) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "一颗七彩的壮年丹，据说吃了可以回到壮年时光。\n");
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

        if (! id(arg))
                return notify_fail("你要吃什么？\n");

        me = this_player();
        message_vision("$N一仰脖，吞下了一颗" + this_object()->name() +
                       "。\n", me);

                tell_object(me, HIR "你觉得似乎自己的年龄发生了变化。\n" NOR);
me->set("age", 30); 
me->set("mud_age",1400000);

        destruct(this_object());
	return 1;
}
