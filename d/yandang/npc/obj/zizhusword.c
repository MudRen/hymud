// sword.c : an example weapon
#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
	set_name(HIY"�߲��齣"NOR, ({ "qing jian" , "swird" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ���߲��齣��\n");
		set("value", 400);
		set("material", "steel");
	}
	init_sword(666);

	set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
	set("unwield_msg", "$N�������е�$n��\n");


	setup();
}
