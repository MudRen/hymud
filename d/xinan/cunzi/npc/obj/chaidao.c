//writen by lnwm
//chaidao.c

#include <weapon.h>
#include <ansi.h>

inherit AXE;

void create()
{
        set_name("柴刀", ({ "chai dao","dao","axe"}) );
        set_weight(1500);
        set("long","山民砍柴用的柴刀\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value",100);
                set("material", "steel");
        }
        init_axe(5);
        set("wield_msg", "$N抽出一把$n握在手中。\n");
        set("unwield_msg", "$N将手中的$n插入腰间。\n");
        setup();
}

