//tiezhihuan.c铁指环
//by trill 04/07/97

#include <armor.h>

inherit FINGER;

void create()
{
        set_name("铁指环", ({"tie zhihuan", "zhihuan", "finger"}));
        set_weight(500);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一枚乌铁打造的指环\n");
                set("unit", "枚");
                set("value", 50);
                set("material", "steel");
                set("armor_prop/armor", 1);
        }
        setup();
}



