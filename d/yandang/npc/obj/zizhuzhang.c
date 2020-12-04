// sword.c : an example weapon

#include <weapon.h>

inherit DAGGER;

void create()
{
	set_name("�����", ({ "zi_zhuci" , "zhuci" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�����⾫�ֵ�����̡�\n");
		set("value", 400);
		set("material", "steel");
	}
	init_dagger(666);

	set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
	set("unwield_msg", "$N�������е�$n��\n");


	setup();
}
