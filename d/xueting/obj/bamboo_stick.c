// bamboo_stick.c
// by pian

#include <weapon.h>

inherit STAFF;

void create()
{
        set_name("���", ({ "bamboo stick", "stick" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("value", 200);
                set("material", "bamboo");
                set("long", 
"����һ����ϰ�����õ������\n");
                set("wield_msg", "$N�ó�һ�������õ�$n���������С�\n");
                set("unequip_msg", "$N�������е�$n��\n");
        }
        init_staff(17);
        setup();
}
 
