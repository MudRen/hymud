#include <ansi.h>
#include <armor.h>
inherit BOOTS;

void create()
{
        set_name(HIY"�������" NOR, ({"boot","xiezi","ji"}));
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
            set("long","һ˫�ý�������˫���ֵĶ���Ь.\n");
                set("value", 15000);
                set("material", "cloth");
                set("armor_prop/armor", 15);
             }
	setup();
}

