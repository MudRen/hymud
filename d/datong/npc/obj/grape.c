// grape.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("����", ({ "grape" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ���Ϻ�ɫ�����ѡ�\n");
		set("unit", "��");
		set("value", 50);
		set("food_remaining", 4);
		set("food_supply", 10);
	}
	setup();
}