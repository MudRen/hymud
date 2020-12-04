// shenliwan.c 福缘丹

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIG "因果丹" NOR, ({ "yg wan", "wan"}) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "一颗七彩的因果丹，据说吃了可以改变你的因果。\n");
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
int max;
        if (! id(arg))
                return notify_fail("你要吃什么？\n");

        me = this_player();
        max = me->query_skill("force")*10 + me->query("combat_exp")/1000;
        message_vision("$N一仰脖，吞下了一颗" + this_object()->name() +
                       "。\n", me);
        if (me->query_condition("killer"))
        {
                message_vision("$N眨眨眼。\n", me);
                tell_object(me, "你觉得这药没啥味道，还不如花生好吃。\n");
        } else
{
if (random(12)==1)
{
me->delete("szj/failed");
message_vision(HIG"$N再次获得破解神照经的机会！\n"NOR, this_player());
}
else if (random(12)==2)
{
me->delete("jiuyin/shang-failed");
message_vision(HIG"$N再次获得解九阴上册的机会！\n"NOR, this_player());
}
else if (random(12)==3)
{
me->delete("jiuyin/xia-failed");
message_vision(HIG"$N再次获得解九阴下册的机会！\n"NOR, this_player());
}
else if (random(12)==4)
{
me->delete("zhou/jieyi");
me->delete("zhou/fail");
me->delete("zhou/failed");
message_vision(HIG"$N再次获得解双手互捕的机会！\n"NOR, this_player());
}
else if (random(12)==5)
{
me->delete("jiuyin/gumu-failed");
message_vision(HIG"$N再次获得解九阴古墓的机会！\n"NOR, this_player());
}	
me->clear_condition();
me->set("betrayer",0);
message_vision(HIG"$N的叛师门数清零！\n"NOR, this_player());

}
        destruct(this_object());
	return 1;
}
