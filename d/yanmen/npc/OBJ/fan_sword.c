#pragma save_binary
// sword:__DIR__"obj/fan_sword.c" ���Ƚ�һ��

#include <weapon.h>

inherit SWORD;

void create()
{
    set_name("���Ƚ�",({ "fan sword","fan","sword" }));
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else{
		set("unit", "��");
		set("long", "����һ����״��������������������ġ�\n");
		set("value", 600);
		set("material", "iron");
                set("wield_msg", "$N��ৡ���һ������ڳ��һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n�������ڡ�\n");
        }
	init_sword(20);
	setup();
}

