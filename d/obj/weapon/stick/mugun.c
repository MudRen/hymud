#include <weapon.h>

inherit CLUB;

void create()
{
        set_name("ľ��", ({"bang"}));
        set_weight(1400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 100);
                set("material", "wood");
                set("wield_msg", "$N��������һ�����һ��$n�������С�\n");
        }
        init_club(15);
        setup();
}
