// melon.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("���ܹ�", ({ "melon" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ������ܹϡ�\n");
		set("unit", "��");
		set("value", 50);
		set("food_remaining", 6);
		set("food_supply", 10);
	}
	setup();
}