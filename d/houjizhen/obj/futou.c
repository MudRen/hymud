// futou.c
// by dicky

#include <ansi.h>
#include <weapon.h>

inherit AXE;

void create()
{
	set_name(BLK"����"NOR, ({ "pozhu fu" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("long", "��һ�Ѻ������ۣ�������ĸ�ͷ��\n");
		set("material", "blacksteel");
		set("wield_msg", "$N��ৡ���һ����������һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n�������䡣\n");
	}

	init_axe(160);
	setup();
}