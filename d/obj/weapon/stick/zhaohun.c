// blade.c

#include <weapon.h>

inherit CLUB;

void create()
{
        set_name("�л��", ({"zhaohun", "stick"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 300);
        }
        init_club(15);
        setup();
}
