// ironarmor.c
#include <armor.h>
inherit CLOTH;

void create()
{
        set_name("����", ({"yin jia", "jia", "armor"}));
        set_weight(30000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
            set("long", "һ������ӲӵĿ��ף�\n");
                set("value", 200);
                set("material", "iron");
                set("armor_type", "cloth");
                set("armor_prop/armor", 135);
             }
        setup();
}

