#include <weapon.h>

inherit CLUB;

void create()
{
        set_name("ɱ�����", ({"shawei bang", "bang"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 200);
                set("material", "wood");
             }
        init_club(20);
        setup();
}

