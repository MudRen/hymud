// yangyandan.c ���յ�
// Last Modified by Winder on Mar. 5 2001

inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
}

void create()
{
	set_name(HIW"���յ�"NOR, ({"yangyan dan", "dan"}));
	set("unit", "��");
	set("vegetable", 0);
	set("nostrum", 0);
	set("lev", 1+random(3));
	set("level", 300);
	set("value", 5000);
	set("long", "����һ����ѩ�ɰ������յ���\n");
	set("pour_type", "1");
	setup();
}

int do_eat(string arg)
{
	object me=this_player();

	if(!id(arg)) return notify_fail("��Ҫ��ʲô��\n");
	if(!present(this_object(), me))
		return notify_fail("��Ҫ��ʲô��\n");
	if( me->is_busy() )
		return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�\n");

	if ( me->query("isyy") )
	{
		message_vision("$N�Թ����յ����ٳ�û��Ч���ˡ�\n",me);
	return notify_fail("�ٳ�û��Ч���ˡ�\n");
	}


	if ( me->query("per") >= 30)
	{
		message_vision("$Nû��Ҫ�����յ���\n",me);
	}
	else
	{

		
if(!me->query("isyy"))		me->add("per", 1);
me->set("isyy",1);
		message_vision("$N����һ�����յ�������ʶ���������������������ƺ������Ǳ�ԭ�����˵㡣\n",me);
		destruct(this_object());
	}
	return 1;
}
