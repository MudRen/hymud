#include <weapon.h>

inherit CLUB;

void create()
{
        set_name("���ǹ", ({ "dragon stick","gun", "bang" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 5000);
                set("material", "steel");
                set("long", "һ���������������ĳ�ǹ��\n");
                set("wield_msg", "$N����һ��$n��˳�����˸�ǹ����\n");
                set("unwield_msg", "$N����һ������$n��غ�����\n");
        }
        init_club(650);
        setup();
}

