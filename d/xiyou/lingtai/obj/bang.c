#include <weapon.h>

inherit STAFF;

void create()
{
        set_name("ľ��", ({"mu zhang"}));
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 100);
                set("material", "wood");
                set("wield_msg", "$N��������һ�����һ��$n�������С�\n");
        }
        init_staff(20);
        setup();
}

