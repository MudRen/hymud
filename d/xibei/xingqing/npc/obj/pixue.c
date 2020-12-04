//
//by trill 04/07/97

#include <armor.h>

inherit BOOTS;

void create()
{
        set_name("Æ¤Ñ¥", ({"pu xue", "xie", "shoes"}));
        set_weight(2000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "Ò»Ë«±¿ÖØµÄÆ¤Ñ¥¡£\n");
                set("unit", "Ë«");
                set("value", 400);
                set("material", "");
                set("armor_prop/armor", 3);
        }
        setup();
}




