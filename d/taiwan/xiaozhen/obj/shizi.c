#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("石狮子", ({ "shizi" }));
        set_weight(70000);
	set("long", "一只石头雕刻而成的狮子,看上去倒还威风。\n" );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "只");
                set("material", "stone");
		   set("value", 6000);
                set("mask","庄");
        }
        setup();
}

