// bintiegun.c ������

#include <weapon.h>

inherit STAFF;

void create()
{
	set_name("������", ({ "bintiegun","tiegun","gun", "bang" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 100);
		set("material", "steel");
		set("long", "һ���������������������\n");
		set("wield_msg", "$N����һ��$n��˳�����˸�������\n");
		set("unwield_msg", "$N����һ������$n��غ�����\n");
	}
	init_staff(35);
	setup();
}
