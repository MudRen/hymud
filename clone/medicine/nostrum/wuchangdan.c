//wuchangdan.c
#include <ansi.h>
inherit ITEM;
void setup()
{}
void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
}
void create()
{
	set_name(HIR"无常丹"NOR, ({"wuchang dan", "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", "这是一颗晶莹火红的无常丹，经桃花岛主精心练制，
有起死回生之功。\n");
		set("lev", 3+random(5));
		set("value", 50000);
	}
	set("pour_type", "1");
	setup();
}

int do_eat(string arg)
{
	int fw;
	int force_limit, neili_limit, force_skill, add_skill, improve;
	int nowcondition;

int exp,pot,i;
	object me = this_player();

exp = 888+random(888);
pot = exp/2;

	force_limit = me->query_skill("force", 1)*10;
	neili_limit = me->query("max_neili");
	force_skill = me->query_skill("force", 1);

	if (!id(arg)) return notify_fail("你要吃什么？\n");
	if (!present(this_object(), me))
		return notify_fail("你要吃什么？\n");
	if (me->is_busy() )
		return notify_fail("别急，慢慢吃，小心别噎着了。\n");
if (me->query_condition("medicine"))
{message_vision("$N上次的药性还没过", me);return notify_fail("你上次的药性还没过。\n");}
	if(me->query("eff_jing") >= me->query("max_jing") &&
		me->query("eff_qi") >= me->query("max_qi") )
	{
		message_vision(HIG"$N吃下一只无常丹，只觉全身冰凉，看来你补药吃太多了，闹起肚子来了！\n" NOR, me);
		me->receive_damage("jing",30);
		me->receive_damage("qi",50);
		me->receive_wound("jing",20);
		me->receive_wound("qi",40);
	}
	else
	{
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
	 	me->set("eff_jing",me->query("max_jing"));
		me->set("jing",me->query("max_jing"));
		me->set("eff_qi",me->query("max_qi"));
		me->set("qi",me->query("max_qi"));
		message_vision(HIR"$N吃下一颗无常丹，一股热流从丹田升起，顿时全身充满力量！\n"NOR,me);
	}
	destruct(this_object());
	me->start_busy(2);
	return 1;
}

