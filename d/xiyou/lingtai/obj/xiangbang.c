#include <weapon.h>

inherit STAFF;

void create()
{
        set_name("��ħ��", ({"xiangmo bang", "bang"}));
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("no_sell", 1);
		set("long", "һ�ѵ���ɫ�Ķ̰��������а�����������ͬһ�����߰����ڰ��ϡ�\n");
                set("value", 200);
                set("material", "steel");
                set("wield_msg", "$N��������һ�����һ��$n�������С�\n");
        }
        init_staff(660);
        setup();
}

