#include <armor.h>

inherit ARMOR;

void create()
{
        set_name("Ƥ��", ({ "pi jia","jia" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "iron");
                set("value", 2000);
                set("armor_prop/armor", 5);
                set("armor_prop/dodge", -2);
        }
        setup();
}

