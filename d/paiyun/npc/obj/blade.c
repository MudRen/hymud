// blade.c

#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("ţ���󿳵�", ({ "kan dao" }) );
	set_weight(15000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("value", 500);
		set("material", "iron");
		set("long", "����һ�����λε�ţ���󿳵��������»�׹��һ�ƺ�ӧ�롣\n");
		set("wield_msg", "$N���һ�����λε�$n�������С�\n");
		set("unequip_msg", "$N�����е�$n�������䡣\n");
	}
	init_blade(70);
	setup();
}