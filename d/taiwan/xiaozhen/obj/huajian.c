#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("����", ({ "jiandao", "sword" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "steel");
		set("long", "���������޼���֦�ļ���,���������⼣�߰ߡ�\n");
		set("value", 1400);
		set("wield_msg", "$N�ó�һ��$n���������е���������\n");
		set("unwield_msg", "$N�������е�$n��\n");
              set("mask","ׯ");
	}
	init_sword(20);
	setup();
}
