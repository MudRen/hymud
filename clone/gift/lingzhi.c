// lingzhi.c ǧ����֥
//����(lywin)2000/4/22

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
	set_name(HIR"������֥"NOR, ({"ling zhi", "zhi"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��������ʿ���������������֥����˵��һ�ÿɵ�8000���飬8000Ǳ�ܡ�\n");
		set("value", 100000);
	}
	setup();
}

int do_eat(string arg)
{
	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");

	this_player()->add("combat_exp", 8000);
	this_player()->add("potential",8000);
	message_vision("$N����һ��������֥��ֻ�����Լ��ֱ�������һЩ !\n", this_player());
	destruct(this_object());
	return 1;
}

