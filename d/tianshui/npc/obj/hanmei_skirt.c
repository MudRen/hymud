// hanmei_skirt.c

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("��÷�ص�ȹ", ({ "hanmei skirt", "skirt" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�׳�ĵ��������ż�֦��ѩʢ���ĺ�÷��\n");
                set("unit", "��");
                set("value", 600);
                set("material", "cloth");
                set("armor_prop/armor", 1);
                set("armor_prop/personality", 3);
                set("female_only", 1);
        }
        setup();
}