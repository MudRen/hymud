#include <weapon.h>

inherit CLUB;
inherit F_UNIQUE;

void create()
{
        set_name("������", ({"puti zhang", "zhang"}));
        set_weight(47000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", "һ�Ѱ���ɫ�Ķ̰���\n");
                set("value", 2330);
                set("material", "steel");
                set("wield_msg", "$N��������һ�����һ��$n�������С�\n");
				set("replace_file", "/d/obj/weapon/stick/qimeigun");
        }
        init_club(140);
        setup();
}

