//baizhan.c.白毡
//date:1997.8.27
//by dan  

#include <armor.h> 
#include <ansi.h>
inherit CLOTH; 

void create()
{
    set_name(YEL"白毡"NOR, ({ "bai zhan", "zhan" }) );
    set("long","这是一条用纯白的细驼毛织成的白毛毡。\n");
    set_weight(3000);     
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "条");
        set("material", "cloth");
        set("value",5000);
        set("armor_prop/armor",15);
    }
    setup();
}

