// armor.c

#include <armor.h>

inherit ARMOR;

void create()
{
	set_name("�������ļ�", ({ "light armor" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "iron");
		set("value", 12000);
		set("armor_prop/armor", 40);
		set("armor_prop/dodge", -2);
	}
	setup();
}
