#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIC"夜明珠"NOR, ({ "yemingzhu","zhuzi","mingzhu" }));
        set_weight(10000);
	set("long", "既使在黑暗中也掩不住其光茫的明珠。\n" );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("material", "stone");
		   set("value", 10000);
                set("mask","庄");
        }
        setup();
}

