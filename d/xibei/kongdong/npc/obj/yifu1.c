#include <armor.h>
inherit CLOTH;


void create()
{
        set_name("�ϲ�����", ({ "cloth" }) );
        set("long","һ��ո�µ��·���������������ֹ���\n");
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
                set("value",400);
                set("armor_prop/armor", 1);
        }
        setup();
}
