// goupi.c
//
// This is the basic equip for players just login.

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("����Ƥë", ({ "pi mao", "pimao" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "fur");
		            set("value", 300+random(800));
                set("armor_prop/armor", 1);
        }
        setup();
}

