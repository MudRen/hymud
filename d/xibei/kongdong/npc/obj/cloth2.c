#include <armor.h>
inherit CLOTH;


void create()
{
        set_name("��ɫ����", ({ "dao pao","pao" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", 3);
        }
        setup();
}
