// bintiegun.c

#include <weapon.h>

inherit CLUB;

void create()
{
	set_name("����", ({ "stick" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 2000);
		set("material", "steel");
		set("long", "һ���������������������\n");
		set("wield_msg", "$N����һ��$n��˳�����˸�������\n");
		set("unwield_msg", "$N����һ������$n��غ�����\n");
	}
	init_club(135);
	setup();
}
