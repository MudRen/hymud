#include <weapon.h>

inherit THROWING;

void create()
{
        set_name("����", ({"pearl"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",    "һ�Ż�Բ�����顣\n");
                set("unit", "��");
                set("base_unit", "��");
                set("base_weight", 1);
                set("base_value", 100);
                set("value", 100);
		set("weapon_prop/personality",1);
		set("wield_msg","$N���Ὣ��������ָ���С�\n");
        }
        set_amount(1);
        init_throwing(20);
        setup();
}

