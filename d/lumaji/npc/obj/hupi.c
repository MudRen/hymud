// hupi.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("��ƤΧȹ", ({ "hupi skirt" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "����һ���ɻ�Ƥ���ɵ�Χȹ��\n");
		set("unit", "��");
		set("value", 2000);
		set("material", "cloth");
		set("armor_prop/armor", 20);
	}
	setup();
}