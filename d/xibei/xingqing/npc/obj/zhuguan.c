//zhuguan.c.���
//date:1997.8.27
//by dan  

#include <armor.h>
inherit HEAD;

void create()
{
        set_name("���", ({ "zhu guan", }) );
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����һ�������鴩�ɵ���ڡ�\n");
                set("unit", "��");
                set("value", 12000);
                set("material", "iron");
                set("armor_prop/armor", 5);
                set("armor_prop/personality", 1);
                set("female_only", 1);
        }
        setup();
}

