#include <armor.h>
inherit CLOTH;


void create()
{
        set_name("�ϳ���", ({ "cloth" }) );
        set("long","һ����ɫ�ĳ��泤���������������ɡ�\n");
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
                set("value",1000);
                set("armor_prop/armor", 1);
        }
        setup();
}
