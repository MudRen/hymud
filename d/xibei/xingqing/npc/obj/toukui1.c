#include <armor.h>
inherit HEAD;
void create()
{
    set_name("��ӧͷ��", ({ "tou kui", }) );
    set_weight(1000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("long", "���Ǿ����Ǵ���ͷ��.\n");
        set("unit", "ֻ");
        set("value",1000);
        set("material", "iron");
        set("armor_prop/armor", 1);
    }
    setup();
}

