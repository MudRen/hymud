//writen by lnwm
//cloth2.c

#include <armor.h>

inherit CLOTH;

void create()
{
    set_name("�黨Сȹ", ({ "suihua qun", "qun" }) );
    set("long","һ��СС���黨Сȹ����СŮ������.\n");
    set_weight(1000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("material", "cloth");
        set("value",100);
        set("armor_prop/armor", 1);
    }
    setup();
}

