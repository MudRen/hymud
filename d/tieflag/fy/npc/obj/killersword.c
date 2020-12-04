 // sword.c : an example weapon
#include <weapon.h>
#include <ansi.h>
inherit SWORD; 
void create()
{
        set_name(HIR"杀手刃"NOR, ({ "killerdagger" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "杀人不沾血的凶器。\n");
                set("value", 400);
                set("material", "steel");
                set("wield_msg", "$N摸出一把$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n藏回怀内。\n");
        }
        ::init_sword(55);
}   
