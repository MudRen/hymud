// jiaozi.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("һ������", ({ "zheng jiao" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "��ͬ��������һ�����ȡ�\n");
		set("unit", "��");
		set("value", 50);
		set("food_remaining", 5);
		set("food_supply", 30);
	}
	setup();
}
