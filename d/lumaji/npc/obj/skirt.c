// skirt.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("��ȹ", ({ "skirt" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "����һ����ͨ�Ĳ�ȹ��\n");
		set("unit", "��");
		set("value", 30);
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("female_only", 1);
	}
	setup();
}