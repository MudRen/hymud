// shoe.c
#include <armor.h>
inherit BOOTS;

void create()
{
        set_name("̤��ѥ", ({ "cloudy shoes", "shoes" }) );
        set_weight(1700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "˫");
                set("value", 100);
                set("material", "cloth");
                set("armor_prop/armor", 12);
                set("armor_prop/dodge", 8);
        }
        setup();
}

