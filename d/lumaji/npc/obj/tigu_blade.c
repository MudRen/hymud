// tugu_blade.c

#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("��ǵ�", ({ "tigu blade" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("value", 200);
		set("material", "iron");
		set("long", "����һ������õļ⵶��\n");
		set("wield_msg", "$N���һ�����λε�$n�������С�\n");
		set("unequip_msg", "$N�����е�$n�������䡣\n");
	}
	init_blade(60);
	setup();
}