// tuofeng.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("�����շ�", ({ "tuofeng"}) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "�����ɸ������Ƶĺ����շ塣\n");
		set("unit", "��");
		set("value", 2000);
		set("food_remaining", 4);
		set("food_supply", 20);
	}
	setup();
}