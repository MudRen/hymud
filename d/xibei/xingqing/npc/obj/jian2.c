//  standard sword.c(第二档) edit by lin on March 3,  97
#include <weapon.h>
#include <ansi.h>
inherit SWORD;
//inherit F_SAVE;
//inherit F_AUTOLOAD;
void create()
{
        set_name("长剑", ({ "sword"}) );
        set_weight(1500);
        set("long","一把精钢打就的长剑，剑身两面开刃，很是锋利。\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 1500);
                set("material", "steel");
        }
        init_sword(15);
        set("wield_msg", "$N「唰」的一声抽出一把$n握在手中。\n");
        set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
        setup();
}

