// pear.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("Ѽ��", ({ "pear" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ�����ɫ�Ĵ�Ѽ�档\n");
		set("unit", "��");
		set("value", 50);
		set("food_remaining", 4);
		set("food_supply", 20);
	}
	setup();
}