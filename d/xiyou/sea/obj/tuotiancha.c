// gangcha.c

#include <weapon.h>

inherit STAFF;


void create()
{
        set_name("�Ź������", ({ "tuotian fork","fork", "cha"}) );
        set_weight(12000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 50);
		set("no_sell", 1);
		set("long", "һ���Ź�������Ť�ɵ����棬�������Щ��׭��\n");
		set("wield_msg", "$N�ӱ����ó��ѻ����������������\n");
		set("unwield_msg", "$N��$n�ַŻر���\n");
                set("material", "iron");
        }
        init_staff(660);
        setup();
}


