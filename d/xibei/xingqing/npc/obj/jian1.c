#include <weapon.h>
//  standard sword.c(最低档) edit by lin on March 3,  97
#include <ansi.h>
inherit SWORD;
//inherit F_SAVE;
//inherit F_AUTOLOAD;
void create()
{
        set_name("铁剑", ({ "sword"}) );
        set_weight(1500);
        set("long","一把普普通通的铁剑，剑身两面开刃，结实耐用.\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 800);
                set("material", "iron");
        }
        init_sword(10);
        set("wield_msg", "$N抽出一把$n握在手中。\n");
        set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
        setup();
}

