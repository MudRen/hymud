#include <ansi.h>
#include <armor.h> 
inherit NECK; 
void create()
{
        set_name(WHT"白色佛珠"NOR, ({ "white bead", "bead" }) );
        set_weight(60);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "条");
        set("value", 3000);
        set("material", "cloth");
        set("armor_prop/armor", 10);
        set("wear_msg", "$N拿出一条$n，摩挲了几下，然後戴在颈上。\n");
        set("unwear_msg", "$N藏起手中的$n。\n");
        }
        setup();
}
