#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("����", ({ "powan" }));
        set_weight(4000);
	set("long", "ˤ���˵�����롣\n" );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
                set("material", "stone");
		   set("value", 3000);
                set("mask","ׯ");
        }
        setup();
}

