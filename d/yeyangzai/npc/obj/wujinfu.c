// blade.c

#include <weapon.h>
#include <ansi.h>

inherit AXE;

void create()
{
	set_name(RED"�ڽ�"NOR,({"wujinfu","fu","axe"}));
	set_weight(12000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value",5000);
		set("material", "iron");
		set("long","΢΢�������Ĵ�ͷ��������Ϊ�ڶ�����װ����\n");
		set("wield_msg","$N�������$n������ǰ�������Ρ�\n");
		set("unequip_msg","$N����΢ת����$n�������\n");
	}
	init_axe(190);
	setup();
}
