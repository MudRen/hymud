#include <weapon.h>
inherit THROWING;
#include <ansi.h>
void create()
{
        set_name(HIY"金蛋"NOR, ({ "gold ball","ball" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","一颗由黄金打造的暗器。\n");
                set("unit", "堆");
                set("base_value", 1000);
                set("base_unit", "把");
                set("base_weight", 50);
                set("wield_msg","$N不知从哪里掏出一颗$n握在手里．\n");
        }
        set_amount(99);
        init_throwing(100);
        setup();

}
