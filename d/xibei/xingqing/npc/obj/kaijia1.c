#include <armor.h>
inherit ARMOR;
void create()
{
        set_name("连环锁子甲", ({"lianhuan jia", "armor", }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一套银光闪闪的铠甲.\n");
                set("unit", "套");
                set("value",1000);
                set("material", "steel");
                set("armor_prop/armor", 4);
                set("armor_prop/defence", 10);
          
        }
        setup();
}

