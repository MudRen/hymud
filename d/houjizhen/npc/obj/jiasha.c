// jiasha.c
// by dicky

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("�಼����", ({ "qingbu jiasha", "jiasha" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "����һ����ͨ�����ġ�\n");
		set("unit", "��");
		set("material", "cloth");
		set("armor_prop/armor", 5);
	}
	setup();
}