// shenliwan.c 福缘丹

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIG "身法丹" NOR, ({ "dex wan", "wan"}) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "一颗七彩的身法丹，据说吃了可以加身法。\n");
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
   
        if (me->query("dex") > i)
        {
                message_vision("$N眨眨眼。\n", me);
                tell_object(me, "你觉得这药没啥味道，还不如花生好吃。\n");
        } else
{
                tell_object(me, HIR "你觉得似乎自己发生了变化。\n" NOR);
                me->add("dex", 1);
}
        destruct(this_object());
	return 1;
}
