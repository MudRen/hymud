// huyao.c


#include <armor.h>

inherit WAIST;

void create()
{
	set_name("Ñü´ø", ({ "yao dai"}) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "Ìõ");
		
		set("value", 0);
		set("material", "leather");
		set("armor_prop/armor", 5);
	}
	setup();
}
