#include <weapon.h>

inherit CLUB;

void create()
{
        set_name( "��ì", ({ "chang mao","mao" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "֦");
                set("long", "һ֦���ɶ�ĳ�ì��ìͷ������\n");
                set("value", 500);
                set("material", "iron");
                set("wield_msg", "$N����һ֦$n���������е���������\n");
                set("unwield_msg", "$N�������е�$n��\n");                
        }

        init_club(50);
        setup();
}

