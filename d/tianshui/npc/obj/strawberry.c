// strawberry.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("��ݮ", ({ "strawberry" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ�����Ĵ��ݮ��\n");
		set("unit", "��");
		set("value", 50);
		set("food_remaining", 4);
		set("food_supply", 10);
	}
	setup();
}