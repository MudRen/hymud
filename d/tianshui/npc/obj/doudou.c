// doudou.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("�춵��", ({ "doudou" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "һ��С���Ӵ��ĺ춵����\n");
		set("unit", "��");
		set("material", "cloth");
		set("armor_prop/armor", 1);
	}
	setup();
}