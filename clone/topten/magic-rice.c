// huyao.c


#include <armor.h>

inherit WAIST;

void create()
{
	set_name("����", ({ "yao dai"}) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		
		set("value", 0);
		set("material", "leather");
		set("armor_prop/armor", 5);
	}
	setup();
}
