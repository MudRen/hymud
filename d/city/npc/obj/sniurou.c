// suji.c �ؼ�

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("����ţ��", ({"niu rou", "niurou"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ��������������ţ�⡣\n");
		set("unit", "��");
		set("value", 350);
		set("food_remaining", 10);
		set("food_supply", 90);
	}
}
