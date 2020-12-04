// sword.c : an example weapon

#include <weapon.h>

inherit DAGGER;

void create()
{
	set_name("紫竹刺", ({ "zi_zhuci" , "zhuci" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long", "一根坚逾精钢的紫竹刺。\n");
		set("value", 400);
		set("material", "steel");
	}
	init_dagger(666);

	set("wield_msg", "$N「唰」地一声抽出一根$n握在手中。\n");
	set("unwield_msg", "$N放下手中的$n。\n");


	setup();
}
