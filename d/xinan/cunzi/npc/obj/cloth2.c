//writen by lnwm
//cloth2.c

#include <armor.h>

inherit CLOTH;

void create()
{
    set_name("碎花小裙", ({ "suihua qun", "qun" }) );
    set("long","一件小小的碎花小裙，给小女孩穿的.\n");
    set_weight(1000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "件");
        set("material", "cloth");
        set("value",100);
        set("armor_prop/armor", 1);
    }
    setup();
}

