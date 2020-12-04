// shenliwan.c 福缘丹

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIR "锻炼石" NOR, ({ "duanlian shi", "shi"}) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "一块七彩的锻炼石，据说用(use)在干将锻炼武器，会有意想不到的效果。\n");
                set("value", 10000);
		set("no_put",1);
		set("unit", "块");
	}
}

void init()
{
	add_action("do_eat", "use");
}

int do_eat(string arg)
{
	object me;

        if (! id(arg))
                return notify_fail("你要吃什么？\n");

        me = this_player();
        message_vision("$N把" + this_object()->name() +
                       "拿出打碎成粉。\n", me);

                tell_object(me, HIR "用这些粉，下次锻炼武器应该不会失败了。。\n" NOR);
                me->set_temp("dlwok",1);

        destruct(this_object());
	return 1;
}
