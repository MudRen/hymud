
#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name("Сʯͷ", ({ "xiao shi tou","shitou","stone" }) );
        set_weight(2400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "stone");
                set("wield_msg", "$N����һ��$n��\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }

        init_hammer(5);
        setup();
}
