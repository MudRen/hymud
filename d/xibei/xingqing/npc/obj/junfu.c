#include <armor.h>
inherit CLOTH;
void create()
{
        set_name("����", ({ "jun fu", "cloth" }));
        set("long", "����һ��ո�µİ��޲�������\n");
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "��");
                set("armor_prop/armor", 1);
        }
        setup();
}

