#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
	set_name(RED"幽冥剑"NOR, ({"youming jian", "youming", "jian", "sword" }));
	set_weight(50000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "一把剑身"+RED+"通红"+NOR",剑尾饰有小骷髅头的长剑。\n");
		set("value", 10000);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回剑鞘。\n");
              set("mask","庄");
	}
	init_sword(500);
	setup();
}
