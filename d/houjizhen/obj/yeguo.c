// yeguo.c
// by dicky

#include <ansi.h>;
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIR"Ұ��"NOR, ({"ye guo", "guo"}));
	set_weight(30);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", 
		"����һֻ�������������Ұ������ͮͮ�ģ������������˵ķ��㡣\n");
		set("food_remaining", 5);
		set("food_supply", 50);
    	setup();
	}
}
