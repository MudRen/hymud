#include <weapon.h>

inherit CLUB;

void create()
{
        set_name("ľ��", ({"bang"}));
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 400);
                set("material", "wood");
                set("wield_msg", "$N��������һ�����һ��$n�������С�\n");
        }
        init_club(20);
        setup();
}

