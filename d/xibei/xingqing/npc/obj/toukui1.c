#include <armor.h>
inherit HEAD;
void create()
{
    set_name("朱缨头盔", ({ "tou kui", }) );
    set_weight(1000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("long", "这是军官们戴的头盔.\n");
        set("unit", "只");
        set("value",1000);
        set("material", "iron");
        set("armor_prop/armor", 1);
    }
    setup();
}

