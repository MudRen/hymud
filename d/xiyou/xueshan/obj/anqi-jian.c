// sgzl

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

int do_install(string);
int do_uninstall(string);

string ori_long="һ��������彣���������ƺ���Щ������װ(install)Щ������ȥ��\n";


void create()
{
        set_name("�彣", ({"pei jian","jian","sword"}));
	set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",ori_long);
                set("orilong",ori_long);
                set("unit", "��");
                set("value", 3000);
                set("material", "steel");
                set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");

                set("anqi/allow", 1);
                set("anqi/max", 20);
                set("anqi/now", 0);
        }
        init_sword(135);
        setup();
}

