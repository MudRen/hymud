// chu tou

#include <weapon.h>

inherit STAFF;



void create()
{
        set_name("锄头", ({ "chu tou","chu" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把普普通通的锄头。\n");
                set("value", 100);
                set("material", "wood");
        }
        init_staff(10);

// These properties are optional, if you don't set them, it will use the
// default values.

        set("wield_msg", "$N纳起一把$n握在手中当武器。\n");
        set("unwield_msg", "$N放下了手中的$n。\n");

// The setup() is required.

        setup();
}
