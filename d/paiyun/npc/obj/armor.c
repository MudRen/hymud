// armor.c

#include <armor.h>

inherit ARMOR;

void create()
{
	set_name("ţƤ��", ({ "armor" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "iron");
		set("value", 1000);
		set("armor_prop/armor", 30);
		set("armor_prop/dodge", -2);
	}
	setup();
}
