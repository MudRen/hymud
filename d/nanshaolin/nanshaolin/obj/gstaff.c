// gangzhang.c ����

#include <weapon.h>
inherit STAFF;

void create()
{
	set_name("�ֻط���", ({ "fo staff" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "���Ƿ����� �ֻط��ȡ�\n");
		set("value", 5000);
		set("rigidity",100);
		set("material", "steel");
		set("wield_msg", "$N���һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n�ջء�\n");
	}
  	init_staff(725);
	setup();
}
