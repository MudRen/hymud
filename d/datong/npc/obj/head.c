// head.c

#include <armor.h>

inherit HEAD;

void create()
{
	set_name("��˿ͷ��", ({ "head armor", "head" }) );
	set_weight(800);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit","��");
		set("material", "copper");
		set("value", 5000);
		set("armor_prop/armor", 30);
		set("armor_prop/dodge", -2);
	}
	setup();
}