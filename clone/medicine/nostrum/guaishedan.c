#include <ansi.h>
inherit ITEM;
void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
	remove_call_out("decay");
	call_out("decay", 180);
}

void create()
{
	set_name("����֮��", ({"guai shedan", "dan", "shedan"}));
	set("unit", "ֻ");
	set("long", "���ǹ��ߵĵ���ԲԲ�ģ�������ɫ���ȳ��ޱȣ���֪��û�ж���\n");
	set("value", 1000);
	set("lev", 3+random(3));
	set("pour_type", "1");
	setup();
}

int do_eat(string arg)
{
	int force_limit, neili_limit,food_limit,water_limit;
int exp,pot,i;
	object me = this_player();

exp = 888+random(888);
pot = exp/2;

	force_limit = me->query_skill("force")*10;
	neili_limit = me->query("max_neili");
	food_limit = me->max_food_capacity();
	water_limit = me->max_water_capacity();

	if (!id(arg)) return notify_fail("��Ҫ��ʲô��\n");
	if (!present(this_object(), me))
		return notify_fail("��Ҫ��ʲô��\n");
	if( me->is_busy() )
		return notify_fail("�𼱣������ȣ�С�ı�ҭ���ˡ�\n");
if (me->query_condition("medicine"))
{message_vision("$N�ϴε�ҩ�Ի�û��", me);return notify_fail("���ϴε�ҩ�Ի�û����\n");}
	if (( me->query("food")>=food_limit)||(me->query("water")>=water_limit))
		return notify_fail("���Ѿ��Ա��ˣ���Ҳ�Բ����κ�һ�㶫����\n");
	if ( neili_limit <= force_limit  )
	{
		me->add("max_neili", 2);
		me->add("neili", 5);
	}
       me->add("combat_exp",exp);me->apply_condition("medicine", 20);
       me->add("potential",pot);
message_vision("$N�����"+chinese_number(exp)+"�㾭��,"+chinese_number(pot)+"��Ǳ��!\n", me);
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
message_vision(HIR"$N�����"+chinese_number(i)+"��ɳ�����!\n"NOR, me);
}       
}	
	message_vision(HIY "$N����һ���ߵ���ֻ��֭Һ�ȼ��༫���ѳ��ޱȣ�ֻ�����˳�ȥ��\n" NOR, me);
	me->add("food",50);
	me->add("water",50);
	destruct(this_object());
	return 1;
}

void decay()
{
	object where = environment(this_object());
	if ( interactive(where) )
		message("vision", GRN"�ߵ�ž��һ�����ˣ�Ū����һ�������ȳ���\n"NOR, 
			where); 
	else
		message("vision", MAG"�ߵ�ž��һ�����ˣ�֭Һ����һ�ء�\n"NOR,
			where);
	destruct(this_object());
}