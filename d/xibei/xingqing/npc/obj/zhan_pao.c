//edit by lin on March 4.  1997
#include <armor.h>
inherit SURCOAT;
void create()
{
        set_name("猩红战袍", ({ "cloth", }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是军队里通用的军服，标志军官身份的战袍。\n");
                set("unit", "件");
                set("value",140);
                set("material", "cloth");
                set("armor_prop/armor", 1);
          
        }
        setup();
}

