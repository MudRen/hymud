//zao_sitao��˿��c
//by trill 
#include <armor.h>
inherit WAIST;
void create()
{
    set_name("��˿��", ({"zao sitao", "yaodai", "waistband"}));
    set_weight(100);
    if ( clonep() )
        set_default_object(__FILE__);
    else {
        set("long", "һ����ɫ��˿����\n");
        set("unit", "��");
        set("value", 50);
        set("material", "silk");
        set("armor_prop/armor", 1);
    }
    setup();
}

