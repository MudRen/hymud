// jiasha.c
// by dicky

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("青布袈裟", ({ "qingbu jiasha", "jiasha" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这是一件普通的袈裟。\n");
		set("unit", "件");
		set("material", "cloth");
		set("armor_prop/armor", 5);
	}
	setup();
}