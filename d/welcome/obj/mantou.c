// jitui.c ����

#include <weapon.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("��ͷ", ({ "man tou","mantou" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ����ͷ��\n");
		set("unit", "��");
		set("value", 0);
		set("food_remaining", 4);
		set("food_supply", 15);
		//set("wield_msg", "$Nץ��һ��$n���������е�������\n");
		set("material", "bone");
	}
	//init_hammer(1);
	setup();
}

