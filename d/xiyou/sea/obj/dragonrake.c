#include <weapon.h>

inherit CLUB;

void create()
{
        set_name("������", ({ "dragon rake", "pa","rake" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 500);
                set("material", "iron");
                set("long", "һ���������߳ݸְҡ�\n");
                set("wield_msg", "$N����һ��$n����ͷ�ϻ�����һȦ��\n");
        }
        init_club(650);
        setup();
}

