#include <armor.h>
inherit HEAD;
void create()
{
        set_name("������", ({ "zan zi", }) );
        set_weight(30);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����һ���ð�����ɵ����Ρ�\n");
                set("unit", "��");
                set("value", 1200);
                set("material", "iron");
                set("armor_prop/armor", 1);
                set("armor_prop/personality", 1);
                set("female_only", 1);
        }
        setup();
}

