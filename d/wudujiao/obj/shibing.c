// shibing.c ����

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("����", ({"shi bing", "bing"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ�������������\n");
		set("unit", "��");
		set("value", 20);
		set("food_remaining", 3);
		set("food_supply", 20);
	}
}
