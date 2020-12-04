// futou.c
// by dicky

#include <ansi.h>
#include <weapon.h>

inherit AXE;

void create()
{
	set_name(BLK"破竹斧"NOR, ({ "pozhu fu" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "把");
		set("long", "这一把毫不起眼，黑黝黝的斧头。\n");
		set("material", "blacksteel");
		set("wield_msg", "$N「唰」地一声从腰间抽出一把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插入腰间。\n");
	}

	init_axe(160);
	setup();
}