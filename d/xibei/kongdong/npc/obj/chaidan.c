// chai dan

#include <weapon.h>

inherit STAFF;



void create()
{
        set_name("��", ({ "chai dan" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����������Ĳ񵣡�\n");
                set("value", 300);
                set("material", "wood");
        }
        init_staff(10);

// These properties are optional, if you don't set them, it will use the
// default values.

        set("wield_msg", "$N���һ�������õ�$n�������е�������\n");
        set("unwield_msg", "$N���������е�$n��\n");

// The setup() is required.

        setup();
}
