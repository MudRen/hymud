// qimeigun.c

#include <weapon.h>

inherit CLUB;

void create()
{
	set_name("��ü��", ({ "qimeigun","gun", "bang" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 5);
		set("material", "wood");
		set("long", "һ���ǳ���ʵ����ü����\n");
		set("wield_msg", "$N����һ��$n��˳�����˸�������\n");
		set("unwield_msg", "$N����һ������$n��غ�����\n");
	}
	init_club(18);
	setup();
}
