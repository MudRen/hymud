// 日本折扇 /d/city/chuzhou/npc/obj/riben_zheshan.c
// by lala, 1997-12-14

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name( WHT"纸折扇"NOR, ({ "zhe shan","fan"}) );
        set_weight(100);
        set("long","一把日本出产的折扇，白纸扇面，上面什么也没有画。\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 600);
                set("material", "bamboo");
        }
        init_sword(11);
        set("wield_msg", "$N将一把折扇拿在手中。\n");
        set("unwield_msg", "$N将手中的$n揣回长袖子里。\n");
        setup();
}
