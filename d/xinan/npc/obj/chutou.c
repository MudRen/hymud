// chu tou

#include <weapon.h>

inherit STAFF;



void create()
{
        set_name("��ͷ", ({ "chu tou","chu" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ������ͨͨ�ĳ�ͷ��\n");
                set("value", 100);
                set("material", "wood");
        }
        init_staff(10);

// These properties are optional, if you don't set them, it will use the
// default values.

        set("wield_msg", "$N����һ��$n�������е�������\n");
        set("unwield_msg", "$N���������е�$n��\n");

// The setup() is required.

        setup();
}
