#include <armor.h>
inherit WRISTS;
void create()
{
        set_name("玉镯子", ({ "zhuo zi", }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一件制作精美的玉镯子。\n");
                set("unit", "件");
                set("value", 5000);
                set("material", "iron");
                set("armor_prop/armor", 1);
                set("armor_prop/personality", 1);
                set("female_only", 1);
        }
        setup();
}

