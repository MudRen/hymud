#include <weapon.h>

inherit HAMMER;
int do_read(string arg);

void create()
{
        set_name("�˰�÷����", ({ "meihua hammer", "hammer" }) );
        set_weight(12000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�ѷְ˰��÷��״��ͭ�����������Щ��׭��\n");
                set("value", 50);
		set("no_sell", 1);
                set("material", "iron");
                set("wield_msg", "$N�ó�һ��$n��������������Ȼ���������С�\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }
        init_hammer(60);
        setup();
}

