// mitao.c
// By dicky

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("ˮ����", ({"mi tao", "mitao"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ��ˮ�����ʵ�ˮ���ң����һ���������һ�����޿��ˡ�\n");
		set("unit", "��");
		set("value", 80);
		set("food_remaining", 4);
		set("food_supply", 30);
	}
}
