// shit.c ��ʺ

inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
}
void create()
{
	set_name(YEL"���Ʊ�"NOR, ({"shit"}));
	set("unit", "��");
	set("value", 0);
	set("lev", 1);
	set("long", "����һ�ѳ���ʺ����֪����˭���ġ�\n");
	setup();
}

int do_eat(string arg)
{
int exp,pot,i;
object me=this_player();
exp = 888+random(888);
pot = exp/2;
	

	if(!id(arg)) return notify_fail("��Ҫ��ʲô��\n");
	if(!present(this_object(), me))
		return notify_fail("��Ҫ��ʲô��\n");
	if( me->is_busy() )
		return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�\n");

if (me->query_condition("medicine"))
{message_vision("$N�ϴε�ҩ�Ի�û��", me);return notify_fail("���ϴε�ҩ�Ի�û����\n");}
if(userp(me))
	{
	message_vision(HIY"$N����һ�ѹ��Ʊ���ֻ��һ�ɶ�����ķΣ���ʱһ��Ż�£�\n" NOR, me);
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
	me->start_busy(2);
destruct(this_object());
	return 1;
}
	if(arg=="shit") 
		return notify_fail("����Ҳ�ܳԣ���������������\n");




	me->start_busy(2);
	return 1;
}
