// blade.c

#include <weapon.h>
#include <ansi.h>

inherit AXE;

void create()
{
	set_name("��師",({"jinbanfu","jinban fu","fu","axe"}));
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value",3000);
		set("material", "iron");
		set("long","һ�ѳ����Ĵ�ͷ���������ڶ�����װ����\n");
		set("wield_msg","$N������γ�һ�ѳ������$n�������С�\n");
		set("unequip_msg","$N�����е�$n�������䡣\n");
	}
	init_axe(180);
	setup();
}
