// shenliwan.c 福缘丹

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIG "武功丹" NOR, ({ "wg wan", "wan"}) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "一颗七彩的武功丹，据说用了(usewg)可以增加指定武功一百级(最高600级)。\n");
                set("value", 10000);
		set("no_put",1);
		set("unit", "颗");
	}
}

void init()
{
	add_action("do_eat", "usewg");
}

int do_eat(string arg)
{
	object me;
	string skillname;
	int skill, skill_basic, times, pertimes;
	
        if (! arg)
                return notify_fail("你要增加加什么武功？\n");

        me = this_player();



	skill = me->query_skill(arg, 1);
	if( skill < 1 )
		return notify_fail("你好像还没有学过这项技能吧？\n");

		if( (string)SKILL_D(arg)->type()=="knowledge" )
return notify_fail("知识类技能吃这个没用的。\n");
		
        message_vision("$N一仰脖，吞下了一颗" + this_object()->name() +
                       "。\n", me);
        if ((skill+1) > 601)
        {
                message_vision("$N眨眨眼。\n", me);
                tell_object(me, "你觉得这药没啥味道，还不如花生好吃。\n");
        } else
{
                tell_object(me, HIR "你觉得似乎自己发生了变化。\n" NOR);
                me->add_skill(arg, 100);
                me->set_skill(arg, skill+100);
}
        destruct(this_object());
	return 1;
}
