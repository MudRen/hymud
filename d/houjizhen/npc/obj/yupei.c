// yupei.c
// by dicky

#include <armor.h>
#include <ansi.h>
inherit NECK;

void create()
{
        set_name(MAG"��ϼ����"NOR, ({ "zixia yupei","yupei","yu"}) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","��");
		set("material", "iron");
		set("value", 1000);
		set("armor_prop/armor", 10);
		set("armor_prop/dodge", 5);
		set("armor_prop/intelligence", 5);
        }
        setup();
}

