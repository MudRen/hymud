// z-dan.c
// 星星(lywin)炼丹任务附属道具
#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name("三黄宝腊丹", ({"gdan5", "dan5"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", "这是一颗三黄宝腊丹。\n");
		set("value", 10000);
	}
	setup();
}

int do_eat(string arg)
{
        object me = this_player();
 	if (!id(arg))
	return notify_fail("你要吃什么？\n");

	if ( me->query("max_neili") < 100 )
	{
		me->add("max_neili", -1);
		message_vision(HIR "$N吃下一颗三黄宝腊丹，只觉得头重脚轻，摇摇欲倒，原来功力不够，药效适得其反！\n" NOR, me);
	}
            else if ( (int)me->query_condition("medicine") > 0 )
	{
		me->add("max_neili", -1);
		message_vision(HIR "$N吃下一颗三黄宝腊丹，只觉得头重脚轻，摇摇欲倒，原来服食太急太多，药效适得其反！\n" NOR, me);
	}
	else
	{
        me->set("neili", (int)me->query("max_neili"));

        message_vision(HIG "$N吃下一颗三黄宝腊丹，只觉得体内真力源源滋生，你的气和精提高了!\n" NOR, me);
	}

        me->apply_condition("medicine", 3);
	
	destruct(this_object());
	return 1;
}