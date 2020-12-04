// color_head.c

#include <armor.h>
#include <ansi.h>

inherit SHIELD;

void create()
{
	set_name( HIY "雨花石" NOR , ({ "yellow stone" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这是一块黄色的雨花石。\n");
		set("unit", "块");
		set("value", 100);
		set("material", "stone");
		set("armor_prop/armor", 1);
//		set("armor_prop/personality", 0);
//		set("female_only", 1);
	}
	setup();
}

