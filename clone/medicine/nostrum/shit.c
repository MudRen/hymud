// shit.c 狗屎

inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
}
void create()
{
	set_name(YEL"狗黄宝"NOR, ({"shit"}));
	set("unit", "堆");
	set("value", 0);
	set("lev", 1);
	set("long", "这是一堆臭狗屎，不知道是谁拉的。\n");
	setup();
}

int do_eat(string arg)
{
int exp,pot,i;
object me=this_player();
exp = 888+random(888);
pot = exp/2;
	

	if(!id(arg)) return notify_fail("你要吃什么？\n");
	if(!present(this_object(), me))
		return notify_fail("你要吃什么？\n");
	if( me->is_busy() )
		return notify_fail("别急，慢慢吃，小心别噎着了。\n");

if (me->query_condition("medicine"))
{message_vision("$N上次的药性还没过", me);return notify_fail("你上次的药性还没过。\n");}
if(userp(me))
	{
	message_vision(HIY"$N吃下一堆狗黄宝，只觉一股恶臭入心肺，顿时一阵呕吐！\n" NOR, me);
       me->add("combat_exp",exp);me->apply_condition("medicine", 20);
       me->add("potential",pot);


message_vision("$N获得了"+chinese_number(exp)+"点经验,"+chinese_number(pot)+"点潜能!\n", me);
i=1+random(3);
if (random(12)==0 || wizardp(me))
{
if ( me->query("4zhuan") || me->query("5zhuan") )
{
if (me->query("expmax",1) < 1)
{
me->set("expmax",i);
}
else
{
me->add("expmax",i);
}       
message_vision(HIR"$N获得了"+chinese_number(i)+"点成长上限!\n"NOR, me);
}       
}
	me->start_busy(2);
destruct(this_object());
	return 1;
}
	if(arg=="shit") 
		return notify_fail("这你也能吃？真是佩服啊佩服！\n");




	me->start_busy(2);
	return 1;
}
