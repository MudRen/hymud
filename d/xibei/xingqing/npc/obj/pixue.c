//
//by trill 04/07/97

#include <armor.h>

inherit BOOTS;

void create()
{
        set_name("Ƥѥ", ({"pu xue", "xie", "shoes"}));
        set_weight(2000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ˫���ص�Ƥѥ��\n");
                set("unit", "˫");
                set("value", 400);
                set("material", "");
                set("armor_prop/armor", 3);
        }
        setup();
}




