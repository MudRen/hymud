#include <weapon.h>

inherit CLUB;

void create()
{
        set_name("��֦", ({"shuzhi"}));
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "wood");
        }
        init_club(8);
        setup();
}

