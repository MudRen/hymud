// jiasha.c

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("�಼����", ({ "monk cloth", "cloth" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�����ɫ������ϴ�ú��Ǹɾ���\n");
                set("unit", "��");
                set("value", 100);
                set("material", "cloth");
                set("armor_prop/armor", 2);
                set("male_only", 1);
        }
        setup();
}
