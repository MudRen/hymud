//tiezhihuan.c��ָ��
//by trill 04/07/97

#include <armor.h>

inherit FINGER;

void create()
{
        set_name("��ָ��", ({"tie zhihuan", "zhihuan", "finger"}));
        set_weight(500);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����һö���������ָ��\n");
                set("unit", "ö");
                set("value", 50);
                set("material", "steel");
                set("armor_prop/armor", 1);
        }
        setup();
}



