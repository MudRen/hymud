// hua_skirt.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("ϸ��ȹ", ({ "skirt" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "����һ�������ϵ�׺��ϸ���Ĳ�ȹ��\n");
		set("unit", "��");
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("female_only", 1);
		set("value",500);
	}
	setup();
}