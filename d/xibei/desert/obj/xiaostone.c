
#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name("小石头", ({ "xiao shi tou","shitou","stone" }) );
        set_weight(2400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("material", "stone");
                set("wield_msg", "$N拿起一块$n。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }

        init_hammer(5);
        setup();
}
