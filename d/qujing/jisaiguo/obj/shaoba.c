#include <weapon.h>

inherit STAFF;

void create()
{
        set_name("��ɨ��", ({"broom"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 50);
                set("material", "wood");
                set("wield_msg", "$N��$n�������У�\n");
        }
        init_staff(10);
        setup();
}

