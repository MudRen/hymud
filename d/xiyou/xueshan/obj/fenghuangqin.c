// sgzl

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

int do_install(string);
int do_uninstall(string);

string ori_long="һ�ѵ���ɫ��ϸ����������͸�������洦���ŵ�㺮�⣬
�������ƺ��и�������װ (install) Щ������ȥ��\n";


void create()
{
       set_name("�����", ({"fenghuang qin","qin","sword"}));
	set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",ori_long);
                set("orilong",ori_long);
                set("unit", "��");
                set("value", 30);
                set("material", "steel");
                set("wield_msg", "$N��Цһ�����ӱ���γ��˷���١�\n");
                set("unwield_msg", "$N�����еķ���ٲ�����У���Ƕ���һ˿Ц�⡣\n");

                set("anqi/allow", 1);
                set("anqi/max", 50);
                set("anqi/now", 0);
        }
        init_sword(660);
        setup();
}

