#include <weapon.h>
#include <ansi.h>
inherit THROWING;

void create()
{
        set_name(RED"小李飞刀"NOR, ({ "flying blade","feidao" }) ); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("wield_msg","$N不知从哪里突然间拽出一把薄薄的$n握在手里．\n");
                set("unit", "些");
                set("base_value", 1);
                set("hxweapon",1);
                set("material", "steel");
                set("base_unit", "把");
                set("base_weight", 10); 
        }       
        set_amount(1);
        init_throwing(200);
        setup();
}
