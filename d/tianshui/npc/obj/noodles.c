// noodles.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        string *name = ({"������","������","������","��˿��","ţ������",
			"��˿��","�Ź���","������","������"});
	set_name( name[random(9)], ({ "noodles" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ���������ڵ�������\n");
		set("unit", "��");
		set("value", 100);
		set("food_remaining", 6);
		set("food_supply", 20);
	}
	setup();
}