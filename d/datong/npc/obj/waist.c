// waist.c

#include <armor.h>

inherit WAIST;

void create()
{
	set_name("�ֿ�����", ({ "waist armor", "waist" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("unit","��");
		set("material", "cloth");
		set("value", 5000);
		set("armor_prop/armor", 30);
	}
	setup();
}