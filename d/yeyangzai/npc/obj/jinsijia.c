// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>

inherit ARMOR;

void create()
{
	set_name("��˿��",({"jinsijia","jia","armor"}));
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material","iron");
		set("armor_prop/armor",40);
		set("value",5000);
	}
	setup();
}
