// wucai_skirt.c

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("��ʳ�ȹ", ({ "wucai skirt", "skirt" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "ǳ��ĵĵ��������ųΡ��ơ��̡���������ɫ�󻨣������Ŀ��\n");
                set("unit", "��");
                set("value", 600);
                set("material", "cloth");
                set("armor_prop/armor", 1);
                set("armor_prop/personality", 3);
                set("female_only", 1);
        }
        setup();
}