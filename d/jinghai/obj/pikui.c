#include <armor.h>

inherit HEAD;

void create()
{
        set_name("Æ¤¿ø", ({ "pi kui", "kui" }) );
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","¸±");
                set("material", "copper");
                set("value", 800);
                set("armor_prop/armor", 5);
                set("armor_prop/dodge", -2);
        }
        setup();
}

