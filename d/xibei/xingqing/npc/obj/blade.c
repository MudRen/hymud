//  standard blade.c(最低档) edit by lin on March 3,  97
#include <weapon.h>
#include <ansi.h>
inherit BLADE;
//inherit F_SAVE;
//inherit F_AUTOLOAD;
void create()
{
        set_name("朴刀", ({ "blade"}) );
        set_weight(2500);
        set("long","一把普普通通的铁刀，重约四五斤。\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 500);
                set("material", "iron");
        }
        init_blade(15);
        set("wield_msg", "$N「唰」的一声抽出一把$n握在手中。\n");
        set("unwield_msg", "$N将手中的$n插入腰间。\n");
        setup();
}

